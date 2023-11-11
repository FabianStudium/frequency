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

void count_char_frequency(const FILE* file, int* frequency) {
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
            count += frequency[i];
        }
    }
    
    return count;
}

int calculate_distinct_char_count(const int* frequency) {
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

void free_memory(const char** arr, const int distinctCharCount) {
    for (int i = 0; i < distinctCharCount; i++) {
        free(arr[i]);
    }
    free(arr);
}

char** sort_arr(const char** arr, const int size) {
    int swapped;
    char* temp;

    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j][1] < arr[j + 1][1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }
}

void print_char_frequency(const char** arr, const int size_arr, const int char_count) {
    for (int i = 0; i < size_arr; i++) {
        int freq = (int)arr[i][1];
        fprintf(stdout, "%c \t%d \t%.2f%% \n", arr[i][0], arr[i][1], (float)freq/char_count*100);
    }
}