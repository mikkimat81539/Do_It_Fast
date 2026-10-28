#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
using namespace sf;

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

int countdown(int &counter, RenderWindow &window, Text &timerText){
	if (counter < 1){
		return 0;
	}

	timerText.setString("Timer: " + to_string(counter));
	window.draw(timerText);

	counter--;
	return counter;
}

int main(){
	// Game Setup
	RenderWindow window(VideoMode( { SCREEN_WIDTH, SCREEN_HEIGHT } ), "Do it Fast"); // window
	window.setPosition({(1440-SCREEN_WIDTH)/2,(900-SCREEN_HEIGHT)/2});

	window.setFramerateLimit(1); // FPS

	// CLOCK
	Clock clock;
	
	// Black Surface
	RectangleShape surface;
	surface.setSize( Vector2f( {SCREEN_WIDTH, 75} )); // surface size
	surface.setFillColor(Color::Black); // surface color

	// TIMER
	int counter = 20;

	Font font("../assets/arial/ARIAL.TTF"); // define font
	Text timerText(font); // define text
	// timerText.setString("Timer: " + std::to_string(counter) + "");
	timerText.setFillColor(Color::White);
	timerText.setPosition(Vector2f{0, 75/4});
	
	// Game Loop
	while(window.isOpen()){
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

		window.display();
	}

}
