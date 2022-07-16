// https://en.wikipedia.org/wiki/Turing_machine#Formal_definition
#pragma once
#include <set>
#include <string>
#include <tuple>
#include <map>
#include <deque>
#include <ostream>

enum Dir { L, R };
using symbol = std::string;
using A = std::tuple<symbol, symbol>;
using B = std::tuple<symbol, symbol, Dir>;
using TransitionFunction = std::map<A, B>;

class TuringMachine {
private:
	const std::set<symbol> tapeSymbols;
	const symbol blankSymbol;
	const std::set<symbol> inputSymbols;
	const std::set<symbol> states;
	const symbol initialState;
	const std::set<symbol> finalStates;
	const TransitionFunction d;
public:
	TuringMachine(
		const std::set<symbol> tapeSymbols,
		const symbol blankSymbol,
		const std::set<symbol> inputSymbols,
		const std::set<symbol> states,
		const symbol initialState,
		const std::set<symbol> finalStates,
		const TransitionFunction d
	);
	std::deque<symbol>& operator() (std::deque<symbol>&);
	static void print_tape(std::deque<symbol>&, std::ostream&);
};

