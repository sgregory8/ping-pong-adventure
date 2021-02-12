//
//  ball.cpp
//  ping
//
//  Created by Jessica Roberts on 07/02/2021.
//

#include "ball.hpp"
#include <cstdlib>
#include <string>
#include <iostream>




Ball::Ball(int startX, int startY){
    // 1. Ball starts in center of board
    // 2. Balls direction gets randomly set
    // 3. ball moves one pixel
    // 4. If ball hits something:
    // 4a. if ball hits wall -> reflect direction
    // 4b. if ball hits paddle -> reflect direction + action
    // 4c. if ball hits player side -> end round
    ballX = startX;
    ballY = startY;
    this->startX = startX;
    this->startY = startY;
    random_direction();
}

void Ball::change_direction(int collision){
    //Changes the direction on collision
    std::cout << "input is " << collision << " \n";
    if (collision == 0){
        std::cout << "changing direction... \n";
        switch(direction){
            case UP_LEFT:
                direction = DOWN_LEFT;
            case UP_RIGHT:
                direction = DOWN_RIGHT;
            case DOWN_LEFT:
                direction = UP_LEFT;
            case DOWN_RIGHT:
                direction = UP_RIGHT;
            break;
        }
    }
    else {
        switch(direction){
            case UP_LEFT:
                direction = UP_RIGHT;
                break;
            case UP_RIGHT:
                direction = UP_LEFT;
                break;
            case DOWN_LEFT:
                direction = DOWN_RIGHT;
                break;
            case DOWN_RIGHT:
                direction = DOWN_LEFT;
                break;
            default:
                std::cout << "problems changing dir! \n";
                break;
        }
    }
}

void Ball::random_direction(){
    //randomises starting direction of ball
    direction = (Direction)((rand() % 3) + 1);
}

void Ball::reset_ball(){
    ballX = startX;
    ballY = startY;
    random_direction();
}

void Ball::move(){
    switch(direction) {
            case UP_LEFT:
                ballX++;
                ballY++;
                break;
            case UP_RIGHT:
                ballX--;
                ballY++;
                break;
            case DOWN_LEFT:
                ballX++;
                ballY--;
                break;
            case DOWN_RIGHT:
                ballX--;
                ballY--;
                break;
        default:
            std::cout << "problems moving! \n";
            break;
    }
}

int Ball::get_ballX(){
    return ballX;
}

int Ball::get_ballY(){
    return ballY;
}


    
    

