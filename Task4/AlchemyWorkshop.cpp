#include "AlchemyWorkshop.h"
#include<iostream>

void AlchemyWorkshop::addRecipe(const string& name, const vector<string>& ingredients)
{
	recipes.push_back(PotionRecipe(name, ingredients));
	cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << '\n';
}

void AlchemyWorkshop::displayAllRecipes() const
{
	if (recipes.empty())
	{
		cout << "아직 등록된 레시피가 없습니다." << '\n';
		return;
	}

	cout << "\n--- [ 전체 레시피 목록 ] ---" << '\n';
	for (size_t i = 0; i < recipes.size(); ++i)
	{
		cout << "- 물약 이름: " << recipes[i].potionName << '\n';
		cout << "  > 필요 재료: ";

		// 재료 목록을 순회하며 출력
		for (size_t j = 0; j < recipes[i].ingredients.size(); ++j)
		{
			cout << recipes[i].ingredients[j];
			// 마지막 재료가 아니면 쉼표로 구분
			if (j < recipes[i].ingredients.size() - 1)
			{
				cout << ", ";
			}
		}
		cout << '\n';
	}
	cout << "---------------------------\n";
}
