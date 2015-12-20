#include <SFML/Graphics.hpp>
#include "sockWrapper.h"
#include "Connection.h"
#include "Splash.h"
#include "Button.h"
#include "Message.h"
#include "textIn.h"



int main(){

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "", false);

    Splash splash(window, "media/XD.png", 4, 4, 2);

    splash.returnWindow(800 , 600, "NetClient");

    textIn textField();

    //setting frame rate
    window.setFramerateLimit(12);

     while (window.isOpen()){

         sf::Event event;
         while (window.pollEvent(event)){

             if (event.type == sf::Event::Closed || close.getSelected())
                 window.close();
         }

        window.clear();
        close.drawMess();
        window.display();
     }
}
