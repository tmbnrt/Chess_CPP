#ifndef KNIGHT_H
#define KNIGHT_H

#include "Character.h"
#include<vector>

class Knight : public Character
{
public:
    Knight();
    ~Knight() override ;
    char                                        getDesignation() const override ;
    void                                        checkMoves(std::vector<std::vector<Character*>> board) override ;
};

#endif
