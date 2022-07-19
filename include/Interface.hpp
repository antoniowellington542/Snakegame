#ifndef Interface_hpp
#define Interface_hpp

#include "Snake.hpp"

#include <iostream>
#include <vector>
#include <iterator>

class Interface{
    public:

        /**
         * @brief Exibi os status da snake e do level
         */
        void showLevelStatus(Snake s);

        /**
         * @brief Renderiza o mapa na tela
         */
        void renderMap(std::vector<std::vector<std::string> > map);

        /**
         * @brief Renderiza o mapa e os status da partida
         * 
         */
        void renderView(std::vector<std::vector<std::string> > &map, Snake s);

};
#endif // Interface_hpp