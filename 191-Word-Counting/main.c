#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trim(char* str);
char* to_lower_case(char* str);

int main()
{
	char in_word[512];
	char out_word[512];

	int counter  = 0;
	int read_at = 0;

	FILE *input;
	FILE *output;

	input  = fopen("/Users/jb/Documents/workspace/sublime/reddit/191-Word-Counting/input.txt", "r");
	output = fopen("/Users/jb/Documents/workspace/sublime/reddit/191-Word-Counting/output.txt", "w+");

	while(fscanf(input, "%s", in_word) == 1)
	{
		trim(to_lower_case(in_word));
		int test = fscanf(output, "%s : %d", out_word, &counter);
		printf("%d\n", test); 
		while( test == 2)
		{
			if(strcmp(in_word, out_word) == 0)
			{
				read_at = ftell(output);
				counter++;
			}

			else
			{
				counter = 0;
			}
		}

		if(read_at != 0)
		{
			fseek(output, read_at, SEEK_SET);
		}

		fflush(output);
		fprintf(output, "%s : %d\n", in_word, counter);
		fflush(output);
		read_at = 0;
	}

	fclose(input);
	fclose(output);
	return 0;
}

char* trim(char* str)
{
	return str;
}

char* to_lower_case(char* str)
{
	char* ptr = str;

	while(*ptr != '\0')
	{
		if(*ptr <= 0x5A && *ptr >= 0x41)
		{
			*ptr += 0x20;
		}

		ptr++;
	}

	return str;
}