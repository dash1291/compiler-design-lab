#include <iostream>

#include "dfa/dfa.cc"

using namespace std;

int main() {
	DFA *dfa;
	dfa = new DFA();
	dfa->NewState();
	dfa->AddTransition(0, '0', 1);
	dfa->AddTransition(0, '1', 1);
	dfa->NewState();
	dfa->AddTransition(1, '0', 2);
	dfa->AddTransition(1, '1', 2);
	dfa->NewState();
	dfa->AddTransition(2, '0', 3);
	dfa->AddTransition(2, '1', 3);
	dfa->NewState();
	dfa->AddTransition(3, '0', 2);
	dfa->AddTransition(3, '1', 2);
	dfa->SetFinal(3);

	if(dfa->TestString("001") == true) {
		cout << "accepted";
	} else {
		cout << "rejected";
	}

	return 0;
}