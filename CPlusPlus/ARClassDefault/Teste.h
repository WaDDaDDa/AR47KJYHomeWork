#pragma once
class Teste
{
public:
    Teste(int Value) {} // ����Ʈ ������.
    ~Teste() {} // ����Ʈ �Ҹ���

    Teste& operator=(const Teste& _Other) = delete; // ����Ʈ ���� ������
    Teste& operator=(const Teste&& _Other) = delete; // ����Ʈ ���� ������
    Teste(const Teste& _Other) = delete; // ����Ʈ ���� ������
    Teste(const Teste&& _Other) = delete; // RValue ���� ������
    //  delete�� ���� �ڵ����� ���������ɵ��� ������� �ʰڴٰ� �Ҽ��ִ�.

    //  �� ������ �־ class ����Ʈ�� �ش� ó�� �� ���̸�.
    //  class�� Ȱ���Կ� �־� �ʿ������ٸ� �ʿ��Ҷ� ���� ���� ����ϴ°����� ��ο� ����.
protected:

private:

    // public:
    // A& operator=(const A& _Other) {}
    // ����Ʈ ���Կ����ڰ� �����մϴ�.
    // A& operator=(const A&& _Other) {} // RValue ���Կ����ڰ� �����մϴ�.

    // public:
    // A() {} // ����Ʈ ������.
    // A(const A& _Other) {} // ����Ʈ ���� ������
    // A(const A&& _Other) {} // RValue ���� ������
    // ~A() {} // ����Ʈ �Ҹ���
};

