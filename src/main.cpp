/*
**
*/

#include	"main.hpp"

int	main(void)
{
  sf::RenderWindow	window(sf::VideoMode(screenW, screenH),
			       "Daedalus");
  sf::Event		event;
  sf::VertexArray	lines(sf::Lines, 18 * screenW);

  /*lines.append(sf::Vertex(sf::Vector2f(100, 100), sf::Color::Blue, sf::Vector2f(10, 10)));
    lines.append(sf::Vertex(sf::Vector2f(100,   0), sf::Color::Yellow, sf::Vector2f(10,  0)));*/
  lines.append(sf::Vertex(sf::Vector2f(  0,   0), sf::Color::Red, sf::Vector2f( 0,  0)));
  lines.append(sf::Vertex(sf::Vector2f(  0, 100), sf::Color::Green, sf::Vector2f( 0, 10)));

  while (window.isOpen())
    {
      while (window.pollEvent(event))
	if (event.type == sf::Event::Closed)
	  window.close();

      window.clear();
      window.draw(lines);
      window.display();
    }

  return 0;
}
