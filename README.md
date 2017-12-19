# Saint-Lagüe distribution method

This is a program/library to calculate the distribution of seats
in an election for a parliament, congress, etc. It uses
the [Webster/Saint-Lagüe method](https://en.wikipedia.org/wiki/Webster/Sainte-Laguë_method)
to make the distribution.

__I'M NOT RESPONSIBLE FOR THE USE OF THIS CODE NOR ITS RESULTS__,
though I'm confident on the implementation.

## Context
The *Webster/Saint-Lagüe method* is a way to distribute seats in a proportional
representation system according to the votes. It is used to assign seats to
political parties when it is not possible to assign decimal seats. It generally tends
to favor smaller parties.

## Usage:

### Standalone executable
You may compile the source code to
produce an executable.
The data is provided in an input file like this:

__westeros.txt__

    9 20 3
    Stark 731320
    Targayren 62352
    Lannister 751748
    Arryn 82765
    Baratheon 145045
    Tully 119083
    Tyrell 49378
    Greyjoyl 64529
    Martell 254812
    
The first line has three numbers: 9,20 and 3. 
The first number (9) indicates the number of parties
(in this case houses). The second number (20) indicates the number
of seats to distribute, and the third number (3) indicates
the *barrier*. Some countries have a minimum percentage 
a party has to meet in order to receive a seat. In westeros case
it is 3%. Each line forward indicates the name of the party and how
many votes it got.

To calculate the distribution, you do:

```
$ ./saint-lague westeros.txt
```

And the output will be:

    Stark: 7 seats
    Lannister: 7 seats
    Arryn: 1 seats
    Baratheon: 1 seats
    Tully: 1 seats
    Martell: 3 seats
    
Another example:

__fruitland.txt__

    5 50 0
    Pear 130755
    Apple 102068
    Grapefruit 34012
    Orange 31090
    Grape 11111

```
$ ./saint-lague fruitland.txt
Pear: 21 seats
Apple: 17 seats
Grapefruit: 5 seats
Orange: 5 seats
Grape: 2 seats
```

### As a library
You may use this code as a library by including the headers
`data.h` and `saint_lague.h`. The files `data.c` and 
`saint_lague.c` are needed because they contain
function definitions. You may use `main.c` as an example.

## More info:

[Saint-Lagüe method page at Wikipedia](https://en.wikipedia.org/wiki/Webster/Sainte-Laguë_method)

## Licence
MIT Licence