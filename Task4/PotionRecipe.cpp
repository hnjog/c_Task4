#include<iostream>
#include"PotionRecipe.h"

PotionRecipe::PotionRecipe()
	:potionName("")
{
}

PotionRecipe::PotionRecipe(const std::string& name, const vector<string>& ingredients)
	: potionName(name),
	ingredients(ingredients.begin(), ingredients.end())
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
	for (auto it = ingredients.begin(); it != ingredients.end(); it++)
	{
		cout << *it;
		if (next(it) != ingredients.end())
		{
			cout << ", ";
		}
	}

	cout << '\n';
}

bool PotionRecipe::IsIngredients(const string& ingredient) const
{
	if (ingredients.find(ingredient) == ingredients.end())
		return false;

	return true;
}
