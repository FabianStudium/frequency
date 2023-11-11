//
//  Header.h
//  frequency
//
//  Created by Fabian Gazzia on 14.10.23.
//

#ifndef frequency_h
#define frequency_h

#define ASCII_SIZE 255

#include <stdio.h>
#include <stdlib.h> // for EXIT_ constants

FILE* open_file(const char*);

int calculate_char_count(const int*);
int calculate_distinct_char_count(const int*);

void count_char_frequency(FILE*, int*);
void free_memory(const char**, const int);
void print_char_frequency(const char**, const int, const int);

char** sort_arr(const char**, const int);
char** store_char_frequency(const int, const int*);

#endif /* frequency_h */
