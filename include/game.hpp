//
// Created by agar on 03/05/2020.
//

#ifndef DAEDALUS_GAME_HPP
#define DAEDALUS_GAME_HPP

#include    <iostream>
#include    <cmath>

#include    <map.hpp>
#include    <player.hpp>

#define     screenW	1920
#define		screenH	1080

void        test_forward(const Map&, Player&);
void        test_backward(const Map&, Player&);
void        test_right(const Map&, Player&);
void        test_left(const Map&, Player&);

void        test_mouse(const Map&, Player&, const sf::RenderWindow&);

void        draw(sf::VertexArray&, const Player&, const Map&);

#endif //DAEDALUS_GAME_HPP