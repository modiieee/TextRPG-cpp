#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

using namespace std;

// 초기 생성 시 사용하는 배열 기반 출력 함수
inline void printStatus(string name, int stat[]) 
{
    cout << "========================================\n";
    cout << "  " << name << " 의 현재 능력치\n";
    cout << "========================================\n";
    cout << "HP: " << stat[0] << "    MP: " << stat[1] << "\n";
    cout << "공격력: " << stat[2] << "    방어력: " << stat[3] << "\n";
    cout << "========================================\n";
}

#endif
