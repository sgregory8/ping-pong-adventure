//
//  board.hpp
//  ping
//
//  Created by Jessica Roberts on 07/02/2021.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include "ball.hpp"
#include "paddle.hpp"

class Board {
public:
    int width,height,player1_score,player2_score;
    Ball ball;
    Paddle paddle1,paddle2;
    
    Board(int width, int height); //Constructor
    void loop();
    void check_collision();
    void check_point_won();
    void print_game_state();
    void print_score();
};


#endif /* board_hpp */
