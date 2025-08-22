#include <iostream>
#include <vector>
#include <string>
#include "PotionRecipe.h"
#include "AlchemyWorkshop.h"

int main() 
{
    AlchemyWorkshop myWorkshop;

    while (true) 
    {
        cout << "⚗️ 연금술 공방 관리 시스템" << '\n';
        cout << "1. 레시피 추가" << '\n';
        cout << "2. 모든 레시피 출력" << '\n';
        cout << "3. 종료" << '\n';
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (cin.fail()) 
        {
            cout << "잘못된 입력입니다. 숫자를 입력해주세요." << '\n';
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) 
        {
            string name;
            cout << "물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            // 여러 재료를 입력받기 위한 로직
            vector<string> ingredients_input;
            string ingredient;
            cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << '\n';

            while (true) 
            {
                cout << "재료 입력: ";
                getline(cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") 
                {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) 
            {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else 
            {
                cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << '\n';
            }

        }
        else if (choice == 2) 
        {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3) 
        {
            cout << "공방 문을 닫습니다..." << '\n';
            break;

        }
        else 
        {
            cout << "잘못된 선택입니다. 다시 시도하세요." << '\n';
        }
    }

    return 0;
}