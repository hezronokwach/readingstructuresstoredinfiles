#ifndef SOFTWARE_H
#define SOFTWARE_H

#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct books_info{

    string title, author;
    float Price;
    int stock_position;

};

//an overload of operator >> is defined
istream& operator>>(istream& receive,books_info &data); //return type of >> is object of type ifstream

void access();

#endif
