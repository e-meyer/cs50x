#include <cs50.h>
#include <stdio.h>

void staircaseMaker(int input);

int main(void)
{
    int height;

	    do
        {
	        height = get_int("Height: ");
	    }
        while (height < 1 || height > 8);

	staircaseMaker(height);
}

//
// The function bellow will print the staircase asked, the default one and the mirrored aswell.
//

void staircaseMaker(int height)
{

	int counter_default_staircase = 1;
//
// The variable 'counter_default_staircase' will help knowing how many hashes
// are going to be printed in the second staircase, starting by 1.
//
	for (int a = height; a > 0; a--)
    {
//
// variable 'a' stores 'height' so we don't have to decrease
// variable 'height's value, which will be used later on
//
		for (int i = 0; i < a - 1; i++)
        {
			printf(" ");
        }
//
// I've tried using C's print function 'printf("%*s", <width>, "")' to print the
// hases in the right position without needing to print blank spaces, but it didn't
// work as I wanted it to, at least not in the 'more' part of Mario's problem, so I
// made another 'for' function to print the spaces.
//

		for (int i = a; i <= height; i++)
        {
			printf("#");
        }
//
// The 'for' function above will print the number of hashes needed in each row
//
// The variable 'i' stores 'a' to know how many hashes will be printed
//
// If we didn't create a variable 'a' in the initial 'for' function, we would
// have to decrease the value of 'height', which is also needed to control the
// number of hashes that will be printing in the function above.
//

		printf("  "); // space to split the staicases

		for(int i = 0; i < counter_default_staircase; i++)
        {
		    printf("#");
        }
//
// This last 'for' will be printing the default staircase
//
// Every loop of the first 'for', the variable will be increasing it's number
// by 1, as it's possible to see down below, so we know how many times the 'for'
// loop needs to run
//

        counter_default_staircase++;

		printf("\n");
	}


}
