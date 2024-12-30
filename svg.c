#include "svg.h"

void svgGraph(Player* players, int playerCount, FILE* outputFile, char* shownStats){
    int graphWidth = 500;
    int graphHeight = 300;
    int dx = graphWidth/playerCount;
    int barWidth = 20;                  

    int scaler = 70;
    int x = 0;
    int y = 0;
    int newHeight = 0;

    int stat = 0;
    int index = 0;

    int isKills = 0;
    int isAssists = 0;
    int isDeaths = 0;

    if(strcmp(shownStats, "kills") == 0){ 
        isKills = 1;
    }
    else if(strcmp(shownStats, "assists") == 0){
        isAssists = 1;
    }
    else if(strcmp(shownStats, "deaths") == 0){
        isDeaths = 1;
    }
    else{
        printf("wrong stat\n");
        exit(1);
    }

    fprintf(outputFile, "<h1>Players %s Graph</h1>\n", shownStats);
    fprintf(outputFile, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n", graphWidth, graphHeight);

    if(isKills){
        for(int i = 0; i < playerCount; i++){
        newHeight = (players[i].kills * graphHeight) / scaler;
        x = i*dx; 
        y = graphHeight - newHeight; 
        fprintf(outputFile, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />\n", x, y, barWidth, newHeight-10);
        fprintf(outputFile, "<text x=\"%d\" y=\"%d\" dy=\".3\">%d</text>",x, y-3, players[i].kills);
        index++;
        }
    }
    else if(isAssists){
        for(int i = 0; i < playerCount; i++){
        newHeight = (players[i].assists * graphHeight) / scaler;
        x = i*dx; 
        y = graphHeight - newHeight; 
        fprintf(outputFile, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />\n", x, y, barWidth, newHeight-10);
        fprintf(outputFile, "<text x=\"%d\" y=\"%d\" dy=\".3\">%d</text>",x, y-3, players[i].assists);
        index++;
        }
    }
    else if(isDeaths){
        for(int i = 0; i < playerCount; i++){
        newHeight = (players[i].deaths * graphHeight) / scaler;
        x = i*dx; 
        y = graphHeight - newHeight; 
        fprintf(outputFile, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />\n", x, y, barWidth, newHeight-10);
        fprintf(outputFile, "<text x=\"%d\" y=\"%d\" dy=\".3\">%d</text>",x, y-3, players[i].deaths);
        index++;
        }
    }
    
    fprintf(outputFile, "</svg>\n");
}
