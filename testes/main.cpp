#include <iostream>
#include "../include/Interface.hpp"
#include "../include/Snake.hpp"

int main(){

    Interface i;
    Snake s(10, 15);
    i.showLevelStatus(s);

    return 0;
}