#include "PotionRepository.h"
#include "PotionDictionary.h"
#include<iostream>

PotionRepository::PotionRepository()
{
}

PotionRepository::~PotionRepository()
{
}

void PotionRepository::DisplayAllStocks() const
{
	if (potionStockMap.empty())
	{
		cout << "아직 개발된 포션이 없습니다." << '\n';
		return;
	}

	cout << "\n--- [ 전체 재고 목록 ] ---" << '\n';
	for (const auto& potionStockPair : potionStockMap)
	{
		cout << "- 물약 이름: " << potionStockPair.first << '\n';
		potionStockPair.second.DisplayStock();
		cout << "---------------------------\n";
	}
	cout << "----------------------------------\n";
}

void PotionRepository::ProvidePotion(const string& potionName)
{
	if (PotionNameCheck(potionName) == false)
		return;

	if (potionStockMap[potionName].Provide())
	{
		cout << "포션 제공 완료!" << '\n';
		cout << potionName << "의 남은 재고 수 : " << potionStockMap[potionName].GetRemain() << '\n';
	}
	else
	{
		cout << "해당 포션이 재고가 없는데요...?" << '\n';
	}
}

void PotionRepository::InitializeStock(const string& potionName)
{
	if (potionStockMap.find(potionName) != potionStockMap.end())
	{
		cout << "이미 초기화된 포션입니다!" << '\n';
		return;
	}

	potionStockMap[potionName] = PotionStack();
	cout << "포션 개발 완료!" << '\n';
	cout << potionName << "을 " << MAX_STOCK << "개 생성하였습니다!" << '\n';
}

bool PotionRepository::DispensePotion(const string& potionName)
{
	if (PotionNameCheck(potionName) == false)
		return false;

	// 생성 시도
	if (potionStockMap[potionName].Dispense())
	{
		// 생성 성공
		cout << "포션 생성 완료!" << '\n';
		cout << potionName << "의 재고 개수 : " << potionStockMap[potionName].GetRemain() << '\n';
		return true;
	}
	else 
	{
		// 생성 실패
		// enum 등으로 실패 타입 반환도 가능하다
		if (potionStockMap[potionName].IsEmptyZero())
		{
			cout << "포션 저장소에 해당 포션의 빈 병이 없습니다!" << '\n';
			cout << "먼저 저장소에 해당 포션의 빈 병을 반환해주세요!" << '\n';
		}
		if (potionStockMap[potionName].IsFull())
		{
			cout << "포션 저장소에 이미 최대치인 " << MAX_STOCK << "만큼 존재합니다!" << '\n';
		}
	}
	
	return false;
}

void PotionRepository::ReturnPotion(const string& potionName)
{
	if (PotionNameCheck(potionName) == false)
		return;

	if (potionStockMap[potionName].ReturnEmpty())
	{
		cout << "빈병 수거 완료!" << '\n';
		cout << potionName << "의 빈병 개수 : " << potionStockMap[potionName].GetEmpty() << '\n';
	}
	else
	{
		cout << "빈 병이 이미 넘칩니다!" << '\n';
		cout << "새로운 포션을 생성해주세요!" << '\n';
	}
}

int PotionRepository::GetPotionStack(const string& potionName)
{
	if (PotionNameCheck(potionName) == false)
		return 0;

	return potionStockMap[potionName].GetRemain();
}

bool PotionRepository::PotionNameCheck(const string& potionName) const
{
	if (potionStockMap.find(potionName) == potionStockMap.end())
	{
		cout << "저장소에 이런 포션은 없습니다!" << '\n';
		return false;
	}

	return true;
}
