#pragma once

#include <set>
#include <vector>
#include <string>

using namespace std;

// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
class PotionRecipe
{
public:
	PotionRecipe();
	// 생성자: 재료 목록을 받아 초기화하도록 수정
	PotionRecipe(const string& name, const vector<string>& ingredients);
	PotionRecipe(const PotionRecipe& other);

	virtual ~PotionRecipe();

public:
	void DisplayRecipe() const;

	const string& GetPotionName() const { return potionName; }
	const set<string>& GetIngredients() const { return ingredients; }

	bool IsIngredients(const string& ingredient) const;

protected:
	string potionName;
	set<string> ingredients; // 단일 재료에서 재료 '목록'으로 변경
};