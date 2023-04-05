
#include <iostream>
#include "GameEngineArray.h"

int main()
{
    // 외우셔야 합니다.
    // 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시. 
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        // 컴파일러에서 지원하는 Arr형에는
        // operator = 함수를 구현하지 않았다.
        int Arr0[10] = { 0, 1, 2, 3 ,4, 5,6 };
        int Arr1[10];
        // Arr1 = Arr0;
    }

    {
        //               600번지
        // int* ArrPtr = new int[20]
        GameEngineArray Array0(10);   // 내가만든 arr로 10개 배열 만듦


        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;                  // 그안에 0부터 1까지 넣음.
        }

        //          700번지
        // ArrPtr = new int[10]
        // 숙제 1 기존의 데이터를 보존하는것을 말하는것이고
        //  [10] 이던게 [5] 로 줄어도 안에있던 데이터가 동일하게 있어야한다.
        // 숙제 2 줄어들든 커지든 데이터는 보존되어야 한다.

        Array0.ReSize(5);     // [10]으로 된거[5]로 재정의

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            printf_s("%d\n", Array0[i]);
        }

        Array0.ReSize(15);   // [5]로 된거 [15]로 재정의

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            printf_s("%d\n", Array0[i]);
        }
    }

    {
        GameEngineArray Array0(10); // heap에 배열 10개를 만든다.
        GameEngineArray Array1(5);  // heap에 배열 5개를 만든다.

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;                  // 그안에 0부터 1까지 넣음.
            int Value = Array0[i];
            int a = 0;
        }

        // 숙제3 왜 터지는지 이해하고 고쳐라.
        Array1 = Array0;    // 여기서 Array1이 가리키고 있는 곳이 Array0이 가리키는 곳과 동일해짐.
        // Array0이 가리키는 곳과 동일한곳을 Array0이 보는만큼 가지게 된다.
     
        // 같은 곳을 가리키는 Array1 과 Array0이 있는것.

        for (size_t i = 0; i < Array1.Count(); i++)
        {
            printf_s("%d\n", Array1[i]);
        }
        int a = 0;
    }
    // 여기서 소멸자가 호출되는데 Array0이랑 Array1은 같은곳을 가리키고 있는데
    // Array0을 먼저 소멸시키고 Array0 을 nullptr로 만든것이라서
    // Array1소멸자가 이미 delete된 영역을 한번더 delete하게 되면서 
    // 메모리 크러시가 발생한다.

    // 막으려면?
    // 1. 같은곳을 가르키는게 아니라 서로 다른곳을 가르키고 거기에 같은값들을 넣어주는것.


    {
        GameEngineArray Array0(10);
        GameEngineArray Array1(5);

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;
        }

        // 숙제4 완전히 동일한 배열이 되게 만들어주세요.
        // Array1 10개 짜리 배열이 되고 0 1 2 3 4 5 6 7 8 9
        Array1 = Array0;

        for (size_t i = 0; i < Array1.Count(); i++)
        {
            printf_s("%d\n", Array1[i]);
        }

    }

}
