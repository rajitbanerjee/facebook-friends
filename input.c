#include <stdio.h>
#include <string.h>
#include "input.h"

/**
 * This method asks the user to provide as input the friends
 * of a Facebook user.
 * 
 * Input: 
 * 1. The names of friends provided as input (friends)
 * 2. The name of the current user for whom friends are taken as input (user_name)

 * 
 * Output:
 * Returns the number of friends provided as input. Note that
 * a user may decide to input less than 4 friends. 
 */
int inputFriends(char friends[][80], char user_name[80]) {
    //loop counter variable
    int i = 0;
    while(i < 4) {
        //prompt user to enter friend name for current user
        printf("Insert friend %d for %s:\n", (i+1), user_name);
        fgets(friends[i], 80, stdin);
        //checks whether a carriage return symbol was provided as input
        if(friends[i][0] == '\n') {
            break;
        }
        //removes carriage return character from the friend's name
        int len = strlen(friends[i]);
        if(len > 0 && friends[i][len-1] == '\n') {
            friends[i][len-1] = '\0';
        }
        //increment loop counter 
        i++;
    }
    //return the number of friends provided as input for current user
    return i;
}
