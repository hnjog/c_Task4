#pragma once

#include <vector>
#include <string>
#include <memory>

#include "Enums.h"

class PotionDictionary;
class PotionRepository;
class PotionRecipe;

using namespace std;

// AlchemyWorkshop 클래스
// 사용자에게 포션 관련 작업을 요구 받고
// 내부 기능들을 이용하여 
class AlchemyWorkshop
{
public:
	AlchemyWorkshop();
	virtual ~AlchemyWorkshop();

public:
	void WorkByRecipe(PotionDictWork recipeWork); // 사전이 할 일
	void WorkByStocks(PotionRepWork stockWork);   // 저장소가 할 일

protected:
	unique_ptr<PotionDictionary> MyPoctionDictonary;
	unique_ptr<PotionRepository> MyPotionRepository;
};