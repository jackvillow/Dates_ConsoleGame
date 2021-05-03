/*
	 By Jackvillow
	 		*/

#include <stdio.h>
#include <windows.h>
#include "windows.h"
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct dates {
	int d;
	int m;
	int y;
}dates;


int x, y;


void adminsettings() {
	setlocale(LC_ALL, "Rus");
	system("mode con cols=120 lines=40");
	system("title DATES");
	dates.d = 1;
	dates.m = 1;
	
} 


void presentation() {
	char txt[] = "ИГРА ДАТЫ";
	for(int i = 0; i<strlen(txt); i++)
	{
		Sleep(150);
		printf("%c", txt[i]);
	}
	Sleep(500);
	printf("\n");
	printf("Введите год игры.\n");
	scanf("%i", &dates.y);
}



void adddate() {
	x = dates.d; y = dates.m;
	scanf("%d %d", &dates.d, &dates.m);
}

bool proverka(int day, int mon) {
	switch (mon) {
	case 1: if (day > 31) return false;else return true;

	case 2: if ((dates.y % 100 != 0) && (dates.y % 4 == 0) && (dates.d <= 29)) return true;
		  else if ((dates.y % 100 == 0) && (dates.y % 400 == 0) && (dates.d <= 29)) return true;
		  else if (dates.d < 29) return true;
		  else return false;

	case 3: if (day > 31) return false; else return true;
	case 4: if (day > 30) return false; else return true;
	case 5: if (day > 31) return false; else return true;
	case 6: if (day > 30) return false; else return true;
	case 7: if (day > 31) return false; else return true;
	case 8: if (day > 31) return false; else return true;
	case 9: if (day > 30) return false; else return true;
	case 10: if (day > 31) return false; else return true;
	case 11: if (day > 30) return false; else return true;
	case 12: if (day > 31) return false; else return true;
	default: return false;
	}
}

void whichdate() {
	switch (dates.d) {
	case 20: y = 1 - dates.m; dates.m += y; break;
	case 21: y = 2 - dates.m; dates.m += y; break;
	case 22: y = 3 - dates.m; dates.m += y; break;
	case 23: y = 4 - dates.m; dates.m += y; break;
	case 24: y = 5 - dates.m; dates.m += y; break;
	case 25: y = 6 - dates.m; dates.m += y; break;
	case 26: y = 7 - dates.m; dates.m += y; break;
	case 27: y = 8 - dates.m; dates.m += y; break;
	case 28: y = 9 - dates.m; dates.m += y; break;
	case 29: y = 10 - dates.m; dates.m += y; break;
	case 30: y = 11 - dates.m; dates.m += y; break;
	case 31: y = 12 - dates.m; dates.m += y; break;
	}
}

void computer() {
	switch (dates.m) {
	case 1: if (dates.d < 20) { x = 20 - dates.d; dates.d += x; }
		  else if (dates.d == 20) dates.m++; else whichdate(); break;
	case 2: if (dates.d < 21) { x = 21 - dates.d; dates.d += x; }
		  else if (dates.d == 21) dates.m++; else whichdate(); break;
	case 3: if (dates.d < 22) { x = 22 - dates.d; dates.d += x; }
		  else if (dates.d == 22) dates.m++; else whichdate(); break;
	case 4: if (dates.d < 23) { x = 23 - dates.d; dates.d += x; }
		  else if (dates.d == 23) dates.m++;  else whichdate(); break;
	case 5: if (dates.d < 24) { x = 24 - dates.d; dates.d += x; }
		  else if (dates.d == 24) dates.m++; else whichdate(); break;
	case 6: if (dates.d < 25) { x = 25 - dates.d; dates.d += x; }
		  else if (dates.d == 25) dates.m++;  else whichdate(); break;
	case 7: if (dates.d < 26) { x = 26 - dates.d; dates.d += x; }
		  else if (dates.d == 26) dates.m++; else whichdate(); break;
	case 8: if (dates.d < 27) { x = 27 - dates.d; dates.d += x; }
		  else if (dates.d == 27) dates.m++; else whichdate(); break;
	case 9: if (dates.d < 28) { x = 28 - dates.d; dates.d += x; }
		  else if (dates.d == 28) dates.m++; else whichdate(); break;
	case 10: if (dates.d < 29) { x = 29 - dates.d; dates.d += x; }
		   else if (dates.d == 29) dates.m++; else whichdate(); break;
	case 11: if (dates.d < 30) { x = 30 - dates.d; dates.d += x; }
		   else if (dates.d == 30) dates.m++; else whichdate(); break;
	case 12:if (dates.d < 31) { x = 31 - dates.d; dates.d += x; }
		   else if (dates.d == 31) dates.d++;  else whichdate(); break;
	}
	
	system("cls");

	if (dates.d == 31 && dates.m == 12) {printf("Сейчас: День %i Месяц %i\n", dates.d, dates.m, dates.y);
		printf("Победила Машина!");
		 exit(1);
	}
}



void gamecomp1() {
	system("cls");
	if (dates.d == 31 && dates.m == 12) {
		printf("Победила Машина!"); exit(1);
	}
	while (dates.d != 31 || dates.m != 12) {
		printf("Сейчас: День %i Месяц %i Год %i", dates.d, dates.m, dates.y);
		printf("\nДобавьте месяц или день в формате <День> <Месяц>.\n");
		adddate();
		if ((dates.d > x) && (dates.m > y)) {
			printf("Неправильная Дата");
			dates.d = x; dates.m = y;
			Sleep(500);
			gamecomp1();
		}
		if ((dates.d < x) || (dates.m < y)) {
			printf("Неправильная Дата");
			dates.d = x; dates.m = y;
			Sleep(500);
			gamecomp1();
		}
	if (proverka(dates.d,dates.m)== false){
		printf("Неправильная дата. Введите еще раз.");
		Sleep(1000);
		dates.d = x; dates.m = y;
		gamecomp1();
	}
	if (dates.d == 31 && dates.m == 12) {
		printf("Вы Победили!"); exit(1);
	}
	computer();
	}
}


void gamecomp2() {
	system("clc");
	computer();
	gamecomp1();
}


void start() {
	system("cls");
	printf("Приветствую Вас в моей игре <<Даты>>. Для начала Вам нужно выбрать каким по счету Вы будете ходить. \nНажмите <1> если будете ходить первым, <2> - вторым.");

	if (_getch() == '1') {
		printf("\nВы ходите первым.");
		Sleep(1000);
		gamecomp1();
	}
	else if (_getch() == '2') {
		printf("\nВы ходите вторым.");
		Sleep(1000);
		gamecomp2();
	}

}




int main() {
	adminsettings();
	presentation();
	start();
	system("cls");
	printf("Сейчас: День %i Месяц %i", dates.d, dates.m,dates.y);
	

}
