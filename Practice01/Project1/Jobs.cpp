#include "Jobs.h"

// 1. 전사: HP +30 특화
Warrior::Warrior(string name, int hp, int mp, int power, int defence)
    : Player(name, "전사", hp + 30, mp, power, defence) 
{
    cout << "* 전사로 전직하였습니다. (HP +30)\n";
}
void Warrior::attack() 
{
    cout << "* 강력한 검기 찌르기를 사용한다!\n";
}

// 2. 마법사: MP +30 특화
Magician::Magician(string name, int hp, int mp, int power, int defence)
    : Player(name, "마법사", hp, mp + 30, power, defence) 
{
    cout << "* 마법사로 전직하였습니다. (MP +30)\n";
}
void Magician::attack() 
{
    cout << "* 파이어볼을 발사한다!\n";
}

// 3. 도적: 공격력 +30 특화
Thief::Thief(string name, int hp, int mp, int power, int defence)
    : Player(name, "도적", hp, mp, power + 30, defence) 
{
    cout << "* 도적으로 전직하였습니다. (공격력 +30)\n";
}
void Thief::attack() 
{
    cout << "* 그림자 속에서 연속 베기를 시전한다!\n";
}

// 4. 궁수: 방어력 +30 특화
Archer::Archer(string name, int hp, int mp, int power, int defence)
    : Player(name, "궁수", hp, mp, power, defence + 30) 
{
    cout << "* 궁수로 전직하였습니다. (방어력 +30)\n";
}
void Archer::attack() 
{
    cout << "* 정밀한 조준으로 화살을 쏴 맞춘다!\n";
}