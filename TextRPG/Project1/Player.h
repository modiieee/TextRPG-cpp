#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Monster;

class Player 
{
protected:
    string name;
    string job;
    int level;
    int hp;
    int mp;
    int power;
    int defence;

public:
    // 생성자
    Player(string name, string job, int hp, int mp, int power, int defence);

    // 가상 소멸자
    virtual ~Player() {}

    // 순수 가상 함수 (자식 클래스에서 무조건 오버라이딩 필수)
    virtual void attack() = 0;

    // 상태 출력 함수
    void printPlayerStatus() const;

    // STEP5 : 실제 몬스터 타격 및 데미지 계산 함수
    void attackMonster(Monster* monster);



    // Getter & Setter
    string getName() const { return name; }
    string getJob() const { return job; }
    int getLevel() const { return level; }

    int getHp() const { return hp; }
    int getMp() const { return mp; }

    int getPower() const { return power; }
    int getDefence() const { return defence; }

    void setHp(int hp) { this->hp = hp; }
    void setMp(int mp) { this->mp = mp; }
    void setPower(int power) { this->power = power; }
    void setDefence(int defence) { this->defence = defence; }
};

#endif