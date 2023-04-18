
#include <iostream>

// friend 란.


class B;
class A;
class A
{
    // 특정 클래스에서 자신의 접근제한 지정자를
    // 취소시키는 문법
    // 상속같은 개념이 아니다.

    // A안에 friend B 를 선언하면 
    // B클래스는 A클래스의 Private 값들을 쓸수있게 된다.
    friend B;

public:

private:
    int Value = 0;
};

class B
{
public:
    // 객체지향을 정면에서 깨는 문법이니까.
    // 이런 문법을 사용하면 객체지향을 깨기 때문이다.
    // 애초에 c++ 객체지향 언어가 아니야.
    // 이종격투기 같은 애에요.
    // 발리투도 무기 무기칙 격투기 


    void Function(A& _Other)
    {
        _Other.Value = 20;
        _Other.Value = 2;
    }

private:
    int Test = 3;
};

class C
{

};

int main()
{
    A NewA;
    B NewB;

    NewB.Function(NewA);

    std::cout << "Hello World!\n";
}
