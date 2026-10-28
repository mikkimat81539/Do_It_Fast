#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main(){
	// Game Setup
	RenderWindow window(VideoMode( { 500, 500 } ), "Do it Fast");

	window.setPosition({(1440-500)/2,(900-500)/2});

	// Game Loop
	while(window.isOpen()){
		// Event Loop
		while (const std::optional event = window.pollEvent()){
			if (event->is<sf::Event::Closed>()){ // close window
				window.close();
			}
		}

		window.clear(Color::White); // clear with a color. called every frame

		window.display();
	}

}
