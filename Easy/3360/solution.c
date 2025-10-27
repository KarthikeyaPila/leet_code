#include <stdbool.h> 
#include <stdio.h> 

bool canAliceWin(int n) {
    int turn = 10; 
    
    int i=0; 

    while(n != 0) {
        //alice turn
        if(i%2 == 0) {
            if(n-turn < 0) {
                return false; 
            }
            n = n-turn; 
        } else { //bob turn
            if(n-turn < 0) {
                return true;
            }
            n = n-turn; 
        }

        turn--; 
        i++; 
    }

    //should not reach here. 
    return true; 
}