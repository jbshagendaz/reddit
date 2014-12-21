#include <stdio.h>

int main(){
	
	int num_arr[10];
	int i,j   = 0;
	int input = 0;
	int sum   = 0;

	printf("Please enter up to 10 numbers to be added together (enter to quit)\n");

	for(i=0; i<10 && input >= 0; i++)
	{
		input = -1;
		printf("Please enter number %d: ", i);
		scanf("%d", &input);

		if(input > 0)
		{
			num_arr[i] = input;	
		}
	}

	for(j=0; j<i; j++)
	{
		printf("%d\n", num_arr[j]);
		sum+= num_arr[j];
	}

	printf("------\n");
	printf("%d", sum);





	return 0;
}