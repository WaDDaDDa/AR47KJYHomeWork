#include "Bomb.h"


Bomb::Bomb()
{
	RenderChar = '@';
}

Bomb::~Bomb()
{

}
 
void Bomb::Update()  // �����Լ� �����ε�
{
	ConsoleGameObject::Update(); // �����ε� �� �Լ��� �⺻������ �θ�Ŭ������ A�� �����ϰ�
	// �����ε��� B�� �����ϴ� ������ �Ҽ��� ������ �̷������� �ƹ��͵� ���� Update()�Լ�
	// �̴��� �����ε��� �Լ��ȿ� ������ָ� �θ��� A�� �����ϰ� �ڽ���B�� �����ϵ��� �����ϴ�.

	if (false >= --BoomCount)
	{
		Off();
	}

}