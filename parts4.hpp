// File Name: parts4.hpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 4
// Last Changed: March 24, 2015

#ifndef _PARTS4_HPP_
#define _PARTS4_HPP_

#include <string>
#include "sllist.hpp"

// CONSTANT VARIABLES
const int LINE_LENGTH = 45; // length of line from part file
const int NAME_LENGTH = 17; // Max length of part name (pname) in part file

const char *IN_FILENAME = // name of part input file to be read from
        "part_data.txt";

const std::string INSTRUCTIONS =
        "\nAvailable choices:\n"
                "\t1. Add part\n"
                "\t2. Delete part\n"
                "\t3. Save part list\n"
                "\t4. Quit\n";

// Read part file and stores Part structure data into a Part array
bool get_part_data_from_file(std::ifstream &inFile, Partlist& p);

// Sends string parameter line to a Stringstream
// Extracts  and stores Part structure data from Stringstream
// Returns Part structure
Part read_part_record(std::string line);

// Reads a certain amount of characters (length) from the stringstream
// returns string of the characters read
std::string read_from_string_stream(std::stringstream &from_str, int length);

// remove whitespaces from end of string
void rtrim(std::string &s);


// Prints data items of part structure to output stream
void print_part(std::ostream &os, Part part);

// Prints partlist to output stream
void print_partlist(std::ostream &os, Partlist & pl);

// Prompts user for part number to delete and removes matching part from list (pl)
bool delete_part(Partlist & pl);

// output parts list to file(outfile_name[])
void save_part_list(Partlist &parts, char outfile_name[]);

// returns string with a set length of characters
std::string get_string(std::string prompt, unsigned int length);

// Store part data from user input
Part get_part_from_user();

#endif