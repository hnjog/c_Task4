#include"PotionStack.h"
#include<iostream>

using namespace std;

PotionStack::PotionStack()
	:remainCount(MAX_STOCK),
	emptyCount(0)
{
}

PotionStack::PotionStack(int remainCount, int emptyCount)
	:remainCount(remainCount),
	emptyCount(emptyCount)
{
}

bool PotionStack::ReturnEmpty()
{
	if (CanReturnEmpty() == false)
		return false;

	emptyCount++;
	return true;
}

bool PotionStack::Dispense()
{
	if (CanDispense() == false)
		return false;

	remainCount++;
	emptyCount--;

	return true;
}

bool PotionStack::Provide()
{
	if (CanProvide() == false)
		return false;

	remainCount--;

	return true;
}

void PotionStack::DisplayStock() const
{
	cout << "-- 재고 : " << remainCount << '\n';
	cout << "--- 회수된 빈병 : " << emptyCount << '\n';
}
