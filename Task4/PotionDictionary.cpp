#include"PotionDictionary.h"
#include<iostream>

PotionDictionary::PotionDictionary()
{
}

PotionDictionary::~PotionDictionary()
{
}

void PotionDictionary::addRecipe(const string& name, const vector<string>& ingredients)
{
	recipes.push_back(PotionRecipe(name, ingredients));
	cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << '\n';
}

void PotionDictionary::displayAllRecipes() const
{
	if (recipes.empty())
	{
		cout << "아직 등록된 레시피가 없습니다." << '\n';
		return;
	}

	cout << "\n--- [ 전체 레시피 목록 ] ---" << '\n';
	for (const PotionRecipe& recipe : recipes)
	{
		cout << "- 물약 이름: " << recipe.GetPotionName() << '\n';
		cout << "  > 필요 재료: ";

		// 재료 목록을 순회하며 출력
		const vector<string>& ingredients = recipe.GetIngredients();
		for (size_t j = 0; j < ingredients.size(); ++j)
		{
			cout << ingredients[j];
			// 마지막 재료가 아니면 쉼표로 구분
			if (j < ingredients.size() - 1)
			{
				cout << ", ";
			}
		}
		cout << '\n';
	}
	cout << "---------------------------\n";
}