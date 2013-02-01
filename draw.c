// +----------------------------------------------------------------+
// | cSnake                                                         |
// +----------------------------------------------------------------+

/**
 * Port of my python snake to c - memory leaks included :)
 *
 * @author  Christopher Marchfelder <marchfelder@googlemail.com>
 * @license GPL
 */
#include <stdio.h>
#include <ncurses.h>

#include "globals.h"
#include "linked_list.h"
#include "draw.h"

// I don't get this... why no extern? ARGH!
llnode *snake;
coord  apple;

void draw_init() {
	WINDOW *win = initscr();

	// We don't want to wait for the EOF && getch shall not block the terminal
	cbreak();
	timeout(0);

	// Without keypad enabled KEY_* and getch won't match
	keypad(win, TRUE);

	// No cursor
	curs_set(0);
}

void draw_shutdown() {
	endwin();
}

void draw_borders() {
	// Draw borders
	mvhline(0, 0, ACS_PLMINUS, width);
	mvhline(height, 0, ACS_PLMINUS, width);

	mvvline(0, 0, ACS_PLMINUS, height+1);
	mvvline(0, width, ACS_PLMINUS, height+1);
}

void draw_snake() {
	// Ssssssnake
	llnode *HEAD = snake;
	while(HEAD != NULL) {
		mvaddch(HEAD->part.y, HEAD->part.x, TOKEN_SNAKE);
		HEAD = HEAD->next;
	}
}

void draw_apple() {
	// Of every tree of the garden thou mayest freely eat
	// But of the tree of the knowledge of good and evil, thou shalt not eat of it
	// (FYI it was a apple)
	mvaddch(apple.y, apple.x, TOKEN_APPLE);
}

void draw_game_over() {

}

void draw() {
	// We don't want to draw the whitespace's
	erase();

	draw_borders();

	if (1) {
		draw_snake();
		draw_apple();
	} else {
		// do something else
	}

	refresh();
}
