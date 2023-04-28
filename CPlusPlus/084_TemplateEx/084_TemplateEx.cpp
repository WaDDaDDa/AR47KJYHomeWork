
// template된 함수나 class등 은 cpp에 구현할수없다.

#include <iostream>
#include "Temp.h"

int main()
{
    Temp<int> NewTemp;

    NewTemp.Function(10);

    TestFunction<int>(2000);

    std::cout << "Hello World!\n";
}
