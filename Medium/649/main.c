#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

char* predictPartyVictory(char* senate) {
    char* str = senate;
    int len = strlen(str);
    char* winner_str;

    int count_R=0;
    int count_D=0;
    for(int i=0; i<len; i++){
        if(str[i] == 'D'){
            count_D++;
        } else {
            count_R++;
        }
    }

    if(count_D == len){
        return "Dire";
    }
    else if(count_R == len){
        return "Radiant";
    }
    
    int begining = 0;
    while(len != 1){
        // 1st char
        if(str[begining] == 'D'){
            for(int i=strlen(str)-1; i>=0; i--){
                if(str[i] == 'R'){
                    str[i] = 'D';
                    str[begining++] = ' ';
                    len--;
                    break;
                }
            }
        } else if(str[begining] == 'R'){
            for(int i=strlen(str)-1; i>=0; i--){
                if(str[i] == 'D'){
                    str[i] = 'R';
                    str[begining++] = ' ';
                    len--;
                    break;
                }
            }
        }
    }
    
    char winner;

    for(int i=0; i<strlen(str); i++){
        if(str[i] != ' '){
            winner = str[i];
            break;
        }
    }


    if(winner == 'D'){
        winner_str = "Dire";
    } else {
        winner_str = "Radiant";
    }

    return winner_str;
}