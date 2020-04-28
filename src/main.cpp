/*
**
*/

#include	"main.hpp"

int	main(void)
{
  sf::RenderWindow	window(sf::VideoMode(800, 600),
			       "Daedalus");
  sf::Event		event;

  while (window.isOpen())
    {
      while (window.pollEvent(event))
	if (event.type == sf::Event::Closed)
	  window.close();

      window.clear();
      window.display();
    }

  return 0;
}
