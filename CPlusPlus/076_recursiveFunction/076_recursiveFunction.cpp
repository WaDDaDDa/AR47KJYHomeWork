

#include <iostream>

// 재귀 함수.

// 재귀함수는 스택메모리를 쓰는것이기 때문에
// 무한으로 재귀가 돌게되면 스택메모리가 넘쳐흘러버리는
// 스택오버플로우 오류가 생길수있으므로 주의.


int Count = 0;

void Test()
{
    int ArrValue[100] = { Count };

    printf_s("%d %d\n", Count, ArrValue[0]);
    ++Count;


    // 스택오버플로우를 주의해야 한다.
    if (10000000 <= Count)
    {
        return;
    }

    return Test();
}

int Test2()  
{
    // 리턴에다가 재귀를 거는 경우에는
    // 꼬리재귀라는 것이 될 가능성이 생기고
    // 꼬리재귀를 할줄안다 모른다는 별로 중요한 내용은 아니야.
    // 그냥 던지는거지 
    if (true)
    {
        return 20;
    }


    // 리턴과 동시에 
    return Test2();
}

int main()
{
    // Test();
}
