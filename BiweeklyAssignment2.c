/* Program to generate a Random Alphanumeric String and Find possible Palindromes by rearranging the Characters of the String. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(int);                 // Factorial function Declaration.

int factorial(int num){                 // Factorial function Definition.
    if(num == 0|| num == 1){
        return 1;
    }
    else{
        return (num * factorial(num-1));
    }
}

int main()
{

    char set[61] = "Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9KkLlMmNnOoPpQqRrSsTtUuVvWwXxYy";             // Initial character set from where the Characters of Random String  will be picked.
    time_t t;
    int *freq = (int*)calloc(123, sizeof(int));
    int odd_len[4] = {5, 7, 9, 11};                 // Possible Odd Length sizes of the Palindrome String. 
    int even_len[3] = {6, 8, 10};                   // Possible Even Length sizes of the Palindrome String.
    int palindrome_len = 0, position, Twos_counter = 0;
   
    srand((unsigned) time(&t));               // srand() function to seed the rand() function used in the program.


    int toss = rand() % 20 + 20;              // Toss to decide whether the String length will be odd or even.
    if(toss < 30){                  
        position = rand() % 4;
        palindrome_len = odd_len[position];
    }
    else if(toss >= 30){
        position = rand() % 3;
        palindrome_len = even_len[position];
    }

    int palindrome_string[palindrome_len];             // Creating an array of appropriate size to store the character of the palindrome String.

    int palindrome_size = sizeof(palindrome_string)/sizeof(palindrome_string[0]);                    // Finding out the Size of the Palindrome String.


    /* Generating the Palindrome String. */

    if(palindrome_size % 2 == 0){             // Generating an Even sized Palindrome String.
      
        int limit = palindrome_size/2;                   
      
        for(int i = 0; i < limit; i++ ){
            int even_position = rand() % 60; 
            palindrome_string[i] = palindrome_string[(palindrome_size-1) - i] = set[even_position];              // Mirroring character assignment to Create a Palindrome.(Typecasting from CHAR to INT)
        }
    }
    else{                                     // Generating an Odd sized Palindrome String. 
        int limit = palindrome_size/2;

        for(int i = 0; i < limit; i++){
            int odd_position = rand() % 60;
            palindrome_string[i] = palindrome_string[(palindrome_size-1) - i] = set[odd_position];               // Mirroring character assignment to Create a Palindrome.(Typecasting from CHAR to INT)
        }
        palindrome_string[limit] = set[rand() % 60];              // Placing the Middle Character in the Odd length Palindrome.
    }


    /* Taking stock of the Frequencies of the Characters Occurring in the Generated String. (It will be required later to find the Number of possible combinations) */

    for(int i = 0; i < palindrome_len; i++)                 // Loop to Get the frequency of the Characters Occurring in the Palindrome String.                            
    {
        int temp = palindrome_string[i];
        freq[temp] = ++ freq[temp];
    }

    for( int m = 0; m < 123; m++){                  // Loop to Cycle through all the Stored Frequency values.
     /* if(*(freq + m) > 0)                                          
            printf("%c. Freq of %c is %d\n", m, m, *(freq + m)); */              // Option to print the Frequencies of the Characters in the Palindrome.
       
        if(*(freq + m) >= 2){                   // Counting the Characters which are occuring at least Once.
            Twos_counter = ++Twos_counter;
        }
    }


    /* Staggered Print statements to Print the Required Output. */

    printf("The Randomly Generated Palindrome String is --> ");
    for(int j = 0; j < palindrome_size; j++){                   // Loop to print the Randomly generated Palindrome String.
        printf("%c", palindrome_string[j]);
    }

    int possible_outcomes = factorial(Twos_counter);                    // Using PnC to find the Total Possible Combinations that can be created.

    printf("\n\nAnd a total of %d Palindrome Strings can be generated from it, which are as follows: \n\n", possible_outcomes);

    for (int j = 0; j < possible_outcomes; j++){                   // Nested Loop statements to Generate and Print the possible combinations of the Palindrome String.

        for (int i = 0; i < ((palindrome_size/2)-1); i++){                  // Loop to Swap around the Palindrome Characters to Generate new Palindrome Combinations.

            int temp = palindrome_string[i];                    

            palindrome_string[i] = palindrome_string[(palindrome_size-1) - i] = palindrome_string[i+1];

            palindrome_string[i+1] = palindrome_string[(palindrome_size-1) - (i+1) ] = temp;
        }

        for(int k = 0; k < palindrome_size; k++){                   // Loop to print the newly generated Palindrome Combination.
            printf("%c", palindrome_string[k]);
        }

        printf("\n");
    }   
}
