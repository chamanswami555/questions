/*
Here's a summary of the provided code:

This code generates a random alphanumeric palindrome string of a specified length
and then generates and prints a series of possible palindrome strings by rearranging characters within the original palindrome string.

Summary:

-The code begins by including necessary header files for input/output operations (stdio.h),
memory allocation (stdlib.h), and time functions (time.h).

-The generateRandomPalindrome function is defined to create a random palindrome string.
It takes an integer length as input and allocates memory for the string.
The function constructs the string symmetrically by selecting random characters from a predefined set of alphanumeric characters.
It ensures that the generated string is a palindrome by copying characters symmetrically. If the length is odd,
a middle character is assigned randomly. The function returns the generated palindrome string.

-The GeneratingandPrintPossibleCombinations function
is defined to generate and print various combinations of the given palindrome string.
It takes the palindrome string, its length, and the number of possible outcomes as inputs.
This function swaps characters symmetrically within the string and prints each combination. 
It repeats this process for the specified number of possible outcomes.

In the main function:

-The random seed is initialized to ensure randomness in the generated strings.
-A random palindrome size between 7 and 11 is generated.
-A random palindrome string is generated using the generateRandomPalindrome function.
-The original palindrome string is printed.
-The number of possible outcomes (half of the palindrome size) is calculated.
-The GeneratingandPrintPossibleCombinations function is called to generate and print possible combinations of the palindrome string.
-The dynamically allocated memory for the palindrome string is freed.
-The program returns 0 to indicate successful execution.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function to generate a random alphanumeric palindrome string of a given length
char *generateRandomPalindrome(int length)
{
    // Allocate memory for the string
    char *str = (char *)malloc((length + 1) * sizeof(char));

    // Define the possible characters in an alphanumeric string
    char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    // Initialize a random seed
    srand(time(NULL));

    // Loop through half of the length
    int i;
    for (i = 0; i < length / 2; i++)
    {
        // Pick a random character from the array of chars
        int index = rand() % 62;

        // Assign the character to both ends of the string symmetrically
        str[i] = chars[index];
        str[length - i - 1] = chars[index];
    }

    // If the length is odd, assign a random character to the middle of the string
    if (length % 2 == 1)
    {
        int index = rand() % 62;
        str[length / 2] = chars[index];
    }

    // Terminate the string with a null character
    str[length] = '\0';

    // Return the string
    return str;
}

// a function for Generating and printing possible combinations of the palindrome string
void GeneratingandPrintPossibleCombinations(char *palindrome_string, int palindrome_size, int possible_outcomes)
{
    int i,j;
    
    // Loop through possible outcomes
    for (j = 0; j < possible_outcomes; j++) 
	{
		// Loop through half of the palindrome_size - 1
        for (i = 0; i < ((palindrome_size / 2)-1); i++) 
		{
			// Swap characters symmetrically around the center of the string
            int temp = palindrome_string[i];
            palindrome_string[i] = palindrome_string[(palindrome_size - 1) - i] = palindrome_string[i + 1];
            palindrome_string[i + 1] = palindrome_string[(palindrome_size - 1) - (i + 1)] = temp;
        }
        // Print the generated palindrome string
        printf("\t%s", palindrome_string);
        printf("\n");
    }

}

int main()
{
	int i,j,k,m;

    // Initialize a random seed
    srand(time(NULL));
    
    // Generate a random size between 5 to 11
    int palindrome_size = rand() % 5 + 7;
    
    // Generate a random palindrome string
    char *palindrome_string = generateRandomPalindrome(palindrome_size);

    // Printing the randomly generated palindrome string
    printf("\tThe Randomly Generated Alphanumeric Palindrome String is --- %s",palindrome_string);

    // Calculate the possible outcomes (unique)
    int possible_outcomes = palindrome_size/2;

    printf("\n\n\tAnd total %d Palindrome Strings can be generated from this Palindrome Strings ---:\n\n", possible_outcomes);
    
    // Generate and print possible combinations of the palindrome string
    GeneratingandPrintPossibleCombinations(palindrome_string, palindrome_size, possible_outcomes);
    
    // Free the dynamically allocated memory
    free(palindrome_string);

    return 0;
}

/*
Summary:
Overall, this code demonstrates the generation of a random palindrome string
and then showcases different combinations of the characters within the palindrome string,
providing insight into the symmetrical nature of palindromes.
*/

/*
Time Complexity:

Generating Random Palindrome String: The generateRandomPalindrome function loops through half of the given length, 
which is approximately length/2. Inside the loop, 
it performs constant time operations such as character assignments and random number generation. 
Additionally, if the length is odd, an extra character is assigned in constant time. 
Therefore, the time complexity of generating a random palindrome string is O(length/2), 
which can be simplified to O(n), where n is the length of the palindrome string.

Generating and Printing Possible Combinations: 
The GeneratingandPrintPossibleCombinations function has two nested loops. 
The outer loop runs possible_outcomes times, and the inner loop runs palindrome_size / 2 - 1 times. 
Within the inner loop, swapping characters and printing takes constant time. 
Thus, the time complexity of this function is O(possible_outcomes/2 * palindrome_size), which can also be simplified to O(n^2),
where n is the length of the palindrome string.

Overall, the dominant factor in time complexity is the generation and printing of possible combinations of the palindrome string.

Space Complexity:

Random Palindrome String:
The generateRandomPalindrome function dynamically allocates memory for the palindrome string of length length + 1.
Therefore, the space complexity for the palindrome string is O(length).

Other Variables:
The chars array occupies constant space, and other variables used for indexing, counting, and temporary storage occupy constant space.

Function Call Overheads:
The space occupied by function call overheads, such as local variables and the return address, is also constant.

Overall, the space complexity is primarily determined by the dynamically allocated palindrome string and is O(length).

In summary, the time complexity of your code is O(n^2) where n is the length of the palindrome string, and the space complexity is O(length).
*/

//                  ~chamanswami
