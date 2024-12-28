#ifndef BISHOP_H
#define BISHOP_H

#include<string>
#include<vector>
#include "Character.h"

class Bishop : public Character
{
public:
    Bishop();
    ~Bishop() override;
    char                                        getDesignation() const override;
    //std::vector<std::vector<int>>               checkMoves(std::vector<std::vector<Character>> board);  // returns possible movement positions

private:
    int											points;
};

#endif