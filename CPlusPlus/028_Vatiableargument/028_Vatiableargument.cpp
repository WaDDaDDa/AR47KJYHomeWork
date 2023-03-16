#include <iostream>


void VarFunction(...)
{

}

void TestFunction(int _1, int _2, int _3)
{

}


// 맨 첫번째 인자만 안다면 다른 인자의 주소도 알수있다.
// 함수의 인자의 주소값은 8바이트 단위로 붙어있다.
// 인자의 크기는 8바이트이다.
//                100     108     116
void TestFunction3(int _1, int _2, int _3)
{
    int* ValuePtr0 = &_1;
    // int* ValuePtr1 = &_2;
    // int* ValuePtr2 = &_3;

    int Value1 = ValuePtr0[0]; // 첫번째 인자의 주소값.
    int Value2 = ValuePtr0[2]; // 두번째 인자의 주소값. 
    int Value3 = ValuePtr0[4]; // 인자는 8바이트 단위로 붙어있는데 int자료형이 4바이트 이기에
                               // 다음인자에 접근하려면 int x 2 만큼 접근해야  다음인자가 나온다.

    // 100 + sizeof(int) * 2

    // __int64 Address0 = 0;
    // __int64 Address1 = 0;
    // __int64 Address2 = 0;

    // Address0 = (__int64)ValuePtr0;
    // Address1 = (__int64)ValuePtr1;
    // Address2 = (__int64)ValuePtr2;

}

void TestFunction2(int _1, ...)
{
    int* ptr = &_1;
    
    int Value0 = ptr[0];  // == 5
    int Value2 = ptr[2];  // == 1
    int Value4 = ptr[4];  // == 2
    int Value6 = ptr[6];  // == 3
    int Value8 = ptr[8];  // == 4
    int Value10 = ptr[10]; // == 5
    int Value12 = ptr[12]; // == ? 쓰레기 값
}

int main()
{
    TestFunction2(5, 1, 2, 3, 4, 5);
}



int main()
{
    // 인자에 제한이 없는 가변인자.

    VarFunction(23, 5, 65, 6, 76, 3, 3); // 인자 갯수를 내 마음대로 넣을 수 있게됨.


    VarFunction("2", "34", "55", 6, 76, 3,"우히히"); // 인자의 자료형도 상관이 없음.

    // 인자의 1가지 특성을 이용한것. = 인자는 8바이트 크기로 배열처럼 위치한다.

    TestFunction(10, 20, 303);

    TestFunction2(5, 1, 2, 3, 4, 5);  //뒤에있는 1,2,3,4,5를 내부에서 찾아낼수 있나. tset해보아라.
    // 인자에 문자와 숫자가 섞여있을때 찾는방법.


    int a = 0;

}
