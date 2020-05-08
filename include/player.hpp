//
// Created by agar on 02/05/2020.
//

#ifndef DAEDALUS_PLAYER_HPP
#define DAEDALUS_PLAYER_HPP

#include    <SFML/Graphics.hpp>

struct      Player
{
    sf::Vector2f    position_ {2, 2};
    sf::Vector2f    direction_ {1, 0};
    sf::Vector2f    camera_ {0, -0.60};
    sf::Vector2f    speed_ {0.05, 0.01};
};

inline  std::ostream& operator<<(std::ostream& os,
        const sf::Vector2f& vec)
{
    os
    << " vec.x " << vec.x
    << " vec.y " << vec.y
    << std::endl;

    return os;
}

inline  std::ostream& operator<<(std::ostream& os,
        const Player& player)
{
    os
    << " position_ " << player.position_
    << " direction_ " << player.direction_
    << " camera_ " << player.camera_
    << " speed_ " << player.speed_
    << std::endl;

    return os;
}

#endif //DAEDALUS_PLAYER_HPP