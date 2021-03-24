#include "GameEngine.h"
#include <ctime>
#include <chrono>

GameEngine::GameEngine(RenderWindow& window, const Player& playerr) : player(playerr), shield("shield2.png", 0, 0, 100, 100, 60, 5, 25, 1)
{
	Clock clock;
	float time = 0;
	float timeBetweenShots = 0;
	float timeBetweenEnemies = 0;
	Event event;
	bool previousIsLine = false;
	int score = 1;
	int playerWidth = player.GetWidth();
	FloatRect playerGlobalBounds;
	float timeBetweenShieldSlides = 0;
	bool isPause = false;
	bool isShield = false;
	float shieldTime = 0;
	float timeBetweenSpeedUping = 0;

	while (window.isOpen()) {
		window.pollEvent(event);
		if (event.type == Event::Closed) break;

		//if (!player.GetIsDead()) {
			TimeOperations(time, clock, timeBetweenShots, timeBetweenEnemies, timeBetweenShieldSlides, shieldTime, timeBetweenSpeedUping);
			playerGlobalBounds = player.GetSprite().getGlobalBounds();
			
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				if(isPause) Sleep(200);
				isPause = !isPause;

				clock.restart();
				pause.SetPause(window);
				window.display();
				if (isPause) Sleep(200);
			}

			if (!isPause) {
				if (timeBetweenEnemies > 1500 - score/100) {
					AddEnemies(score, previousIsLine);
					timeBetweenEnemies = 0 + rand() % 500;
				}

				if (Keyboard::isKeyPressed(Keyboard::Space) && timeBetweenShots > player.GetTimeBetweenShots()) {
					playerBullets.push_back(Laser(player.GetSprite().getPosition().x, player.GetSprite().getPosition().y, 1));
					timeBetweenShots = 0;
				}

				if (Keyboard::isKeyPressed(Keyboard::Q) && shieldTime >= 7500) {
					isShield = true;
					shieldTime = 0;
				}
				if (isShield && shieldTime >= 5000) {
					isShield = false;
					shieldTime = 0;
				}

				if (timeBetweenSpeedUping >= 1000000 / player.GetTimeBetweenShots() && player.GetTimeBetweenShots() >= 100) {
					player.SpeedUpShooting();
					timeBetweenSpeedUping = 0;
				}

				for (int i = 0; i < playerBullets.size(); i++) {
					if (playerBullets[i].GetIsDead()) {
						playerBullets.erase(playerBullets.begin() + i);
						break;
					}
				}
				for (int i = 0; i < enemies.size(); i++) {
					if (enemies[i].GetIsDead()) {
						enemies.erase(enemies.begin() + i);
						break;
					}
				}
				for (int i = 0; i < enemyBullets.size(); i++) {
					if (enemyBullets[i].GetIsDead()) {
						enemyBullets.erase(enemyBullets.begin() + i);
						break;
					}
				}

				window.clear();
				background.Update(time, player.GetX(), window);

			
				for (int i = 0; i < playerBullets.size(); i++) {
					playerBullets[i].Update(time, 1, window);
					for (int j = 0; j < enemies.size(); j++) {
						if (playerBullets[i].GetSprite().getGlobalBounds().intersects(enemies[j].GetSprite().getGlobalBounds())) {
							enemies[j].Explode();
							playerBullets[i].Kill();
							score += 100 + score / 200;
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
						if (!isShield) {
							player.SubtractHP(5);
						}
						enemyBullets[i].Explode();
					}
				}

				player.Update(time, 1, window);

				if (!player.GetIsDead() && !player.GetExploding() && isShield) {
					shield.Update(timeBetweenShieldSlides, window, player.GetX() - 25, player.GetY() - 25);
				}
				window.display();


			}
		//}
	}
	//system("cls");
}


			//unsigned int start_time = std::clock();
			//
			//unsigned int end_time = std::clock(); // конечное время
			//unsigned int search_time = end_time - start_time;
			//if (search_time > 0) cout << search_time << endl;


void GameEngine::AddEnemies(int score, bool& previousIsLine)
{
	short temp = rand() % 10;
	if (!previousIsLine && score >= 1000) {
		if (temp == 0) {
			if (score > 7500) {
				enemies.push_back(Enemy(0, -100, 1));
				enemies.push_back(Enemy(500, -100, 1));
			}
			enemies.push_back(Enemy(125, -100, 1));
			enemies.push_back(Enemy(375, -100, 1));
			enemies.push_back(Enemy(250, -100, 1));
			previousIsLine = true;
		}
		else if (temp == 1) {
			if (score > 7500) {
				enemies.push_back(Enemy(0, -250, 1));
				enemies.push_back(Enemy(500, -250, 1));
			}
			enemies.push_back(Enemy(125, -175, 1));
			enemies.push_back(Enemy(375, -175, 1));
			enemies.push_back(Enemy(250, -100, 1));
			previousIsLine = true;
		}
		else if (temp == 2) {
			if (score > 7500) {
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

	//TESTS
	//enemies.push_back(Enemy(0, -100, 1));
	//enemies.push_back(Enemy(500, -100, 1));
	//enemies.push_back(Enemy(125, -100, 1));
	//enemies.push_back(Enemy(375, -100, 1));
	//enemies.push_back(Enemy(250, -100, 1));
}

void GameEngine::TimeOperations(float& time, Clock &clock, float & timeBetweenShots, float & timeBetweenEnemies, float& timeBetweenShieldSlides, float& shieldTime, float & timeBetweenSpeedUping)
{
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 1000;
	timeBetweenShots += time;
	timeBetweenEnemies += time;
	timeBetweenShieldSlides += time;
	shieldTime += time;
	timeBetweenSpeedUping += time;
}
