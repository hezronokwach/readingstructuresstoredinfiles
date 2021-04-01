#include<iostream>
#include "software.h"




    //an overload of operator >> is defined a
    istream& operator>>(istream& receive,books_info &data){//return type of >> is object of type ifstream
        receive>>ws;//remove leading whitespace
        getline(receive, data.title);
        getline(receive, data.author);
        receive >> data.Price;
        receive >> data.stock_position;
        return receive;
    }

void access(){
    string id, b;
    cout << "Enter name of file you wish to be read:\n";
    cin >> id;
    b = id + ".txt";

    auto file =ifstream(b);//same as ifstream file  then file.open(b)
    vector<books_info> shelf;//each index will hold unique book info

    if(file.is_open())
    { //if file is successfully opened then;
        for(books_info data; file >> data;){// keep reading until nothing is left
            // only get here if read succeeded
            shelf.push_back(data);
        }

        for(auto const data:shelf){//read only no modification allowed
            cout <<"\ntitle: "<< data.title <<"\n";
            cout <<"author: "<<data.author<<"\n";
            cout <<"unit price: "<<"Kshs. "<<data.Price<<"\n\a\a";
            cout << "available copies: " << data.stock_position << " books\n\a";
        }

        file.close();//must do this because next read is not known

        if(!file.fail()){//if reading fails and the badbit or failbit is not set implicitly then
            cout << "Failed to read specified file!\a\a\n";
        }
    }

    else{
        cout << "Specified file doesn't exist!\a\a\a";
    }

}

