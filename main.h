//
//  Header.h
//  frequency
//
//  Created by Fabian Gazzia on 14.10.23.
//

#ifndef main_h
#define main_h

#include <stdio.h> // for file i/o
#include <stdlib.h> // for strtol, abs, and EXIT_ constants
#include <string.h>

const int file_exists(const char*);
const int path_is_not_safe(const char*);
const int check_argument_count(const int);
const int parse_input_failed(char*, const char*, const size_t);

#endif /* main_h */
