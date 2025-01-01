#include "player.h"
#include "match.h"

int findPlayerById(Player* players, int playerCount, int id){
    for(int i = 0; i < playerCount; i++){
        if (players[i].id == id) {
            return i;
        }
    }
    return -1;
}

int countPlayers(FILE* playerFile){
    int count = 0;
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), playerFile) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        count++;
    }
    return count;
}

void loadPlayers(Player* players, FILE* playerFile){
    char playerBuffer[256];
    char delim[2] = ",";
    int index = 0;
    while(fgets(playerBuffer, sizeof(playerBuffer), playerFile) != NULL){
        playerBuffer[strcspn(playerBuffer, "\n")] = '\0';
        char* token = strtok(playerBuffer, delim);
        players[index].id = atoi(token);
        token = strtok(NULL, delim);
        if(token){
            strcpy(players[index].nickname, token);
            index++;
        }
    }
}

void statsUpdate(Player* player, int kills, int asists, int deaths, int wasRed, int isWinner){
    player->kills += kills;
    player->assists += asists;
    player->deaths += deaths;
    player->matchesPlayed++;
    if(isWinner){
        player->wins++;
    } 
    else{
        player->losses++;
    }
    if(wasRed){
        player->redPlayed++;
    } 
    else{
        player->bluePlayed++;
    }
    if(kills > player->mostKillsInGame){
        player->mostKillsInGame = kills;
    }
    player->killsAverage = (float)player->kills / player->matchesPlayed;
    
    if(player->deaths > 0){
        player->KD_Ratio = (float)player->kills / player->deaths;
    }
    else{
        player->KD_Ratio = (float)player->kills;
    }
}
