#include "Alchemy.h"

// 생성자: 기본 레시피 세팅
AlchemyWorkshop::AlchemyWorkshop() 
{
    recipes.push_back({ "HP포션", "허브", "맑은물" });
    recipes.push_back({ "MP포션", "마나잎", "맑은물" });
    recipes.push_back({ "스태미나포션", "허브", "베리" });
    recipes.push_back({ "해독제", "독버섯", "맑은물" });
}

// 1. 전체 레시피 출력하기
void AlchemyWorkshop::ShowAllRecipes() const 
{
    cout << "\n[ 전체 레시피 목록 ]\n";
    for (const auto& recipe : recipes) {
        cout << "- " << recipe.name << ": " << recipe.ingredient1 << " x1, " << recipe.ingredient2 << " x1\n";
    }
}

// 2. 포션 이름으로 검색하기
void AlchemyWorkshop::SearchByName(string name) const 
{
    bool found = false;

    // std::string::find를 사용하여 부분 일치 검색 지원 ("HP"만 쳐도 "HP포션" 검색됨)
    for (const auto& recipe : recipes) 
    {
        if (recipe.name.find(name) != string::npos) 
        {
            cout << "-> " << recipe.name << ": " << recipe.ingredient1 << " x1, " << recipe.ingredient2 << " x1\n";
            found = true;
        }
    }

    // 검색 결과가 없을 경우
    if (!found) {
        cout << "찾을 수 없습니다.\n";
    }
}

// 3. 재료로 검색하기
void AlchemyWorkshop::SearchByIngredient(string ingredient) const 
{
    int count = 0;

    for (const auto& recipe : recipes) 
    {
        // 재료1 또는 재료2에 검색어가 포함되어 있는지 확인
        if (recipe.ingredient1.find(ingredient) != string::npos ||
            recipe.ingredient2.find(ingredient) != string::npos) {
            cout << "-> " << recipe.name << " (" << recipe.ingredient1 << " x1, " << recipe.ingredient2 << " x1)\n";
            count++;
        }
    }
    cout << "총 " << count << "개의 레시피를 찾았습니다.\n";
}

// 메뉴 루프 실행
void AlchemyWorkshop::run() 
{
    while (true) {
        cout << "\n=== 포션 제작소 ===\n";
        cout << "1. 전체 레시피 보기\n";
        cout << "2. 포션 이름으로 검색\n";
        cout << "3. 재료로 검색\n";
        cout << "0. 돌아가기\n\n";
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            ShowAllRecipes();
        }
        else if (choice == 2) {
            cout << "검색할 포션 이름: ";
            string name;
            cin >> name;
            SearchByName(name);
        }
        else if (choice == 3) {
            cout << "검색할 재료: ";
            string ingredient;
            cin >> ingredient;
            SearchByIngredient(ingredient);
        }
        else if (choice == 0) {
            break; // 루프 탈출 후 메인 메뉴로 복귀
        }
        else {
            cout << "* 잘못된 입력입니다.\n";
        }
    }
}