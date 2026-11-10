#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;


// function to detect point-rectangle collision
bool pointRectCollision(Vector2i mousePos, RectangleShape rect){ 
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

	float setText_x = textSize_X + button.getPosition().x + 10;
	float setText_y = textSize_Y + button.getPosition().y - 5;
	
	Vector2f textPos = {setText_x, setText_y};

	return textPos;
}

int main(){
	// SCREEN
	RenderWindow window(sf::VideoMode({800, 600}), "PAUSE SCREEN");

	// PAUSE BUTTON RECT
	RectangleShape pauseBtn;
	pauseBtn.setPosition(Vector2f(10, 10));
	pauseBtn.setSize(Vector2f(100, 100));
	pauseBtn.setOutlineColor(Color(145, 11, 1, 255));
	pauseBtn.setOutlineThickness(3.0f);	
	pauseBtn.setFillColor(Color::Red);

	// PAUSE BUTTON TEXT
	Font font("../assets/arial/ARIAL.TTF");

	Text pauseText(font);
	pauseText.setPosition(textCenter(pauseBtn));
	pauseText.setString("P");
	pauseText.setCharacterSize(50);

	// GAME LOOP
	while (window.isOpen()){
		// MOUSE
		if (Mouse::isButtonPressed(Mouse::Button::Left)){
			if(pointRectCollision(Mouse::getPosition(), pauseBtn)){
				cout << "COLLISION" << endl;
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
