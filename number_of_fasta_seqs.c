/*
 * Author: Alessandro Coppe
 * Purpose: To count number of FASTA seqs or show the sequences description
 * Language: C
 * 
 *  (c) 2019 Coppe
 *  This code is licensed under MIT license (see LICENSE.txt for details)
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char *argv[]){
    const int STRING_MAX_LEN = 300;
    char line[STRING_MAX_LEN + 1];
    FILE *file;
    char ch;
    int header = 0;
    int exit = 0;
    int number_of_seqs = 0;
    int number_of_sequences = 0;
    char first_char;
    /* Help string */
    char help[] = "Usage: number_of_fasta_seqs  [OPTION]... FASTA_FILE.\n  "
        "-d\tshow only description lines\n  "
        "-h\tshow help options";

    /* Options section */
    while ((ch = getopt(argc, argv, "dh")) != EOF) {
        switch (ch) {
            case 'd':
                header = 1;
                break;
            case 'h':
                exit = 1;
                puts(help);
                return 0;
            default:
                header = 0;
                return -1;
        }
    }

    argc -= optind;
    argv += optind;
    /* Options end */

    /* Check if there is a FASTA file argument */
    if (argc < 1) {
        fprintf(stderr, "Fasta file name not specified\n");
        return 1;
    }

    /* If the FASTA file is not present */
    if (!(file = fopen(argv[0], "r"))) {
        fprintf(stderr, "Coud not find file: %s\n", argv[0]);
        return 1;
    }


    /* Working part of the sofware: */
    while ( fgets(line, STRING_MAX_LEN, file) ) {
        first_char = line[0];
        if (header) {
            if (first_char == '>')
                fprintf(stdout, "%s", line);
        } else {
            if (first_char == '>')
                number_of_seqs++;
        }
    }

    if (!header)
        fprintf(stdout, "%i\n", number_of_seqs);

    return 0;
}
