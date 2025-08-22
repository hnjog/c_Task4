#pragma once

#include <vector>
#include <string>
#include <memory>

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
	void DevelopPotionReceipe(const string& name, const vector<string>& ingredients_input) const;
	void ShowAllPotionReceipe() const;
	void ShowAllPotionStock() const;
	void ProvidePotion(const string& name);
	void ProducePotion(const string& name);

protected:
	unique_ptr<PotionDictionary> MyPoctionDictonary;
	unique_ptr<PotionRepository> MyPotionRepository;
};