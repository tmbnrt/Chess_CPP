#ifndef PAWN_H
#define PAWN_H

#include<string>
#include<vector>
#include "Character.h"

class Pawn : public Character
{
public:
    Pawn();
    ~Pawn() override;
    char                                        getDesignation() const override;
    Action                                      checkMoves(std::vector<std::vector<Character*>> board);  // returns possible movement positions

private:   
};

#endif