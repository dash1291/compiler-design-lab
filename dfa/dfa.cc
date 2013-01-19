#include "dfa.h"

using namespace std;

DFA::DFA() {
	current = 0;
}

// Create a new state in the DFA and return its index.
int DFA::NewState() {
	Node newnode;
	newnode.isFinal = false;
	DfaNodes.push_back(newnode);
	return DfaNodes.size();
}

void DFA::AddTransition(int source, char input, int dest) {
	DfaNodes[source].transition[input] = dest;
}

// Set a state at a particular index as final state.
void DFA::SetFinal(int index) {
	DfaNodes[index].isFinal = true;
}

// feed a character and return true if the DFA reaches its final state.
bool DFA::TestChar(char input) {
	int dest;
	dest = DfaNodes[current].transition[input];
	current = dest;
	if(DfaNodes[current].isFinal == true) {
		return true;
	} else {
		return false;
	}
}

void DFA::Reset() {
	current = 0;
}

// Feed a string and return true if the DFA reaches the final state.
bool DFA::TestString(char *s) {
	char c;
	bool res;
	while(*s != '\0') {
		c = *s;
		res = TestChar(c);
		s++;
	}
	Reset();
	return res;
}