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
#include <sstream>
using namespace std;

struct coffee_record_t {
    string name;
    string brand;
    int rating;
    float cost_per_pound;
    bool is_dark_roast;
    string other_notes;
};

void print_coffee_record(coffee_record_t coffee_record);

int main ()
{
    coffee_record_t new_record;
    cout << "Enter coffee name:\t";
    getline (cin, new_record.name);

    cout << "Enter coffee brand:\t";
    getline(cin, new_record.brand);

    cout << "Enter rating:\t";
    string rating_string;
    getline(cin, rating_string);
    new_record.rating = stoi(rating_string);

    cout << "Enter cost per pound:\t";
    string cost_string;
    getline(cin, cost_string);
    new_record.cost_per_pound = stof(cost_string);

    cout << "Is this a dark roast [y/n]?\t";
    string dark_roast_answer;
    getline(cin, dark_roast_answer);
    if(dark_roast_answer == "y")
    {
        new_record.is_dark_roast = true;
    } else
    {
        new_record.is_dark_roast = false;
    }

    cout << "Write any other notes. Write 'none' for no added notes:\t";
    getline(cin, new_record.other_notes);

    print_coffee_record(new_record);

    return 0;
}


void print_coffee_record(coffee_record_t record)
{
    cout << "Coffee Name:\t" << record.name << endl;
    cout << "Coffee Brand:\t" << record.brand << endl;
    cout << "Rating:\t" << record.rating << endl;
    cout << "Cost Per Pound:\t" << record.cost_per_pound << endl;
    if(record.is_dark_roast)
    {
        cout << "This is a dark roast." << endl;
    } else
    {
        cout << "This is not a dark roast." << endl;
    }
    cout << "Other Notes:\t" << record.other_notes << endl;
}
