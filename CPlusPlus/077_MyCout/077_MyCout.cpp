

#include <iostream>

class MyEndl
{
};

// 그냥 이런식으로 printf를 사용할수있게 해주는 것.
class MyCout
{
public:
    void operator<<(const MyEndl& _Value)
    {
        printf_s("\n");
    }

    MyCout& operator<<(const char* _Text)
    {
        printf_s(_Text);

        return *this;
    }
};

namespace std
{
    MyEndl MEndl;
    MyCout MCout;
}


int main()
{
    //std::MCout.operator<<("Hello World!").operator<<(std::MEndl);

    std::cout.operator<<("Hello World!").operator<<(std::endl); // endl == 엔터

    // std::cout << "Hello World!\n";
}
