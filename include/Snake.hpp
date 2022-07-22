#ifndef Snake_hpp
#define Snake_hpp
#include <iostream>
#include <vector>

class Snake{
    private:
      int score;
      int s_body;
      int lifes;

    public:
      Snake(int x, int y);
      int showScore();
      void increaseScore();
      void lostLife();
      int showLife();
      void increaseBody();
};
#endif //Snake_hpp