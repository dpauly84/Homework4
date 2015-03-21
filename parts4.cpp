#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "sllist.hpp"
#include "parts4.hpp"
#include "utils.hpp"

using namespace std;

int main() {

//change
    Partlist partlist;

    Part p1 = {"antenna", "4553-02", 1.98, "A123", "B021", 12};
    Part p2 = {"ratchet", "2347-01", 0.8725, "A007", "B021", 12};
    Part p3 = {"seatbelt", "1987-01", 0.431, "A333", "B001", 12};
    Part p4 = {"pin", "5637-03", 0.0351, "A007", "B010", 12};
    Part p5 = {"pin", "5637-03", 0.0351, "A007", "B010", 12};

    partlist.add(p1);
    partlist.add(p2);
    partlist.add(p3);
    partlist.add(p4);
    delete_part("4553-02", partlist);
    print_partlist(cout, partlist);
    return 0;
}

// Read part file and stores Part structure data into a Part array
int get_part_data_from_file(ifstream &inFile, Partlist &p);

// Sends string parameter line to a Stringstream
// Extracts  and stores Part structure data from Stringstream
// Returns Part structure
Part read_part_record(std::string line);

// Reads a certain amount of characters (length) from the stringstream
// returns string of the characters read
std::string read_from_string_stream(std::stringstream &from_str, int length);

// remove whitespaces from end of string
void rtrim(std::string &s);

// Sends part data to file based on user selection and weight
int send_part_data_to_file
        (std::ofstream &outFile, Part partArray[], int records, int selection, double weight);

// Prints data items of part structure to output stream
void print_part(std::ostream &os, Part part) {
    // Set precision
    os.setf(ios::fixed);
    os.setf(ios::showpoint);
    os.precision(2);

    // Send part out output stream
    os << part.pname << " "
            << part.pnumber << ", "
            << part.weight << " N, "
            << part.inStock << " "
            << "in stock" << endl;
}

//TODO desc
void print_partlist(std::ostream &os, Partlist &pl) {
    PartNode *current;
    Part copy;

    for (current = pl.first(); current != pl.end(); current = pl.next(current)) {
        copy = pl.retrieve(current);
        print_part(os, copy);
    }
}


bool delete_part(string compare, Partlist &pl) {
    PartNode *current;
    Part copy;

    for (current = pl.first(); current != pl.end(); current = pl.next(current)) {
        copy = pl.retrieve(current);
        if (copy.pnumber == compare) {
            cout << "Deleted the part: ";
            print_part(cout, copy);
            pl.remove(current);
            return true;
        }
    }
    cout << "No parts matched" << endl;
    return false;

}

// output parts list to file(outfile_name[])
void save_part_list(Partlist &parts, char outfile_name[]);

// returns string with a set length of characters
string get_string(string prompt, unsigned int length) {
    string returnString;
    bool isValidString = true; // conversion status

    if (length > 0) {
        do {
            if (!isValidString) {
                cout << "You must enter " << length << " characters." << endl;
            }
            cout << prompt;
            cin >> returnString;
            if (returnString.length() == length) {
                isValidString = true;
            } else isValidString = false;
        } while (!isValidString);
    } else exit(EXIT_FAILURE);

    return returnString;
}

Part get_part_from_user() {
    Part addPart; // part to be added
    char tempName[17]; // temporary hold part name in c-string
    cout << "\nAdding a new part..." << endl;
    cout << "\tEnter part name: ";

    // get user input and store in part to be saved to the list
    cin.getline(tempName, 17); // read 17 characters
    addPart.pname = tempName;  // convert c-string to std::string
    addPart.pnumber = get_string("\tEnter a part number: ", 7);
    addPart.weight = get_double("\tEnter weight: ");
    addPart.supplier1 = get_string("\tEnter supplier code of primary supplier: ", 4);
    addPart.supplier2 = get_string("\tEnter supplier code of secondary supplier: ", 4);
    addPart.inStock = get_int("\tEnter number in stock: ");
    cout << endl;
    return addPart;
}