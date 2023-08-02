//To solve the problem in C, we'll follow the same steps as in the previous everydayassinments

/* to uderstand this see comments in earlier EverydayAssignment s
   we're doing the same thing here that we did there,
   add on...that,
   Plotting the Frequency Distribution of Highest base Frequency over Random 50 Integers
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
    
    /* Find the maximum frequency for
	 plot (print) the Frequency Distribution over different bases on x-axis */
	int max=0;
	for(i=0;i<9;i++)
	{
	    if(max<B[i])
	    max=B[i];
	}
	
	// Print the frequency distribution over different bases on x-axis
	printf("\n\n\tthe Frequency Distribution over different bases on x-axis -->\n\n");
	
	while(max)
	{
		printf("\t\t");
		for(i=0;i<9;i++)
		{
// Print an asterisk (*) if the frequency of the current base is greater than or equal to 'max'	
			if(B[i]>=max)
			printf("* ");
// Print a space if the frequency is less than 'max', to maintain spacing			
			else
			printf("  ");
		}
		printf("\n");
		max--;
	}
	
	// Print the base numbers on the x-axis
	printf("\t\t");
	for(i=2;i<=10;i++)
	printf("%d ",i);
	
	// Print the label for the BASE on the y-axis
	printf("\n\n\t\t       BASE");

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

Finding the maximum frequency:
The loop iterates over the array b of size 9 once to find the maximum value.
This has a time complexity of O(1),
bcoz where n (fixed) is the size of the array (in this case, n = 9).

Printing the frequency distribution:
The outer loop runs 'max' times,
where 'max' is the maximum frequency found in step 1.
The inner loop iterates over the array B of size 9,
and for each iteration,
it performs constant time operations (printing asterisk or space).
So, the time complexity of printing the frequency distribution is O(n * max),
where n is the size of the array (in this case, n = 9).

Printing the base numbers on the x-axis and the label for the BASE on the y-axis:
These parts have a constant time complexity as they only involve printing fixed values.

Overall, the time complexity of the program is O(1) 
(bcoz in this case or program we have all things is fixed,
in can be O(n) if we give values as variable, at run time)
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
