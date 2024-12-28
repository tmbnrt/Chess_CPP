#ifndef KING_H
#define KING_H

#include<string>
#include<vector>
#include "Character.h"

class King : public Character
{
public:
    King();
    ~King() override;
    char                                        getDesignation() const override;
    //std::vector<std::vector<int>>               checkMoves(std::vector<std::vector<Character>> board);  // returns possible movement positions

private:
    bool										initMove;
};

#endif
