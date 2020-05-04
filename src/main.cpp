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

    /*
    map.draw(player.position_.x, player.position_.y);
    test_forward(map, player);
    map.draw(player.position_.x, player.position_.y);
    test_forward(map, player);
    map.draw(player.position_.x, player.position_.y);
    test_backward(map, player);
    map.draw(player.position_.x, player.position_.y);
    test_backward(map, player);
    map.draw(player.position_.x, player.position_.y);
     */

    sf::VertexArray lines(sf::Lines, screenW);

    for (int i = 0; i < screenW; i++)
    {
        lines.append(sf::Vertex(sf::Vector2f(i, 0), sf::Color::Cyan));
        lines.append(sf::Vertex(sf::Vector2f(i, 600), sf::Color::Cyan));
    }

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear();
            window.draw(lines);
            window.display();
        }
    }

    return 0;

}