//
//  main.c
//  frequency
//
//  Created by Fabian Gazzia on 14.10.23.
//

#include "main.h"
#include "frequency.h"

int main(const int argc, const char * argv[]) {
    /*   input validierung   */
    check_argument_count(argc);
    
    if(path_is_not_safe(argv[1])) {
        fprintf(stderr, "Error: Unsafe file path provided. File needs to be in the same directory as the program\n");
        return EXIT_FAILURE;
    }

    // Define the size of the destination buffer
    const size_t buffer_size = 256;
    char filename[buffer_size];

    if(parse_input_failed(filename, argv[1], buffer_size)) {
        fprintf(stderr, "Error: Failed to safely copy the input string.\n");
        return EXIT_FAILURE;
    }

    int char_frequency_ascii[ASCII_SIZE] = {0}; // declares a 128 long array and init. each value with 0
        // the ascii value of a character is used as the position of the array
   
    FILE* file = open_file(filename);

    /*      i -> character as integer
            array[i] -> frequency as integer
    */
    count_char_frequency(file, char_frequency_ascii);
    
    fclose(file);

    /*   calculates the total amount of characters {a,...,z,A,...,Z}   */
    int char_count = calculate_char_count(char_frequency_ascii);
    /*   calculates the amount of distinct characters {a,...,z,A,...,Z}   */
    int distinct_char_count = calculate_distinct_char_count(char_frequency_ascii);

    /*   creates a 2d array
            array[i] -> character
            array[i] -> frequency as integer
    */
    char** char_frequency_arr = store_char_frequency(distinct_char_count, char_frequency_ascii);

    /*   sort letter array by frequency | bubble sort   */
   char** char_frequency_arr_sorted = sort_arr(char_frequency_arr, distinct_char_count);

    /*   print result   */
    print_char_frequency(char_frequency_arr, distinct_char_count, char_count); // calculates percentage dynamically .. not pretty

    /*   memory handling   */
    free_memory(char_frequency_arr, distinct_char_count);

    return EXIT_SUCCESS;
}

const int check_argument_count(const int argc) {
    if(argc != 2) {
        fprintf(stderr, "Please provide a filename.\n\nUsage: ./frequency <path>/<filename>.<extenstion>.");
        return 0;
    }

    return 1;
}

const int file_exists(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return 0; // Does not exist
    }
    
    fclose(file);
    
    return 1; // Exists
}

const int parse_input_failed(char* dst, const char* src, const size_t dst_size) {
    if (src == NULL || dst == NULL) {
        return 1; // Invalid input
    }

    // Use strlcpy for safe string copying .. keyword: buffer overflow
    size_t src_len = strlcpy(dst, src, dst_size);

    // Check if the entire source string was copied
    if (src_len >= dst_size) {
        return 1; // Source string was truncated
    }

    return 0; // Success
}

/* Source: GPT*/
/* Input sanitisation .. check if user provides any unsafe characters that could lead to vulnerabilities like path traversal, file access, etc.*/
const int path_is_not_safe(const char* input) {
    const char* unsafe_char[] = {
        "..", "/", "\\", 
        "%2e%2e%2f", "%2e%2e%5c", // url encoded '../' '..\'
        "%2F", "%5C", // url encoded '/' '\'
        "%2f", "%5c" // url encoded '/' '\'
    };

    size_t unsafe_char_count = sizeof(unsafe_char) / sizeof(unsafe_char[0]);

    /*
    unsafe_char_count calculates the number of elements in the patterns array by dividing the total byte size of the array (sizeof(patterns)) by the byte size of a single element (sizeof(patterns[0])). This ensures that the subsequent loop iterates accurately through each element in the array, preventing out-of-bounds access and making the code adaptable to changes in the array size.
    */

    for (size_t i = 0; i < unsafe_char_count; i++) {
        if (strstr(input, unsafe_char[i]) != NULL) {
            return 1; // Unsafe path
        }
    }
    return 0; // Safe path
}