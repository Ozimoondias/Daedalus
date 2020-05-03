/*
**
*/

#include    <game.hpp>

int main()
{

    sf::RenderWindow    window(sf::VideoMode(screenW, screenH),
            "Daedalus");
    sf::Event   event;

    Player      player;
    Map         map;

    map.draw(player.position_.x + player.position_.y * 10);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear();
            //window.draw();
            window.display();
        }
    }

    return 0;

}