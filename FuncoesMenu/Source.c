#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#define CITYCOUNT 42

char codigo;
int map[CITYCOUNT][CITYCOUNT] = {
	//{   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,  17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,  41}
	/*0 = "SAN FRANCISCO"*/       {   0,  640,    0,  380,    0,    0,    0,  300,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*1 = "PORTLAND"*/            { 640,    0,  170,    0,    0,    0,    0,  580,  420,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*2 = "SEATLE"*/              {   0,  170,    0,    0,    0,    0,    0,    0,  500,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*3 = "LOS ANGELES"*/         { 380,    0,    0,    0,  120,  160,    0,    0,    0,    0,    0,    0,    0,    0,    0,  270,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*4 = "SAN DIEGO"*/           {   0,    0,    0,  120,    0,  140,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  350,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*5 = "PALM SPRINGS"*/        {   0,    0,    0,  160,  140,    0,  440,  780,    0,    0,    0,    0,    0,    0,    0,  290,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*6 = "GRAND CANYON"*/        {   0,    0,    0,    0,    0,  440,    0,    0,    0,    0,    0,    0,    0,    0,    0,  470,  360,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*7 = "LAKE TAHOE"*/          { 300,  580,    0,    0,    0,  780,    0,    0,  420,    0,    0,    0,    0,    0,  520,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*8 = "BOISE"*/               {   0,  420,  500,    0,    0,    0,    0,  420,    0,  670,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*9 = "YELLOWSTONE"*/         {   0,    0,    0,    0,    0,    0,    0,    0,  670,    0,  930,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 1340,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*10 = "DENVER"*/             {   0,    0,    0,    0,    0,    0,    0,    0,    0,  930,    0,  120,  170,  160,  530,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  540,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*11 = "COLORADO SPRINGS"*/   {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  120,    0,  180,    0,    0,    0,    0,   0,    0,  730,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*12 = "ASPEM"*/              {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  170,  180,    0,   80,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*13 = "VAIL"*/               {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  160,    0,   80,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*14 = "SALT LAKE CITY"*/     {   0,    0,    0,    0,    0,    0,    0,  520,    0,    0,  530,    0,    0,    0,    0,  420,  660,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*15 = "LAS VEGAS"*/          {   0,    0,    0,  270,    0,  290,  470,    0,    0,    0,    0,    0,    0,    0,  420,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*16 = "PHOENIX"*/            {   0,    0,    0,    0,  350,    0,  360,    0,    0,    0,    0,    0,    0,    0,  660,    0,    0,  350,  990, 1070,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*17 = "ALBUQUERQUE"*/        {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  350,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*18 = "SAN ANTONIO"*/        {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  990,   0,    0,  280,    0,  310,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*19 = "DALLAS"*/             {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  730,    0,    0,    0,    0, 1070,   0,  280,    0,    0,  250,    0,    0,    0,    0,  790,    0,  320,  550,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*20 = "ST LOUIS"*/           {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  290,  400,  250,    0,    0,    0,  300,    0,  250,    0,    0,    0,    0,    0,   0},
	/*21 = "HOUSTON"*/            {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,  310,  250,    0,    0,  530,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*22 = "NOVA ORLEANS"*/       {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,  530,    0,  860,    0,  640,  470,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*23 = "MIAMI"*/              {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,  860,    0,   30,  230,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*24 = "FORT LAUDERDALE"*/    {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,   30,    0,  180,    0,    0,    0,    0,    0,  470,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*25 = "ORLANDO"*/            {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,  640,  230,  180,    0,  440,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*26 = "ATLANTA"*/            {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,  790,    0,    0,  470,    0,    0,  440,    0,  390,    0,    0,    0,    0,    0,    0,    0,    0,  560,    0,    0,    0,    0, 240},
	/*27 = "MEMPHIS"*/            {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,  290,    0,    0,    0,    0,    0,  390,    0,  140,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 210},
	/*28 = "LITTLE ROCK"*/        {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,  320,  400,    0,    0,    0,    0,    0,    0,  140,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*29 = "KANSAS CITY"*/        {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,  550,  250,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  190,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0},
	/*30 = "MINNEAPOLIS"*/        {   0,    0,    0,    0,    0,    0,    0,    0,    0, 1340,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  380,  340,  410,    0,    0,    0,    0,    0,    0,    0,   0},
	/*31 = "OMAHA"*/              {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  540,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  190,  380,    0,    0,  470,    0,    0,    0,    0,    0,    0,    0,   0},
	/*32 = "MILWAUKEE"*/          {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  340,    0,    0,   90,    0,    0,    0,    0,    0,    0,    0,   0},
	/*33 = "CHICAGO"*/            {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,  300,    0,    0,    0,    0,    0,    0,    0,    0,    0,  410,  470,   90,    0,  280,  180,    0,  700,    0,    0,    0,   0},
	/*34 = "DETROIT"*/            {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  280,    0,    0,    0,  530,  640,    0,  650,   0},
	/*35 = "INDIANAPOLIS"*/       {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,  250,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  180,    0,    0,    0,  590,    0,    0,    0, 290},
	/*36 = "RICHMOND"*/           {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,  560,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  200,    0,    0,    0, 710},
	/*37 = "WASHINGTON"*/         {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  700,  530,  590,  200,    0,  240,    0,    0,   0},
	/*38 = "NOVA YORK"*/          {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  640,    0,    0,  240,    0,  210,  150,   0},
	/*39 = "BOSTON"*/             {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  210,    0,  170,   0},
	/*40 = "ALBANY"*/             {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  650,    0,    0,    0,  150,  170,    0,   0},
	/*41 = "NASHVILLE"*/          {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   0,    0,    0,    0,    0,    0,    0,    0,    0,  240,  210,    0,    0,    0,    0,    0,    0,    0,  290,  710,    0,    0,    0,    0,   0},
};

int findCityByName(char* cityName) {
	int i = 0;
	while (cityName[i] != '\0') {
		cityName[i] = (char)toupper((int)cityName[i]);
		i++;
	}
	if (strcmp(cityName, "seatle") == 0) return 0;
	else if (strcmp(cityName, "portland") == 0) return 1;
	else if (strcmp(cityName, "san francisco") == 0) return 2;
	else if (strcmp(cityName, "los angeles") == 0) return 3;
	else if (strcmp(cityName, "san diego") == 0) return 4;
	else if (strcmp(cityName, "boise") == 0) return 5;
	else if (strcmp(cityName, "lake tahoe") == 0) return 6;
	else if (strcmp(cityName, "las vegas") == 0) return 7;
	else if (strcmp(cityName, "palm springs") == 0) return 8;
	else if (strcmp(cityName, "yellowstone") == 0) return 9;
	else if (strcmp(cityName, "salt lake city") == 0) return 10;
	else if (strcmp(cityName, "grand canyon") == 0) return 11;
	else if (strcmp(cityName, "phoenix") == 0) return 12;
	else if (strcmp(cityName, "denver") == 0) return 13;
	else if (strcmp(cityName, "colorado springs") == 0) return 14;
	else if (strcmp(cityName, "vail") == 0) return 15;
	else if (strcmp(cityName, "aspen") == 0) return 16;
	else if (strcmp(cityName, "albuquerque") == 0) return 17;
	else if (strcmp(cityName, "minneapolis") == 0) return 18;
	else if (strcmp(cityName, "omaha") == 0) return 19;
	else if (strcmp(cityName, "kansas city") == 0) return 20;
	else if (strcmp(cityName, "dallas") == 0) return 21;
	else if (strcmp(cityName, "san antonio") == 0) return 22;
	else if (strcmp(cityName, "houston") == 0) return 23;
	else if (strcmp(cityName, "milwaukee") == 0) return 24;
	else if (strcmp(cityName, "chicago") == 0) return 25;
	else if (strcmp(cityName, "st louis") == 0) return 26;
	else if (strcmp(cityName, "little rock") == 0) return 27;
	else if (strcmp(cityName, "memphis") == 0) return 28;
	else if (strcmp(cityName, "nova orleans") == 0) return 29;
	else if (strcmp(cityName, "detroit") == 0) return 30;
	else if (strcmp(cityName, "indianapolis") == 0) return 31;
	else if (strcmp(cityName, "nashville") == 0) return 32;
	else if (strcmp(cityName, "atlanta") == 0) return 33;
	else if (strcmp(cityName, "orlando") == 0) return 34;
	else if (strcmp(cityName, "fort lauderdale") == 0) return 35;
	else if (strcmp(cityName, "miami") == 0) return 36;
	else if (strcmp(cityName, "albany") == 0) return 37;
	else if (strcmp(cityName, "boston") == 0) return 38;
	else if (strcmp(cityName, "nova york") == 0) return 39;
	else if (strcmp(cityName, "washington") == 0) return 40;
	else if (strcmp(cityName, "richmond") == 0) return 41;
	return -1;
}

char* findCityByIndex(int i) {
	switch (i)
	{
	case 0:return "SAN FRANCISCO";
	case 1:return "PORTLAND";
	case 2:return "SEATLE";
	case 3:return "LOS ANGELES";
	case 4:return "SAN DIEGO";
	case 5:return "PALM SPRINGS";
	case 6:return "GRAND CANYON";
	case 7:return "LAKE TAHOE";
	case 8:return "BOISE";
	case 9:return  "YELLOWSTONE";
	case 10:return "DENVER";
	case 11:return "COLORADO SPRINGS";
	case 12:return "ASPEM";
	case 13:return "VAIL";
	case 14:return "SALT LAKE CITY";
	case 15:return "LAS VEGAS";
	case 16:return "PHOENIX";
	case 17:return "ALBUQUERQUE";
	case 18:return "SAN ANTONIO";
	case 19:return "DALLAS";
	case 20:return "ST LOUIS";
	case 21:return "HOUSTON";
	case 22:return "NOVA ORLEANS";
	case 23:return "MIAMI";
	case 24:return "FORT LAUDERDALE";
	case 25:return "ORLANDO";
	case 26:return "ATLANTA";
	case 27:return "MEMPHIS";
	case 28:return "LITTLE ROCK";
	case 29:return "KANSAS CITY";
	case 30:return "MINNEAPOLIS";
	case 31:return "OMAHA";
	case 32:return "MILWAUKEE";
	case 33:return "CHICAGO";
	case 34:return "DETROIT";
	case 35:return "INDIANAPOLIS";
	case 36:return "RICHMOND";
	case 37:return "WASHINGTON";
	case 38:return "NOVA YORK";
	case 39:return "BOSTON";
	case 40:return "ALBANY";
	case 41:return "NASHVILLE";
	default:
		return "";
	}
}

void gotoxy(int lin, int col)
{
	HANDLE Saida;

	COORD Posicao;

	Saida = GetStdHandle(STD_OUTPUT_HANDLE);

	Posicao.X = col;
	Posicao.Y = lin;

	SetConsoleCursorPosition(Saida, Posicao);
}


void banner() {
	gotoxy(0, 35);
	printf("   __  _______ ___       ______                \n");
	gotoxy(1, 35);
	printf("  / / / / ___//   |     /_  __/___  __  _______\n");
	gotoxy(2, 35);
	printf(" / / / /\\__ \\/ /| |      / / / __ \\/ / / / ___/\n");
	gotoxy(3, 35);
	printf("/ /_/ /___/ / ___ |     / / / /_/ / /_/ / /    \n");
	gotoxy(4, 35);
	printf("\\____//____/_/  |_|    /_/  \\____/\\__,_/_/     \n");
}

void cidades() {
	printf("\nCIDADES DISPONIVEIS:\n");
	printf("0)SEATLE               1)PORTLAND        2)SAN FRANCISCO        3)LOS ANGELES      4)LOS ANGELES     5)SAN DIEGO\n");
	printf("6)BOISE                7)LAKE TAHOE      8)LAS VEGAS            9)PALM SPRINGS     10)YELLOWSTONE    11)SALT LAKE CITY\n");
	printf("12)ASPEM               13)VAIL           14)SALT LAKE CITY      15)LAS VEGAS       16)PHOENIX        17)ALBUQUERQUE\n");
	printf("18)SAN ANTONIO         19)DALLAS         20)ST LOUIS            21)HOUSTON         22)NOVA ORLEANS   23)MIAMI\n");
	printf("24)FORT LAUDERDALE     25)ORLANDO        26)ATLANTA             27)MEMPHIS         28)LITTLE ROCK    29)KANSAS CITY\n");
	printf("30)MINNEAPOLIS         31)OMAHA          32)MILWAUKEE           33)CHICAGO         34)DETROIT        35)INDIANAPOLIS\n");
	printf("36)RICHMOND            37)WASHINGHTON    38)NOVA YORK           39)BOSTON          40)ALBANY         41)NASHVILLE\n");
}

void op1() {
	int escolha, codigoCidade = 0;
	char nomeCidade[20];

	system("cls");
	cidades();
	printf("\n1) DIGITAR NOME DA CIDADE\n2) DIGITAR O CODIGO DA CIDADE\n");
	printf("DIGITE O CODIGO DA OPCAO DESEJADA: ");
	scanf("%d", &escolha);

	system("cls");
	cidades();
	if (escolha == 1) {
		getc(stdin);
		scanf("%[^\n]%*c", nomeCidade);
		codigoCidade = findCityByName(nomeCidade);
		printf("%d", codigoCidade);
	}
	else {
		scanf("%d", &codigoCidade);
		printf("%d", codigoCidade);
	}
}

void op2() {
	int escolha, codigoCidade1, codigoCidade2 = 0;
	char nomeCidade1[20], nomeCidade2[20];

	system("cls");
	cidades();
	printf("\n1) DIGITAR O NOME DAS CIDADES\n2) DIGITAR O CODIGO DAS CIDADES\n");
	printf("DIGITE O CODIGO DA OPCAO DESEJADA: ");
	scanf("%d", &escolha);
	
	system("cls");
	cidades();
	if (escolha == 1) {
		getc(stdin);
		scanf("%[^\n]%*c", nomeCidade1);
		codigoCidade1 = findCityByName(nomeCidade1);

		scanf("%[^\n]%*c", nomeCidade2);
		codigoCidade2 = findCityByName(nomeCidade2);

		printf("%d %d", codigoCidade1, codigoCidade2);
	}
	else {
		scanf("%d", &codigoCidade1);
		scanf("%d", &codigoCidade1);

		printf("%d %d", codigoCidade1, codigoCidade2);
	}

}

void op3() {
	printf("entrou no 3");
}

void op4() {
	printf("entrou no 4");
}

void menu() {
	banner();
	gotoxy(8, 37);
	printf("1) DEFINIR O CICLO A PARTIR DE UMA CIDADE");
	gotoxy(9, 37);
	printf("2) OPC 1");
	gotoxy(10, 37);
	printf("3) OPC 2");
	gotoxy(11, 37);
	printf("4) VOLTAR\n");
	gotoxy(12, 37);
	printf("DIGITE O CODIGO DA OPCAO DESEJADA: ");
	codigo = getchar();

	switch (codigo)
	{
	case '1':
		op1();
		break;
	case '2':
		op2();
		break;
	case '3':
		op3();
		break;
	case '4':
		op4();
		break;
	}
}

void main() {
	menu();
}