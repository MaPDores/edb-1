#include <string.h>
#include <ctype.h>
#define CITYCOUNT 42

int map[42][42] = { 
{    0, 170, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    170, 0, 640, 0, 0, 420, 580, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 640, 0, 380, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 380, 0, 120, 0, 0, 270, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 120, 0, 0, 0, 0, 140, 0, 0, 0, 350, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    500, 420, 0, 0, 0, 0, 420, 0, 0, 670, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 580, 300, 0, 0, 420, 0, 0, 780, 0, 520, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 270, 0, 0, 0, 0, 290, 0, 420, 470, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 160, 140, 0, 780, 290, 0, 0, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 670, 0, 0, 0, 0, 0, 0, 0, 930, 0, 0, 0, 0, 1340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 520, 420, 0, 0, 0, 0, 660, 530, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 470, 440, 0, 0, 0, 360, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 350, 0, 0, 0, 0, 0, 660, 360, 0, 0, 0, 0, 0, 350, 0, 0, 0, 1070, 990, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 930, 530, 0, 0, 0, 120, 160, 170, 0, 0, 540, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 180, 0, 0, 0, 0, 730, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 170, 180, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 350, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 1340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0, 0, 0, 340, 410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 540, 0, 0, 0, 0, 380, 0, 190, 0, 0, 0, 0, 470, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 550, 0, 0, 0, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1070, 0, 730, 0, 0, 0, 0, 0, 550, 0, 280, 250, 0, 0, 0, 320, 0, 0, 0, 0, 0, 790, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 990, 0, 0, 0, 0, 0, 0, 0, 0, 280, 0, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250, 310, 0, 0, 0, 0, 0, 0, 530, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0, 0, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 410, 470, 0, 0, 0, 0, 90, 0, 300, 0, 0, 0, 280, 180, 0, 0, 0, 0, 0, 0, 0, 0, 700, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0, 0, 0, 300, 0, 400, 290, 0, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 400, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 290, 140, 0, 0, 0, 0, 210, 390, 0, 0, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 530, 0, 0, 0, 0, 0, 0, 0, 0, 0, 470, 640, 0, 860, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 650, 0, 640, 530, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 250, 0, 0, 0, 0, 0, 290, 0, 0, 0, 0, 0, 0, 0, 590, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0, 290, 0, 240, 0, 0, 0, 0, 0, 0, 0, 710}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 790, 0, 0, 0, 0, 0, 0, 390, 470, 0, 0, 240, 0, 440, 0, 0, 0, 0, 0, 0, 560}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 640, 0, 0, 0, 440, 0, 180, 230, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 30, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 860, 0, 0, 0, 0, 230, 30, 0, 0, 0, 0, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 650, 0, 0, 0, 0, 0, 0, 0, 170, 150, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 170, 0, 210, 0, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 640, 0, 0, 0, 0, 0, 0, 150, 210, 0, 240, 0}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 700, 0, 0, 0, 0, 530, 590, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200}, 
{    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 710, 560, 0, 0, 0, 0, 0, 0, 200, 0} 
};


int findCityByName(char* cityName) {
	int i = 0;
	while (cityName[i] != '\0') {
		cityName[i] = (char)toupper((int)cityName[i]);
		i++;
	}
	if (strcmp(cityName, "SEATLE") == 0) return 0;
	else if (strcmp(cityName, "PORTLAND") == 0) return 1;
	else if (strcmp(cityName, "SAN FRANCISCO") == 0) return 2;
	else if (strcmp(cityName, "LOS ANGELES") == 0) return 3;
	else if (strcmp(cityName, "SAN DIEGO") == 0) return 4;
	else if (strcmp(cityName, "BOISE") == 0) return 5;
	else if (strcmp(cityName, "LAKE TAHOE") == 0) return 6;
	else if (strcmp(cityName, "LAS VEGAS") == 0) return 7;
	else if (strcmp(cityName, "PALM SPRINGS") == 0) return 8;
	else if (strcmp(cityName, "YELLOWSTONE") == 0) return 9;
	else if (strcmp(cityName, "SALT LAKE CITY") == 0) return 10;
	else if (strcmp(cityName, "GRAND CANYON") == 0) return 11;
	else if (strcmp(cityName, "PHOENIX") == 0) return 12;
	else if (strcmp(cityName, "DENVER") == 0) return 13;
	else if (strcmp(cityName, "COLORADO SPRINGS") == 0) return 14;
	else if (strcmp(cityName, "VAIL") == 0) return 15;
	else if (strcmp(cityName, "ASPEN") == 0) return 16;
	else if (strcmp(cityName, "ALBUQUERQUE") == 0) return 17;
	else if (strcmp(cityName, "MINNEAPOLIS") == 0) return 18;
	else if (strcmp(cityName, "OMAHA") == 0) return 19;
	else if (strcmp(cityName, "KANSAS CITY") == 0) return 20;
	else if (strcmp(cityName, "DALLAS") == 0) return 21;
	else if (strcmp(cityName, "SAN ANTONIO") == 0) return 22;
	else if (strcmp(cityName, "HOUSTON") == 0) return 23;
	else if (strcmp(cityName, "MILWAUKEE") == 0) return 24;
	else if (strcmp(cityName, "CHICAGO") == 0) return 25;
	else if (strcmp(cityName, "ST LOUIS") == 0) return 26;
	else if (strcmp(cityName, "LITTLE ROCK") == 0) return 27;
	else if (strcmp(cityName, "MEMPHIS") == 0) return 28;
	else if (strcmp(cityName, "NOVA ORLEANS") == 0) return 29;
	else if (strcmp(cityName, "DETROIT") == 0) return 30;
	else if (strcmp(cityName, "INDIANAPOLIS") == 0) return 31;
	else if (strcmp(cityName, "NASHVILLE") == 0) return 32;
	else if (strcmp(cityName, "ATLANTA") == 0) return 33;
	else if (strcmp(cityName, "ORLANDO") == 0) return 34;
	else if (strcmp(cityName, "FORT LAUDERDALE") == 0) return 35;
	else if (strcmp(cityName, "MIAMI") == 0) return 36;
	else if (strcmp(cityName, "ALBANY") == 0) return 37;
	else if (strcmp(cityName, "BOSTON") == 0) return 38;
	else if (strcmp(cityName, "NOVA YORK") == 0) return 39;
	else if (strcmp(cityName, "WASHINGTON") == 0) return 40;
	else if (strcmp(cityName, "RICHMOND") == 0) return 41;
	return -1;
}

char* findCityByIndex(int i) {
    switch (i)
    {
    case 0:return "SEATLE";
    case 1:return "PORTLAND";
    case 2:return "SAN FRANCISCO";
    case 3:return "LOS ANGELES";
    case 4:return "SAN DIEGO";
    case 5:return "BOISE";
    case 6:return "LAKE TAHOE" ;
    case 7:return "LAS VEGAS";
    case 8:return "PALM SPRINGS" ;
    case 9:return  "YELLOWSTONE" ;
    case 10:return "SALT LAKE CITY";
    case 11:return "GRAND CANYON";
    case 12:return "PHOENIX";
    case 13:return "DENVER";
    case 14:return "COLORADO SPRINGS";
    case 15:return "VAIL";
    case 16:return "ASPEN";
    case 17:return "ALBUQUERQUE" ;
    case 18:return "MINNEAPOLIS" ;
    case 19:return "OMAHA";
    case 20:return "KANSAS CITY" ;
    case 21:return "DALLAS";
    case 22:return "SAN ANTONIO" ;
    case 23:return "HOUSTON";
    case 24:return "MILWAUKEE";
    case 25:return "CHICAGO";
    case 26:return "ST LOUIS";
    case 27:return "LITTLE ROCK" ;
    case 28:return "MEMPHIS";
    case 29:return "NOVA ORLEANS";
    case 30:return "DETROIT";
    case 31:return "INDIANAPOLIS";
    case 32:return "NASHVILLE";
    case 33:return "ATLANTA";
    case 34:return "ORLANDO";
    case 35:return "FORT LAUDERDALE";
    case 36:return "MIAMI";
    case 37:return "ALBANY";
    case 38:return "BOSTON";
    case 39:return "NOVA YORK";
    case 40:return "WASHINGTON";
    case 41:return "RICHMOND";
    DEFAULT:
        return "";
    }
}