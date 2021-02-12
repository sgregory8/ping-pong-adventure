//
//  board.cpp
//  ping
//
//  Created by Jessica Roberts on 07/02/2021.
//

#include "board.hpp"
#include "ball.hpp"
#include <iostream>

Board::Board(int width, int height){
    // Game Logic
    //1. get board size and add ball and paddles
    //2. set initial scores
    //3.
    //4.
    this->width = width;
    this->height=height;
    player1_score = 0;
    player2_score = 0;
    ball = Ball(width/2,height/2);
    paddle1 = Paddle(0, height/2);
    paddle2 = Paddle(width, height/2);
        
    }

void Board::loop(){
    print_score();
    while (player1_score <= 1 && player2_score <= 1){
        //1. Move the ball
        ball.move();
        print_game_state();
        //2. Move player 1 if requested
        //3. Move player 2 is requested
        //4. check for contact
        check_collision();
        //5. Check if ball off table
        check_point_won();
    }
}

void Board::check_collision(){
    // if ballX,ballY is on/in paddle region of either -> collided with paddle
    // if ballY = 0 or height -> collided with walls
    if (ball.get_ballY() == 0 || ball.get_ballY() == height) {
        std::cout << "COLLISION WITH WALL!!!\n";
        ball.change_direction(0);
    }
}

void Board::check_point_won(){
    //if ballX = 0 -> player 2 wins
    if (ball.get_ballX() <= 0){
        std::cout << "Player 2 Scores!\n";
        player2_score++;
        print_score();
        std::cout << "console:: resetting board\n";
        ball.reset_ball();
        paddle1.reset_paddle();
        paddle2.reset_paddle();
    }
    // if ballX = width -> player 1 wins
    if (ball.get_ballX() >= width) {
        std::cout << "Player 1 Scores!\n";
        player1_score++;
        print_score();
        std::cout << "console:: resetting board\n";
        ball.reset_ball();
        paddle1.reset_paddle();
        paddle2.reset_paddle();
    }

}

void Board::print_game_state(){
    std::cout << "Ball at: " << ball.get_ballX() << "," << ball.get_ballY() << " \n";
}

void Board::print_score(){
    std::cout << "------------------------------------ \n";
    std::cout << "Player 1: " << player1_score << "   -     : Player 2: " << player2_score << " \n";
    std::cout << "------------------------------------ \n";
}


