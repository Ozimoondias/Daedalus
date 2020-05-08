//
// Created by agar on 03/05/2020.
//

#include <game.hpp>

void        k_forward_backward(const Map& map, Player& player,
        const int& dir)
{
    float   mov_speed = player.speed_.x * dir;

    if (map.check(player.position_.x + player.direction_.x * mov_speed,
            player.position_.y))
        player.position_.x += player.direction_.x * mov_speed;
    if (map.check(player.position_.x,
            player.position_.y + player.direction_.y * mov_speed))
        player.position_.y += player.direction_.y * mov_speed;
}

void        k_right_left(const Map& map, Player& player,
        const int& dir)
{
    float   mov_speed = player.speed_.x * dir;

    if (map.check(player.position_.x + player.camera_.x * mov_speed,
            player.position_.y))
        player.position_.x += player.camera_.x * mov_speed;
    if (map.check(player.position_.x,
            player.position_.y + player.camera_.y * mov_speed))
        player.position_.y += player.camera_.y * mov_speed;
}

void        m_right_left(const Map& map, Player& player,
        const int& dir)
{
    float   rot_speed = player.speed_.y * dir;
    double  old_dir = player.direction_.x;
    double  old_cam = player.camera_.x;

    player.direction_.x = player.direction_.x * std::cos(rot_speed)
            - player.direction_.y * std::sin(rot_speed);
    player.direction_.y = old_dir * std::sin(rot_speed)
            + player.direction_.y * std::cos(rot_speed);

    player.camera_.x = player.camera_.x * std::cos(rot_speed)
            - player.camera_.y * std::sin(rot_speed);
    player.camera_.y = old_cam * std::sin(rot_speed)
            + player.camera_.y * std::cos(rot_speed);
}

void        draw(sf::VertexArray& lines,
        const Player& player, const Map& map)
{
    for (int x = 0; x < screenW; x++)
    {
        double camX = 2 * x / (double)screenW - 1;

        double rdirX = player.direction_.x +
                player.camera_.x * camX;
        double rdirY = player.direction_.y +
                player.camera_.y * camX;

        int mapX = int(player.position_.x);
        int mapY = int(player.position_.y);

        double  sideDistX;
        double  sideDistY;

        double  deltaDistX = std::abs(1 / rdirX);
        double  deltaDistY = std::abs(1 / rdirY);
        double  perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rdirX < 0)
        {
            stepX = -1;
            sideDistX = (player.position_.x - mapX)
                    * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player.position_.x)
                    * deltaDistX;
        }
        if (rdirY < 0)
        {
            stepY = -1;
            sideDistY = (player.position_.y - mapY)
                    * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player.position_.y)
                    * deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (!map.check(mapX, mapY))
                hit = 1;
            //std::cout << "hit " << hit << std::endl;
        }

        perpWallDist = (side == 0)
                ? ((float)mapX - player.position_.x
                    + (float)(1 - stepX) / 2) / rdirX
                : ((float)mapY - player.position_.y
                    + (float)(1 - stepY) / 2) / rdirY;

        int lineHeight = (int)(screenH / perpWallDist);

        int drawS = -lineHeight / 2 + screenH / 2;
        if (drawS < 0)
            drawS = 0;
        int drawE = lineHeight / 2 + screenH / 2;
        if (drawE > screenH)
            drawE = screenH;

        int ceilingPixel = 0;
        int groundPixel = screenH;

        lines.append(sf::Vertex(sf::Vector2f(x, ceilingPixel), sf::Color::Cyan));
        ceilingPixel = int(-lineHeight * (1.0 - 0.6) + screenH * 0.5f);
        lines.append(sf::Vertex(sf::Vector2f(x, ceilingPixel), sf::Color::Cyan));

        lines.append(sf::Vertex(sf::Vector2f(x, groundPixel), sf::Color::Green));
        groundPixel = int(lineHeight * (1.0 - 0.6) + screenH * 0.5f);
        lines.append(sf::Vertex(sf::Vector2f(x, groundPixel), sf::Color::Green));

        lines.append(sf::Vertex(sf::Vector2f(x, drawS), sf::Color::Red));
        lines.append(sf::Vertex(sf::Vector2f(x, drawE), sf::Color::Red));

        

        //std::cout << " rdirX " << mapX << " rdirY " << mapY << std::endl;
    }
}