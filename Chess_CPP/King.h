#ifndef KING_H
#define KING_H

#include "Character.h"
#include<vector>

class King : public Character
{
public:
    King();
    ~King() override ;
    char                                        getDesignation() const override ;
    void                                        checkMoves(std::vector<std::vector<Character*>> board) override ;

private:
    DangerZone									dangerZone;
};

#endif
