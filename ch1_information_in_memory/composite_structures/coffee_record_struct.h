/*
 * composite_structure.cpp
 * Joseph J. Radler
 *
 * Kubica DSA book:
 * CoffeeRecord {
 *  String: Name
 *  String: Brand
 *  Integer: Rating
 *  Float: Cost per Pound
 *  Boolean: Is_Dark_Roast
 *  String: Other_Notes
 * }
 */
#include <iostream>
#include <string>

#ifndef COFFEE_RECORD_STRUCT_H
#define COFFEE_RECORD_STRUCT_H

struct coffee_record_t {
    std::string name;
    std::string brand;
    int rating;
    float cost_per_pound;
    bool is_dark_roast;
    std::string other_notes;
};

void print_coffee_record(coffee_record_t);

#endif /*COFFEE_RECORD_STRUCT_H*/
