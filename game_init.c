//
// Created by Lili on 26/03/2020.
//

//
// Created by Lili on 24/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_init.h"

// framework of game taken from focus week 2 lab

//function which initialises players
void initialize_players(player players[PLAYERS_NUM])
{

    // implement here the functionality to initialize the players
    //each player has a color, pieces which they captured from their opponent,
    //a name,pieces they kept and if its there turn or not.
    players[0].player_color = RED;
    players[1].player_color = GREEN;

    players[0].piecesPlayerCaptured = 0;
    players[1].piecesPlayerCaptured = 0;

    players[0].piecesPlayerOwnsReserve = 0;
    players[1].piecesPlayerOwnsReserve = 0;

    players[0].piecesPlayerOwns = 18;
    players[1].piecesPlayerOwns = 18;

    players[0].playerTurn = true;
    players[1].playerTurn = false;
    printf("Please enter a name for Player 1.\n ");
    scanf("%s",&players[0].playerName);
    printf("Please enter a name for Player 2.\n ");
    scanf("%s",&players[1].playerName);
    printf("Player 1 name: %s \n player 1 color: %d (0 = red,1 = green)\n ",players[0].playerName,players[0].player_color);
    printf("Player 2 name: %s \n player 2 color: %d (0 = red,1 = green)\n",players[1].playerName,players[1].player_color);

}

//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s)
{
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s)
{
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s)
{
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s)
{
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE])
{

    for(int i=0; i< BOARD_SIZE; i++)
    {

        for(int j=0; j< BOARD_SIZE; j++)
        {
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else
            {
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else
                {
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else
                        set_green(&board[i][j]);
                }
            }
        }


    }


}

