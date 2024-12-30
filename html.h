#pragma once
#include "player.h"

void htmlHeader(FILE* outputFIle);
void htmlTable(Player* players, int playerCount, FILE* outputFile);
void htmlEnd(FILE* outputFile);