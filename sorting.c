#include <stdio.h>
#include <string.h>
#include "sorting.h"

/**
 * Method to perform selection sort in order to sort the names in friendSuggestions
 * in alphabetical order, and also in a decreasing order by the number of friends
 * that each of them have (this is stored in numFriendsOfSuggestions).
 * 
 * Input:
 * 1. The number of elements in friendSuggestions and numFriendsOfSuggestions (x)
 * 2. The number of friends that each of the suggested users have (numFriendsOfSuggestions)
 * 3. The names of all the suggested users to be friends with the selected user (friendSuggestions)
 */
void sort(int x, int numFriendsOfSuggestions[], char friendSuggestions[][80]) {
    //temporary string used for swapping two strings
	char swap [80];
    //array index containing maximum element
	int maxIndex;

	//one by one, traverse through boundary of unsorted subarray
	for (int i = 0; i < x - 1; i++){
		//find the maximum element in unsorted array 
		maxIndex = i;
		for (int j = i + 1; j < x; j++) {
            //if a new maximum element is found, update the maximum index
			if (numFriendsOfSuggestions[j] > numFriendsOfSuggestions[maxIndex]) {
				maxIndex = j;
            }
            /*
            Since we need to sort the friend suggestions alphabetically (increasing order),
            here maxIndex actually acts as the minimum index instead of maximum.
            However, only two names are compared at a time, so we do not need a new variable 
            for minIndex, and maxIndex can be used. 
            maxIndex is updated if two users who have the same number of friends need to be swapped
            in order to sort them lexicographically.
            */
            if ((strcmp(friendSuggestions[j], friendSuggestions[maxIndex]) < 0) && 
                (numFriendsOfSuggestions[j] == numFriendsOfSuggestions[maxIndex])) {
				maxIndex = j;
            }
        }
        
        //swap the found maximum element with the first element 
		int k = numFriendsOfSuggestions[i];
		numFriendsOfSuggestions[i] = numFriendsOfSuggestions[maxIndex];
		numFriendsOfSuggestions[maxIndex] = k;
        //swap the respective friend suggestions as well
		strcpy(swap, friendSuggestions[i]);
		strcpy(friendSuggestions[i], friendSuggestions[maxIndex]);
		strcpy(friendSuggestions[maxIndex], swap);
	}
}
//end of sorting.c file