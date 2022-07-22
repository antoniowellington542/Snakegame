#include "../include/Snake.hpp"

Snake::Snake(int x, int y){
  score = 0;
  lifes = 5;
}

int Snake::showScore(){
  return score;
}

void Snake::increaseScore(){
  score++;
}

void Snake::lostLife(){
  lifes--;
}

int Snake::showLife(){
  return lifes;
}

void Snake::increaseBody(){
  s_body++;
}