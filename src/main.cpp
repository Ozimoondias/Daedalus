/*
**
*/

#include    <game.hpp>

int main()
{

    sf::RenderWindow    window(sf::VideoMode(screenW, screenH),
            "Daedalus");//, sf::Style::Fullscreen);
    sf::Event   event;

    Player      player;
    Map         map;

    int ii = 0;

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            k_forward_backward(map, player, 1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            k_forward_backward(map, player, -1);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            k_right_left(map, player, 1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            k_right_left(map, player, -1);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            m_right_left(map, player, 1);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            m_right_left(map, player, -1);

        sf::VertexArray lines(sf::Lines, screenW);

        window.clear();

        draw(lines, player, map);
        window.draw(lines);

        window.display();

    }

    return 0;

}