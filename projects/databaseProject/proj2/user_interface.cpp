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
//  FILE:        user_interface.cpp
//
//  DESCRIPTION:
//   This file contains the user interface.
//
****************************************************************/

#include <string.h>
#include <iostream>
using namespace std;
#include "record.h"
#include "llist.h"
void getaddress(char [], int);

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        llist mylist;

        char option[64];
        char temp[100];
        int checkInput;
        int accountno;
        char name[25];
        char address[80];
        int i;
        int quitProgram;

        checkInput = 1;
        quitProgram = 1;

        #ifdef DEBUG
            cout << "[DEBUG] Program is running in debug mode \n\n";
        #endif

        cout << "\nWelcome! You can access the database by choosing an option below:\n";

        while(quitProgram == 1)
        {
            option[0] = '\0';
            checkInput = 1;

            cout << "\n-----------------------------------------------------------\n";
            cout << "These are the available options:\n\n";
            cout << "add:\t\tAdd a new record to the database\n";
            cout << "printall:\tPrint all records in the database\n";
            cout << "find:\t\tFind record(s)\n";
            cout << "delete:\t\tDelete existing record(s) from the database\n";
            cout << "quit:\t\tQuit the program\n";
            cout << "\n-----------------------------------------------------------\n";

            cout << "Enter an option: ";
            cin >> option;

            cin.clear();
            cin.getline(temp, 100);

            while(checkInput > 0)
            {
                if(option[0] == 'a')
                {
                    if(option[1] == 'd' || option[1] == '\0')
                        if(option[2] == 'd' || option[2] == '\0')
                            checkInput = strcmp(option, "add");
                }
                else if(option[0] == 'p')
                {
                    if(option[1] == 'r' || option[1] == '\0')
                        if(option[2] == 'i' || option[2] == '\0')
                            if(option[3] == 'n' || option[3] == '\0')
                                if(option[4] == 't' || option[4] == '\0')
                                    if(option[5] == 'a' || option[5] == '\0')
                                        if(option[6] == 'l' || option[6] == '\0')
                                            if(option[7] == 'l' || option[7] == '\0')
                                                checkInput = strcmp(option, "printall");
                }
                else if(option[0] == 'f')
                {
                    if(option[1] == 'i' || option[1] == '\0')
                        if(option[2] == 'n' || option[2] == '\0')
                            if(option[3] == 'd' || option[3] == '\0')
                                checkInput = strcmp(option, "find");
                }
                else if(option[0] == 'd')
                {
                    if(option[1] == 'e' || option[1] == '\0');
                        if(option[2] == 'l' || option[2] == '\0')
                            if(option[3] == 'e' || option[3] == '\0')
                                if(option[4] == 't' || option[4] == '\0')
                                    if(option[5] == 'e' || option[5] == '\0')
                                        checkInput = strcmp(option, "delete");
                }
                else if(option[0] == 'q')
                {
                    if(option[1] == 'u' || option[1] == '\0')
                        if(option[2] == 'i' || option[2] == '\0')
                            if(option[3] == 't' || option[3] == '\0')
                                checkInput = strcmp(option, "quit");
                }


                if(checkInput > 0 && (option[0] != 'a' || option[0] != 'p' || option[0] != 'f' || option[0] != 'd' || option[0] != 'q'))
                {
                    cout << "ERROR! Please enter a valid option: ";
                    cin >> option;
                    cin.clear();
                    cin.getline(temp, 100);
                }
            }

            if(option[0] == 'a' && checkInput <= 0)
            {
                accountno = -1;

                cout << "\nEnter the account number: ";
                cin >> accountno;
                cin.clear();
                cin.getline(temp, 100);

                while(accountno <= 0)
                {
                    cout << "Invalid accountnumber! Account numbers must be a postive integer.\nEnter the account number: ";
                    cin >> accountno;
                    cin.clear();
                    cin.getline(temp, 100);
                }

                cout << "Enter the name: ";
                cin >> name;
                cin.clear();
                cin.getline(temp, 100);

                for(i = 0; i < (int) strlen(name); i++)
                {
                    if(name[i] == '\t')
                    {
                        cout << "You cannot use tab characters!\nEnter the name: ";
                        cin >> name;
                        cin.clear();
                        cin.getline(temp, 100);
                        name[strlen(name) - 1] = '\0';
                    }
                }

                getaddress(address, 80);

                cout << "\nadding record...\n\n";
                mylist.addRecord(accountno, name, address);
            }
            else if(option[0] == 'p' && checkInput <= 0)
            {
                cout << mylist;
            }
            else if(option[0] == 'f' && checkInput <= 0)
            {
                cout << "\nEnter the account number: ";
                cin >> accountno;
                cin.clear();
                cin.getline(temp, 100);

                while(accountno <= 0)
                {
                    cout << "The account number must be positive: ";
                    cin >> accountno;
                    cin.clear();
                    cin.getline(temp, 100);
                }

                mylist.findRecord(accountno);
            }
            else if(option[0] == 'd' && checkInput <= 0)
            {
                cout << "\nEnter the account number: ";
                cin >> accountno;
                cin.clear();
                cin.getline(temp, 100);

                while(accountno <= 0)
                {
       	            cout << "The account number must be positive: ";
                    cin >> accountno;
                    cin.clear();
                    cin.getline(temp, 100);
                }

                cout << "\ndeleting record...\n\n";
                mylist.deleteRecord(accountno);
            }
            else if(option[0] == 'q' && checkInput <= 0)
            {
                quitProgram = 0;
            }
        }
    
    }
    else
    {
        cout << "ERROR! check arguments\n";
    }

    return 0;
}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   The getaddress function.
//                 This function gives prompts the user to enter
//                             an address. This funcion allows
//                             input of multiple lines, and stores
//                             it into one character array. New
//                             line characters are replaced with
//                             spaces.
//
//  Parameters:    address (char *) : contains the array which will
//                             store the address
//                 length (int) : contains the length of the
//                             address array
//
//  Return values:  
//
****************************************************************/

void getaddress(char * address, int length)
{
    char temp;
    int i;
    int done;

    i = 0;
    done = 0;

    for(i = 0; i < length; i++)
        address[i] = 0;

    i = 0;

    #ifdef DEBUG
        cout << "\n[DEBUG] getaddress()\n\n";
    #endif

    cout << "Enter the address (press <esc> + <new line> when done):\n";
    while(done == 0)
    {
        cin.get(temp);

        if(temp == 27)
        {
            done = 1;
        }
        else if(temp == '\n')
        {
            #ifdef DEBUG
                cout << "[DEBUG] replacing '\\n' with ' '\n";
            #endif

            address[i] = ' ';
            i++;
        }
        else
        {
            address[i] = temp;
            i++;
        }
    }
}
