#include <stdio.h>
#include "data.h"
#include "saint_lague.h"

#define DEFAULT_FILE_NAME "votes.txt"

void process(Party *parliament, const unsigned int n_parties, const unsigned int available_seats,
			 const unsigned int min_percentage){
	unsigned int i;

	//first, enforce minimum percentage policy if there is one (if the minimum barrier is greater than 0)
	if(min_percentage > 0){
		//if the votes of a party are less than required, they are like 0, they wont be taken into account
		const unsigned int min_votes = (unsigned int)(sum_votes(parliament,n_parties)*(min_percentage/100.0f));
		for(i = 0; i < n_parties;i++) if(parliament[i].votes < min_votes) parliament[i].votes = 0;
	}

	//after enforcing minimum percentage policy, distribute the votes
	sl_distribute(parliament, n_parties, available_seats);

	//print the results
	for(i = 0; i < n_parties;i++) if(parliament[i].seats != 0) PRINT_P(parliament[i]);
}

int main(int argv,char **argc) {
	//get the file
	//if a file location is provided, use that file, otherwise use the default name
	FILE * f = fopen(argv == 2 ? argc[1] : DEFAULT_FILE_NAME,"r");

	//no file available :o>
	if(!f){
		//the user provided a file name
		if(argv == 2) puts("ERROR: The specified file cannot be reached");
		//the user provided no file name
		else puts("ERROR: No file name was provided and the file '" DEFAULT_FILE_NAME "' cannot be reached");
		return 0;
	}

	//firs line: How many parties, seats and the minimum percentage
	unsigned int p,s,m,i; fscanf(f,"%u %u %u",&p,&s,&m); //get the parties, seats and minimum percentage

	//get the data
	Party parties[p];
	for(i = 0; i < p;i++) parties[i] = get_party_from_file(f);

	//pass the data to the second main and never think of the file again
	fclose(f);
	process(parties, p, s, m);

	return 0;
}