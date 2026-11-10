#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace sf;

// function to detect point-rectangle collision
bool pointRectCollision(Vector2i mousePos, RectangleShape &rect){ 

	if(mousePos.x > int(rect.getPosition().x) && mousePos.x < int(rect.getPosition().x + rect.getSize().x) && mousePos.y > int(rect.getPosition().y) && mousePos.y < int(rect.getPosition().y + rect.getSize().y)){
		return true;
	}

	else {
		return false;
	}
	
}

// Function for centering Text inside rect
Vector2f textCenter(RectangleShape &button){
	float textSize_X = button.getSize().x / 4;
	float textSize_Y = button.getSize().y / 4;

	float setText_x = textSize_X + button.getPosition().x + 5;
	float setText_y = textSize_Y + button.getPosition().y;
	
	Vector2f textPos = {setText_x, setText_y};

	return textPos;
}

int main(){
	// SCREEN
	RenderWindow window(sf::VideoMode({800, 600}), "PAUSE SCREEN");
	window.setFramerateLimit(60);

	// PAUSE BUTTON RECT
	RectangleShape pauseBtn;
	pauseBtn.setPosition(Vector2f(10, 10));
	pauseBtn.setSize(Vector2f(50, 50));
	pauseBtn.setOutlineColor(Color(145, 11, 1, 255));
	pauseBtn.setOutlineThickness(3.0f);	
	pauseBtn.setFillColor(Color::Red);

	// PAUSE BUTTON TEXT
	Font font("../assets/arial/ARIAL.TTF");

	Text pauseText(font);
	pauseText.setPosition(textCenter(pauseBtn));
	pauseText.setString("P");
	pauseText.setCharacterSize(20);

	bool isPause = false;

	// GAME LOOP
	while (window.isOpen()){
		// MOUSE RECT Collision
		if (Mouse::isButtonPressed(Mouse::Button::Left)){
			if(pointRectCollision(Mouse::getPosition(window), pauseBtn) && !isPause){

				pauseBtn.setOutlineColor(Color(20, 68, 156, 255));
				pauseBtn.setFillColor(Color(10, 235, 255));
				pauseText.setString("R");
				pauseText.setCharacterSize(20);

				isPause = true;

				this_thread::sleep_for(chrono::milliseconds(100)); // delay

			}

			/*else if (pointRectCollision(Mouse::getPosition(window), pauseBtn), isPause){

				pauseBtn.setOutlineColor(Color(145, 11, 1, 255));
				pauseBtn.setFillColor(Color::Red);
				pauseText.setString("P");
				pauseText.setCharacterSize(50);

				isPause = false;

				this_thread::sleep_for(chrono::milliseconds(100));	
			}*/

		}


		if (Mouse::isButtonPressed(Mouse::Button::Left)){
			if (pointRectCollision(Mouse::getPosition(window), pauseBtn) && isPause){

				pauseBtn.setOutlineColor(Color(145, 11, 1, 255));
				pauseBtn.setFillColor(Color::Red);
				pauseText.setString("P");
				pauseText.setCharacterSize(20);

				isPause = false;

				this_thread::sleep_for(chrono::milliseconds(100)); // delay
			}

		}


		while (const std::optional event = window.pollEvent()){
		// Close window: exit
			if (event->is<sf::Event::Closed>())
			window.close();
		}
		

		window.clear(Color::White);

		// DRAW
		window.draw(pauseBtn);
		window.draw(pauseText);

		window.display();
	}

	return 0;
} 
