#pragma once

#include "PotionRecipe.h"

// 포션 레시피 추가 및 검색 용 클래스
class PotionDictionary
{
public:
    PotionDictionary();
    virtual ~PotionDictionary();

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void AddRecipe(const string& name, const vector<string>& ingredients);

    // 모든 레시피 출력 메서드
    void DisplayAllRecipes() const;

    PotionRecipe SearchRecipeByName(const string& name) const;
    vector< PotionRecipe> SearchRecipeByIngredient(const string& ingredient) const;

protected:
	vector<PotionRecipe> recipes;
};
