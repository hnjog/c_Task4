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

void AlchemyWorkshop::WorkByRecipe(PotionDictWork recipeWork)
{
	switch (recipeWork)
	{
	case PotionDictWork::PDW_ADD_RECIPE:
	{
		string name;
		cout << "물약 이름: ";
		cin.ignore(10000, '\n');
		getline(cin, name);

		// 여러 재료를 입력받기 위한 로직
		vector<string> ingredients_input;
		string ingredient;
		cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << '\n';

		while (true)
		{
			cout << "재료 입력: ";
			getline(cin, ingredient);

			// 사용자가 '끝'을 입력하면 재료 입력 종료
			if (ingredient == "끝")
			{
				break;
			}
			ingredients_input.push_back(ingredient);
		}

		// 입력받은 재료가 하나 이상 있을 때만 레시피 추가
		if (!ingredients_input.empty())
		{
			MyPoctionDictonary->AddRecipe(name, ingredients_input);
		}
		else
		{
			cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << '\n';
		}
	}
	break;
	case PotionDictWork::PDW_DIS_ALL:
	{
		MyPoctionDictonary->DisplayAllRecipes();
	}
		break;
	case PotionDictWork::PDW_SRC_NAME:
	{
		string name;
		cout << "물약 이름: ";
		cin.ignore(10000, '\n');
		getline(cin, name);

		PotionRecipe recipe = MyPoctionDictonary->SearchRecipeByName(name);
		if (recipe.GetPotionName() != "")
		{
			cout << "해당 물약 레시피가 있습니다!" << '\n';
		}
		else
		{
			cout << "해당 물약 레시피는 없습니다!" << '\n';
		}
	}
		break;
	case PotionDictWork::PDW_SRC_INGRE:
	{
		string ingredient;
		cout << "재료 이름: ";
		cin.ignore(10000, '\n');
		getline(cin, ingredient);

		vector<PotionRecipe> ingredients_input = MyPoctionDictonary->SearchRecipeByIngredient(ingredient);

		cout << "\n--- [ 해당 재료가 들어가는 레시피 목록 ] ---" << '\n';
		for (const PotionRecipe& recipe : ingredients_input)
		{
			recipe.DisplayRecipe();
		}
		cout << "---------------------------\n";
	}
		break;
	case PotionDictWork::PDW_COUNT:
	default:
		break;
	}
}

void AlchemyWorkshop::WorkByStocks(PotionRepWork stockWork)
{
}
