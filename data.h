//
// Created by dalek_cos on 18/12/2017.
//

#ifndef DHONT_DATA_H
#define DHONT_DATA_H

#include <stdio.h>

#define STRING_SIZE 15

typedef struct party_t{
	char name[STRING_SIZE];
	unsigned int votes,seats;
}Party;


#define PRINT_P(p) printf("%s: %u seats\n",p.name,p.seats)

/**
 * Gets a party from a given file
 *
 * @param file The file where the party (or parties) are contained
 * @return a party with its votes as they appear in the file, and its seats set to zero
 */
Party get_party_from_file(FILE *file);

unsigned int sum_votes(Party *parties, const unsigned int n_parties);

#endif //DHONT_DATA_H
