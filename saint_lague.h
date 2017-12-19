//
// Created by Eduardo Castillo on 17/12/2017.
//

#ifndef SAINT_LAG_H
#define SAINT_LAG_H

#include "data.h"

/**
 * Distributes the seats of a parliament between some parties
 * Implements the Saint-Lagüe Method for distributing seats in a proportional representation system
 * Usage:
 *
 * sl_distribute(arrayOfParties,len,8) will distribute 8 seats among the parties in the array.
 *
 * The function modifies the value 'seats' in each element of the array.
 *
 * @param parliament array of parties
 * @param n_parties number of parties
 * @param n_seats number of seats to distribute between the parties
 */
void sl_distribute(Party *parliament, const unsigned int n_parties, const unsigned int n_seats);

#endif //SAINT_LAG_H