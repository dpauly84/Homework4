#include "sllist.hpp"
#include <iostream>

Partlist::Partlist() {
    m_first = NULL;
    m_last = NULL;
}

Partlist::~Partlist() {
    //TODO
}

// return pointer to first element of list
PartNode *Partlist::first() {
    return m_first;
}

// return pointer to "one past the end" of the list
PartNode *Partlist::end() {
    return m_last->next;
}

// return pointer to next element after current
PartNode *Partlist::next(PartNode *current) {
    return current->next;
}

// return Part pointed to by current
Part Partlist::retrieve(PartNode *current) {
    return current->value;
}

// delete element pointed to by current from list
void Partlist::remove(PartNode *current) {
    PartNode *tmp = m_first;

    if (m_first == current) {
        m_first = current->next;
    } else {
        while (tmp->next != current) {
            tmp = tmp->next;
        }
        tmp->next = current->next;
    }
    delete current;
}

// add element made from part (by make_copy) to end of list
void Partlist::add(Part part) {
    PartNode *newNode;
    newNode = make_copy(part);
    if (m_first == NULL) {
        m_first = newNode;
        m_last = newNode;
    }

    else {
        m_last->next = newNode;
        m_last = newNode;
    }
}

// returns true if list is empty
bool Partlist::is_empty() {
    return m_first == NULL ? true : false;
}

// create new element for the list with fields copied
// from p and return pointer to created element
PartNode *Partlist::make_copy(Part p) {
    Part *newPart = new Part; // new Part to hold copy of Part p
    // Copy contents of p to newPart
    newPart->pname = p.pname;
    newPart->pnumber = p.pnumber;
    newPart->weight = p.weight;
    newPart->supplier1 = p.supplier1;
    newPart->supplier2 = p.supplier2;
    newPart->inStock = p.inStock;

    PartNode *newNode = new PartNode; // new PartNode to return
    // Assign PartNode values
    newNode->value = *newPart;
    newNode->next = NULL;
    return newNode;
}

