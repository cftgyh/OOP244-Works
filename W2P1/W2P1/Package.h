/*
OOP244 Workshop 2 p1: Package header file

Name: Xinyu Zhang
Email: xzhang399@myseneca.ca
Student ID: 174538215
Date: 2023-01-25
I have done all the coding by myself and
only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_PACAGE_H_
#define SDDS_PACKAGE_H_

#define filename_r "Filtered_Dataset.csv"

namespace sdds {

    struct Customers {
        char* Package_Name;
        int user_id;
        double timeinhours;
        int dayofyear;
        int Fwifitime;
        int Fctime;
        char dayofweek;
    };

    int loadTraces(); // loads a customers structure with its values from the file
           
    int loadTraces(Customers& user); // allocates dynamic array of customers and loads all the file records into the array.

    void grouptTraces(); //Group the dynamic array of records based on the user id of customers.

   
    // ADD [1]: Declare a prototype for the display function, this function displays a customer record on the screen.
    void display();

   // ADD [2]: Declare a prototype for the deallocateMemory function that do the following:
                         // (1). deallocates all the Package names in the customer (users) elements,
                         // (2). deallocates the users array 

    void deallocateMemory();

}
#endif  