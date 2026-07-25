#pragma once
#ifndef ALCHEMY_H
#define ALCHEMY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [STEP 7] 포션 레시피 구조체 정의
struct PotionRecipe 
{
    string name;
    string ingredient1;
    string ingredient2;
};

// [STEP 7] 포션 제작소(연금술 공방) 클래스 설계
class AlchemyWorkshop 
{
private:
    // 레시피를 저장할 vector
    vector<PotionRecipe> recipes;

public:
    AlchemyWorkshop(); // 생성자

    // 기능 메서드들
    void ShowAllRecipes() const;
    void SearchByName(string name) const;
    void SearchByIngredient(string ingredient) const;

    // 제작소 메뉴 루프 실행 함수
    void run();
};

#endif