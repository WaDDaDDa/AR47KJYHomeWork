
#include <iostream>

// char* ArrChar을 가지는 Test클래스를 만든다.
// 이 의미는 char의 주소값을 가지는 Test클래스를 만들게 된다는 것이고.
// 주소값을 가진다는 것은 char을 여러개 가지는 배열을 받을수있다는것과 같다.
class Test
{
    char* ArrChar;

public:
    void Resize(size_t Size)
    {
        ArrChar = new char[Size];
    }
};

int main()
{
    char* Arrint = new char();

    delete Arrint;

    // 이녀석을 만든다는것 자체가 
    // char의 배열을 만든것과 같다는것.
    Test* ArrTest = new Test[10];

    delete[] ArrTest;

    // Test ArrTest = Test();

}
