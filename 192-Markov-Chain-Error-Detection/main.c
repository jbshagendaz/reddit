#include <stdio.h>

//not needed but w/e
struct markov_table {
	long table[26][26];
};

//used to print the markov table after input reading
void print_markov_table(struct markov_table *markov_table){
	
	//used ascii lowercase and input was all lower case
	char x = 0x61;
	char y = 0x61; 

	//prints the x-axis label
	for(x=0x61; x<0x7B; x++){
		printf("\t%c", x);
	}

	printf("\n");
	
	//prints the x-axis label and data
	for(x=0x61; x<0x7B; x++){
		printf("%c", x);

		for(y=0x61; y<0x7B; y++){
			printf("\t%ld", markov_table->table[x-0x61][y-0x61]);
		}

		printf("\n");
	}
}

double check_word(char *word, struct markov_table *markov_table){
	char curr_char;
	char prev_char;
	int i = 0;
	int j = 0;
	long char_percent = 0;
	double percent = 0.0;

	while(word[i] != '\0'){
		if(i != 0){
			prev_char = word[i-1];
			curr_char = word[i];


			if(markov_table->table[prev_char-0x61][curr_char-0x61] > 0){
				for(j=0; j<26; j++){
					char_percent += markov_table->table[prev_char-0x61][j];
				}
				percent += (double) markov_table->table[prev_char-0x61][curr_char-0x61]/char_percent;	
				//printf("%c -> %c: %ld - %lf\n", prev_char, curr_char, markov_table->table[prev_char-0x61][curr_char-0x61], percent);
			}
			
			else{
				return 0.0;
			}
		}

		i++;
	}

	return (percent/i)*100;
}

int main(int argc, char *argv[]){
	char in_word[512];
	char curr_char;
	char prev_char;
	int i;

	struct markov_table markov_table = {0};
	FILE *input = fopen("input.txt", "r");

	while(fscanf(input, "%s", in_word) == 1){
		i = 0;
		while(in_word[i] != '\0'){
			if(i != 0){
				prev_char = in_word[i-1];
				curr_char = in_word[i];

				markov_table.table[prev_char-0x61][curr_char-0x61]++;
			}

			i++;
		}
	}

	print_markov_table(&markov_table);

	for(i=1; i<argc; i++){
		printf("%s: %lf\n", argv[i], check_word(argv[i], &markov_table));
	}

	return 0;
}