#pragma once
class Teste
{
public:
    Teste(int Value) {} // 디폴트 생성자.
    ~Teste() {} // 디폴트 소멸자

    Teste& operator=(const Teste& _Other) = delete; // 디폴트 대입 연산자
    Teste& operator=(const Teste&& _Other) = delete; // 디폴트 대입 연산자
    Teste(const Teste& _Other) = delete; // 디폴트 복사 생성자
    Teste(const Teste&& _Other) = delete; // RValue 복사 생성자
    //  delete를 통해 자동으로 만들어진기능들을 사용하지 않겠다고 할수있다.

    //  현 수업에 있어서 class 디폴트를 해당 처럼 할 것이며.
    //  class를 활용함에 있어 필요해진다면 필요할때 직접 만들어서 사용하는것으로 모두와 합의.
protected:

private:

    // public:
    // A& operator=(const A& _Other) {}
    // 디폴트 대입연산자가 존재합니다.
    // A& operator=(const A&& _Other) {} // RValue 대입연산자가 존재합니다.

    // public:
    // A() {} // 디폴트 생성자.
    // A(const A& _Other) {} // 디폴트 복사 생성자
    // A(const A&& _Other) {} // RValue 복사 생성자
    // ~A() {} // 디폴트 소멸자
};

