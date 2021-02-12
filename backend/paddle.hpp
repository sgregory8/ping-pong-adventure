//
//  paddle.hpp
//  ping
//
//  Created by Jessica Roberts on 09/02/2021.
//

#ifndef paddle_hpp
#define paddle_hpp

#include <stdio.h>

class Paddle {
public:
    int paddleX,paddleY,startX,startY;
    
    Paddle(int x = 0 ,int y = 0);
    void reset_paddle();
    void move_paddle(int user_direction);
};

#endif /* paddle_hpp */
