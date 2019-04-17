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
void sort(int x, int numFriendsOfSuggestions[], char friendSuggestions[][80]);