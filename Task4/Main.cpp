#include <iostream>
#include <vector>
#include <string>
#include "PotionRecipe.h"
#include "AlchemyWorkshop.h"
#include "Enums.h"

int main() 
{
    AlchemyWorkshop myWorkshop;

    while (true) 
    {
        cout << "⚗️ 연금술 공방 관리 시스템" << '\n';
        cout << "1. 레시피 추가" << '\n';
        cout << "2. 모든 레시피 출력" << '\n';
        cout << "3. 레시피 검색(이름)" << '\n';
        cout << "4. 레시피 검색(재료)" << '\n';
        cout << "5. 물약 재고 현황 출력" << '\n';
        cout << "6. 레시피로 물약 등록하기" << '\n';
        cout << "7. 물약 생산하기" << '\n';
        cout << "8. 물약의 빈병 반환하기" << '\n';
        cout << "9. 물약 사용하기" << '\n';
        cout << "10. 종료" << '\n';
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
            myWorkshop.WorkByRecipe(PotionDictWork::PDW_ADD_RECIPE);
        }
        else if (choice == 2) 
        {
            myWorkshop.WorkByRecipe(PotionDictWork::PDW_DIS_ALL);
        }
        else if (choice == 3)
        {
            myWorkshop.WorkByRecipe(PotionDictWork::PDW_SRC_NAME);
        }
        else if (choice == 4)
        {
            myWorkshop.WorkByRecipe(PotionDictWork::PDW_SRC_INGRE);
        }
        else if (choice == 10) 
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