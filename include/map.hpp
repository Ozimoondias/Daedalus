//
// Created by agar on 03/05/2020.
//

#ifndef DAEDALUS_MAP_HPP
#define DAEDALUS_MAP_HPP

#include <array>

struct  Map
{
    std::array<int, 10*10> map_
    {
            {
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1
            }
    };

    void    draw(const int& player_pos)
    {
        for(int i = 0; i < map_.size() ; i++) {
            if (i == player_pos)
                std::cout << "# ";
            else
                {
                    if (i % 10 == 0)
                        std::cout << std::endl;
                    std::cout << map_[i] << " ";
                }
        }
        std::cout << std::endl;
    }

    bool    check(const int& player_pos)
    {
        return map_[player_pos] != 1;
    }

};

inline  std::ostream& operator<<(std::ostream& os,
        const Map& map)
{
    for(int i = 0; i < map.map_.size() ; i++)
    {
        if (i % 10 == 0)
            os << std::endl;
        os << map.map_[i] << " ";
    }

    return os;
}

#endif //DAEDALUS_MAP_HPP
