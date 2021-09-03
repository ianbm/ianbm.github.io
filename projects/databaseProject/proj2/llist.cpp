/*****************************************************************
//
//  NAME:        Ian Manzano
//
//  HOMEWORK:    project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        December 3, 2020
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This file defines the llist functions.
//
****************************************************************/

#include <cstddef>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#include "record.h"
#include "llist.h"

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   The constructor
//                 Initializes the llist and reads data from file
//
//  Parameters:
//
//  Return values:
//
****************************************************************/

llist::llist()
{
    start = NULL;
    strcpy(filename, "data.txt");
    readfile();
}

/*****************************************************************
//
//  Function name: llist  
//
//  DESCRIPTION:   The copy constructor
//                 Initializes the llist and reads data from file
//
//  Parameters:
//
//  Return values:
//
****************************************************************/

llist::llist(char * ufilename)
{
    start = NULL;
    strcpy(filename, ufilename);
    readfile();
}

/*****************************************************************
//
//  Function name: ~llist  
//
//  DESCRIPTION:   The destructor     
//                 Writes the llist data to a file and cleans up
//
//  Parameters:
//
//  Return values:
//
****************************************************************/

llist::~llist()
{
    writefile();
    cleanup();
}

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   The addRecord function
//                 Adds a record to the database in descending
//                      order based on the account number.
//
//  Parameters:    uaccountno (int) : contains the account number
//                 uname (char[]) : contains the name
//                 uaddress (char[]) : contains the address
//
//  Return values:  0 : failed to add record
//                  1 : successfully added record
//
****************************************************************/

int llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    struct record * temp;
    struct record * before;
    struct record * after;
    int added;
    int done;

    #ifdef DEBUG
        cout << "\n[DEBUG] called addRecord() function...\n";
    #endif

    added = 0;
    temp = new struct record;

    (*temp).accountno = uaccountno;
    strcpy((*temp).name, uname);
    strcpy((*temp).address, uaddress);
    (*temp).next = NULL;
    done = 0;

    if(start == NULL || uaccountno > (*start).accountno)
    {
        added = 1;
        (*temp).next = start;
        start = temp;
    }
    else
    {
        before = start;
        after = (*start).next;

        while(done == 0)
        {
            if(uaccountno <= (*before).accountno && (after == NULL || uaccountno > (*after).accountno))
            {
                added = 1;
                (*before).next = temp;
                (*temp).next = after;
                done = 1;
            }
            else
            {
                before = after;
                after = (*after).next;
            }
        }
    }

    return added;
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   The findRecord function
//                 Finds and prints record(s) from the database
//                      with the provided account number.
//
//  Parameters:    uaccountno (int) : contains the account number
//
//  Return values:  0 : record not found
//                  1 : record found
//
****************************************************************/

int llist::findRecord(int uaccountno)
{
    struct record * temp;
    int done;
    int found;

    #ifdef DEBUG
        cout << "\n[DEBUG] called findRecord() function...\n";
        cout << "[DEBUG] Account Number: " << uaccountno << endl;
        cout << "[DEBUG] searching database for account number " << uaccountno << "\n\n";
    #endif

    temp = start;
    done = 0;
    found = 0;

    if(start == NULL)
        cout << "\nThe list is empty!\n";
    else
    {
     	while(done == 0)
        {
            if((*temp).accountno == uaccountno)
            {
                cout << "\nAccount Number: " << (*temp).accountno << endl;
                cout << "Name: " << (*temp).name << endl;
                cout << "Address: " << (*temp).address << endl;
                cout << endl;
                found = 1;
            }

            if((*temp).next == NULL)
                done = 1;
            else
                temp = (*temp).next;
        }

        if(found == 0)
            cout << "\nCould not find a record with account number " << uaccountno <<" in the list\n";
    }

    return found;
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   The printAllRecords function
//                 Prints all records from the database.
//
//  Parameters:    
//
//  Return values:  
//
****************************************************************/

void llist::printAllRecords()
{
    struct record * temp;
    int done;

    #ifdef DEBUG
        cout << "\n[DEBUG] called printAllRecords() function...\n";
        cout << "[DEBUG] Printing all records in the database...\n\n";
    #endif

    temp = start;
    done = 0;

    if(start == NULL)
        cout << "\nThe list is empty!" << endl;
    else
    {
        while(done == 0)
        {
            cout << "\nAccount Number: " << (*temp).accountno << endl;
            cout << "Name: "<< (*temp).name << endl;
            cout << "Address: " << (*temp).address << "\n\n";
            temp = (*temp).next;

            if(temp == NULL)
                done = 1;
        }
    }

}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   The deleteRecord function
//                 Deletes alls record from the database with the
//                      provided account number.
//
//  Parameters:    uaccountno (int) : contains the account number
//
//  Return values:  0 : nothing deleted
//                  1 : record(s) deleted
//
****************************************************************/

int llist::deleteRecord(int uaccountno)
{
    struct record * temp;
    struct record * previous;
    int found;
    int done;

    #ifdef DEBUG
        cout << "\n[DEBUG] called deleteRecord() function...\n";
        cout << "[DEBUG] Account Number: " << uaccountno << endl;
        cout << "[DEBUG] searching database for account number " << uaccountno << "\n\n";
    #endif

    temp = start;
    found = 0;
    done = 0;

    if(start == NULL)
        cout << "\nThe list is empty!" << endl;
    else
    {
        while(done == 0)
        {
            if(temp == NULL)
                done = 1;
            else if((*start).accountno == uaccountno)
            {
                #ifdef DEBUG
                    cout << "[DEBUG] deleting account...\n\n";
                #endif

                previous = start;
                temp = (*start).next;
                start = temp;
                delete previous;
                found = 1;
            }
            else if((*temp).accountno == uaccountno)
            {
                #ifdef DEBUG
       	       	    cout << "[DEBUG] deleting account...\n\n";
       	       	#endif

                (*previous).next = (*temp).next;
                delete temp;
                temp = (*previous).next;
                found = 1;
            }
            else
            {
             	previous = temp;
                temp = (*temp).next;
            }
        }
    }

    return found;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   The deleteRecord function
//                 Deletes a record from the database.
//
//  Parameters:    
//                      
//  Return values:  0 : file not found
//                  1 : file found
//
****************************************************************/

int llist::readfile()
{
    int uaccountno;
    char uname[25];
    char uaddress[80];
    int found;
    ifstream filein;

    #ifdef DEBUG
        cout << "\n[DEBUG] called readfile() function...\n";
        cout << "[DEBUG] filename: " << filename << "\n\n";
    #endif

    found = 1;
    filein.open(filename);

    if(filein == NULL)
    {
        found = 0;
    }
    else
    {
        while(filein >> uaccountno)
        {
            filein.get();
            filein.getline(uname, 25, '\n');
            filein.getline(uaddress, 80, '\n');

            #ifdef DEBUG
                cout << "[DEBUG] adding account...\n";
                cout << "[DEBUG] Account Number: " << uaccountno << endl;
                cout << "[DEBUG] Name: " << uname << endl;
                cout << "[DEBUG] Address: " << uaddress << "\n\n";
            #endif

            addRecord(uaccountno, uname, uaddress);
        }

        filein.close();
    }

    return found;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   The deleteRecord function
//                 Deletes a record from the database.
//
//  Parameters:    
//                      
//  Return values:  0 : file not found
//                  1 : file found
//  
****************************************************************/

int llist::writefile()
{
    struct record * temp;
    int found;
    ofstream fileout;

    #ifdef DEBUG
        cout << "\n[DEBUG] called writefile() function...\n";
        cout << "[DEBUG] filename: " << filename << "\n\n";
    #endif

    found = 1;
    fileout.open("data.txt");
    temp = start;

    if(fileout == NULL)
    {
        found = 0;
    }
    else
    {
        while(temp != NULL)
        {
            #ifdef DEBUG
                cout << "[DEBUG] saving account...\n";
                cout << "[DEBUG] Account Number: " << (*temp).accountno << endl;
                cout << "[DEBUG] Name: " << (*temp).name << endl;
                cout << "[DEBUG] Address: " << (*temp).address << "\n\n";
            #endif

            fileout << (*temp).accountno << "\n";
            fileout << (*temp).name << "\n";
            fileout << (*temp).address << "\n";

            temp = (*temp).next;
        }
    }

    fileout.close();

    return found;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   The cleanup function
//                 Deletes all records from the database.
//
//  Parameters:    
//                      
//  Return values: 
//  
****************************************************************/

void llist::cleanup()
{
    struct record * temp;
    struct record * after;

    #ifdef DEBUG
        cout << "\n[DEBUG] called cleanup() function...\n\n";
    #endif

    temp = start;

    while(temp != NULL)
    {
        #ifdef DEBUG
            cout << "[DEBUG] deleting account...\n";
            cout << "[DEBUG] Account Number: " << (*temp).accountno << endl;
            cout << "[DEBUG] Name: " << (*temp).name << endl;
            cout << "[DEBUG] Address: " << (*temp).address << "\n\n";
        #endif

        after = (*temp).next;
        delete(temp);
        temp = after;
    }

    start = NULL;
}

/*****************************************************************
//
//  Function name: operator<<
//
//  DESCRIPTION:   The deleteRecord function
//                 Deletes a record from the database.
//
//  Parameters:    stream : the stream that will hold the
//                     processed data.
//                 list : the list the contains the data to be
//                     processed.
//
//  Return values:  
//
****************************************************************/

ostream& operator<<(ostream& stream, const llist& list)
{
    struct record * temp;
    int done;

    #ifdef DEBUG
        cout << "\n[DEBUG] overloaded << operator\n";
        cout << "[DEBUG] Printing all records in the database...\n\n";
    #endif

    temp = list.start;
    done = 0;

    if(list.start == NULL)
        cout << "\nThe list is empty!" << endl;
    else
    {
        while(done == 0)
        {
            stream << "\nAccount Number: " << (*temp).accountno << endl;
            stream << "Name: "<< (*temp).name << endl;
            stream << "Address: " << (*temp).address << "\n\n";
            temp = (*temp).next;

            if(temp == NULL)
                done = 1;
        }
    }

    return stream;
}
