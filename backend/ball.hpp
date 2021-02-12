//
//  ball.hpp
//  ping
//
//  Created by Jessica Roberts on 07/02/2021.
//

#ifndef ball_hpp
#define ball_hpp

#include <stdio.h>
#include <string>

enum Direction{UP_LEFT,UP_RIGHT,DOWN_LEFT,DOWN_RIGHT};

class Ball {
public:
    int ballX,ballY,startX,startY;
    Direction direction;
    Ball(int x = 0 ,int y = 0);
    void move();
    void change_direction(int collision);
    void random_direction();
    void reset_ball();
    int get_ballX();
    int get_ballY();
    
};


#endif /* ball_hpp */
