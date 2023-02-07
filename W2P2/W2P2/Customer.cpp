/*
OOP244 Workshop 2 p1: Customer.cpp file

Name: Xinyu Zhang
Email: xzhang399@myseneca.ca
Student ID: 174538215
Date: 2023-01-28
I have done all the coding by myself and
only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete
    void EmptyRecord(Customers& c_rec)
    {
        c_rec = { 0 };
    }
    void EmptyRecord(CustomersRecord& t_rec)
    {
        t_rec.ptr_rec = nullptr;
        t_rec.noOfRecords = 0;
    }

    bool read(Customers& rec)
    {
        bool validValue;
        
        cout << " Enter User name: ";
        read(rec.user_name, 21);
        if (rec.user_name[0] != '\0')
        {
            validValue = true;
            cout << " Enter likes_count: ";
            cin >> rec.likes_count;
            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << " Enter replies_count: ";
            cin >> rec.replies_count;
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
        }
        else
        {
            validValue = false;
        }

        return validValue;
    }
    void read(char* str, int len) 
    {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec)
    {
        if (t_rec.noOfRecords == 0)
        {
            t_rec.ptr_rec = new Customers[t_rec.noOfRecords + 1];
            *t_rec.ptr_rec = c_rec;
        }
        else
        {
            int i;
            Customers* newCustomer = nullptr;
            newCustomer = new Customers[t_rec.noOfRecords + 1];

            for (i = 0; i < t_rec.noOfRecords; i++)
            {
                newCustomer[i] = t_rec.ptr_rec[i];
            }
            newCustomer[t_rec.noOfRecords] = c_rec;

            delete[] t_rec.ptr_rec;
            t_rec.ptr_rec = nullptr;
            t_rec.ptr_rec = newCustomer;
        }
        t_rec.noOfRecords += 1;
    }

    void display(const Customers& c_rec)
    {
        cout << c_rec.user_name << ", "
             << c_rec.likes_count << ", "
             << c_rec.retweets_count << ", "
             << c_rec.replies_count << ", "
             << c_rec.share_videos << endl;
    }
    void display(const CustomersRecord& t_rec)
    {
        int i;
        for (i = 1; i < t_rec.noOfRecords + 1; i++)
        {
            cout << i << ". ";
            display(t_rec.ptr_rec[i-1]);
            cout << endl;
        }
    }
    // complete
}
