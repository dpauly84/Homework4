#ifndef _SLLIST_HPP_
#define _SLLIST_HPP_

#include <string>
#include <ostream>

struct Part
{
    std::string pname; // part name
    std::string pnumber; // part number format DDDD-DD where D is a digit
    double weight; // part weight
    std::string supplier1; // part suppllier1 format CDDD where C is a character
    std::string supplier2; // part supplier2 format CDDD
    int inStock; // Quantity of parts in stock
};

struct PartNode {
    Part value;
    PartNode *next;
};

class Partlist {
public:

// constructor and destructor
    Partlist(); // make empty list
    ~Partlist(); // delete all remaining elements, freeing their memory

// accessors
    PartNode *first(); // return pointer to first element of list
    PartNode *end(); // return pointer to "one past the end" of the list
    PartNode *next(PartNode *current); // return pointer to next element after current
    Part retrieve(PartNode *current); // return Part pointed to by current

// mutators
    void remove(PartNode *current); // delete element pointed to by current from list
    void add(Part part); // add element made from part (by make_copy) to end of list

private:
// helper functions
    PartNode *make_copy(Part p); // create new element for the list with fields copied
                                 // from p and return pointer to created element

// data
    PartNode *m_first; //TODO desc
    PartNode *m_last; //TODO desc

};

#endif