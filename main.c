#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

/* Header files explanation:
 * <windows.h> for Sleep() must be included first!
 * <conio.h> for kbhit() and getch(); these get keyboard inputs without waiting for an enter key press
 * <time.h> for clock() and CLOCKS_PER_SEC; need these to know how long to Sleep() for
 * <stdio.h> obvious reasons
 */

enum { B_WIDTH = 20, B_HEIGHT = 20, MAX_LENGTH = 20 };

void printBoard(char board[20][21]) {
	puts("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
	for (int i = 0; i < 20; ++i)
		printf("\xBA%s\xBA\n", board[i]);
	puts("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
}

int main() {
	enum Direction { RIGHT, DOWN, LEFT, UP } dir;
	char board[20][21] = {
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    " };	// 20 spaces
	char snakePos[MAX_LENGTH][2] = { {10, 10} };
	for (int i = 0; i < 1000; ++i) {
		int startClock = clock();
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printBoard(board);
		char c = kbhit() ? getch(), kbhit() ? getch() : 0 : 0;
		if (c)
			printf("Key read: %c", c);
		Sleep(100 - (clock() - startClock) / (CLOCKS_PER_SEC / 1000));
	}
	return 0;
}
