#include "html.h"

void htmlHeader(FILE* outputFile){
    fprintf(outputFile, "<!DOCTYPE html>\n<html lang=\"en\">");
    fprintf(outputFile, "<body>\n");
    fprintf(outputFile, "<h1>League of Legends statistiky</h1>\n");
}


void htmlTable(Player* players, int playerCount, FILE* outputFile){
    fprintf(outputFile, "<table border='1'>\n<tr><th>Name</th><th>Kills</th><th>Assists</th><th>Deaths</th><th>Wins</th><th>Losses</th><th>Red Team</th><th>Blue Team</th><th>Matches</th><th>Most Kills</th><th>Kill Average</th><th>K/D Ratio</th></tr>\n");
    for(int i = 0; i < playerCount; i++){
        fprintf(outputFile, "<tr><td>%s</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%.2f</td><td>%.2f</td></tr>\n",players[i].nickname, players[i].kills, players[i].assists, players[i].deaths, players[i].wins, players[i].losses,players[i].redPlayed, players[i].bluePlayed, players[i].matchesPlayed, players[i].mostKillsInGame,players[i].killsAverage, players[i].KD_Ratio);
        
    }
    fprintf(outputFile, "</table>\n");
}

void htmlEnd(FILE* outputFile){
    fprintf(outputFile, "</body>\n</html>\n");
}
