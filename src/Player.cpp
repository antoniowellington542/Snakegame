#include "../include/Player.hpp"
#include <utility>

bool Player::isVisited(int x, int y){
    for(int i=0;i<tested_positions.size();i++){
        if(tested_positions[i].first == x && tested_positions[i].second == y) {
            return true;
        }
    }
    // Adiciona nas posicões testadas
    std::pair<int, int> pos;
    pos.first = x;
    pos.second = y;
    tested_positions.push_back(pos);

    return false;
}

bool Player::path(int snake_x, int snake_y, int food_x, int food_y, std::vector<std::vector<std::string> > &map){
    std::pair<int,int> pos;
    
    // Encerra caso a comida seja encontrada
    if(snake_x==food_x && snake_y==food_y) {solution_path = safe_positions;return true;}
    
    // Verifica a posição abaixo
    if((map[snake_x+1][snake_y]==" " || map[snake_x+1][snake_y]=="c") && isVisited(snake_x+1, snake_y) == false){
      pos.first = snake_x+1;
      pos.second = snake_y;
      safe_positions.push_back(pos);
      path(snake_x+1, snake_y, food_x, food_y, map);
      }

    // Verifica a posição acima
    if((map[snake_x-1][snake_y]==" " || map[snake_x-1][snake_y]=="c") && isVisited(snake_x-1, snake_y) == false){ 
      pos.first = snake_x-1;
      pos.second = snake_y;
      safe_positions.push_back(pos);
      path(snake_x-1, snake_y, food_x, food_y, map);
      }

    // Verifica a posição direita
    if((map[snake_x][snake_y+1]==" " || map[snake_x][snake_y+1]=="c") && isVisited(snake_x, snake_y+1) == false){
       pos.first = snake_x;
      pos.second = snake_y+1;
      safe_positions.push_back(pos);
      path(snake_x, snake_y+1, food_x, food_y, map);
      }

    // Verifica a posição esquerda
    if((map[snake_x][snake_y-1]==" " || map[snake_x][snake_y-1]=="c") && isVisited(snake_x, snake_y-1) == false){
      pos.first = snake_x;
      pos.second = snake_y-1;
      safe_positions.push_back(pos);
      path(snake_x, snake_y-1, food_x, food_y, map);
      }

    return false;
}

float Player::distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void Player::possible_paths(int fx, int fy) {
  
  float back;
  float next;
  for (int i = 0; i < safe_positions.size(); i++) {
    back = distance(safe_positions[i].first, safe_positions[i].second, fx,  fy);
    next = distance(safe_positions[i+1].first, safe_positions[i+1].second, fx,  fy);
    
    if(back-next > 1 || back-next < -1){
      int posxback=safe_positions[i].first;
      int posyback=safe_positions[i].second;
      std::vector<std::pair<int, int> > aux;
      aux.push_back(std::make_pair(posxback, posyback));
      for(int j=i;j>= 0;j--){
        int posxnext=safe_positions[j].first;
        int posynext=safe_positions[j].second;
        if(distance(posxback,posyback,posxnext,posynext)==1){
          std::pair<int,int> a;
             aux.push_back(std::make_pair(posxnext, posynext));  
          posxback=posxnext;
          posyback=posynext;
        }
      }
      paths.push_back(aux);
    }

  int menor = 99999; 
  for (auto it: paths) {
      if(it.size() < menor){
        solution_path.clear();
        solution_path = it;
      }
  }
}

void Player::find_solution(std::vector<std::vector<std::string> > &map, int food_x, int food_y, int snake_x, int snake_y){
    path(snake_x, snake_y, food_x, food_y, map);
  
}

int Player::next_move(){
    //sorteia uma ação aleatória que não causa morte
    /*retorna uma ação aleatória entre 0 e 4*/
    return rand()%4;
}