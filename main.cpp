#include <iostream>
#include <windows.h> // Needed for console colors
#include "defination.h"
#include "structures.h"
#include "classes.h"
using namespace std;

// Function to set console text color
void setColor(int color)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

int main()
{

    driver d1;
    trip t1;
    Akhrajat a1;
    Signup s1;
    Credentials l1;
    driver_info dinfo;
    trip_history thistory;
    daily_akhrajat dakhrajat;
    credentials cred;
    signup_credentials cdata;
    int choice;
    int main_choice;
    int mainchoice2;
    char ch;
    bool issignedup = false;
    bool loginSuccess = false;
    setColor(11);
    cout << "           ------------------------------------------------" << endl;
    cout << "           |                                                |" << endl;
    cout << "           |         MLCS Truck Management System           |" << endl;
    cout << "           |                                                |" << endl;
    cout << "           ------------------------------------------------" << endl;

    ////////////////////////////////////////////////////////////////////
    //
    //                         Main Menu
    //
    ////////////////////////////////////////////////////////////////////

    do
    {
        setColor(11);
        cout << "--------------              --------------              -------------- " << endl;
        cout << "|             |             |             |             |             |" << endl;
        cout << "|  1. SIGNUP  |             |   2.LOGIN   |             |   EXIT      |" << endl;
        cout << "|             |             |             |             |             |" << endl;
        cout << "--------------               --------------              -------------- " << endl;
        cout << endl;
        setColor(13);
        cout << "Enter your choice(1-3): ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        if (choice == 1 && !issignedup)
        {
            setColor(13);
            cout << "enter Signup Details: " << endl;
            cout << "Enter Name: ";
            getline(cin, cdata.name);
            cout << "Enter Phone Number: ";
            getline(cin, cdata.phone_number);
            cout << "Enter Address: ";
            getline(cin, cdata.address);
            cout << "Enter CNIC Number: ";
            getline(cin, cdata.cnic_number);
            cout << "Enter Vehicle Number: ";
            getline(cin, cdata.vehicle_number);
            cout << "Enter Username: ";
            getline(cin, cdata.username);
            cout << "Enter Password: ";
            getline(cin, cdata.password);
            s1.insertnode(cdata.name, cdata.phone_number, cdata.address, cdata.cnic_number, cdata.vehicle_number, cdata.username, cdata.password);
            setColor(10);
            cout << "Signup Successful!" << endl
                 << endl;
            issignedup = true;
        }
        else if (choice == 2 && !loginSuccess)
        {
            setColor(13);
            cout << "Enter Login Details: " << endl;
            cout << "Enter Username: ";
            getline(cin, cdata.username);
            cout << "Enter Password: ";
            getline(cin, cdata.password);

            if (s1.searchcredentials(cdata.username, cdata.password))
            {
                setColor(10);
                cout << "Login Successful!" << endl
                     << endl;
                loginSuccess = true;
                setColor(10);
                cout << "welcome back " << cdata.username << "!" << endl
                     << endl;
                do
                {
                    setColor(14);
                    cout << "     ---------------------------" << endl;
                    cout << "     |        MAIN MENU        |" << endl;
                    cout << "     ---------------------------" << endl;
                    cout << endl;
                     setColor(9);  
                    cout << "-------------------      -----------------    " << endl;
                    cout << "|                  |     |                |    " << endl;
                    cout << "| 1. Driver MANAGE |     | 2. Trip MANAGE |     " << endl;
                    cout << "|                  |     |                |      " << endl;
                    cout << "--------------------      -----------------     " << endl;
                    cout << endl;
                    cout << endl;
                    cout << "---------------------     ------------------    " <<endl;
                    cout << "|                    |    |                |   " << endl;
                    cout << "| 3. Akhrajat MANAGE |    |   4. EXIT      |   " << endl;
                    cout << "|                    |    |                |   " << endl;
                    cout << " --------------------     ------------------    " <<endl;
                    cout << endl;
                    cout << endl;
                    setColor(13);
                    cout << "Enter your choice(1-4): ";
                    cin >> choice;
                    cin.ignore();
                    cout << endl;
                    if (choice == 1)
                    {
                        do
                        {
                            setColor(14);
                            cout <<"--------------------------------" << endl;
                            cout <<"|     DRIVER DASHBOARD          |" << endl;
                            cout <<"--------------------------------" << endl;
                             setColor(13);
                            cout << "1. Add Driver" << endl;
                            cout << "2. Delete Driver" << endl;
                            cout << "3. Search Driver by Name" << endl;
                            cout << "4. Display All Drivers" << endl;
                            cout << "5. Sort Drivers by Name" << endl;
                            cout << "6.Exit" << endl;
                            cout << "Enter your choice(1-6): ";
                            cin >> choice;
                            cin.ignore();
                            cout << endl;
                            if (choice == 1)
                            {
                                do
                                {
                                    setColor(13);
                                    cout << "Enter Driver Details: " << endl;
                                    cout << "Enter Name: ";
                                    getline(cin, dinfo.name);
                                    cout << "Enter Phone Number: ";
                                    getline(cin, dinfo.phone_number);
                                    cout << "Enter CNIC Number: ";
                                    getline(cin, dinfo.cnic_number);
                                    cout << "Enter Vehicle Number: ";
                                    getline(cin, dinfo.vehicle_number);
                                    cout << "Enter Address: ";
                                    getline(cin, dinfo.address);
                                    d1.insertnode(dinfo.name, dinfo.phone_number, dinfo.cnic_number, dinfo.vehicle_number, dinfo.address);
                                    cout << "Do you want to add more Driver? (y/n): ";
                                    cin >> ch;
                                    cin.ignore();

                                } while (ch == 'y' || ch == 'Y');
                                setColor(10);
                                cout << "Driver Added Successfully!" << endl
                                     << endl;
                                d1.display();
                            }
                            else if (choice == 2)
                            {
                                d1.deletenode();
                                setColor(10);
                                cout << "Driver Deleted Successfully!" << endl
                                     << endl;
                                     setColor(7);
                                d1.display();
                            }
                            else if (choice == 3)
                            {
                                string search_name;
                                    setColor(13);
                                cout << "Enter Driver Name to Search: ";
                                getline(cin, search_name);
                                setColor(7);
                                d1.searchbyname(search_name);
                            }
                            else if (choice == 4)
                            {
                                setColor(7);
                                d1.display();
                            }
                            else if (choice == 5)
                            {
                                d1.insertionSortByName();
                                setColor(10);
                                cout << "Drivers Sorted by Name Successfully!" << endl
                                     << endl;
                                setColor(7);
                                d1.display();
                            }
                        } while (choice != 6);
                    }

                    else if (choice == 2)
                    {
                        do
                        {
                            setColor(14);
                            cout <<"--------------------------------" << endl;
                            cout <<"|   TRIP HISTORY DASHBOARD     |" << endl;
                            cout <<"--------------------------------" << endl;
                             setColor(10);
                            
                           
                            setColor(13);
                            cout << "1. Add Trip History" << endl;
                            cout << "2. Delete Trip History" << endl;
                            cout << "3. Search Trip by Vehicle Number" << endl;
                            cout << "4. Search Trip by Bilty Number" << endl;
                            cout << "5. Display All Trip History" << endl;
                            cout << "6. Display All Trip History in Reverse" << endl;
                            cout << "7. Sort Trips by Bilty Number" << endl;
                            cout << "8.Exit" << endl;
                            cout << "Enter your choice(1-8): ";
                            cin >> choice;
                            cin.ignore();
                            cout << endl;
                            if (choice == 1)
                            {
                                do
                                {
                                    setColor(13);
                                    cout << "Enter Trip History Details: " << endl;
                                    cout << "Enter Bilty Number: ";
                                    cin >> thistory.bilty_number;
                                    cin.ignore();
                                    cout << "Enter Vehicle Number: ";
                                    getline(cin, thistory.vehicle_number);
                                    cout << "Enter Driver Phone No: ";
                                    getline(cin, thistory.phone_no);
                                    cout << "Enter Party Kariya: ";
                                    cin >> thistory.Party_amount;
                                    cin.ignore();
                                    cout << "Enter MLCS Kariya: ";
                                    cin >> thistory.mlcs_amount;
                                    cin.ignore();
                                    cout << "Enter Comasion: ";
                                    cin >> thistory.commission;
                                    cin.ignore();
                                    cout << "Enter Mail Detail: ";
                                    getline(cin, thistory.material);
                                    cout << "Enter Loading From: ";
                                    getline(cin, thistory.from);
                                    cout << "Enter Unloading: ";
                                    getline(cin, thistory.to);
                                    cout << "Enter Party Name: ";
                                    getline(cin, thistory.party_name);
                                    cout << "Enter Broker: ";
                                    getline(cin, thistory.broker);
                                    cout << "Enter Tafseel Akhrajat: ";
                                    getline(cin, thistory.tafseel_akhrajat);
                                    t1.insertnode(thistory.bilty_number, thistory.vehicle_number, thistory.phone_no, thistory.Party_amount, thistory.mlcs_amount, thistory.commission, thistory.material, thistory.from, thistory.to, thistory.party_name, thistory.broker, thistory.tafseel_akhrajat);
                                    cout << "Do you want to add more Trip History? (y/n): ";
                                    cin >> ch;
                                    cin.ignore();
                                } while (ch == 'y' || ch == 'Y');
                                setColor(10);
                                cout << "Trip History Added Successfully!" << endl
                                     << endl;
                                t1.display();
                            }
                            else if (choice == 2)
                            {
                                t1.deletenode();
                                setColor(10);
                                cout << "Trip History Deleted Successfully!" << endl
                                     << endl;
                                setColor(7);
                                t1.display();
                            }
                            else if (choice == 3)
                            {
                                string vehicle_number;
                                setColor(13);
                                cout << "Enter Vehicle Number to Search: ";
                                getline(cin, vehicle_number);
                                setColor(7);
                                t1.searchbyvehicle(vehicle_number);
                            }
                            else if (choice == 4)
                            {
                                int bilty_number;
                                setColor(13);
                                cout << "Enter Bilty Number to Search: ";
                                cin >> bilty_number;
                                cin.ignore();
                                setColor(7);
                                t1.searchbybilty(bilty_number);
                            }
                            else if (choice == 5)
                            {
                                setColor(7);
                                t1.display();
                            }
                            else if (choice == 6)
                            {
                                setColor(7);
                                t1.displayreverse();
                            }
                            else if (choice == 7)
                            {
                                t1.insertionSortByBilty();
                                setColor(10);
                                cout << "Trips Sorted by Bilty Number Successfully!" << endl
                                     << endl;
                                setColor(7);
                                t1.display();
                            }
                        } while (choice != 8);
                    }
                    else if (choice == 3)
                    {
                        do
                        {
                            setColor(14);
                            cout <<"--------------------------------" << endl;
                            cout <<"|  DAILY AKHRAJAT DASHBOARD    |" << endl;
                            cout <<"--------------------------------" << endl;
                             setColor(11);
                           
                            cout << "----------MAIN MENU----------" << endl;
                            cout << "1. Add Akhrajat" << endl;
                            cout << "2. Delete Akhrajat" << endl;
                            cout << "3. Search Akhrajat by Date" << endl;
                            cout << "4. Display All Akhrajat" << endl;
                            cout << "5. Sort Akhrajat by Amount" << endl;
                            cout << "6. Exit" << endl;
                            cout << "Enter your choice(1-6): ";
                            cin >> choice;
                            cin.ignore();
                            cout << endl;

                            cout << "--------------------------------" << endl
                                 << endl;

                            if (choice == 1)
                            {
                                do
                                {
                                    setColor(13);
                                    cout << "Enter Akhrajat Details: " << endl;
                                    cout << "Enter Date: ";
                                    getline(cin, dakhrajat.date);
                                    cout << "Enter Tafseel Kharcha: ";
                                    getline(cin, dakhrajat.tafseel_kharcha);
                                    cout << "Enter Amount: ";
                                    cin >> dakhrajat.amount;
                                    cin.ignore();
                                    a1.insertnode(dakhrajat.date, dakhrajat.tafseel_kharcha, dakhrajat.amount);
                                    cout << "Do you want to add more Akhrajat? (y/n): ";
                                    cin >> ch;
                                    cin.ignore();
                                } while (ch == 'y' || ch == 'Y');
                                setColor(10);
                                cout << "Akhrajat Added Successfully!" << endl
                                     << endl;
                            }
                            else if (choice == 2)
                            {
                                a1.deletenode();
                                setColor(10);
                                cout << "Akhrajat Deleted Successfully!" << endl
                                     << endl;
                                setColor(7);
                                a1.display();
                            }
                            else if (choice == 3)
                            {
                                string date;
                                setColor(13);
                                cout << "Enter Date to Search Akhrajat: ";
                                getline(cin, date);
                                a1.searchbydate(date);
                            }
                            else if (choice == 4)
                            {
                                setColor(7);
                                a1.display();
                            }
                            else if (choice == 5)
                            {
                                a1.insertionSortByAmount();
                                setColor(10);
                                cout << "Akhrajat Sorted by Amount Successfully!" << endl
                                     << endl;
                                setColor(7);
                                a1.display();
                            }

                        } while (choice != 6);
                    }

                } while (choice != 4);
            }
            else
            {
                setColor(12);
                cout << "Invalid Username or Password!" << endl
                     << endl;
            }
        }
    } while (choice != 3);

    return 0;
}
