#ifndef DFA_H
#define DFA_H

#include <map>
#include <vector>

class DFA {
private:
	typedef struct node { 
		std::map<char, int> transition;
		bool isFinal;
	} Node;

	std::vector<Node> DfaNodes;
	int current;

public:
	DFA();
	void AddTransition(int source, char input, int dest);
	int NewState();
	void SetFinal(int index);
	bool TestChar(char input);
	bool TestString(char *str);
	void Reset();
};

#endif