//
// Created by agar on 03/05/2020.
//

#include <game.hpp>

void        test_forward(const Map& map, Player& player)
{
    if (map.check(player.position_.x + player.direction_.x * 0.05,
            player.position_.y))
        player.position_.x += player.direction_.x * 0.05;
    if (map.check(player.position_.x,
            player.position_.y + player.direction_.y * 0.05))
        player.position_.y += player.direction_.y * 0.05;
}

void        test_backward(const Map& map, Player& player)
{
    if (map.check(player.position_.x - player.direction_.x * 0.05,
            player.position_.y))
        player.position_.x -= player.direction_.x * 0.05;
    if (map.check(player.position_.x,
            player.position_.y - player.direction_.y * 0.05))
        player.position_.y -= player.direction_.y * 0.05;
}

void        test_right(const Map& map, Player& player)
{
    if (map.check(player.position_.x + player.camera_.x * 0.05,
            player.position_.y))
        player.position_.x += player.camera_.x * 0.05;
    if (map.check(player.position_.x,
            player.position_.y + player.camera_.y * 0.05))
        player.position_.y += player.camera_.y * 0.05;
}

void        test_left(const Map& map, Player& player)
{
    if (map.check(player.position_.x - player.camera_.x * 0.05,
            player.position_.y))
        player.position_.x -= player.camera_.x * 0.05;
    if (map.check(player.position_.x,
            player.position_.y - player.camera_.y * 0.05))
        player.position_.y -= player.camera_.y * 0.05;
}

void        test_mouse(const Map& map, Player& player, const sf::RenderWindow& window)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);
    float   xxx = position.x - screenW/2;
    sf::Mouse::setPosition(sf::Vector2i(screenW/2, screenH/2), window);

    if (xxx != 0)
    {
        xxx /= 1000;

        double odx = player.direction_.x;
        double ocx = player.camera_.x;

        player.direction_.x = player.direction_.x * std::cos(xxx)
                - player.direction_.y * std::sin(xxx);
        player.direction_.y = odx * std::sin(xxx)
                + player.direction_.y * std::cos(xxx);

        player.camera_.x = player.camera_.x * std::cos(xxx)
                - player.camera_.y * std::sin(xxx);
        player.camera_.y = ocx * std::sin(xxx)
                + player.camera_.y * std::cos(xxx);
    }
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
            //std::cout << "if 1" << std::endl;
            stepX = -1;
            sideDistX = (player.position_.x - mapX) * deltaDistX;
        }
        else
        {
            //std::cout << "else 1" << std::endl;
            stepX = 1;
            sideDistX = (mapX + 1.0 - player.position_.x) * deltaDistX;
        }
        if (rdirY < 0)
        {
            //std::cout << "if 2" << std::endl;
            stepY = -1;
            sideDistY = (player.position_.y - mapY) * deltaDistY;
        }
        else
        {
            //std::cout << "else 2" << std::endl;
            stepY = 1;
            sideDistY = (mapY + 1.0 - player.position_.y) * deltaDistY;
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

        if (side == 0)
            perpWallDist = (mapX - player.position_.x + (1 - stepX) / 2) / rdirX;
        else
            perpWallDist = (mapY - player.position_.y + (1 - stepY) / 2) / rdirY;

        int lineHeight = (int)(screenH / perpWallDist);

        int drawS = -lineHeight / 2 + screenH / 2;
        if (drawS < 0)
            drawS = 0;
        int drawE = lineHeight / 2 + screenH / 2;
        if (drawE >= screenH)
            drawE = screenH - 1;

        lines.append(sf::Vertex(sf::Vector2f(x, drawS), sf::Color::Cyan));
        lines.append(sf::Vertex(sf::Vector2f(x, drawE), sf::Color::Red));

        //std::cout << " rdirX " << mapX << " rdirY " << mapY << std::endl;
    }
}