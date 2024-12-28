#ifndef ROOK_H
#define ROOK_H

#include<string>
#include<vector>
#include "Character.h"
#include "Action.h"

class Rook : public Character
{
public:
    Rook();
    ~Rook() override;
    char                                        getDesignation() const override;    
    Action                                      checkMoves(std::vector<std::vector<Character*>> board) override ;  // returns possible movement positions

private:
    int											points;
};

#endif