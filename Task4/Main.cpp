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
        cout << "환영합니다! 모험가님!" << '\n';
        cout << "⚗️ 연금술 공방 관리 시스템" << '\n';
        cout << "1. 레시피 추가" << '\n';
        cout << "2. 모든 레시피 출력" << '\n';
        cout << "3. 물약 재고 현황 출력" << '\n';
        cout << "4. 물약 제공받기" << '\n';
        cout << "5. 물약 생산하기" << '\n';
        cout << "6. 물약의 빈병 반환하기" << '\n';
        cout << "7. 종료" << '\n';
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

        // 여기서 그냥 choice를 AlchemyWorkshop 에 건내주거나
        // 각각의 역할에 맞는 함수를 호출하는게 더 좋아보인다
        if (choice == 1) 
        {
            string name;
            cout << "물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            if (name.size() == 0)
            {
                cout << ">> 물약 이름을 입력하지 않았습니다!" << '\n';
                continue;
            }

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
                myWorkshop.DevelopPotionReceipe(name, ingredients_input);
            }
            else
            {
                cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << '\n';
            }
        }
        else if (choice == 2) 
        {
            myWorkshop.ShowAllPotionReceipe();
        }
        else if (choice == 3)
        {
            myWorkshop.ShowAllPotionStock();
        }
        else if (choice == 4)
        {
            string name;
            cout << "물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            if (name.size() == 0)
            {
                cout << ">> 물약 이름을 입력하지 않았습니다!" << '\n';
                continue;
            }

            myWorkshop.ProvidePotion(name);
        }
        else if (choice == 5)
        {
            string name;
            cout << "물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            if (name.size() == 0)
            {
                cout << ">> 물약 이름을 입력하지 않았습니다!" << '\n';
                continue;
            }

            myWorkshop.ProducePotion(name);
        }
        else if (choice == 7) 
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