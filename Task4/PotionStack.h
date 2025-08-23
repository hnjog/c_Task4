#pragma once

const int MAX_STOCK = 3;

class PotionStack
{
public:
	PotionStack();
	PotionStack(int remainCount, int emptyCount);

public:
	inline int GetRemain() const { return remainCount; }
	inline int GetEmpty() const { return emptyCount; }

	inline bool IsFull() const { return remainCount == MAX_STOCK; }
	inline bool IsEmptyZero() const { return emptyCount == 0; }

	inline bool CanProvide() const { return remainCount > 0; }
	inline bool CanDispense() const { return emptyCount > 0 && remainCount < MAX_STOCK; }
	inline bool CanReturnEmpty() const { return emptyCount < MAX_STOCK; }

public:
	bool ReturnEmpty();

	bool Dispense();
	bool Provide();

	void DisplayStock() const;

protected:
	int remainCount;
	int emptyCount;
};
