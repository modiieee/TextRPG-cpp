#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

// [STEP 6] Item 구조체 정의
struct Item 
{
    string name;
    int price;

    // 아이템 정보 출력 함수
    void PrintInfo() const 
    {
        cout << name << " (" << price << "G)";
    }
};

#endif