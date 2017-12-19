//
// Created by dalek_cos on 18/12/2017.
//

#include "saint_lague.h"

#define SL_FORMULA(p) ((p).votes/(2*(p).seats + 1))

void sl_distribute(Party *parliament, const unsigned int n_parties, const unsigned int n_seats) {
	unsigned int i;
	/*
	ALGORITHM:
	1. Apply Hont's formula to each party
	2. Assign a seat to the party with most votes
	3. Repeat until all seats are assigned
	*/
	for(i = 0; i < n_seats;i++){
		//get the major party according to the formula
		unsigned int max_sl = 0,max_sl_index = 0,p;
		for(p = 0; p < n_parties;p++){
			const unsigned int sl = SL_FORMULA(parliament[p]);
			if(sl > max_sl){
				max_sl = sl;
				max_sl_index = p;
			}
		}

		//now we have the index of the major party, we use it to increase its seats by one
		parliament[max_sl_index].seats++;
	}
}
