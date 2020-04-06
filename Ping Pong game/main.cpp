#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include<cstdlib>
#include<ctime>

using namespace std;

const map<int, sf::Color> harita =
{ {0,sf::Color::Blue},
  {1,sf::Color::Red},
  {2,sf::Color::Magenta},
  {3,sf::Color::Green},
  {4,sf::Color::Yellow}
};

const map<int, float> baslangic =
{ {0,-5.0f},{1,5.f}};


void klavyeKontrol();
void ballControl(sf::RectangleShape& top, sf::RectangleShape& oyuncu1, sf::RectangleShape& oyuncu2);

float max_speed = 25.0f;
float speed_1 = 0.f;
float speed_2 = 0.f;
int direction = 1.f;
float ivme = 1.0f;
float drag = 0.5f;
float dt;
int space = 0;
int random;
float top_x=0.f;
float top_y=0.f;


int main()
{
	srand(time(NULL));

	sf::ContextSettings ayarlar;
	ayarlar.antialiasingLevel = 4;
	sf::RenderWindow pencere(sf::VideoMode(1024, 576), "Ping Pong", sf::Style::Default, ayarlar);

	sf::RectangleShape oyuncu1;
	oyuncu1.setSize(sf::Vector2f(10, 80));
	oyuncu1.setPosition(5, (576 / 2) - 40);
	oyuncu1.setFillColor(sf::Color::White);

	sf::RectangleShape oyuncu2;
	oyuncu2.setSize(sf::Vector2f(10, 80));
	oyuncu2.setPosition(1024-15, (576 / 2) - 40);
	oyuncu2.setFillColor(sf::Color::White);

	sf::RectangleShape top;
	top.setSize(sf::Vector2f(15, 15));
	top.setPosition((1024 / 2) - 7.5, (576 / 2) - 7.5);

	sf::Clock zaman;
	

	while (pencere.isOpen())
	{
		sf::Event olay;
		dt = zaman.restart().asSeconds();


		while (pencere.pollEvent(olay))
		{
			if (olay.type == sf::Event::Closed)
			{
				pencere.close();
			}
		}

		klavyeKontrol();

		oyuncu1.move(0, speed_1 * dt * 60);
		oyuncu2.move(0, speed_2 * dt * 60);


		pencere.clear();

		pencere.draw(oyuncu1);
		pencere.draw(oyuncu2);
		pencere.draw(top);

		pencere.display();

	}

	return 0;
}

void klavyeKontrol()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction = -1;
		if (speed_1 > -max_speed)
		{
			speed_1 += direction * dt * 60 * ivme;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = 1;
		if (speed_1 < max_speed)
		{
			speed_1 += direction * dt * 60 * ivme;
		}
	}

	if (speed_1 > 0.f)
	{
		speed_1 -= drag * dt * 60;

		if (speed_1 < 0.f)
		{
			speed_1 = 0.f;
		}
	}

	else if (speed_1 < 0.f)
	{
		speed_1 += drag * dt * 60;

		if (speed_1 > 0.f)
		{
			speed_1 = 0.f;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction = -1;
		if (speed_2 > -max_speed)
		{
			speed_2 += direction * dt * 60 * ivme;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction = 1;
		if (speed_2 < max_speed)
		{
			speed_2 += direction * dt * 60 * ivme;
		}
	}

	if (speed_2 > 0.f)
	{
		speed_2 -= drag * dt * 60;

		if (speed_2 < 0.f)
		{
			speed_2 = 0.f;
		}
	}

	else if (speed_2 < 0.f)
	{
		speed_2 += drag * dt * 60;

		if (speed_2 > 0.f)
		{
			speed_2 = 0.f;
		}
	}
}

void ballControl(sf::RectangleShape& top, sf::RectangleShape& oyuncu1, sf::RectangleShape& oyuncu2)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && space == 0)
	{
		random = rand() % 2;
		top_x = baslangic.at(random);
		random = rand() % 2;
		top_y = baslangic.at(random);
		++space;
	}

	if (top.getPosition().y >= 576-15)
	{
		top_y = -top_y;
	}

	else if (top.getPosition().y <= 0)
	{
		top_y = -top_y;
	}

	if (top_x )
	{

	}

}

