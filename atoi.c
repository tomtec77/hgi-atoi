/**
 * @file atoi.c
 * @author Tomas E. Tecce
 *
 * MIT Hacking a Google Interview Handout 1
 * Question: Create a function that converts a string to an integer
 */
#include <stdio.h>
#include <stdlib.h>

int stringtoint(char *);


int main(int argc, char **argv)
{
	int number;

	/* Input section: read the string input by the user, checking that the
	   user actually did input something */
	if (argc < 2) {
		fprintf(stderr, "Error: no string given - Exit\n");
		fflush(stderr);
		exit(EXIT_FAILURE);
	}

	/* This line is to check the string conversion - we attempt to print
	   the input directly */
	printf("Check: %d\n", (int)(*(argv+1)));

	number = stringtoint(*(argv+1));
	printf("Converted number: %d\n", number);

	return EXIT_SUCCESS;
}


/*
 * This is the function that does the trick. The idea is to go over the
 * string (character array) element by element. Starting at the beginning,
 * check if the first character is a minus sign (to establish the sign of
 * the number).
 * Problems of this implementation:
 *     - It assumes that the string given is composed of digits only, with
 *       an optional negative number at the beginning.
 *     - For large numbers it will give a wrong result due to overflow.
 */
int stringtoint(char *text)
{
	int i;
	int number=0, offset=0, sign=1;

	/* Start by checking if the first character is a minus sign. If it is,
	   increase the offset to skip it when reading the digits */
	if (text[0] == '-') {
		sign   = -1;
		offset = 1;
	}

	/* Read the character array until the string terminator '\0' is
	   found. We make use of the fact that char numbers have a consecutive
	   numeric code value (which is not necessarily 0 for the char '0',
	   thus the need to substract the offset). As we move along the array,
	   we multiply the previous count by 10 */
	for (i=offset; text[i] != '\0'; i++)
	  number = number*10 + text[i] - '0';

	return sign*number;
}
