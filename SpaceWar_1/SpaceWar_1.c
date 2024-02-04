#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <stdbool.h>
//in the name of god :)
#pragma execution-charector-set("utf-8");
#pragma comment(lib, "winmm.lib")
#pragma warning(disable : 4996)

//color
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
void t_lred() {
	system("color 0C");
}
void t_red() {
	system("color 04");
}
void cdefualt() {
	system("color 07");
}

//tool
int hortizol(int i) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	return (columns - i) / 2;
}
int virtical(int i) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return (rows - i) / 2;
}
void cursor(int t) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	if (t == 0) cursorInfo.bVisible = FALSE; else cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//variable
struct pleyer
{
	char name[100];
	int point;
}p1, p2;
//program parts

void start();
int menu();
void sign_up();
void sign_in();

//main

int main() {
	SetConsoleOutputCP(65001);
	//PlaySoundA(TEXT("C:\\Users\\SAMSUNG\\Downloads\\Music\\Mouse-Click-01-m-FesliyanStudios.com.wav"),NULL,SND_FILENAME|SND_SYNC);
	cursor(0);
	//start();
	//sign_up();
	int choz;
	while (true)
	{
		choz = menu();
		switch (choz)
		{
		case 0:
			sign_up();
			break;
		case 1:
			sign_in();
			break;
		default:
			break;
		}
	}
}

int new_game() {
	int choz = 0;
	char c = 'w';
	int sp = hortizol(18);
	while (true) {
		switch (c) {
		case 'w':
			if (choz != 0)
				choz--;
			break;
		case 's':
			if (choz != 2)
				choz++;
			break;
		case 13:
			return choz;
		}
		if (c != 'y') {
			choz == 0 ? printf("%s", KRED) : printf("%s", KWHT);
			printf("%*s┌─┐┬┌─┐┌┐┌  ┬ ┬┌─┐\n", sp + 1, "");
			printf("%*s└─┐││ ┬│││  │ │├─┘\n", sp + 1, "");
			printf("%*s└─┘┴└─┘┘└┘  └─┘┴  \n", sp + 1, "");
			puts("");
			choz == 1 ? printf("%s", KRED) : printf("%s", KWHT);
			printf("%*s┌─┐┬┌─┐┌┐┌  ┬┌┐┌\n", sp + 2, "");
			printf("%*s└─┐││ ┬│││  ││││\n", sp + 2, "");
			printf("%*s└─┘┴└─┘┘└┘  ┴┘└┘\n", sp + 2, "");
			puts("");
			choz == 2 ? printf("%s", KRED) : printf("%s", KWHT);
			printf("%*s┌┬┐┌─┐┌┐┌┬ ┬\n", sp + 4, "");
			printf("%*s│││├┤ ││││ │\n", sp + 4, "");
			printf("%*s┴ ┴└─┘┘└┘└─┘\n", sp + 4, "");
		}
		c = _getch();
		if ((choz == 2 && c == 's') || (choz == 0 && c == 'w'))
			c = 'y';
		else
			system("cls");
	}
}
void start() {
	t_red();
	//PlaySoundA("D:\\Porograming\\SpaceWar\\cmake-build-debug\\music\\Wars.wav", NULL, SND_FILENAME | SND_ASYNC);
	int sp = virtical(6);
	for (int i = 0; i < sp; i++)
		printf("\n");
	sp = hortizol(strlen("███████╗██████╗  █████╗  ██████╗███████╗    ██╗    ██╗ █████╗ ██████╗    "));
	printf("%*s███████╗██████╗  █████╗  ██████╗███████╗    ██╗    ██╗ █████╗ ██████╗ \n", sp, "");
	printf("%*s██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝    ██║    ██║██╔══██╗██╔══██╗\n", sp, "");
	printf("%*s███████╗██████╔╝███████║██║     █████╗      ██║ █╗ ██║███████║██████╔╝\n", sp, "");
	printf("%*s╚════██║██╔═══╝ ██╔══██║██║     ██╔══╝      ██║███╗██║██╔══██║██╔══██╗\n", sp, "");
	printf("%*s███████║██║     ██║  ██║╚██████╗███████╗    ╚███╔███╔╝██║  ██║██║  ██║\n", sp, "");
	printf("%*s╚══════╝╚═╝     ╚═╝  ╚═╝ ╚═════╝╚══════╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝\n", sp, "");
	printf("%*s", 16, "");
	for (int i = 0; i < 48; i++) {
		printf("█ ");
		Sleep(100);
	}
	system("cls");
	cdefualt();

}
int menu()
{
	int choz = 0;
	char c = 'w';
	while (true) {
		switch (c) {
		case 'w':
			if (choz != 0)
				choz--;
			break;
		case 's':
			if (choz != 2)
				choz++;
			break;
		case 13:
			return new_game();
		}

		if (c != 'y') {
			choz == 0 ? printf("%s", KRED) : printf("%s", KWHT);
			int sp = hortizol(18);
			printf("%*s┌┐┌┌─┐┬ ┬  ┌─┐┌─┐┌┬┐┌─┐\n", sp, "");
			printf("%*s│││├┤ │││  │ ┬├─┤│││├┤ \n", sp, "");
			printf("%*s┘└┘└─┘└┴┘  └─┘┴ ┴┴ ┴└─┘\n", sp, "");
			printf("\n");
			choz == 1 ? printf("%s", KRED) : printf("%s", KWHT);
			printf("%*s┌─┐┌─┐┬  ┬┌─┐┌┬┐  ┌─┐┌─┐┌┬┐┌─┐\n", sp - 2, "");
			printf("%*s└─┐├─┤└┐┌┘├┤  ││  │ ┬├─┤│││├┤ \n", sp - 2, "");
			printf("%*s└─┘┴ ┴ └┘ └─┘─┴┘  └─┘┴ ┴┴ ┴└─┘\n", sp - 2, "");

			choz == 2 ? printf("%s", KRED) : printf("%s", KWHT);
			printf("%*s┌─┐─┐ ┬┬┌┬┐\n", sp + 5, "");
			printf("%*s├┤ ┌┴┬┘│ │ \n", sp + 5, "");
			printf("%*s└─┘┴ └─┴ ┴ \n", sp + 5, "");

		}
		c = _getch();
		if ((choz == 2 && c == 's') || (choz == 0 && c == 'w'))
			c = 'y';
		else
			system("cls");
	}
}
void sign_up() {
	char* st = NULL;
	char read[1000];
	cursor(1);
	printf("name:\nemail: \npassword(at least 8 char): \nre enter pass: \n");
	char c; int i = 0; char* re;
	while (true) {
		i = 0;
		gotoxy(6, 0);
		printf("%*s", 90, "");
		gotoxy(6, 0);
		while (true)
		{
			st = realloc(st, (1 + i) * sizeof(char));
			c = getchar();
			if (c == EOF || c == '\n')
			{
				st[i] = '\0'; break;
			}
			st[i++] = c;
		}
		bool check = true;
		FILE* fp = fopen("playerlist.csv", "r");
		while (!EOF || check == true)
		{
			fgets(read, sizeof(read), fp);
			if (read[0] == '\0')break;
			re = strtok(read, ",");
			if (!strcmp(re, st))
				check = false;
			read[0] = '\0';
		}
		if (check == true)
		{
			fclose(fp); break;
		}
	}
	FILE* fp = fopen("playerlist.csv", "a");

	fprintf(fp, "%s,", st);

	i = 0;
	gotoxy(7, 1);
	while (true)
	{
		st = realloc(st, (1 + i) * sizeof(char));
		c = getchar();
		if (c == EOF || c == '\n')
		{
			st[i] = '\0'; break;
		}
		st[i++] = c;
	}
	fprintf(fp, "%s,", st);

	i = 0;
	gotoxy(27, 2);
	while (true)
	{
		st = realloc(st, (1 + i) * sizeof(char));
		c = getchar();
		if (c == EOF || c == '\n' && i >= 8)
		{
			st[i] = '\0'; break;
		}
		else if (c != '\n')
			st[i++] = c;
		else
		{
			gotoxy(27 + i, 2);
		}
	}
	fprintf(fp, "%s,", st);

	gotoxy(16, 3);
	char* st2 = NULL;
	while (true)
	{
		i = 0;
		while (true)
		{
			st2 = realloc(st2, (1 + i) * sizeof(char));
			c = getchar();
			if (c == EOF || c == '\n')
			{
				st2[i] = '\0'; break;
			}
			st2[i++] = c;
		}
		if (!strcmp(st, st2))
			break;
		gotoxy(16, 3);
		printf("%*s", 900, "");
		gotoxy(16, 3);

	}
	fprintf(fp, "0\n");
	fclose(fp);
	free(st);
	free(st2);
	printf("%ssigned up successfully", KGRN);
	Sleep(500);
	system("cls");
	cursor(0);
}
void sign_in() {
	char read[1000], * st = NULL, * re = NULL, c; int i = 0;
	printf("user name: \npassword(if you forget the pass type 'forget'): ");
	gotoxy(10, 0);
	cursor(1);
	while (true) {
		i = 0;
		gotoxy(10, 0);
		printf("%*s", 90, "");
		gotoxy(10, 0);
		while (true)
		{

			st = realloc(st, (1 + i) * sizeof(char));
			c = getchar();
			if (c == EOF || c == '\n')
			{
				st[i] = '\0'; break;
			}
			st[i++] = c;
		}
		bool check = false;
		FILE* fp = fopen("playerlist.csv", "r");
		while (!EOF || check == false)
		{
			fgets(read, sizeof(read), fp);
			if (read[0] == '\0')break;
			re = strtok(read, ",");
			if (!strcmp(re, st))
				check = true;
			else
				read[0] = '\0';
		}
		re = strtok(NULL, ",");
		re = strtok(NULL, ",");
		if (check == true)
		{
			fclose(fp); break;
		}
	}
	while (true)
	{
		i = 0;
		gotoxy(strlen("password(if you forget the pass type 'forget'):"), 1);
		printf("%*s", 50, "");
		gotoxy(strlen("password(if you forget the pass type 'forget'):"), 1);
		while (true)
		{
			st = realloc(st, (1 + i) * sizeof(char));
			c = _getch();
			if (c != '\r' && c != 10 && c != 8)
				printf("*");
			if (c == EOF || c == '\r' && i >= 8)
			{
				st[i] = '\0'; break;
			}
			else if (c != '\r' && c != '\b')
			{
				st[i++] = c; st[i] = '\0';
			}
			else if (st == "forget")
			{

			}
			else if (c == 8)
			{
				if (i != 0)
					st[--i] = '\0';
				gotoxy(strlen("password(if you forget the pass type 'forget'):") + i, 1);
				printf("%*s", 50, "");
				gotoxy(strlen("password(if you forget the pass type 'forget'):") + i, 1);

			}
			else
			{
				gotoxy(strlen("password(if you forget the pass type 'forget'):") + i, 1);
			}

		}
		if (!strcmp(st, re))
		{

			printf("\n%ssigned in successfully", KGRN);
			Sleep(500); break;
		}
	}
	system("cls");
}