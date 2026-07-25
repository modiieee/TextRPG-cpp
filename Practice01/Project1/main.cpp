#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Jobs.h"
#include "Utils.h"
#include "Monster.h"
#include "Item.h"
#include "Alchemy.h"

using namespace std;

int main() 
{
    string name;
    const int SIZE = 4;
    int stat[SIZE] = { 0 }; // [0]:HP, [1]:MP, [2]:공격력, [3]:방어력

    cout << "========================================\n";
    cout << "   [ 던전 탈출 텍스트 RPG ]\n";
    cout << "========================================\n";

    cout << "용사의 이름을 입력해주세요: ";
    cin >> name;
    cout << "\n";

    // [STEP 2] HP/MP 및 공격력/방어력 입력 검사 루프
    while (true) 
    {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> stat[0] >> stat[1];
        if (stat[0] > 50 && stat[1] > 50) break;
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n\n";
    }

    while (true) 
    {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> stat[2] >> stat[3];
        if (stat[2] > 50 && stat[3] > 50) break;
        cout << "공격력이나 방어력이 너무 작습니다. 다시 입력해주세요.\n\n";
    }

    cout << "\n";
    printStatus(name, stat);

    // [STEP 3] 캐릭터 강화 메뉴 루프
    int hpPotion = 5, mpPotion = 5;
    bool isGameStart = false;
    int choice;

    cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다.\n";

    while (!isGameStart) 
    {
        cout << "========================================\n";
        cout << "< 캐릭터 강화 >\n";
        cout << "1. HP UP    2. MP UP    3. 공격력 2배\n";
        cout << "4. 방어력 2배    5. 현재 능력치    0. 게임 시작\n";
        cout << "========================================\n";
        cout << "번호를 선택해주세요: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            if (hpPotion > 0) 
            {
                stat[0] += 20; hpPotion--;
                cout << "* HP가 20 증가했습니다. (HP 포션 차감: 남은 포션 " << hpPotion << "개)\n";
            }
            else cout << "* HP 포션 부족!\n";
            break;
        case 2:
            if (mpPotion > 0) 
            {
                stat[1] += 20; mpPotion--;
                cout << "* MP가 20 증가했습니다. (MP 포션 차감: 남은 포션 " << mpPotion << "개)\n";
            }
            else cout << "* MP 포션 부족!\n";
            break;
        case 3:
            stat[2] *= 2;
            cout << "* 공격력이 2배로 증가했습니다. (현재 공격력: " << stat[2] << ")\n";
            break;
        case 4:
            stat[3] *= 2;
            cout << "* 방어력이 2배로 증가했습니다. (현재 방어력: " << stat[3] << ")\n";
            break;
        case 5:
            printStatus(name, stat);
            break;
        case 0:
            cout << "게임을 시작합니다!\n";
            isGameStart = true;
            break;
        default:
            cout << "* 잘못된 번호입니다. 0~5 사이의 숫자를 입력해주세요.\n";
            break;
        }
        cout << "\n";
    }

    // =========================================================================
    // [STEP 4] 전직 시스템 (다형성 및 동적 할당 구현)
    // =========================================================================
    Player* player = nullptr; // 1. Player* player = nullptr 선언
    int jobChoice;

    while (player == nullptr) 
    {
        cout << "< 전직 시스템 >\n";
        cout << name << "님, 직업을 선택해주세요!\n";
        cout << "1. 전사    2. 마법사    3. 도적    4. 궁수\n";
        cout << "선택: ";
        cin >> jobChoice;

        // 2. 이전 STEP의 name, stat[] 값을 생성자로 넘기며 동적 할당
        switch (jobChoice) 
        {
        case 1:
            player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
            break;
        case 2:
            player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
            break;
        case 3:
            player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
            break;
        case 4:
            player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
            break;
        default:
            cout << "* 잘못된 선택입니다. 1~4 사이의 번호를 선택해주세요.\n\n";
            break;
        }
    }

    player->printPlayerStatus();

    // 몬스터 랜덤 생성을 위해 현재 시간을 기준으로 Seed 설정
    srand(static_cast<unsigned int>(time(nullptr)));

    //------------------------------------------------------------------
    // STEP6 : 인벤토리 및 메인 메뉴 시스템. 주의사항 : 메인 루프 바깥에 선언하여 던전 방문 후에도 아이템 데이터가 유지되어야 함. 
    // ------------------------------------------------------------------

    vector<Item> inventory;
    const int MAX_INVENTORY_SIZE = 10;

    // 포션 제작소 객체 생성
    AlchemyWorkshop workshop;

    bool isRunning = true;

    while (isRunning && player->getHp() > 0)
    {
        cout << "=== 메인 메뉴 ===\n";
        cout << "1. 던전 입장\n";
        cout << "2. 인벤토리 확인\n";
        cout << "3. 포션 제작소\n"; // STEP7 메뉴 추가.
        cout << "0. 게임 종료\n\n";
        cout << "선택 : ";

        int menuChoice;
        cin >> menuChoice;

        if (menuChoice == 1)
        {
            string mName, mDrop;
            int mHP, mAtk, mDef, mPrice;

            int randomNum = rand() % 2;

            if (randomNum == 0)
            {
                mName = "슬라임";
                mHP = 30;
                mAtk = 20;
                mDef = 10;
                mDrop = "슬라임의 끈적한 젤리";
                mPrice = 30;
            }
            else
            {
                mName = "고블린";
                mHP = 50;
                mAtk = 35;
                mDef = 15;
                mDrop = "낡은 단검";
                mPrice = 50;
            }
            Monster monster(mName, mHP, mAtk, mDef, mDrop, mPrice);
            
            cout << "\n[ 전투 시작! ] " << player->getName() << "(" << player->getJob() << ") vs " << monster.getName() << "\n\n";

            // 전투 루프
            while (player->getHp() > 0 && monster.getHP() > 0)
            {
                player->attackMonster(&monster);
                if (monster.getHP() <= 0) break;
                monster.attack(player);
            }

            // 전투 승리 시 아이템 드롭 & 인벤토리 push_back.
            if (player->getHp() > 0)
            {
                Item droppedItem = monster.getDropItem();
                inventory.push_back(droppedItem); // vector 에 아이템 저장. 

                cout << " * 전투 승리!\n";
                cout << "    -> " << droppedItem.name << "획득!\n";
                cout << "    -> 인벤토리에 저장되었습니다. \n\n";
            }
            else
            {
                cout << " * 전투 패배... \n\n";
            }
        }
        // 인벤토리 확인 메뉴
        else if (menuChoice == 2)
        {
            cout << "\n[ 인벤토리(" << inventory.size() << "/" << MAX_INVENTORY_SIZE << ") ]\n";

            if (inventory.empty())
            {
                cout << "인벤토리가 비어있습니다.\n";
            }
            else
            {
                int index = 1;
                // STEP6 : range-basef for 문으로 전체 아이템 출력 
                for (const auto& item : inventory)
                {
                    cout << index++ << ". ";
                    item.PrintInfo(); // Item 구조체의 PrintInfo 호출
                    cout << "\n";
                }
            }
            cout << "\n";
        }
        else if (menuChoice == 3)
        {
            workshop.run();
        }
        else if (menuChoice == 0)
        {
            cout << "게임을 종료합니다. \n";
            isRunning = false;
        }
        else
        {
            cout << "* 잘못된 번호입니다. 다시 선택해주세요. \n\n";
        }
    }
    // STEP4. 프로그램 종료 전 delete player 호출 (메모리 누수 방지)
    delete player;
    player = nullptr;

    return 0;
}