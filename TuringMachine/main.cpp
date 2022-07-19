#include <iostream>
#include "TuringMachine.h"
#include "Adder.h"
using namespace std;

int main(void) {
	Adder adder;
	Tape tape = { "11", "00", "00" }; // add 100 + 100 (binary)
	TuringMachine::print_tape(adder(tape), cout);
	cout << endl;
}

