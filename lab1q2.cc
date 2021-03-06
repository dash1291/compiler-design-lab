#include <iostream>

#include "dfa/dfa.cc"

using namespace std;

int main(int argc, char *argv[]) {
	DFA *dfa;
	dfa = new DFA();
	dfa->NewState();
	dfa->AddTransition(0, '/', 1);
	
	dfa->NewState();
	dfa->AddTransition(1, '/', 2);
	dfa->AddTransition(1, '*', 3);
	
	dfa->NewState();
	dfa->AddTransition(2, '.', 2);
	dfa->SetFinal(2);

	dfa->NewState();
	dfa->AddTransition(3, '.', 3);
	dfa->AddTransition(3, '*', 4);

	dfa->NewState();
	dfa->AddTransition(4, '/', 5);
	

	dfa->NewState();
	dfa->AddTransition(5, '.', 0);
	dfa->AddTransition(5, '/', 1);
	dfa->SetFinal(5);

	if(dfa->TestString(argv[1]) == true) {
		cout << "accepted" << endl;
	} else {
		cout << "rejected" << endl;
	}

	return 0;
}