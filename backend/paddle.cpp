//
//  paddle.cpp
//  ping
//
//  Created by Jessica Roberts on 09/02/2021.
//

#include "paddle.hpp"

Paddle::Paddle(int startX, int startY){

    paddleX = startX;
    paddleY = startY;
    this->startX = startX;
    this->startY = startY;
}

void Paddle::reset_paddle(){
    paddleX=startX;
    paddleY=startY;
}

void Paddle::move_paddle(int direction){
    // direction 0 = UP
    // direction 1 = DOWN
    switch (direction) {
        case 0:
            paddleY++;
            break;
        case 1:
            paddleY--;
            break;
        default:
            break;
    }
}
