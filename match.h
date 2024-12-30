#pragma once
#include "player.h"

void readIds(FILE* matchFile, int* IDsArr);
void setStats(FILE* matchFIle, int matchStats[3][3]);
int sameIDinTeam(int* ids);
int hasDuplicateIDs(int* redIDs, int* blueIDs);
void processMatch(Player* players, int playerCount, FILE* matchFile);