//
//  Header.h
//  frequency
//
//  Created by Fabian Gazzia on 14.10.23.
//

#ifndef Header_h
#define Header_h

#include <stdio.h> // for file i/o
#include <stdlib.h> // for strtol, abs, and EXIT_ constants
#include <string.h>

int check_argument_count(const int);
const int file_exists(const char*);
int parse_input_failed(char*, const char*, const size_t);
int path_is_not_safe(const char*);

#endif /* Header_h */
