#pragma once

#include <map>
#include <string>
#include <memory>

#include "PotionStack.h"

using namespace std;

class PotionDictionary;

// 포션 제작 및 소모 관련 클래스
class PotionRepository
{
public:
	PotionRepository();
	virtual ~PotionRepository();

public:
	// 포션 재고 현황
	void DisplayAllStocks() const;

	void ProvidePotion(const string& potionName);

	// 포션을 MAX_STOCK 까지 초기화
	void InitializeStock(const string& potionName);

	// 포션 제작 시도, 성공 여부 return
	bool DispensePotion(const string& potionName);

	// 해당 이름의 포션 공병이 회수됨
	void ReturnPotion(const string& potionName); 

	// 포션의 remain / empty Count
	int GetPotionStack(const string& potionName);

private:
	bool PotionNameCheck(const string& potionName) const;

protected:
	map<string, PotionStack> potionStackMap; // 현재 가진 포션 (공병 x)
};

// 현재 작업 방향성
// AlchmyWork 등이
//