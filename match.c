#include "match.h"

void readIds(FILE* matchFile, int* IDsArr){
    char matchBuffer[256];
    char del[2] = ",";
    if(fgets(matchBuffer, sizeof(matchBuffer), matchFile) != NULL){
        char* token = strtok(matchBuffer, del);
        for(int i = 0; i < 3; i++){
            IDsArr[i] = atoi(token);
            token = strtok(NULL, del);
        }
    }
}


void setStats(FILE* matchFIle, int matchStats[3][3]){
    char buffer[256];
    char delims[3] = ",;";
    if(fgets(buffer, sizeof(buffer), matchFIle)){
        char* token = strtok(buffer, delims);
        for(int idIndex = 0; idIndex < 3; idIndex++){
            for(int statIndex = 0; statIndex < 3; statIndex++){
                matchStats[idIndex][statIndex] = atoi(token);
                token = strtok(NULL, delims);
            }
        }
    }
}

int sameIDinTeam(int* ids){
    for(int i = 0; i < 2; i++){
        for(int j = i+1; j < 3; j++){
            if(ids[i] == ids[j]){
                return 1;
            }
        }
    }
    return 0;
}

int hasDuplicateIDs(int* redIDs, int* blueIDs){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(redIDs[i] == blueIDs[j]){
                return 1;
            }
        }
    }
    return 0;
}

void processMatch(Player* players, int playerCount, FILE* matchFile){
    char buffer[256];
    int redIDs[3] = {0};
    int blueIDs[3] = {0};
    int redKAD[3][3] = {0};
    int blueKAD[3][3] = {0};
    char winner[10];

    int redWon = 0;
    int blueWon = 0;

    readIds(matchFile, redIDs);
    setStats(matchFile, redKAD);

    readIds(matchFile, blueIDs);
    setStats(matchFile, blueKAD);

    if(fgets(winner, sizeof(winner), matchFile)) {
        winner[strcspn(winner, "\n")] = '\0';
    }
    if(strcmp(winner, "red") == 0){
        redWon = 1;
    }
    else if(strcmp(winner, "blue") == 0){
        blueWon = 1;
    }
    else{
        printf("invalid winner\n");
        exit(1);
    }

    if(hasDuplicateIDs(redIDs, blueIDs)){
        printf("same ids on both teams\n");
        exit(1);
    }
    if(sameIDinTeam(redIDs) || sameIDinTeam(blueIDs)){
        printf("same id in one team\n");
        exit(1);
    }

    for(int i = 0; i < 3; i++){
        int index = findPlayerById(players, playerCount, redIDs[i]);
        if(index == -1){ // player was not found
            printf("red player [%d] was not found\n", redIDs[i]);
            exit(1);
        }
        else{
            statUpdate(&players[index], redKAD[i][0], redKAD[i][1], redKAD[i][2], 1, redWon);
        }
    }

    for(int i = 0;i < 3; i++){
        int index = findPlayerById(players, playerCount, blueIDs[i]);
        if(index == -1){
            printf("blue player [%d] was not found\n", blueIDs[i]);
            exit(1);
        }
        else{
            statUpdate(&players[index], blueKAD[i][0], blueKAD[i][1], blueKAD[i][2], 0, blueWon);
        }
    }
}