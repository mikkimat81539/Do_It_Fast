#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

int main(){
	// Game Setup
	RenderWindow window(VideoMode( { SCREEN_WIDTH, SCREEN_HEIGHT } ), "Do it Fast"); // window
	window.setPosition({(1440-SCREEN_WIDTH)/2,(900-SCREEN_HEIGHT)/2});

	// Black Surface
	RectangleShape surface;
	surface.setSize( Vector2f( {SCREEN_WIDTH, 75} )); // surface size
	surface.setFillColor(Color::Black); // surface color

	// TIMER
	Font font("../assets/arial/ARIAL.TTF"); // define font
	Text timerText(font); // define text
	timerText.setString("Timer: ");
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
		window.draw(timerText);

		window.display();
	}

}
