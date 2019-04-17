#include <stdio.h>
#include <string.h>
#include "input.h"
#include "sorting.h"

//Global variables
//1. Array containing Facebook users (at most 6 users, at most 80 characters long strings) 
char users[6][80];
//2. 3D Array containing at most 4 friends of at most 6 users
//          rows = user number        (0, 1, 2, 3, 4, 5)           at most 6 possibilities
//       columns = friend number        (0, 1, 2, 3)               at most 4 possibilities 
// 3rd dimension = name of friends (string / array of characters)  at most 80 characters long
char userFriends [6][4][80];
//3. Total number of friends for each user (at most 6 users)
int numFriendsPerUser[6];
//4. List of users who are the friends suggestions for another user (taken as input from menu)
char friendSuggestions[5][80];
//5. Stores the number of friends that each person in the friendSuggestions array has
int numFriendsOfSuggestions[5];
//6. Total number of facebook users (can be less than 6 users)
int numOfUsers = 0;
  
//Function prototypes
//1. Function to provide users as input
int inputFacebookUsers();
//2. Function to check if other users are already friends with user of choice
//Hence suggest at most 2 friends to user of choice based on who has the most number of friends
void suggestFriends(char user_choice[80], int index, char friendsUser[][80]);

/**
 * main() function: Processing starts here.
 */
int main(void) {  
    //invoke here the function to provide users as input
	//also store number of users provided as input as returned by the function call
	numOfUsers = inputFacebookUsers();

	//display list of users provided as input
    printf("\n%d Facebook users have been provided as input.\n", numOfUsers);
   	for (int i = 0; i < numOfUsers; i++) {
        printf("(%d) %s\n", (i + 1), users[i]);
   	}

	//stores user choice (number)
	int choice;
	do {
		//prompt user to enter choice from displayed menu 
		printf("\nInput the Facebook user to whom you want to provide friends suggestions:\nUser ");
   		scanf("%d", &choice);
		printf("\n");	
	} while (choice < 1 || choice > numOfUsers);
    
	//call function to suggest at most 2 friends to user of choice
    suggestFriends(users[choice-1], choice-1, userFriends[choice-1]); 
    return 0;
}

/**
 * This function asks the users to provide a list of Facebook users.
 * For each user, we can input at most 4 friends.
 */
int inputFacebookUsers() {
	//loop-control variable
    int i = 0;

	//loop to iteratively ask for user input
    while(i < 6) {
		//ask for input of Facebook User name, store input in users[] array
        printf("\nInput a Facebook User:\n");
        fgets(users[i], 80, stdin);

        //checks whether a carriage return symbol was provided as input
		//if enter ('\n') is pressed, then break from loop (stop taking user input)
        if(users[i][0] == '\n') {
            break;
        }

        //removes carriage return character from the user's name
		//ex. "John\n\0" would become "John\0\0", string terminates at the first '\0'
        int len = strlen(users[i]);
        if(len > 0 && users[i][len-1] == '\n') {
            users[i][len-1] = '\0';
        }
        //print blank line
		printf("\n");

		//Call function to input at most 4 friends for current user.
		/*
		userFriends is the 3D array, which in the function call specifies the row index only,
		which means that for that particular row, the parameter that's passed is a 2D
		array composed of the 2nd and 3rd dimensions of the userFriends array.

		In essence, for a user index (i), the list of friends for that 
		user index is passed as parameter. 
		That ith row is where the friends are taken as input. 		 
		*/	 
		//Also store number of friends entered as returned by function call.
        numFriendsPerUser[i] = inputFriends(userFriends[i], users[i]);

		//increment loop counter to proceed to next user
        i++;
    }
	//return number of users provided as input
    return i;
}

/**
 * This function checks whether other users are already friends of 
 * the user for whom suggestions are required.
 * 
 * Then it calls the sort() function to sort the friend suggestions 
 * alphabetically and also in decreasing order by number of friends
 * of each suggestion.
 * 
 * Finally, it displays at most 2 friend suggestions for required user
 * 
 * Input: 
 * 1. Name of the user for whom suggestions are required (user_choice)
 * 2. Index of array which stores the name of user chosen (index)
 * 3. 2D array which stores the list of friends for chosen user (friendsUser)
 *     (This is a subpart of the larger 3D array that contains 
 *      the friend lists for all the users provided as input)
 * 
 * Output: 
 * At most 2 friend suggestions    
 */
void suggestFriends(char user_choice[80], int index, char friendsUser[][80]) {
	//array index variable
	int x = 0;

	//iterate through users[] array
	for (int i = 0; i < numOfUsers; i++) {
		//declare and initialise flag for check
		int flag = 0;

		//iterate through user's friend list
		//if another facebook user is in the friend list, then set flag = 1
		for (int j = 0; j < numFriendsPerUser[index]; j++) {
			if (strcmp(users[i], friendsUser[j]) == 0) {
				flag = 1;
			}
		}

		//copy into friendSuggestions all the users who are not already in the friend list
		if (strcmp(user_choice, users[i]) != 0 && flag == 0) {
			strcpy(friendSuggestions[x], users[i]);
			numFriendsOfSuggestions[x] = numFriendsPerUser[i];
			//increment array index
			x++;
		}
	}
	//sort friendSuggestions alphabetically and also in decreasing order of number of friends 
	sort (x, numFriendsOfSuggestions, friendSuggestions);
	
	//display at most 2 suggested friends for user of choice
	printf("Suggested Friends for %s:\n", user_choice);
	for(int i = 0; i < 2; i++) {
		if (friendSuggestions[i] != NULL) {
			printf("%s\n", friendSuggestions[i]);
		}
	}
}
//end of main.c file