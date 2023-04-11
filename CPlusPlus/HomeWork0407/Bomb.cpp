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


	// �ٸ� ���� ���ɶ����� �θ��ڵ带 Ȯ���ϱ⿡ �����ϴ�.
	if (false == GetFire())   // Fire �� false �� ��źī��Ʈ �����ϰ� 0���� �۾�����
		                      // ��ź�� ���ڸ� &�� �ٲٰ� Fire�� true�� �ٲ۴�.
	{
		if (0 >= --BoomCount) // off�� ���� off�� bomb�� ��� �����ִ� �ǹ̰� �ȴ�.
		{
			//Off();  // BoomCount�� 0�� �ȴٸ�. ������ ����.
			// ��ź�� ���ڰ� & �� ���ϸ鼭 &�� ���ڰ��� ��ĭ�� �̵��ϴ�.
			Bomb::SetChar('&'); // ��ź�� ���ڸ� '&'�� ����.
			FireOn();
			// ��ź�� ��ġ�� �������� �����Ѵ�.
		}
	}
}

void Bomb::Render()
{
	ConsoleGameObject::Render();

	if (true == GetFire()) // Fire�� true�̸� ���� �ϴ���. �̶�¶�. �����̳�����
		// isupdate �� Fire ��� false�� �ٲ���.
	{
		// ���� ��Ŀ����. ���⿡.
		
		Explosion();

		if (FireCount == FirePower) // ���� ī��Ʈ�� 0���� �۾����� ��������.
		{
			Death();
		}
	}

}

void Bomb::Explosion()
{
	if (FirePower == FireCount)
	{
		return;
	}

	for (int i = 0; i < FireCount; i++)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos().Left(i), RenderChar);
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos().Right(i), RenderChar);
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos().Up(i), RenderChar);
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos().Down(i), RenderChar);
	}
	FireCount++;
}