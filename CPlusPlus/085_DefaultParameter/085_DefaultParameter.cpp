

#include <iostream>


// 함수는 디폴트 파라메터를 가질수있다.
// 해당 처럼 인자내에서 선언을 해준다면.
// 인자를 대입해주지 않아도 해당인자에 해당값이 있는것으로 인식되어 사용된다.
void Function(int _Value = 50)
{
    std::cout << _Value << std::endl;
}

// 단 주의 해야할 점은 오버로딩에 주의하여야 한다.
// 인자가 없어도 인자를 인식하기때문에 오버로딩하여 인자가없는 함수를 만든다던지
// 하는 상황이 펼쳐진다면 어느함수를 호출해야하는지 알수 없기 때문에 이런점은 유의하며 사용 해야함.

void Function(int _Value, int _Test = 50)
{
    std::cout << _Value << std::endl;
}



// 디폴트 인자는 무조건 인자의 가장 오른쪽부터 만들수 있다.
// 디폴트 인자가 필요한 상황인데 한개만 적용 해야할때에는 맨 오른쪽인자부터 디폴트 인자를 사용한다.
//void Function0(int _Value = 50, int _Test)
//{
//    std::cout << _Value << std::endl;
//}
int main()
{
    Function(10, 20);

    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
    // Function(20);

    std::cout << "Hello World!\n";
}