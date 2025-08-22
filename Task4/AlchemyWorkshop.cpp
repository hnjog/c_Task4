#include "AlchemyWorkshop.h"
#include"PotionDictionary.h"
#include"PotionRecipe.h"

AlchemyWorkshop::AlchemyWorkshop()
{
	MyPoctionDictonary = make_unique<PotionDictionary>();
}

AlchemyWorkshop::~AlchemyWorkshop()
{
}

void AlchemyWorkshop::AddRecipe(const string& name, const vector<string>& ingredients)
{
	MyPoctionDictonary->AddRecipe(name, ingredients);
}

void AlchemyWorkshop::DisplayAllRecipes() const
{
	MyPoctionDictonary->DisplayAllRecipes();
}

PotionRecipe AlchemyWorkshop::SearchRecipeByName(const string& name) const
{
	return MyPoctionDictonary->SearchRecipeByName(name);
}

vector<PotionRecipe> AlchemyWorkshop::SearchRecipeByIngredient(const string& ingredient) const
{
	return MyPoctionDictonary->SearchRecipeByIngredient(ingredient);
}