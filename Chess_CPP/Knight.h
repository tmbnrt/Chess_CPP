#ifndef KNIGHT_H
#define KNIGHT_H

#include<string>
#include<vector>
#include "Character.h"

class Knight : public Character
{
public:
    Knight();
    ~Knight() override;
    char                                        getDesignation() const override;
    //std::vector<std::vector<int>>               checkMoves(std::vector<std::vector<Character>> board);  // returns possible movement positions

private:
    int											points;
};

#endif