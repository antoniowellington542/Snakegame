#ifndef Player_hpp
#define Player_hpp

#include <vector>

class Player{
    private:
        std::vector<std::pair<int,int> > tested_positions;
        std::vector<std::pair<int,int> > safe_positions;
        std::vector<std::pair<int, int> > solution_path;
    public:
        bool isVisited(int x, int y);
        bool path(int snake_x, int snake_y, int food_x, int food_y, std::vector<std::vector<std::string> > &map);
        void find_solution(std::vector<std::vector<std::string> > &map, int food_x, int food_y, int snake_x, int snake_y);
        /**
         * Retorna a próxima ação do jogador um mapeamento de 0-3, representando ir para esquerda, cima, direita, baixo
         * @return a próxima ação do jogador
         **/
        int next_move();
};
#endif //Player_hpp