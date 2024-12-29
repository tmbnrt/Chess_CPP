#ifndef QUEEN_H
#define QUEEN_H

#include "Character.h"
#include<vector>

class Queen : public Character
{
public:
    Queen();
    ~Queen() override;
    char                                        getDesignation() const override ;
    void                                        checkMoves(std::vector<std::vector<Character*>> board) override ;
};

#endif
