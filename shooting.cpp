#include <SFML\Graphics.hpp> 
#include <iostream> 
#include <algorithm> 
#include <vector>
class Shoot{
	public:
		Shoot(sf::Vector2f size) {
			shoot.setSize(size);
			shoot.setFillColor(sf::Color::Red);
		}
		void fire(int speed) {
			shoot.move(speed, 0);
		}
		int getRight() {
			return shoot.getPosition().x + shoot.getSize().x;
		}
		int getLeft() {
			return shoot.getPosition().x ;
		}
		int getTop() {
			return shoot.getPosition().y;

		}
		int getBottom() {
			return shoot.getPosition().y + shoot.getSize().y;
		}
		void draw(sf::RenderWindow &window) {
			window.draw(shoot);
		}
		void setPos(sf::Vector2f newPos) {
			shoot.setPosition(newPos);
		}
private:
	sf::RectangleShape shoot;
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::Clock clock;

	std::vector<Shoot> shootVect;
	bool isFiring = false;
	sf::Texture texture;
	if (!texture.loadFromFile("hero.png"))
	{
		std::cout <<"Error", "\n";
		system("pause");
		return 0;
	}
	texture.loadFromFile("hero.png");
	sf::Sprite circle;
	circle.setTexture(texture);
	circle.setPosition(20, 20);
	circle.setScale(0.3f, 0.3f);
	
	 
	while (window.isOpen())
	{
		sf::Time time = clock.getElapsedTime();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				break;
				//access to the keyboard 
			case sf::Event::KeyPressed:
			{
				sf::Vector2f pos = circle.getPosition();
				if (pos.x >= 0 && pos.x <= 800) {
					if (event.key.code == sf::Keyboard::Left) {
						circle.move(-1, 0);
					}
					if (event.key.code == sf::Keyboard::Right) {
						circle.move(1, 0);
					}
				}
				if (pos.y >= 0 && pos.y <= 600) {
					if (event.key.code == sf::Keyboard::Up) {
						circle.move(0, -1);
					}
					if (event.key.code == sf::Keyboard::Down) {
						circle.move(0, 1);
					}
				}
				if (pos.x < 0)
					circle.move(1, 0);
				if (pos.x > 800)
					circle.move(-1, 0);
				if (pos.y < 0)
					circle.move(0, 1);
				if (pos.y > 600)
					circle.move(0, -1);
				std::cout << pos.x << pos.y;
			}
			
			break;
			case sf::Event::MouseButtonPressed:
			{
				if (event.key.code == sf::Mouse::Left)
				{
					isFiring = true;
				}
			}break;
			default:
				break;
		}
	}
	// the character always focuses on the cursor
	sf::Vector2f center = circle.getPosition();
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		
	sf::Vector2u circleSize = circle.getTexture()->getSize();
	circle.setOrigin(circleSize.x / 2, circleSize.y / 2);
	sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;
	const float Pi = 3.14159f;
	circle.setRotation(90 + atan2f(d.y, d.x) * 180 / Pi);
	//circle.setPosition(mousePosition.x, mousePosition.y);

	//color of window is yellow
	window.clear(sf::Color::Yellow);
		

	//shooting
	if (isFiring == true) {
		Shoot newShoot(sf::Vector2f(20, 5));
		newShoot.setPos(sf::Vector2f(circle.getPosition().x, circle.getPosition().y));
		shootVect.push_back(newShoot);
		isFiring = false;
	}
	for (int i = 0; i < shootVect.size(); i++) {
		shootVect[i].draw(window);
		shootVect[i].fire(3);
	}

	// draw cirle 
	
	window.draw(circle);
	window.display();
}

	return 0;
}

