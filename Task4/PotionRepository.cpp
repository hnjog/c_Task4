#include "PotionRepository.h"
#include "PotionDictionary.h"
#include<iostream>

PotionRepository::PotionRepository()
{
}

PotionRepository::~PotionRepository()
{
}

void PotionRepository::InitializeStock(const string& potionName)
{
	if (potionStackMap.find(potionName) != potionStackMap.end())
	{
		cout << "이미 초기화된 포션입니다!" << '\n';
		return;
	}

	potionStackMap[potionName] = PotionStack();
	cout << "포션 생성 완료!" << '\n';
	cout << potionName << "을 " << MAX_STOCK << "개 생성하였습니다!" << '\n';
}

bool PotionRepository::DispensePotion(const string& potionName)
{
	if (PotionNameCheck(potionName) == false)
		return false;

	if (potionStackMap[potionName].remainCount >= MAX_STOCK)
	{
		cout << "포션 저장소에 이미 최대치인 "<< MAX_STOCK <<"만큼 존재합니다!" << '\n';
		return false;
	}

	if (potionStackMap[potionName].emptyCount <= 0)
	{
		cout << "포션 저장소에 해당 포션의 빈 병이 없습니다!" << '\n';
		cout << "먼저 저장소에 해당 포션의 빈 병을 반환해주세요!" << '\n';
		return false;
	}

	potionStackMap[potionName].remainCount++;
	potionStackMap[potionName].emptyCount--;
	cout << "포션 생성 완료!" << '\n';
	cout << potionName << "을 " << 1 << "개 만들었어요!" << '\n';
	return true;
}

void PotionRepository::ReturnPotion(const string& potionName)
{
	if (PotionNameCheck(potionName) == false)
		return;

	if (potionStackMap[potionName].emptyCount >= MAX_STOCK)
	{
		cout << "빈 병이 이미 넘칩니다!" << '\n';
		cout << "새로운 포션을 생성해주세요!" << '\n';
		return;
	}

	potionStackMap[potionName].emptyCount++;
	cout << "빈병 수거 완료!" << '\n';
	cout << potionName << "의 빈병 개수 : " << potionStackMap[potionName].emptyCount <<'\n';
}

int PotionRepository::GetPotionStack(const string& potionName)
{
	if (PotionNameCheck(potionName) == false)
		return 0;

	return potionStackMap[potionName].remainCount;
}

bool PotionRepository::PotionNameCheck(const string& potionName) const
{
	if (potionStackMap.find(potionName) == potionStackMap.end())
	{
		cout << "저장소에 이런 포션은 없습니다!" << '\n';
		return false;
	}

	return true;
}
