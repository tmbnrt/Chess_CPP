#ifndef PAWN_H
#define PAWN_H

#include "Character.h"
#include<vector>

class Pawn : public Character
{
public:
    Pawn();
    ~Pawn() override ;
    char                                        getDesignation() const override ;
    void                                        checkMoves(std::vector<std::vector<Character*>> board) override ;
};

#endif
