#include "GameEngine.h"
#include <ctime>

GameEngine::GameEngine(RenderWindow& window, const Player& playerr) : player(playerr), shield("shield2.png", 0, 0, 100, 100, 60, 5, 100)
{
	//(string filename, int rectTop, int rectLeft, int rectWidth, int rectHeight, int rows, int cols, float timeBetweenSlides, bool loop, bool reverseLoop)
	Clock clock;
	float time = 0;
	float timeBetweenShots = 0;
	float timeBetweenEnemies = 0;
	Event event;
	bool previousIsLine = false;
	int score = 0;
	int temp = 0;
	int playerWidth = player.GetWidth();
	FloatRect playerGlobalBounds;
	float timeBetweenShieldSlides = 0;
	float timeBetweenExplodeSlides = 0;
	bool pause = false;


	while (window.isOpen()) {
		while (window.pollEvent(event))	if (event.type == sf::Event::Closed) window.close();
		//if (!player.GetIsDead()) {
			TimeOperations(time, clock, timeBetweenShots, timeBetweenEnemies, timeBetweenShieldSlides);
			playerGlobalBounds = player.GetSprite().getGlobalBounds();

			timeBetweenExplodeSlides += time;

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{

				Sleep(130);
				pause = !pause;

				clock.restart();
				stop.SetPause(window);


				window.display();
				cout << "Pause\n";


			}

			if (!pause)
			{
				if (timeBetweenEnemies > 1000) {
					AddEnemies(score, previousIsLine);
					timeBetweenEnemies = 0 + rand() % 500;
				}
				if (Keyboard::isKeyPressed(Keyboard::Space) && timeBetweenShots > player.GetTimeBetweenShots()) {
					playerBullets.push_back(Laser(player.GetSprite().getPosition().x, player.GetSprite().getPosition().y, 1));
					timeBetweenShots = 0;
				}


				for (int i = 0; i < playerBullets.size(); i++) {
					if (playerBullets[i].GetIsDead()) {
						playerBullets.erase(playerBullets.begin() + i);
						cout << "Bullet\n";
					}
				}
				for (int i = 0; i < enemies.size(); i++) {
					if (enemies[i].GetIsDead()) {
						enemies.erase(enemies.begin() + i);
						cout << "Enemy\n";
					}
				}
				for (int i = 0; i < enemyBullets.size(); i++) {
					if (enemyBullets[i].GetIsDead()) {
						enemyBullets.erase(enemyBullets.begin() + i);
						cout << "enemyBullet\n";
					}
				}


				window.clear();

				//background.Update(time, 0.2, window);

				for (int i = 0; i < playerBullets.size(); i++) {
					playerBullets[i].Update(time, 1, window);
					for (int j = 0; j < enemies.size(); j++) {
						if (playerBullets[i].GetSprite().getGlobalBounds().intersects(enemies[j].GetSprite().getGlobalBounds())) {
							//cout << temp++ << endl;
							enemies[j].Explode();
							playerBullets[i].Kill();
						}
					}
				}
				for (int i = 0; i < enemies.size(); i++) {
					enemies[i].Update(time, 0.35, window);
					float enemyX = enemies[i].GetX();
					float playerX = player.GetX();
					if (enemyX > playerX - playerWidth && enemyX < playerX + playerWidth && enemies[i].GetTimeBetweenShots() > 1000 && enemies[i].GetY() < player.GetY()) {
						enemyBullets.push_back(Laser(enemyX, enemies[i].GetY(), -1));
						enemies[i].SetTimeBetweenShots(0);
					}
				}
				for (int i = 0; i < enemyBullets.size(); i++) {
					enemyBullets[i].Update(time, -0.5, window);
					if (enemyBullets[i].GetSprite().getGlobalBounds().intersects(playerGlobalBounds) && !enemyBullets[i].GetIsDead() && !enemyBullets[i].GetExploding()) {
						player.SubtractHP(50);
						enemyBullets[i].Explode();
					}
				}

				player.Update(time, 1, window);

				if (!player.GetIsDead() && !player.GetExploding()) {
					shield.Update(timeBetweenShieldSlides, window, player.GetX() - 25, player.GetY() - 25);
				}
				window.display();
			}
		//}
	}
	//system("cls");
}



void GameEngine::AddEnemies(int score, bool& previousIsLine)
{
	short temp = rand() % 10;
	if (!previousIsLine) {
		if (temp == 0) {
			if (score > 1000) {
				enemies.push_back(Enemy(0, -100, 1));
				enemies.push_back(Enemy(500, -100, 1));
			}
			enemies.push_back(Enemy(125, -100, 1));
			enemies.push_back(Enemy(250, -100, 1));
			enemies.push_back(Enemy(375, -100, 1));
			previousIsLine = true;
		}
		else if (temp == 1) {
			if (score > 1000) {
				enemies.push_back(Enemy(0, -250, 1));
				enemies.push_back(Enemy(500, -250, 1));
			}
			enemies.push_back(Enemy(125, -175, 1));
			enemies.push_back(Enemy(250, -100, 1));
			enemies.push_back(Enemy(375, -175, 1));
			previousIsLine = true;
		}
		else if (temp == 2) {
			if (score > 1000) {
				enemies.push_back(Enemy(0, -100, 1));
				enemies.push_back(Enemy(500, -400, 1));
			}
			enemies.push_back(Enemy(125, -175, 1));
			enemies.push_back(Enemy(250, -250, 1));
			enemies.push_back(Enemy(375, -325, 1));
			previousIsLine = true;
		}
		else {
			enemies.push_back(Enemy(rand() % 500, -100, 1));
		}
	}
	else {
		enemies.push_back(Enemy(rand() % 500, -100, 1));
		previousIsLine = false;
	}
}

void GameEngine::TimeOperations(float& time, Clock &clock, float & timeBetweenShots, float & timeBetweenEnemies, float& timeBetweenShieldSlides)
{
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 1000;
	timeBetweenShots += time;
	timeBetweenEnemies += time;
	timeBetweenShieldSlides += time;
}
