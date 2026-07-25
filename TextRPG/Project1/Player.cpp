#include "Player.h"
#include "Monster.h"

Player::Player(string name, string job, int hp, int mp, int power, int defence)
    : name(name), job(job), level(1), hp(hp), mp(mp), power(power), defence(defence) {}

void Player::printPlayerStatus() const 
{
    cout << "----------------------------------------\n";
    cout << "닉네임: " << name << " | 직업: " << job << " | Lv." << level << "\n";
    cout << "HP: " << hp << " | MP: " << mp << " | 공격력: " << power << " | 방어력: " << defence << "\n";
    cout << "----------------------------------------\n";
}

// STEP5 주의할 점 : 실제 데미지 계산은 전투 함수에서 처리
void Player::attackMonster(Monster* monster)
{
    cout << "--- 플레이어 턴 ---\n";
    this->attack(); // 가상 함수 호출. (플레이어 공격)

    // 데미지 공식 : 공격력 - 방어력 (0 이하이면 1로 고정)
    int damage = power - monster->getDefence();
    if (damage <= 0)
    {
        damage = 1;
    }

    int prevHP = monster->getHP();
    int currentHP = prevHP - damage;
    monster->setHP(currentHP);

    cout << monster->getName() << "에게 " << damage << " 데미지!\n";
    cout << monster->getName() << " HP: " << prevHP << " -> " << currentHP;
    if (currentHP <= 0)
    {
        cout << " (사망)";
    }
    cout << "\n\n";
}