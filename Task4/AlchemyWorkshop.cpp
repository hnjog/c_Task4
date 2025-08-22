#include "AlchemyWorkshop.h"
#include "PotionDictionary.h"
#include "PotionRecipe.h"
#include "PotionRepository.h"

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
	if (name.size() == 0)
		return;

	MyPotionRepository->ProvidePotion(name);
}

void AlchemyWorkshop::ProducePotion(const string& name)
{
	if (name.size() == 0)
		return;

	MyPotionRepository->DispensePotion(name);
}
