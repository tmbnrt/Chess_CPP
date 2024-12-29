#ifndef BISHOP_H
#define BISHOP_H

#include "Character.h"
#include<vector>

class Bishop : public Character
{
public:
    Bishop();
    ~Bishop() override ;
    char                                        getDesignation() const override ;
    void                                        checkMoves(std::vector<std::vector<Character*>> board, bool friendlyFire = false) override ;
};

#endif
