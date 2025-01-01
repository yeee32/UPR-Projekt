#pragma once
#include "player.h"

typedef struct{
    int kills;
    int assists;
    int deaths;
}TempKAD;

void readIds(FILE* matchFile, int* IDsArr);
void setStats(FILE* matchFIle, TempKAD* teamStats);
int sameIDinTeam(int* ids);
int hasDuplicateIDs(int* redIDs, int* blueIDs);
void processMatch(Player* players, int playerCount, FILE* matchFile);
