#pragma once

#include <vector>
#include <string>
#include <memory>

class PotionDictionary;
class PotionRecipe;

using namespace std;

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop 
{
public:
    AlchemyWorkshop();
    virtual ~AlchemyWorkshop();

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const string& name, const vector<string>& ingredients);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    PotionRecipe SearchRecipeByName(const string& name) const;
    vector<PotionRecipe> SearchRecipeByIngredient(const string& ingredient) const;

protected:
    unique_ptr<PotionDictionary> MyPoctionDictonary;
};