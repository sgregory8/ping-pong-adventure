//
//  main.cpp
//  ping
//
//  Created by Jessica Roberts on 07/02/2021.
//

#include <iostream>
#include "board.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "3...2...1...Lets Play!\n";
    Board game = Board(100,50);
    game.loop();
    return 0;
}
