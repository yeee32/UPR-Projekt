#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "player.h"
#include "html.h"
#include "match.h"
#include "svg.h"


int main(int argc, char* argv[]){
    if (argc != 4){
        printf("invalid number of argumetns\n");
        return 1;
    }
    char* matchesPath = argv[1];
    char* playerIDPath = argv[2];
    char* outputPath = argv[3];
    

    FILE* matchesFile = fopen(matchesPath, "r");
    FILE* playersFile = fopen(playerIDPath, "r");
    FILE* outputFile = fopen(outputPath, "w");

    int playerCount = countPlayers(playersFile); 

    fclose(playersFile);

    playersFile = fopen(playerIDPath, "r");
    Player* players = (Player*)calloc(playerCount, sizeof(Player));
    loadPlayers(players, playersFile);
    char matchBuffer[256];
    while(fgets(matchBuffer, sizeof(matchBuffer), matchesFile)){
        matchBuffer[strcspn(matchBuffer, "\n")] = '\0';
        if(strcmp(matchBuffer, "match") == 0){
            processMatch(players, playerCount, matchesFile);
        }
        else{
            printf("no 'match' at the start\n");
            return 1;
        }
    }
    htmlHeader(outputFile);
    htmlTable(players, playerCount, outputFile);
    svgGraph(players, playerCount, outputFile,"kills");
    svgGraph(players, playerCount, outputFile,"deaths");
    svgGraph(players, playerCount, outputFile,"assists");
    htmlEnd(outputFile);

    free(players);
    players = NULL;
    fclose(playersFile);
    fclose(matchesFile);
    fclose(outputFile);

    return 0;
}
