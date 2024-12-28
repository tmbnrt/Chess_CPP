#ifndef ACTION_H
#define ACTION_H

#include<vector>

class Action
{
public:
	Action();
	~Action();
	std::vector<std::vector<int>>				moves;
	std::vector<std::vector<int>>				kills;

	void										addMove(std::vector<int> move);
	void										addKill(std::vector<int> kill);
};

#endif