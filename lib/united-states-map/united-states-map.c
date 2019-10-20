#include <string.h>
#include <ctype.h>
#define CITYCOUNT 42

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
        cityName[i] = (char) toupper((int)cityName[i]);
        i++;
    }
    if (strcmp(cityName, "SAN FRANCISCO"   ) == 0) return 0;
    else if (strcmp(cityName, "PORTLAND"        ) == 0) return 1;
    else if (strcmp(cityName, "SEATLE"          ) == 0) return 2;
    else if (strcmp(cityName, "LOS ANGELES"     ) == 0) return 3;
    else if (strcmp(cityName, "SAN DIEGO"       ) == 0) return 4;
    else if (strcmp(cityName, "PALM SPRINGS"    ) == 0) return 5;
    else if (strcmp(cityName, "GRAND CANYON"    ) == 0) return 6;
    else if (strcmp(cityName, "LAKE TAHOE"      ) == 0) return 7;
    else if (strcmp(cityName, "BOISE"           ) == 0) return 8;
    else if (strcmp(cityName, "YELLOWSTONE"     ) == 0) return 9;
    else if (strcmp(cityName, "DENVER"          ) == 0) return 10;
    else if (strcmp(cityName, "COLORADO SPRINGS") == 0) return 11;
    else if (strcmp(cityName, "ASPEM"           ) == 0) return 12;
    else if (strcmp(cityName, "VAIL"            ) == 0) return 13;
    else if (strcmp(cityName, "SALT LAKE CITY"  ) == 0) return 14;
    else if (strcmp(cityName, "LAS VEGAS"       ) == 0) return 15;
    else if (strcmp(cityName, "PHOENIX"         ) == 0) return 16;
    else if (strcmp(cityName, "ALBUQUERQUE"     ) == 0) return 17;
    else if (strcmp(cityName, "SAN ANTONIO"     ) == 0) return 18;
    else if (strcmp(cityName, "DALLAS"          ) == 0) return 19;
    else if (strcmp(cityName, "ST LOUIS"        ) == 0) return 20;
    else if (strcmp(cityName, "HOUSTON"         ) == 0) return 21;
    else if (strcmp(cityName, "NOVA ORLEANS"    ) == 0) return 22;
    else if (strcmp(cityName, "MIAMI"           ) == 0) return 23;
    else if (strcmp(cityName, "FORT LAUDERDALE" ) == 0) return 24;
    else if (strcmp(cityName, "ORLANDO"         ) == 0) return 25;
    else if (strcmp(cityName, "ATLANTA"         ) == 0) return 26;
    else if (strcmp(cityName, "MEMPHIS"         ) == 0) return 27;
    else if (strcmp(cityName, "LITTLE ROCK"     ) == 0) return 28;
    else if (strcmp(cityName, "KANSAS CITY"     ) == 0) return 29;
    else if (strcmp(cityName, "MINNEAPOLIS"     ) == 0) return 30;
    else if (strcmp(cityName, "OMAHA"           ) == 0) return 31;
    else if (strcmp(cityName, "MILWAUKEE"       ) == 0) return 32;
    else if (strcmp(cityName, "CHICAGO"         ) == 0) return 33;
    else if (strcmp(cityName, "DETROIT"         ) == 0) return 34;
    else if (strcmp(cityName, "INDIANAPOLIS"    ) == 0) return 35;
    else if (strcmp(cityName, "RICHMOND"        ) == 0) return 36;
    else if (strcmp(cityName, "WASHINGTON"      ) == 0) return 37;
    else if (strcmp(cityName, "NOVA YORK"       ) == 0) return 38;
    else if (strcmp(cityName, "BOSTON"          ) == 0) return 39;
    else if (strcmp(cityName, "ALBANY"          ) == 0) return 40;
    else if (strcmp(cityName, "NASHVILLE"       ) == 0) return 41;
    return -1;
}

char* findCityByIndex(int i) {
    switch (i)
    {
    case 0:return "SAN FRANCISCO"    ;
    case 1:return "PORTLAND"         ;
    case 2:return "SEATLE"           ;
    case 3:return "LOS ANGELES"      ;
    case 4:return "SAN DIEGO"        ;
    case 5:return "PALM SPRINGS"     ;
    case 6:return "GRAND CANYON"     ;
    case 7:return "LAKE TAHOE"       ;
    case 8:return "BOISE"            ;
    case 9:return  "YELLOWSTONE"     ;
    case 10:return "DENVER"          ;
    case 11:return "COLORADO SPRINGS";
    case 12:return "ASPEM"           ;
    case 13:return "VAIL"            ;
    case 14:return "SALT LAKE CITY"  ;
    case 15:return "LAS VEGAS"       ;
    case 16:return "PHOENIX"         ;
    case 17:return "ALBUQUERQUE"     ;
    case 18:return "SAN ANTONIO"     ;
    case 19:return "DALLAS"          ;
    case 20:return "ST LOUIS"        ;
    case 21:return "HOUSTON"         ;
    case 22:return "NOVA ORLEANS"    ;
    case 23:return "MIAMI"           ;
    case 24:return "FORT LAUDERDALE" ;
    case 25:return "ORLANDO"         ;
    case 26:return "ATLANTA"         ;
    case 27:return "MEMPHIS"         ;
    case 28:return "LITTLE ROCK"     ;
    case 29:return "KANSAS CITY"     ;
    case 30:return "MINNEAPOLIS"     ;
    case 31:return "OMAHA"           ;
    case 32:return "MILWAUKEE"       ;
    case 33:return "CHICAGO"         ;
    case 34:return "DETROIT"         ;
    case 35:return "INDIANAPOLIS"    ;
    case 36:return "RICHMOND"        ;
    case 37:return "WASHINGTON"      ;
    case 38:return "NOVA YORK"       ;
    case 39:return "BOSTON"          ;
    case 40:return "ALBANY"          ;
    case 41:return "NASHVILLE"       ;
    default:
        return "";
    }
}