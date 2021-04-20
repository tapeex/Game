#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Animation.h"
#include "Pause.h"
#include "Menu.h"
#include "Background.h"
#include <Windows.h>
#include <vector>
using namespace std;

class GameEngine
{
	Player player;
	vector<Laser> playerBullets;
	vector<Enemy> enemies;
	vector<Laser> enemyBullets;

	Background background;

	Menu menu;
	Pause stop;

	Animation shield;

public:
	GameEngine() = default;
	GameEngine(RenderWindow& window, const Player& playerr, bool isPaused = false);

	void AddEnemies(int score, bool &previousIsLine);

	void TimeOperations(float &time, Clock &clock, float& timeBetweenShots, float& timeBetweenEnemies, float& timeBetweenShieldSlides, float& shieldTime, float& timeBetweenSpeedUping);
};

