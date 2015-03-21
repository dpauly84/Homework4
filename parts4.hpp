#ifndef _PARTS4_HPP_
#define _PARTS4_HPP_

#include <string>
#include "sllist.hpp"

void print_part(std::ostream &os, Part part);
void print_partlist(std::ostream &os, Partlist & pl);
bool delete_part(std::string compare, Partlist & pl);
std::string get_string(std::string prompt, unsigned int length);
Part get_part_from_user();

#endif