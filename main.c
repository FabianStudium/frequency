//
//  main.c
//  frequency
//
//  Created by Fabian Gazzia on 14.10.23.
//

#include "main.h"

int main(const int argc, const char * argv[]) {
    
    /*  variables (sizes)
        file_stream[]
        letters[file_stream.length][frequencyInt][frequency%]
    */
    
    /*  input validierung 
        * 1 arg
        * file exists
    */

    /*  file operations
        * read content per letter
        * write from stream to 2d array
            - for i in stream: 
                for j in string:
                    string[j] == stream[i] ? string[j][1]++ : string[j+1] = stream[i];
    */

    /*  sort letter array by frequency
    */

    /*  frequency
        * calculate frequency per letter in %
            - total amount: for i in string: string[i][0] * string[i][1] || string[i][1] + string[i+1][1] ...
            - frequency per letter: for i in string: string[i][1] / total * 100
                - maybe store together with string
                    * string[] -> letter
                    * string[][] -> frequency in int
                    * string[][][] -> frequency in %
    */

   /*   print result
   */
    
    return EXIT_SUCCESS;

}