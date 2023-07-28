// include necessary header files
#include <stdio.h> // for input/output functions
#include <stdlib.h> // for using the rand() or srand() functions
#include <time.h> // for generate the random number generator with the current time

/* The base function takes an integer number as input
   and returns the maximum digit present in that number that equal to his base */
int base(int n)
{
    int m = 0;
    
   /* using a while loop,
	  we extract the last digit of the number using the modulo operator (%).
	  We then compare this digit with the current maximum digit (m),
	  and if it is greater, we update m to this digit. */
    while (n > 0)
	{
        int r = n % 10;
        if (r > m)
		{
            m = r;
        }
        n /= 10;
    }
    return m;
}

// The main function is where the execution of the program starts.
int main()
{
    // Seed the random number generator
    srand(time(NULL));
    /* This sets the seed value for the random number generator to the current time,
	   ensuring different random values on each program run. */

    // Generate a random integer with 10 digits and the last place digit is at least 5
    
    int long long rn = 5000000000 + rand() % 5000000000;
    /* The need for using long long int arises
	   bcoz the range of values by the int data type
	   is not sufficient for the problem requirements.*/
	   
    /* this will give us a random value in the range 0 to 4999999999.
	   By adding 5000000000, we shift the range to 5000000000 to 9999999999. */

    // Calculate the highest base of the integer
    int B = base(rn) + 1;

    // Print the random integer and its highest base
    printf("The random integer is: %d\n", rn);
    printf("The Highest Base of the random integer is: %lld\n", B);

    return 0;
}

/* Time Complexity Analysis:

The base function loops through the digits of the given integer number.
The number of digits in an integer n is approximately log10(n) + 1.
In the worst case,
the base function will loop through all the digits,
which means the time complexity of this function is O(log10(n)).

Generating the random integer and calculating the highest base are
both simple operations and do not contribute significantly to the time complexity.

Therefore,
the overall time complexity of the program is dominated by the base function,
which is O(log10(n)).
In this program,
the time complexity is not directly dependent
on the number of digits in the random integer (which is fixed at 10 in this case).
It depends on the value of the random integer itself
and is logarithmic with respect to that value. */

/* The given C program generates a random 10-digit integer
   with the last place digit being at least 5.
   It then calculates and prints the highest base of the generated integer. */
   
/* Overall, this program demonstrates how to generate a random integer
   with specific requirements and calculate the highest base of that integer
   using a user-defined function. It showcases the usage of random number generation,
   basic arithmetic operations, and function calls in C programming. */
   
//                  ~chamanswami
