#include "utils.h"

#include <iostream>
#include <sstream>
#include "boardc4.h"
#include "boardc5.h"
#include "boardothello.h"
#include "boardblocks.h"

Game parse_game(const char *arg) {
    std::string string(arg);
    if (string=="connect4") return BOARDC4;
    else if (string=="connect5") return BOARDC5;
    else if (string=="othello") return OTHELLO;
    else if (string=="blocks") return BLOCKS;
    else return OTHELLO;
}

float parse_float(const char *str,float defvalue) {
    std::stringstream ss(str);
    float v = 0;
    ss >> v;

    if (ss.fail()) return defvalue;

    return v;
}

Board *choose_game(Game game) {
	std::cout<<"let's play ";
	switch (game) {
	case BOARDC4:
		std::cout<<"connect 4"<<std::endl;
		return new BoardC4();
	case BOARDC5:
		std::cout<<"connect 5"<<std::endl;
		return new BoardC5();
	case OTHELLO:
		std::cout<<"othello"<<std::endl;
		return new BoardOthello();
    case BLOCKS:
        std::cout<<"blocks"<<std::endl;
        return new BoardBlocks(20,14,true);
	}
}

Player *play_game(Player *player_a,Player *player_b,Board *board,int max_move) {
    assert(board);
    assert(player_a);
    assert(player_b);

    player_a->print();
    std::cout<<" VS ";
    player_b->print();
    std::cout<<std::endl;

	//FIXME check if there is a player one and a player two
	Player *player_current=player_a;
	Player *winner=NULL;
	Move *last_move=NULL;

    int k=0;
	while (k<max_move or not max_move) {
		board->print();

		//get the move
		Move *move=player_current->get_move(board,last_move);
		if (not move) break;
        if (last_move) delete last_move;
		last_move=move;

		//actually play the move
		board->play_move(*move);

		//check for win
		Token winner_token=board->check_for_win();
		if (winner_token!=NOT_PLAYED) {
			if (winner_token==player_a->get_player()) winner=player_a;
			else winner=player_b;
			break;
		}

		//switch player
		if (player_current==player_a) player_current=player_b;
		else player_current=player_a;

        k++;
	}
    if (last_move) delete last_move;

    board->print();
	if (winner) {
		std::cout<<"winner: ";
		winner->print();
	} else {
		std::cout<<"draw";
	}
	std::cout<<std::endl;

	return winner;
}