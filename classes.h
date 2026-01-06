#ifndef CLASSES_H
#define CLASSES_H

#include "structures.h"
#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
//
//                              Driver Class Definations
//
//////////////////////////////////////////////////////////////////////////////


class driver
{
    node *first = NULL;
public:
    void insertnode(string &name, string &phone_number, string &cnic_number,
                    string &vehicle_number, string &address);
    void deletenode();
    void deletefromposition(int pos);
    void searchbyname(string name);
    void display();
    void insertionSortByName();
};

//////////////////////////////////////////////////////////////////////////////
//
//                              Trip Class Definations
//
////////////////////////////////////////////////////////////////////////////

class trip
{
    trip_node *first = NULL;
    trip_node *last = NULL;
public:
    void insertnode(int &bilty_number, string vehical_number, string &driver_phoneno,
                    int &party_kariya, int &mlcs_kariya, int &comasion,
                    string &mail_detail, string loading_from, string &unloading,
                    string party_name, string &broker, string &tafseel_akhrajat);
    void deletefromposition(int pos);
    void deletenode();
    void searchbyvehicle(string name);
    void searchbybilty(int bilty_number);
    void display();
    void displayreverse();
    void insertionSortByBilty();
};

//////////////////////////////////////////////////////////////////////////////
//
//                              Akhrajat Class Definations
//
////////////////////////////////////////////////////////////////////////////

class Akhrajat
{
    akhrajat_node *first = NULL;
public:
    void insertnode(string &date, string tafseel_kharcha, int &amount);
    void deletenode();
    void searchbydate(string date);
    void display();
    void insertionSortByAmount();
};


//////////////////////////////////////////////////////////////////////////////
//
//                               login Class Definations
//
////////////////////////////////////////////////////////////////////////////

class Credentials
{
    credentials_node *first = NULL;
public:
    void insertnode(string &username, string &password);
    void deletenode();
    bool searchcredentials(string &username, string &password);
    void display();
};

////////////////////////////////////////////////////////////////////////////
//                               
//                              singup Class Definations
//
////////////////////////////////////////////////////////////////////////////

class Signup
{
    signup_credentials_node *first = NULL;
public:
    void insertnode(string &name, string &phone_number, string &address,
                    string &cnic_number, string &vehicle_number,
                    string &username, string &password);
    void deletenode();
    bool searchcredentials(string &username, string &password);
    void display();
};

#endif
