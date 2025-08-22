#include "AlchemyWorkshop.h"
#include"PotionDictionary.h"

AlchemyWorkshop::AlchemyWorkshop()
{
	MyPoctionDictonary = make_unique<PotionDictionary>();
}

AlchemyWorkshop::~AlchemyWorkshop()
{
}

void AlchemyWorkshop::addRecipe(const string& name, const vector<string>& ingredients)
{
	MyPoctionDictonary->addRecipe(name, ingredients);
}

void AlchemyWorkshop::displayAllRecipes() const
{
	MyPoctionDictonary->displayAllRecipes();
}
