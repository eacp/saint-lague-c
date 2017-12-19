//
// Created by Eduardo Castillo on 17/12/2017.
//

#ifndef DHONT_DATA_H
#define DHONT_DATA_H

#include <stdio.h>

#define STRING_SIZE 15

//A party.
typedef struct party_t{
	char name[STRING_SIZE];
	unsigned int votes,seats;
}Party;

//prints a party
#define PRINT_P(p) printf("%s: %u seats\n",p.name,p.seats)

/**
 * Gets a party from a file.
 *
 * The file is a FILE variable. After scanning the file, the file can be used to read the next
 * party, or anything. This functions consumes the data from the file.
 * It can be used to scan various parties in a single file.
 *
 * @param file The file where the party(ies) is(are)
 * @return a single party
 */
Party get_party_from_file(FILE *file);

/**
 * Sums the votes of the parties in a given array
 *
 * @param parties An array of parties
 * @param n_parties The number of parties in the array
 * @return the sum of the votes of those parties
 */
unsigned int sum_votes(Party *parties, const unsigned int n_parties);

/**
 * Enforces a policy some countries have about an entry barrier or minimum percentage,
 * in which if a party doesn't reach a given percentage, the party won't be taken into account.
 *
 * @param parties Array of parties
 * @param np Number of parties
 * @param min The minimum percentage
 */
void enforce_min_percentage_policy(Party *parties, const unsigned int np, const unsigned int min);

#endif //DHONT_DATA_H
