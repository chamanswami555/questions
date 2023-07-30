//To solve the problem in C, we'll follow the same steps as in the previous everydayassinments

/* to uderstand this see comments in EverydayAssignment1.c
   we're doing the same thing here that we did there,
   add on...that,
   Count how many Random Integers belong to different highest bases
   (Highest base Frequency over different bases) */
   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer with 10 digits and last digit >= 5
int gri()
{
    return (rand() % 5000000000) + 5000000000;
}

// Function to find the highest base of an integer
int base(int num)
{
    int b = 1;
    while (num > 0)
	{
        int r = num % 10;
        if (r > b)
            b = r;
        num /= 10;
    }
    return b + 1;
}

int main()
{
    srand(time(0));

    int B[9] = {0}; // Array to store the count of different highest bases (2 to 10)

    printf("\tRandom Integers and their Highest Bases:-\n");
    int i;
    for (i = 0; i < 50; ++i)
	{
        int rn = gri();
        int boq = base(rn);

        // Ensure the highest base is within the valid range (2 to 10)
        if (boq >= 2 && boq <= 10)
		{
            B[boq - 2]++; // Increment the count for the respective highest base ~from JAS sirji's HINT...
            printf("\t\tThe Highest Base of %d is %d.\n", rn, boq);
        }
    }

    printf("\n\tHighest Base Frequency over different bases:-\n");
    for (i = 0; i < 9; ++i)
	{
        printf("\t\tBase %d: %d occurrence(s).\n", (i + 2), B[i]);
    }

    return 0;
}

/*
Time Complexity Analysis :-

Generating 50 random integers: The time complexity of generating each random integer is constant, 
O(1), because the rand() function takes constant time to produce a random number.
Generating 50 random integers would also be constant, as the number of iterations is fixed.

Finding the highest base of each integer: For each 10-digit integer,
we need to examine all its digits to find the highest one.
Since the number of digits in the integer is fixed (10 digits),
this operation takes O(1) time, as the number of iterations is constant.

Overall, the time complexity of the program is O(1) 
because the dominant operation across all steps is performed a constant number of times,
and the input size (50 integers) does not affect the overall time complexity.
*/

/* NOTE!
In theoretical time complexity analysis,
constants are ignored as they don't change with input size.
However, in practice, the actual execution time will depend on various factors,
including the efficiency of the random number generator and other hardware-specific considerations.
i mean i want to explain that in this program we have fixed input size,
by the way anything can happen */

//                  ~chamanswami
