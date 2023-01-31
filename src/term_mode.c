/*
** EPITECH PROJECT, 2018
** Tetris
** File description:
** Term mode
*/

#include <unistd.h>
#include <term.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int switch_mode(int on)
{
	static struct termios oldT;
	struct termios newT;

	if (on) {
		tcgetattr(STDIN_FILENO, &oldT);
		tcgetattr(STDIN_FILENO, &newT);
		newT.c_lflag &= ~ECHO;
		newT.c_lflag &= ~ICANON;
		tcsetattr(STDIN_FILENO, TCSANOW, &newT);
	} else
		tcsetattr(STDIN_FILENO, TCSANOW, &oldT);
	return (0);
}

int non_blocking_read(int on)
{
	static struct termios oldT;
	struct termios newT;

	if (on) {
		if (tcgetattr(STDIN_FILENO, &oldT) == -1)
			return (-1);
		if (tcgetattr(STDIN_FILENO, &newT) == -1)
			return (-1);
		newT.c_lflag &= ECHO;
		newT.c_lflag &= ~ICANON;
		newT.c_cc[VMIN] = 0;
		newT.c_cc[VTIME] = 1;
		return (tcsetattr(STDIN_FILENO, TCSANOW, &newT));
	} else
		return (tcsetattr(STDIN_FILENO, TCSANOW, &oldT));
}
