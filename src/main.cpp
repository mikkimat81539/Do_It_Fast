#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using namespace sf;

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

// set countdown timer
int countdown(int &counter, RenderWindow &window, Text &timerText){
	if(counter < 0){
		return 0;
	}

	timerText.setString("Timer: " + to_string(counter));
	window.draw(timerText);

	return counter;
}

// function for positioning font inside rectangle
Vector2f textCenter(RectangleShape &rect){
	float boxSize_X = rect.getPosition().x/2;
	float boxSize_Y = rect.getPosition().y/2;

	float boxPos_X = rect.getPosition().x + boxSize_X + 6;
	float boxPos_Y = rect.getPosition().y + boxSize_Y;

	Vector2f textPos = {boxPos_X, boxPos_Y};

	return textPos;
}

bool PointRectCollision(Vector2i mousePos, RectangleShape &rect){
	if (mousePos.x > rect.getPosition().x && mousePos.x < rect.getPosition().x + rect.getSize().x && mousePos.y > rect.getPosition().y && mousePos.y < rect.getPosition().y + rect.getSize().y){
		return true;
	}

	return 0;
}

int main(){
	// Game Setup
	RenderWindow window(VideoMode( { SCREEN_WIDTH, SCREEN_HEIGHT } ), "Do it Fast"); // window
	window.setPosition({(1440-SCREEN_WIDTH)/2,(900-SCREEN_HEIGHT)/2});

	window.setFramerateLimit(60); // FPS

	
	// Black Surface
	RectangleShape surface;
	surface.setSize( Vector2f( {SCREEN_WIDTH, 75} )); // surface size
	surface.setFillColor(Color::Black); // surface color

	// CLOCK
	int counter = 20;
	Clock clock;

	Font font("../assets/arial/ARIAL.TTF"); // define font
	Text timerText(font); // define text
	timerText.setFillColor(Color::White);
	timerText.setPosition(Vector2f{355, 75/4});

	// PAUSE BUTTON RECT
	RectangleShape pauseBtn;
	pauseBtn.setPosition(Vector2f(10, 10));
	pauseBtn.setSize(Vector2f(50, 50));
	pauseBtn.setFillColor(Color(230, 103, 94, 255));
	
	// PAUSE BUTTON TEXT
	Text pauseText(font);
	pauseText.setString("| |");
	pauseText.setPosition(textCenter(pauseBtn));
	pauseText.setFillColor(Color::White);

	bool isPause = false; // pause button is not clicked

	// Game Loop
	while(window.isOpen()){
		// Track Elapsed Time in seconds
		float seconds = clock.getElapsedTime().asSeconds();

		if (seconds > 1.00){
			counter--;
			clock.restart();
		}

		// Mouse-Rect Collision Detection	
		if(Mouse::isButtonPressed(Mouse::Button::Left)){
			if(PointRectCollision(Mouse::getPosition(window), pauseBtn) && !isPause){
				pauseBtn.setFillColor(Color(2, 119, 191));	
				isPause = true;

				this_thread::sleep_for(chrono::milliseconds(100)); // delay
				
				clock.stop();
			}
		}

		if(Mouse::isButtonPressed(Mouse::Button::Left)){
			if(PointRectCollision(Mouse::getPosition(window), pauseBtn) && isPause){
				pauseBtn.setFillColor(Color::Red);	
				isPause = false;

				this_thread::sleep_for(chrono::milliseconds(100)); // delay

				counter = 20;
				
				clock.start();
			}
		}		

		// Event Loop
		while (const std::optional event = window.pollEvent()){
			if (event->is<sf::Event::Closed>()){ // close window
				window.close();
			}
		}
		
		window.clear(Color::White); // clear with a color. called every frame
		
		// DRAW
		window.draw(surface);	
		countdown(counter, window, timerText);
		window.draw(pauseBtn);
		window.draw(pauseText);	
	
		window.display();
	}

}
