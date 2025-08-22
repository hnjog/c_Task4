#include "AlchemyWorkshop.h"
#include "PotionDictionary.h"
#include "PotionRecipe.h"
#include "PotionRepository.h"
#include <iostream>

AlchemyWorkshop::AlchemyWorkshop()
{
	MyPoctionDictonary = make_unique<PotionDictionary>();
	MyPotionRepository = make_unique<PotionRepository>();
}

AlchemyWorkshop::~AlchemyWorkshop()
{
}

void AlchemyWorkshop::DevelopPotionReceipe(const string& name, const vector<string>& ingredients_input) const
{
	if (name.size() == 0)
		return;

	if (ingredients_input.size() == 0)
		return;

	MyPoctionDictonary->AddRecipe(name, ingredients_input);
	MyPotionRepository->InitializeStock(name);
}

void AlchemyWorkshop::ShowAllPotionReceipe() const
{
	MyPoctionDictonary->DisplayAllRecipes();
}

void AlchemyWorkshop::ShowAllPotionStock() const
{
	MyPotionRepository->DisplayAllStocks();
}

void AlchemyWorkshop::ProvidePotion(const string& name)
{
	if (IsValidPotionName(name) == false)
		return;

	MyPotionRepository->ProvidePotion(name);
}

void AlchemyWorkshop::ReturnEmptyPotion(const string& name)
{
	if (IsValidPotionName(name) == false)
		return;

	MyPotionRepository->ReturnPotion(name);
	cout << "자동으로 포션 생성을 시도합니다!" << '\n';
	MyPotionRepository->DispensePotion(name);
}

vector<PotionRecipe> AlchemyWorkshop::GetCanMakePotionsByIngre(const string& name)
{
	vector<PotionRecipe> RecipeVector;

	if (name.size() == 0)
		return RecipeVector;

	RecipeVector = MyPoctionDictonary->SearchRecipeByIngredient(name);

	return RecipeVector;
}

bool AlchemyWorkshop::IsValidPotionName(const string& name)
{
	PotionRecipe searchName = MyPoctionDictonary->SearchRecipeByName(name);
	if (searchName.GetPotionName().size() == 0)
		return false;

	return true;
}
