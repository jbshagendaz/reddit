/***
iso 8601 standard for dates tells us the proper way to do an extended day is yyyy-mm-dd

    yyyy = year
    mm = month
    dd = day

A company's database has become polluted with mixed date formats. They could be one of 6 different formats

    yyyy-mm-dd
    mm/dd/yy
    mm#yy#dd
    dd*mm*yyyy
    (month word) dd, yy
    (month word) dd, yyyy

(month word) can be: Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec

Note if is yyyy it is a full 4 digit year. If it is yy then it is only the last 2 digits of the year. Years only go between 1950-2049.
***/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const char *month_array[12] = {
	    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
	    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	
	char in_date[25];
	char month_str[4];
	
	int year  = 0;
	int month = 0;
	int day   = 0;

	FILE *input;
	FILE *output;

	input = fopen("/Users/jb/Documents/workspace/reddit/188-YYYY-MM-DD/input.txt", "r");
	output = fopen("/Users/jb/Documents/workspace/reddit/188-YYYY-MM-DD/output.txt", "w");
	
	while(fgets(in_date, 25, input)){
		if (sscanf(in_date, "%d-%d-%d", &year, &month, &day) == 3){}
		else if(sscanf(in_date, "%d/%d/%d", &month, &year, &day) == 3){}
		else if(sscanf(in_date, "%d#%d#%d", &month, &year, &day) == 3){}
		else if(sscanf(in_date, "%d*%d*%d", &day, &month, &year) == 3){}
		else if(sscanf(in_date, "%s%d%d", month_str, &day, &year) == 3){
			for(int i=0; i<11; i++){
				if(strcmp(month_str, month_array[i]) == 0){
					month = i + 1;
					break;
				}
			}
		}


		if(year <=49){
			year += 2000;
		}
		else if (year >= 50 && year < 100){
			year += 1900;
		}
		printf("%d-%02d-%02d\n", year, month, day);
		fprintf(output, "%d-%02d-%02d\n", year, month, day);
	}

	fclose(input);
	fclose(output);

	return 0;
}