#include "WindowADT.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <optional>







WindowADT::WindowADT(const std::string& window_title){
	this->window_title = window_title;

	window.create(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), window_title);

	
}

/*
determines what the user is doing, whether they close window, press a button
type something, etc
*/
void WindowADT::handle_event(const sf::Event& event){
	if (event.is<sf::Event::Closed>()){
		window.close();
	}
}


/*
main loop of the window
*/
void WindowADT::run(){
	while (window.isOpen()){

		while (const std::optional<sf::Event> event = window.pollEvent()){
			handle_event(*event);
		}

		window.clear();

		draw();
		window.display();
	}
}


