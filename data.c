//
// Created by dalek_cos on 18/12/2017.
//

#include "data.h"

Party get_party_from_file(FILE *file) {
	Party p;
	fscanf(file,"%s %u",p.name,&p.votes);
	p.seats = 0;
	return p;
}

unsigned int sum_votes(Party *parties, const unsigned int n_parties) {
	unsigned int sum = 0,i;
	for(i = 0; i < n_parties;i++) sum+=parties[i].votes;
	return sum;
}