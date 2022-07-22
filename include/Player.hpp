#ifndef Player_hpp
#define Player_hpp

#include <vector>
#include <cmath>

class Player{
    private:
        std::vector<std::pair<int,int> > tested_positions;
        std::vector<std::pair<int,int> > safe_positions;
        std::vector<std::pair<int, int> > solution_path;
        std::vector<std::vector<std::pair<int, int> > > paths;
    public:
        bool isVisited(int x, int y);
        bool path(int snake_x, int snake_y, int food_x, int food_y, std::vector<std::vector<std::string> > &map);
        void find_solution(std::vector<std::vector<std::string> > &map, int food_x, int food_y, int snake_x, int snake_y);
        void possible_paths(int fx, int fy);
        float distance(int x1, int y1, int x2, int y2);
        /**
         * Retorna a próxima ação do jogador um mapeamento de 0-3, representando ir para esquerda, cima, direita, baixo
         * @return a próxima ação do jogador
         **/
        int next_move();
};
#endif //Player_hpp