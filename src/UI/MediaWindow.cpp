#include "MediaWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Color.hpp"
#include "WindowADT.hpp"
#include <iostream>


MediaWindow::MediaWindow() : WindowADT("Media Window"){

	if(!title_font.openFromFile("assets/Fonts/Sono-Bold.ttf")){
		std::cout << "No Font found.\n";
	}
	t = new sf::Text(title_font);
	t->setPosition({SCREEN_WIDTH / 2, 600});
}

	


void MediaWindow::display_song_title(const Song* song){
	t->setString(song->get_title());

	t->setCharacterSize(24);
	t->setFillColor(sf::Color::Red);
	window.draw( *t);

}

void MediaWindow::display_song_artist(const Song* song){

}

void MediaWindow::display_song_album(const Song* song){

}

void MediaWindow::draw(){
	if (t){
		window.draw(*t);
	}
}


void MediaWindow::display_song_info(const Song* song){
	display_song_title(song);
	display_song_artist(song);
	display_song_album(song);
}


MediaWindow::~MediaWindow(){

}