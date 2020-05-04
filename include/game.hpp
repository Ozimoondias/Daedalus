//
// Created by agar on 03/05/2020.
//

#ifndef DAEDALUS_GAME_HPP
#define DAEDALUS_GAME_HPP

#include    <iostream>

#include    <map.hpp>
#include    <player.hpp>

#define     screenW	1280
#define		screenH	720

void        test_forward(Map&, Player&);
void        test_backward(Map&, Player&);
void        test_right(Map&, Player&);
void        test_left(Map&, Player&);

#endif //DAEDALUS_GAME_HPP