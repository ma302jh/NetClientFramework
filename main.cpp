#include <SFML/Graphics.hpp>
#include "sockWrapper.h"
#include "Connection.h"
#include "Splash.h"
#include "Button.h"
#include "Message.h"
#include "textIn.h"
#include "textOut.h"

int main(){

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "", false);

    //splash uses the window for the splash screen display
    Splash splash(window, "media/XD.png", 4, 4, 2);

    //function in splash can return window to desired size after, should make that auto-matic
    splash.returnWindow(800 , 600, "NetClient");

    textOut textBox(20, 20, 600, 400, 20, window);

    textIn textField( 20, 460, 300, 30, window);


    //setting frame rate
    window.setFramerateLimit(12);

    //connection object with timeout passed into args
    Connection connection(1000);

    //add a socket for the connection to handle
    connection.addSocket("irc", "irc.freenode.net", 6666);

    sf::sleep(sf::milliseconds(1000));

    connection.sendTo("irc", "NICK revengeBUTT\r\n");
    connection.sendTo("irc", "USER dr 8 *:devon revenge\r\n");
    connection.sendTo("irc", "JOIN :#cplusplus.com\r\n");



    //main window loop is presently for debugging
     while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){


            switch(event.type){

                case sf::Event::Closed:

                    window.close();
                    break;

                case sf::Event::KeyPressed:

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){

                        connection.sendTo("irc", textField.getText());

                    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){

                        window.close();
                    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){

                        connection.killConnection("irc");
                    }

                    break;

            }
        }

        //refreshes background
        window.clear(sf::Color::White);

        textField.drawText();
        textBox.drawBox();

        if(connection.dataAvailable("irc")){

            textBox.addString(connection.receiveFrom("irc"));
        }

        textField.keyListen(event);

        //displays everything to draw to the window
        window.display();
     }
}
