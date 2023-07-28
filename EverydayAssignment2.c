// to uderstand this see comments in EverydayAssignment1.c
// we're doing the same thing here that we did there, but here we're doing it for 50

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int base(long long int num) {
    int b = 0;
    
    while (num > 0) {
        int r = num % 10;
        if (r > b) {
            b = r;
        }
        num /= 10;
    }

    return b + 1;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));
    
    printf("Generating 50 random integers with 10 digits...\n");
    int i;
    for (i = 0; i < 50; i++) {
        // Generate a random 10-digit integer with the last digit at least 5
        long long int rn = 5000000000 + rand() % 5000000000;;

        // Calculate the highest base of the generated integer
        int B = base(rn);

        printf("The Highest Base of %lld is %d.\n", rn, B);
    }

    return 0;
}
/*
Time Complexity Analysis :-

Generating 50 random integers: Generating a single random integer takes constant time (O(1)),
so generating 50 random integers will also take constant time.

Calculating the highest base for a 10-digit integer:
The base function contains a while loop that iterates over each digit of the 10-digit integer.
Since the number has a fixed length of 10 digits,
the loop will execute 10 times for each call to the function, making it O(1) in this context.

Considering both parts together,
the overall time complexity of the program remains O(1).
This is because generating 50 random integers and calculating the highest base for each integer
both have constant time complexities,
and the number of operations remains the same regardless of the input size.
*/

//                  ~ chamanswami
