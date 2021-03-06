#include "Adder.h"

Adder::Adder()
	: TuringMachine(
		{ "0" },
		"_",
		{ "_", "00", "01", "11", "1", "0" },
		{ "q0", "q1", "q2", "q3" },
		"q0",
		{ "q3" },
		{
			{{"q0", "00"}, {"q0", "00", R}},
			{{"q0", "01"}, {"q0", "01", R}},
			{{"q0", "10"}, {"q0", "10", R}},
			{{"q0", "11"}, {"q0", "11", R}},
			{{"q0",  "_"}, {"q1",  "_", L}},

			{{"q1", "00"}, {"q1",  "0", L}},
			{{"q1", "01"}, {"q1",  "1", L}},
			{{"q1", "10"}, {"q1",  "1", L}},
			{{"q1", "11"}, {"q2",  "0", L}},
			{{"q1",  "_"}, {"q3",  "_", R}},

			{{"q2", "11"}, {"q2",  "1", L}},
			{{"q2", "10"}, {"q2",  "0", L}},
			{{"q2", "01"}, {"q2",  "0", L}},
			{{"q2", "00"}, {"q1",  "1", L}},
			{{"q2",  "_"}, {"q3",  "1", R}}
		}
	)
{ }
