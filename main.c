//
// Created by Eduardo Castillo on 17/12/2017.
//

#include <stdio.h>
#include "data.h"
#include "saint_lague.h"

#define DEFAULT_FILE_NAME "votes.txt"

//This function processes the data once it has been acquired  in the main.
void process(Party *parliament, const unsigned int n_parties, const unsigned int available_seats,
			 const unsigned int min_percentage){
	unsigned int i; //for iteration purposes

	//first, enforce minimum percentage policy if there is one (if the minimum barrier is greater than 0)
	if(min_percentage > 0) enforce_min_percentage_policy(parliament,n_parties,min_percentage);

	//after enforcing minimum percentage policy, distribute the votes
	sl_distribute(parliament, n_parties, available_seats);

	//print the results
	for(i = 0; i < n_parties;i++) if(parliament[i].seats != 0) PRINT_P(parliament[i]);
}

//The main acquires the data and passes it to the process function
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