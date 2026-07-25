#include "Monster.h"

Monster::Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemPrice)
    : name(name), hp(hp), power(power), defence(defence), dropItemName(dropItemName), dropItemPrice(dropItemPrice) {}

// 몬스터 공격. 
void Monster::attack(Player* player) {
    cout << "--- 몬스터 턴 ---\n";
    cout << name << "의 공격!\n";

    // [데미지 공식] 공격력 - 방어력 (0 이하이면 1로 고정)
    int damage = power - player->getDefence();
    if (damage <= 0) 
    {
        damage = 1;
    }

    int prevHp = player->getHp();
    int currentHp = prevHp - damage;
    player->setHp(currentHp);

    cout << player->getName() << "에게 " << damage << " 데미지!\n";
    cout << player->getName() << " HP: " << prevHp << " -> " << currentHp;
    if (currentHp <= 0) 
    {
        cout << " (사망)";
    }
    cout << "\n\n";
}