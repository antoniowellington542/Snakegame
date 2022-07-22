#ifndef Level_hpp
#define Level_hpp
#include <iostream>
#include <string>
#include <vector>
#include "Snake.hpp"

class Level{
    private:
      int m_x;
      int m_y;
      int m_comidas;
      int m_level_atual;
      std::string m_levels_file; //<! arquivo com os níveis do jogo
      std::vector<std::vector<std::string> > m_levels; //<! vector contendo os labirintos, pode ser interpretado como uma matriz 
    public:
      Level(std::string levels_file, Snake &m_snake);
      void generateFood(); 
      std::vector<std::string> * getMap();
      bool updateLevel(Snake &m_snake);
};
#endif //Level_hpp