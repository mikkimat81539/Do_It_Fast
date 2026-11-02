#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

int countdown(int &counter, Text &text, RenderWindow &window){
	if (counter < 0){
		return 0;
	}

	text.setString("Seconds: " + to_string(counter)); // writing out text

	window.draw(text);

	return counter;
}

int main(){
	// SETUP
	RenderWindow window(sf::VideoMode({300, 300}), "COUNTDOWN TIMER"); // Create Main Window
	window.setFramerateLimit(60);
	
	// TIMER
	Clock clock;
	int counter = 20; // countdown from 20 seconds -- starting point
	
	// TEXT
	Font font("../assets/arial/ARIAL.TTF");
	Text timerText(font);				
	timerText.setPosition(Vector2f{50, 50});
	timerText.setFillColor(Color::Black);
	
	// GAME LOOP
	while (window.isOpen()){
		float seconds = clock.getElapsedTime().asSeconds(); // elapsed time in seconds

		cout << seconds << endl;

		// If 1 second passes subract counter by 1 and restart clock
		if (seconds > 1.00){
			counter--;
			clock.restart();
		}


		while (const std::optional event = window.pollEvent()){
			// Close window: exit
			if (event->is<sf::Event::Closed>())
			window.close();
		}		
		
		
		window.clear(Color::White);

		countdown(counter, timerText, window);
		
		window.display();
	}
}
