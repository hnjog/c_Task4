#include"PotionRecipe.h"

PotionRecipe::PotionRecipe(const std::string& name, const vector<string>& ingredients)
	: potionName(name),
	ingredients(ingredients)
{
}

PotionRecipe::PotionRecipe(const PotionRecipe& other)
	:potionName(other.potionName), // string의 복사 생성자
	ingredients(other.ingredients) // vector의 복사 생성자
{
}
