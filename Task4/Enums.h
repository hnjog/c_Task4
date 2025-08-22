#pragma once

enum class PotionDictWork
{
	PDW_ADD_RECIPE = 0,
	PDW_DIS_ALL,
	PDW_SRC_NAME,
	PDW_SRC_INGRE,
	PDW_COUNT,
};

enum class PotionRepWork
{
	PRW_INIT= 0,
	PRW_DISPENSE,
	PRW_RET_EMPTY,
	PRW_GET_COUNT_NAME,
	PRW_COUNT,
};