#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int id;
    char nickname[101];
    int kills;
    int assists;
    int deaths;
    int wins;
    int losses;
    int redPlayed;
    int bluePlayed;
    int matchesPlayed;
    int mostKillsInGame;
    float killsAverage;
    float KD_Ratio;
}Player;

int findPlayerById(Player* players, int playerCount, int id);
int countPlayers(FILE* playerFile);
void loadPlayers(Player* players, FILE* playerFile);
void statUpdate(Player* player, int kills, int asists, int deaths, int wasRed, int isWinner);