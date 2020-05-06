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

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }

        test_mouse(map, player, window);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            test_forward(map, player);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            test_backward(map, player);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            test_right(map, player);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            test_left(map, player);

        sf::VertexArray lines(sf::Lines, screenW);

        window.clear();

        draw(lines, player, map);
        window.draw(lines);

        window.display();

    }

    return 0;

}