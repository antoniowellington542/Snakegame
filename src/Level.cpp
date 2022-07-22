#include <iostream>
#include "../include/Level.hpp"

Level::Level(std::string levels_file, Snake &m_snake){
  //carrega o nivel ou os níveis
    this->m_levels_file = levels_file;
    this->fase_atual = 0;
    ifstream levelFile(levels_file);
    int levels = 0;
    string line;
    int x, y, comidas, pos, lineCount;
    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
          if( std::isdigit(line[0]) != 0 ){

            if(levels == 0){
              int pos = line.find(' ');
              x = stoi(line.substr(0, pos));
              line.erase(0, pos);
              
              int pos = line.find(' ');
              x = stoi(line.substr(0, pos));
              line.erase(0, pos);
    
              int pos = line.find(' ');
              comida = stoi(line.substr(0, pos));
              line.erase(0, pos);
    
              this->m_x = x;
              this->m_y = y;
              this->m_comidas = comidas;    
            }
            
            levels++;
            lineCount = 0;
          } else {
            
            // if(line.find("V") != string::npos){
            //   x = lineCount-1; 
            //   y = line.find("V");
            //   Snake m_snake(x, y);
            //   std::cout << "X = " << x << ", Y = " << y << "."<< std::endl;
            // }
            this->m_levels[levels-1][lineCount].push_back(line);
            
            lineCount++;            
          }  
        }
    }
};

void Level::generateFood(){
  int x, y;
  int contador = 0;
  std::srand(time(0));
  while(this->m_comidas != contador){
    x = std::rand() * this->m_x;
    y = std::rand() * this->m_y;
    if(this->m_comidas != contador){
      if(this->m_levels[this->m_level_atual][x][y] == " "){
          this->m_levels[this->m_level_atual][x][y] = "C";
          contador++;
      }      
    } else {
      break;
    } 
  }
};

std::vector<std::string> * getMap(){
  return this->m_levels[this->m_level_atual];
};

/*
Se existir, o método atualiza os atributos para o próximo nível e retorna true, se não houver uma fase seguinte, então o método só retorna false
*/

bool updateLevel(Snake &m_snake){
  //carrega o nivel ou os níveis
    ifstream levelFile(this->m_levels_file);
    this->fase_atual++;
    int levels = 0;
    string line;
    int x, y, comidas, pos;
    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
          if( std::isdigit(line[0]) != 0 ){

            if( levels == this->fase_atua ){
              int pos = line.find(' ');
              x = stoi(line.substr(0, pos));
              line.erase(0, pos);
              
              int pos = line.find(' ');
              x = stoi(line.substr(0, pos));
              line.erase(0, pos);
    
              int pos = line.find(' ');
              comida = stoi(line.substr(0, pos));
              line.erase(0, pos);
    
              this->m_x = x;
              this->m_y = y;
              this->m_comidas = comidas;

              break;
            }

            levels++;
          } 


        }
    }
};