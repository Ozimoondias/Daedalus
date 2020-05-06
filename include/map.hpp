//
// Created by agar on 03/05/2020.
//

#ifndef DAEDALUS_MAP_HPP
#define DAEDALUS_MAP_HPP

#include <array>

struct  Map
{
    int map_[10][10]
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    void    draw(const int& pos_x, const int& pos_y)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == pos_x && j == pos_y)
                    std::cout << "# ";
                else
                    std::cout << map_[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    bool    check(const int& x, const int& y) const
    {
        return map_[x][y] != 1;
    }

};

inline  std::ostream& operator<<(std::ostream& os,
        const Map& map)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            os << map.map_[i][j] << " ";
        os << std::endl;
    }
    return os;
}

#endif //DAEDALUS_MAP_HPP
