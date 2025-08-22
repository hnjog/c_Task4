#include"PotionDictionary.h"
#include<iostream>

PotionDictionary::PotionDictionary()
{
}

PotionDictionary::~PotionDictionary()
{
}

void PotionDictionary::AddRecipe(const string& name, const vector<string>& ingredients)
{
	recipesMap[name] = PotionRecipe(name, ingredients);
	cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << '\n';
}

void PotionDictionary::DisplayAllRecipes() const
{
	if (recipesMap.empty())
	{
		cout << "아직 등록된 레시피가 없습니다." << '\n';
		return;
	}

	cout << "\n--- [ 전체 레시피 목록 ] ---" << '\n';
	for (const auto& recipePair : recipesMap)
	{
		recipePair.second.DisplayRecipe();
	}
	cout << "---------------------------\n";
}

PotionRecipe PotionDictionary::SearchRecipeByName(const string& name) const
{
	auto it = recipesMap.find(name);
	if (it != recipesMap.end())
		return it->second;

	return PotionRecipe();
}

vector<PotionRecipe> PotionDictionary::SearchRecipeByIngredient(const string& ingredient) const
{
	vector<PotionRecipe> FindRecipes;
	for (const auto& recipe : recipesMap)
	{
		if (recipe.second.IsIngredients(ingredient))
		{
			FindRecipes.push_back(recipe.second);
		}
	}

	return FindRecipes;
}
