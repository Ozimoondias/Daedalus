//
// Created by agar on 03/05/2020.
//

#ifndef DAEDALUS_GAME_HPP
#define DAEDALUS_GAME_HPP

#include    <iostream>
#include    <cmath>

#include    <map.hpp>
#include    <player.hpp>

#define     screenW 1920//720
#define		screenH 1080//480

void        k_forward_backward(const Map&, Player&,
        const int&);
void        k_right_left(const Map&, Player&,
        const int&);
void        m_right_left(const Map&, Player&,
        const int&);

void        draw(sf::VertexArray&, const Player&, const Map&);

#endif //DAEDALUS_GAME_HPP