#ifndef QUEEN_H
#define QUEEN_H

#include<string>
#include<vector>
#include "Character.h"

class Queen : public Character
{
public:
    Queen();
    ~Queen() override;
    char                                        getDesignation() const override;
    //std::vector<std::vector<int>>               checkMoves(std::vector<std::vector<Character>> board);  // returns possible movement positions

private:

};

#endif