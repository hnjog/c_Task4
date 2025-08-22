#include<iostream>
#include"PotionRecipe.h"

PotionRecipe::PotionRecipe()
	:potionName("")
{
}

PotionRecipe::PotionRecipe(const std::string& name, const vector<string>& ingredients)
	: potionName(name),
	ingredients(ingredients)
{
}

PotionRecipe::PotionRecipe(const PotionRecipe& other)
	:potionName(other.potionName), // string의 복사 생성자
	ingredients(other.ingredients) // vector의 복사 생성자
{
}

PotionRecipe::~PotionRecipe()
{
}

void PotionRecipe::DisplayRecipe() const
{
	cout << "- 물약 이름: " << potionName << '\n';
	cout << "  > 필요 재료: ";

	// 재료 목록을 순회하며 출력
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

bool PotionRecipe::IsIngredients(const string& ingredient) const
{
	for (const string& ingre : ingredients)
	{
		if (ingre == ingredient)
			return true;
	}

	return false;
}
