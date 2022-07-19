#ifndef Food_hpp
#define Food_hpp
#include <iostream>

class Level{
    private:
      int m_comidas;
    public:
      //Food(int comidas);
      void generateFood(int &size_x, int &size_y, std::vector<std::string> &m_maze);
};
#endif //Food_hpp