#pragma once
class AClassDefault
{
public:
    AClassDefault(int Value) {} // ����Ʈ ������.
    ~AClassDefault() {} // ����Ʈ �Ҹ���

    AClassDefault& operator=(const AClassDefault& _Other) = delete; // ����Ʈ ���� ������
    AClassDefault& operator=(const AClassDefault&& _Other) = delete; // ����Ʈ ���� ������
    AClassDefault(const AClassDefault& _Other) = delete; // ����Ʈ ���� ������
    AClassDefault(const AClassDefault&& _Other) = delete; // RValue ���� ������
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

