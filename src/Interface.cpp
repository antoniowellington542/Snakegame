#include "../include/Interface.hpp"

void Interface::showLevelStatus(Snake s){

    std::cout << "Lives: ";
    for(int i=0;i<s.showLife();i++){
        std::cout << "❤️  ";
    }
    std::cout << " | ";
    std::cout << "Score: " << s.showScore() << " |";
}

void Interface::renderMap(std::vector<std::vector<std::string> > map){
    for(auto it: map){
        for(auto it2: it){
            std::cout << it2;
        }
        std::cout << std::endl;
    }
}

void Interface::renderView(std::vector<std::vector<std::string> > &map, Snake s){
    system("clear");
    showLevelStatus(s);
    renderMap(map);
}