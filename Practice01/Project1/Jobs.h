#pragma once
#ifndef JOBS_H
#define JOBS_H

#include "Player.h"

// 1. 전사 (HP 특화)
class Warrior : public Player 
{
public:
    Warrior(string name, int hp, int mp, int power, int defence);
    void attack() override;
};

// 2. 마법사 (MP 특화)
class Magician : public Player 
{
public:
    Magician(string name, int hp, int mp, int power, int defence);
    void attack() override;
};

// 3. 도적 (공격력 특화)
class Thief : public Player 
{
public:
    Thief(string name, int hp, int mp, int power, int defence);
    void attack() override;
};

// 4. 궁수 (방어력 특화)
class Archer : public Player 
{
public:
    Archer(string name, int hp, int mp, int power, int defence);
    void attack() override;
};

#endif