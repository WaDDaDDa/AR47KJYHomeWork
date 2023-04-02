#pragma once
//#include "Player.h"
//#include "Monster.h"

class Player;
class Monster;
class ShootingGame
{
public:
	static void Loading();

	static void GameUpdate(); 

	static void Collision();

	static void GameProgress();

private:

	static Player MainPlayer; //슈팅게임은 반드시 MainPlayer를 가진다.

	ShootingGame() 
	{
	}
};