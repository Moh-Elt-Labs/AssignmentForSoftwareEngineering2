//
// Created by moham on 29/04/2020.
//

#ifndef FOCUS_GAME_MECHANICS_H
#define FOCUS_GAME_MECHANICS_H

#endif //FOCUS_GAME_MECHANICS_H


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//Function to create the player turns
void player_turns(player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE]);

//Function to preform player moves
void player_moves(player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z);

bool check_piece_possible(player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z,int i,int j,bool notChosenPiece);

bool check_move_possible(player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z,int i, int j,bool chosenPlaceToMove);

struct piece * pop(square board[BOARD_SIZE][BOARD_SIZE], int i, int j);
struct piece * pop_stack(square board[BOARD_SIZE][BOARD_SIZE], int i, int j);

struct piece * push(int value,square board[BOARD_SIZE][BOARD_SIZE], int k, int l);
struct piece * push_stack(square board[BOARD_SIZE][BOARD_SIZE], int k, int l,int i,int j);
