//
// Created by agar on 03/05/2020.
//

#include <game.hpp>

void        test_forward(Map& map, Player& player)
{
    if (map.check(player.position_.x + player.direction_.x, player.position_.y))
        player.position_.x += player.direction_.x;
    if (map.check(player.position_.x, player.position_.y + player.direction_.y))
        player.position_.y += player.direction_.y;
}

void        test_backward(Map& map, Player& player)
{
    if (map.check(player.position_.x - player.direction_.x, player.position_.y))
        player.position_.x -= player.direction_.x;
    if (map.check(player.position_.x, player.position_.y - player.direction_.y))
        player.position_.y -= player.direction_.y;
}

void        test_right(Map& map, Player& player)
{
    if (map.check(player.position_.x + player.camera_.x, player.position_.y))
        player.position_.x += player.camera_.x;
    if (map.check(player.position_.x, player.position_.y + player.camera_.y))
        player.position_.y += player.camera_.y;
}

void        test_left(Map& map, Player& player)
{
    if (map.check(player.position_.x - player.camera_.x, player.position_.y))
        player.position_.x -= player.camera_.x;
    if (map.check(player.position_.x, player.position_.y - player.camera_.y))
        player.position_.y -= player.camera_.y;
}
