#include <stdio.h>
#include <stdlib.h>

void print_map(int **map);

int main(){

	int map[10][10];
	int random_number;
	int i;
	int j;

	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			random_number = rand() % 100;

			//Empty Space
			if(random_number < 60){
				map[i][j] = 0;
			}
			//Asteroids
			else if(random_number < 90){
				map[i][j] = 1;
			}
			//Gravity Well
			else{
				map[i][j] = 2;
			}
		}
	}
	return 0;
}