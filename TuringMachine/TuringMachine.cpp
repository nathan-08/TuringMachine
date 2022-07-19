#include "TuringMachine.h"
#include <algorithm>

using namespace std;

TuringMachine::TuringMachine(
	const std::set<symbol> tapeSymbols,
	const symbol blankSymbol,
	const std::set<symbol> inputSymbols,
	const std::set<symbol> states,
	const symbol initialState,
	const std::set<symbol> finalStates,
	const TransitionFunction d
) :
	tapeSymbols(tapeSymbols),
	blankSymbol(blankSymbol),
	inputSymbols(inputSymbols),
	states(states),
	initialState(initialState),
	finalStates(finalStates),
	d(d)
{}

Tape& TuringMachine::operator() (Tape& tape) {
	symbol state = initialState;
	size_t idx = 0;
	while (finalStates.find(state) == finalStates.end()) {
		try {
			auto [new_state, new_symbol, new_direction] = d.at({ state, tape.at(idx) });
			tape.at(idx) = new_symbol; // update tape
			state = new_state;  // update state
			if (new_direction == L) { // move left
				if (idx == 0) {
					tape.push_front(blankSymbol);
				}
				else {
					--idx;
				}
			}
			else { // move right
				++idx;
				if (idx == tape.size()) tape.push_back(blankSymbol);
			}
		}
		catch (exception&) {
			throw logic_error("machine crashed");
		}
	}
	return tape;
}

void TuringMachine::print_tape(Tape& tape, ostream& os) {
	for_each(tape.begin(), tape.end(), [&](symbol s) {
		os << "[" << s << "]";
		});
}

