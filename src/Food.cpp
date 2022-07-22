#include <iostream>
#include "Level.hpp"

Food(int comidas){
  this->m_comidas = comidas;
}

void Food::generateFood(int &size_x, int &size_y, std::vector<std::string> &m_maze){
  int x, y;
  int contador = 0;
  std::srand(time(0));
  while(this->m_comidas != contador){
    x = std::rand() * size_x;
    y = std::rand() * size_y;
    if(this->m_comidas != contador){
      if(m_maze[x][y] == " "){
          m_maze[x][y] = "C";
          contador++;
      }      
    } else {
      break;
    } 
  }
}

