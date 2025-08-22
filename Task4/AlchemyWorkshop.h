#pragma once

#include <vector>
#include <string>
#include <memory>

class PotionDictionary;
class PotionRepository;
class PotionRecipe;

using namespace std;

// AlchemyWorkshop 클래스: 포션 레시피 및 포션 기능 전반 담당 클래스
class AlchemyWorkshop 
{
public:
    AlchemyWorkshop();
    virtual ~AlchemyWorkshop();

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void AddRecipe(const string& name, const vector<string>& ingredients);

    // 모든 레시피 출력 메서드
    void DisplayAllRecipes() const;

    PotionRecipe SearchRecipeByName(const string& name) const;
    vector<PotionRecipe> SearchRecipeByIngredient(const string& ingredient) const;

protected:
    shared_ptr<PotionDictionary> MyPoctionDictonary;
    unique_ptr<PotionRepository> MyPotionRepository;
};