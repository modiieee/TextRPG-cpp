#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
#include <algorithm> // std::max 사용을 위해 포함
#include "Player.h"
#include "Item.h"

using namespace std;

class Monster {
private:
    string name;
    int hp;
    int power;
    int defence;
    string dropItemName;
    int dropItemPrice;

public:
    // 생성자
    Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemPrice);

    // 몬스터가 플레이어를 공격하는 함수
    void attack(Player* player);

    // Getter & Setter
    string getName() const { return name; }
    int getHP() const { return hp; }
    int getPower() const { return power; }
    int getDefence() const { return defence; }
    string getDropItemName() const { return dropItemName; }
    int getDropItemPrice() const { return dropItemPrice; }

    void setHP(int hp) { this->hp = hp; }

    // step6 : 몬스터가 드롭할 Item 구조체 반환 메서드. 
    Item getDropItem() const
    {
        return { dropItemName, dropItemPrice };
    }
};

#endif
