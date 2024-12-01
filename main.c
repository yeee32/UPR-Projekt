#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int id;
    char* nickname;
    int kills;
    int assists;
    int deaths;
    char* color;
}Player;

/*
    potential errors:
        cannot have the same id play multiple characters in a match
        player id cant be missing in the game recors file
        file must have all the necessary info
            "match" at the beginning
            3 red players!
            their stats
            3 blue players
            their stats
            who won (red or blue)
*/

int main(int argc, char* argv[]){
    
    char* matchRecordsFile = argv[1];
    char* playersFile = argv[2];
    char* output = argv[3];

    if(argc != 4){
        printf("Wrong number of arguments!\n");
        return 1;
    }

    return 0;
}