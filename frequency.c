//
//  main.c
//  frequency
//
//  Created by Fabian Gazzia on 14.10.23.
//

#include "frequency.h"

FILE* open_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "File could not be opened.\n");
        exit(EXIT_FAILURE);
    }

    return file;
}

void count_char_frequency(FILE* file, int* frequency) {
    char c;

    while ((c = fgetc(file)) != EOF) {
        if(((int)c >= 65 && (int)c <=90) || ((int)c >= 97 && (int)c <= 122)) {
            frequency[(int)c]++;
        }
    }
}

int calculate_char_count(const int* frequency) {
    int count = 0;

    for (int i = 0; i < ASCII_SIZE; i++) {
        if (frequency[i] > 0) {
            count++;
        }
    }
    
    return count;
}

char** store_char_frequency(const int char_count, const int* ascii_arr) {
    char** freq_arr = (char**)malloc(char_count * sizeof(char*));
    
    for(int i = 0; i < char_count; i++) {
        freq_arr[i] = (char*)malloc(2 * sizeof(char));
    }

    int index = 0;

    for(int i = 0; i < ASCII_SIZE; i++) {
        if(ascii_arr[i] > 0) {
            freq_arr[index][0] = (char)i;
            freq_arr[index][1] = ascii_arr[i];
            index++;
        }
    }

    return freq_arr;
}

// Function to free allocated memory for the 2D array
void free_memory(const char** arr, const int distinctCharCount) {
    for (int i = 0; i < distinctCharCount; i++) {
        free(arr[i]);
    }
    free(arr);
}