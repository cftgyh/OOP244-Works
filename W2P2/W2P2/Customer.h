/*
OOP244 Workshop 2 p1: Customer.h file

Name: Xinyu Zhang
Email: xzhang399@myseneca.ca
Student ID: 174538215
Date: 2023-01-28
I have done all the coding by myself and
only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };


    void EmptyRecord(Customers& c_rec);
    void EmptyRecord(CustomersRecord& t_rec);
    bool read(Customers& rec);
    void read(char* str, int len);
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);
    void display(const Customers& c_rec);
    void display(const CustomersRecord& t_rec);

}

#endif 