#ifndef DEFINATION_H
#define DEFINATION_H
#include "structures.h"
#include "classes.h"
#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////////////
//
//                              Driver Class Definations
//
////////////////////////////////////////////////////////////////////////////

void driver::insertnode(string &name, string &phone_number, string &cnic_number, string &vehicle_number, string &address)
{
    node *temp = new node;

    temp->data.name = name;
    temp->data.phone_number = phone_number;
    temp->data.cnic_number = cnic_number;
    temp->data.vehicle_number = vehicle_number;
    temp->data.address = address;
    temp->next = NULL;

    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        node *ptr = first;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void driver::deletenode()
{
    if (first == NULL)
    {
        cout << "Linklist empty" << endl;
    }
    else
    {
        node *temp;
        temp = first;
        first = first->next;
        delete temp;
    }
}

void driver::deletefromposition(int pos)
{
    if (first == nullptr)
    {
        cout << "Linked list empty\n";
        return;
    }

    // Delete first node
    if (pos == 0)
    {
        node *temp = first;
        first = first->next;
        delete temp;
        cout << "Node at position " << pos << " deleted successfully\n";
        return;
    }

    // Find previous node of the node to be deleted
    node *prev = nullptr;
    node *curr = first;
    int count = 0;
    while (curr != nullptr && count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == nullptr)
    {
        cout << "Invalid position\n";
        return;
    }

    // Delete node
    prev->next = curr->next;
    delete curr;

    cout << "Node at position " << pos << " deleted successfully\n";
}

void driver::searchbyname(string name)
{
    node *temp;
    temp = first;
    while (temp != NULL)
    {
        if (temp->data.name == name)
        {
            cout << "Driver Name: " << temp->data.name << endl;
            cout << "Phone Number: " << temp->data.phone_number << endl;
            cout << "CNIC Number: " << temp->data.cnic_number << endl;
            cout << "Vehicle Number: " << temp->data.vehicle_number << endl;
            cout << "Address: " << temp->data.address << endl;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "Driver not found" << endl;
}

void driver::display()
{
    node *temp;
    temp = first;

    while (temp != NULL)
    {
        cout << "Driver Name: " << temp->data.name << endl;
        cout << "Phone Number: " << temp->data.phone_number << endl;
        cout << "CNIC Number: " << temp->data.cnic_number << endl;
        cout << "Vehicle Number: " << temp->data.vehicle_number << endl;
        cout << "Address: " << temp->data.address << endl;
        cout << "-----------------------" << endl;
        temp = temp->next;
    }
}

void driver::insertionSortByName() {
    if (first == nullptr || first->next == nullptr)
        return; // 0 or 1 element, already sorted

    node *sorted = nullptr; // new sorted list
    node *current = first;

    while (current != nullptr) {
        node *nextNode = current->next; // store next node
        // Insert current node into sorted list
        if (sorted == nullptr || current->data.name < sorted->data.name) {
            current->next = sorted;
            sorted = current;
        } else {
            node *ptr = sorted;
            while (ptr->next != nullptr && ptr->next->data.name < current->data.name) {
                ptr = ptr->next;
            }
            current->next = ptr->next;
            ptr->next = current;
        }
        current = nextNode;
    }

    first = sorted; // update head
}


////////////////////////////////////////////////////////////////////////////
//
//                              Trip Class Definations
//
////////////////////////////////////////////////////////////////////////////

void trip::insertnode(int &bilty_number, string vehical_number, string &driver_phoneno, int &party_kariya, int &mlcs_kariya, int &comasion, string &mail_detail, string loading_from, string &unloading, string party_name, string &broker, string &tafseel_akhrajat)
{
    trip_node *temp = new trip_node;

    temp->data.bilty_number = bilty_number;
    temp->data.vehicle_number = vehical_number;
    temp->data.phone_no = driver_phoneno;
    temp->data.Party_amount = party_kariya;
    temp->data.mlcs_amount = mlcs_kariya;
    temp->data.commission = comasion;
    temp->data.material = mail_detail;
    temp->data.from = loading_from;
    temp->data.to = unloading;
    temp->data.party_name = party_name;
    temp->data.broker = broker;
    temp->data.tafseel_akhrajat = tafseel_akhrajat;
    temp->next = NULL;
    temp->prev = NULL;

    if (first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void trip::deletefromposition(int pos)
{
    if (first == nullptr)
    {
        cout << "Linked list empty\n";
        return;
    }

    // Delete first node
    if (pos == 0)
    {
        trip_node *temp = first;
        first = first->next;
        if (first != nullptr)
            first->prev = nullptr;
        else
            last = nullptr; // List became empty
        delete temp;
        cout << "Node at position " << pos << " deleted successfully\n";
        return;
    }

    // Find node to be deleted
    trip_node *curr = first;
    int count = 0;
    while (curr != nullptr && count < pos)
    {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr)
    {
        cout << "Invalid position\n";
        return;
    }

    // Delete node
    if (curr->next != nullptr)
        curr->next->prev = curr->prev;
    else
        last = curr->prev; // Deleted last node

    if (curr->prev != nullptr)
        curr->prev->next = curr->next;

    delete curr;

    cout << "Node at position " << pos << " deleted successfully\n";
}

void trip::searchbybilty(int bilty_number)
{
    trip_node *temp;
    temp = first;
    while (temp != NULL)
    {
        if (temp->data.bilty_number == bilty_number)
        {
            cout << "Bilty Number: " << temp->data.bilty_number << endl;
            cout << "Vehicle Number: " << temp->data.vehicle_number << endl;
            cout << "Driver Phone No: " << temp->data.phone_no << endl;
            cout << "Party Kariya: " << temp->data.Party_amount << endl;
            cout << "MLCS Kariya: " << temp->data.mlcs_amount << endl;
            cout << "Comasion: " << temp->data.commission << endl;
            cout << "Mail Detail: " << temp->data.material << endl;
            cout << "Loading From: " << temp->data.from << endl;
            cout << "Unloading: " << temp->data.to << endl;
            cout << "Party Name: " << temp->data.party_name << endl;
            cout << "Broker: " << temp->data.broker << endl;
            cout << "Tafseel Akhrajat: " << temp->data.tafseel_akhrajat << endl;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "Trip History not found" << endl;
}

void trip::searchbyvehicle(string name)
{
    trip_node *temp;
    temp = first;
    while (temp != NULL)
    {
        if (temp->data.vehicle_number == name)
        {
            cout << "Bilty Number: " << temp->data.bilty_number << endl;
            cout << "Vehicle Number: " << temp->data.vehicle_number << endl;
            cout << "Driver Phone No: " << temp->data.phone_no << endl;
            cout << "Party Kariya: " << temp->data.Party_amount << endl;
            cout << "MLCS Kariya: " << temp->data.mlcs_amount << endl;
            cout << "Comasion: " << temp->data.commission << endl;
            cout << "Mail Detail: " << temp->data.material << endl;
            cout << "Loading From: " << temp->data.from << endl;
            cout << "Unloading: " << temp->data.to << endl;
            cout << "Party Name: " << temp->data.party_name << endl;
            cout << "Broker: " << temp->data.broker << endl;
            cout << "Tafseel Akhrajat: " << temp->data.tafseel_akhrajat << endl;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "Trip History not found" << endl;
}


void trip::deletenode()
{
    if (first == NULL)
    {
        cout << "Linklist empty" << endl;
    }
    else
    {
        trip_node *temp;
        temp = last;
        last = last->prev;
        if (last != NULL)
        {
            last->next = NULL;
        }
        else
        {
            first = NULL; // List became empty
        }
        delete temp;
    }
}

void trip::display()
{
    trip_node *temp;
    temp = first;

    while (temp != NULL)
    {
        cout << "Bilty Number: " << temp->data.bilty_number << endl;
        cout << "Vehicle Number: " << temp->data.vehicle_number << endl;
        cout << "Driver Phone No: " << temp->data.phone_no << endl;
        cout << "Party Kariya: " << temp->data.Party_amount << endl;
        cout << "MLCS Kariya: " << temp->data.mlcs_amount << endl;
        cout << "Comasion: " << temp->data.commission << endl;
        cout << "Mail Detail: " << temp->data.material << endl;
        cout << "Loading From: " << temp->data.from << endl;
        cout << "Unloading: " << temp->data.to << endl;
        cout << "Party Name: " << temp->data.party_name << endl;
        cout << "Broker: " << temp->data.broker << endl;
        cout << "Tafseel Akhrajat: " << temp->data.tafseel_akhrajat << endl;
        cout << "-----------------------" << endl;
        temp = temp->next;
    }
}

void trip::displayreverse()
{
    trip_node *temp;
    temp = last;

    while (temp != NULL)
    {
        cout << "Bilty Number: " << temp->data.bilty_number << endl;
        cout << "Vehicle Number: " << temp->data.vehicle_number << endl;
        cout << "Driver Phone No: " << temp->data.phone_no << endl;
        cout << "Party Kariya: " << temp->data.Party_amount << endl;
        cout << "MLCS Kariya: " << temp->data.mlcs_amount << endl;
        cout << "Comasion: " << temp->data.commission << endl;
        cout << "Mail Detail: " << temp->data.material << endl;
        cout << "Loading From: " << temp->data.from << endl;
        cout << "Unloading: " << temp->data.to << endl;
        cout << "Party Name: " << temp->data.party_name << endl;
        cout << "Broker: " << temp->data.broker << endl;
        cout << "Tafseel Akhrajat: " << temp->data.tafseel_akhrajat << endl;
        cout << "-----------------------" << endl;
        temp = temp->prev;
    }
}


void trip::insertionSortByBilty() {
    if (first == nullptr || first->next == nullptr)
        return;

    trip_node *sorted = nullptr;
    trip_node *current = first;

    while (current != nullptr) {
        trip_node *nextNode = current->next;
        current->prev = current->next = nullptr;

        if (sorted == nullptr) {
            sorted = current;
        } else if (current->data.bilty_number < sorted->data.bilty_number) {
            current->next = sorted;
            sorted->prev = current;
            sorted = current;
        } else {
            trip_node *ptr = sorted;
            while (ptr->next != nullptr && ptr->next->data.bilty_number < current->data.bilty_number) {
                ptr = ptr->next;
            }
            current->next = ptr->next;
            if (ptr->next != nullptr)
                ptr->next->prev = current;
            ptr->next = current;
            current->prev = ptr;
        }

        current = nextNode;
    }

    // Update first and last
    first = sorted;
    last = sorted;
    while (last->next != nullptr)
        last = last->next;
}


////////////////////////////////////////////////////////////////////////////
//
//                              Akhrajat Class Definations
//
////////////////////////////////////////////////////////////////////////////

void Akhrajat::insertnode(string &date, string tafseel_kharcha, int &amount)
{
    akhrajat_node *temp = new akhrajat_node;

    temp->data.date = date;
    temp->data.tafseel_kharcha = tafseel_kharcha;
    temp->data.amount = amount;
    temp->next = NULL;

    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        akhrajat_node *ptr = first;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void Akhrajat::deletenode()
{
    if (first == NULL)
    {
        cout << "Linklist empty" << endl;
    }
    else
    {
        akhrajat_node *temp;
        temp = first;
        first = first->next;
        delete temp;
    }
}

void Akhrajat::searchbydate(string date)
{
    akhrajat_node *temp;
    temp = first;
    while (temp != NULL)
    {
        if (temp->data.date == date)
        {
            cout << "Date: " << temp->data.date << endl;
            cout << "Tafseel Kharcha: " << temp->data.tafseel_kharcha << endl;
            cout << "Amount: " << temp->data.amount << endl;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "Akhrajat not found" << endl;
}

void Akhrajat::display()
{
    akhrajat_node *temp;
    temp = first;

    while (temp != NULL)
    {
        cout << "Date: " << temp->data.date << endl;
        cout << "Tafseel Kharcha: " << temp->data.tafseel_kharcha << endl;
        cout << "Amount: " << temp->data.amount << endl;
        cout << "-----------------------" << endl;
        temp = temp->next;
    }
}


void Akhrajat::insertionSortByAmount() {
    if (first == nullptr || first->next == nullptr)
        return;

    akhrajat_node *sorted = nullptr;
    akhrajat_node *current = first;

    while (current != nullptr) {
        akhrajat_node *nextNode = current->next;
        if (sorted == nullptr || current->data.amount < sorted->data.amount) {
            current->next = sorted;
            sorted = current;
        } else {
            akhrajat_node *ptr = sorted;
            while (ptr->next != nullptr && ptr->next->data.amount < current->data.amount) {
                ptr = ptr->next;
            }
            current->next = ptr->next;
            ptr->next = current;
        }
        current = nextNode;
    }

    first = sorted;
}


//////////////////////////////////////////////////////////////////////////////
//
//                               login Class Definations
//
////////////////////////////////////////////////////////////////////////////

void Credentials::insertnode(string &username, string &password)
{
    credentials_node *temp = new credentials_node;

    temp->data.username = username;
    temp->data.password = password;
    temp->next = NULL;

    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        credentials_node *ptr = first;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void Credentials::deletenode()
{
    if (first == NULL)
    {
        cout << "Linklist empty" << endl;
    }
    else
    {
        credentials_node *temp;
        temp = first;
        first = first->next;
        delete temp;
    }
}

bool Credentials::searchcredentials(string &username, string &password)
{
    credentials_node *temp;
    temp = first;
    while (temp != NULL)
    {
        if (temp->data.username == username && temp->data.password == password)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

void Credentials::display()
{
    credentials_node *temp;
    temp = first;

    while (temp != NULL)
    {
        cout << "Username: " << temp->data.username << endl;
        cout << "Password: " << temp->data.password << endl;
        cout << "-----------------------" << endl;
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//                              singup Class Definations
//
////////////////////////////////////////////////////////////////////////////

void Signup::insertnode(string &name, string &phone_number, string &address,
                    string &cnic_number, string &vehicle_number,
                    string &username, string &password)
{
    signup_credentials_node *temp = new signup_credentials_node;

    temp->data.name = name;
    temp->data.phone_number = phone_number;
    temp->data.address = address;
    temp->data.cnic_number = cnic_number;
    temp->data.vehicle_number = vehicle_number;
    temp->data.username = username;
    temp->data.password = password;
    temp->next = NULL;

    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        signup_credentials_node *ptr = first;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void Signup::deletenode()
{
    if (first == NULL)
    {
        cout << "Linklist empty" << endl;
    }
    else
    {
        signup_credentials_node *temp;
        temp = first;
        first = first->next;
        delete temp;
    }
}

bool Signup::searchcredentials(string &username, string &password)
{
    signup_credentials_node *temp;
    temp = first;
    while (temp != NULL)
    {
        if (temp->data.username == username && temp->data.password == password)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

void Signup::display()
{
    signup_credentials_node *temp;
    temp = first;

    while (temp != NULL)
    {
        cout << "Name: " << temp->data.name << endl;
        cout << "Phone Number: " << temp->data.phone_number << endl;
        cout << "Address: " << temp->data.address << endl;
        cout << "CNIC Number: " << temp->data.cnic_number << endl;
        cout << "Vehicle Number: " << temp->data.vehicle_number << endl;
        cout << "Username: " << temp->data.username << endl;
        cout << "Password: " << temp->data.password << endl;
        cout << "-----------------------" << endl;
        temp = temp->next;
    }
}

#endif