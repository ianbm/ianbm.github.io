/*****************************************************************
//
//  NAME:        Ian Manzano
//
//  HOMEWORK:    3
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 21, 2020
//
//  FILE:        user_interface.c
//
//  DESCRIPTION:
//   This file contains the user-interface
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "record.h"
#include "database.h"
void getaddress(char [], int);
int debugmode;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   The main function.
//                 This function gives the user an interface to
//                             interact with the program.
//
//  Parameters:    argc (int) : contains the number of arguments
//                             which will be processed
//                 *argv[] (char) : contains the values of the
//                             arguments which will be processed
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char *argv[])
{
    if(argc == 1 || (argc == 2 && strcmp(argv[1], "debug") == 0))
    {
        struct record * start;
        char option[64];
        char temp[100];
        int checkInput;
        int accountno;
        char name[25];
        char address[80];
        int i;
        int quitProgram;

        start = NULL;
        checkInput = 1;
        quitProgram = 1;

        if(argc == 2 && strcmp(argv[1], "debug") == 0)
        {
            debugmode = 1;
        }

        if(debugmode == 1)
        {
            printf("\n[DEBUG] argc: %d\n", argc);
            printf("[DEBUG] argv: %s\n\n", argv[1]);
        }

        readfile(&start, "list.txt");

        printf("\nWelcome! You can access the database by choosing an option below:\n");

        while(quitProgram == 1)
        {
            option[0] = '\0';
            checkInput = 1;

            printf("\n-----------------------------------------------------------\n");
            printf("These are the available options:\n\n");
            printf("add:\t\tAdd a new record to the database\n");
            printf("printall:\tPrint all records in the database\n");
            printf("find:\t\tFind record(s)\n");
            printf("delete:\t\tDelete existing record(s) from the database\n");
            printf("quit:\t\tQuit the program\n");
            printf("\n-----------------------------------------------------------\n");

            printf("Enter an option: ");
            scanf("%s", option);
            fgets(temp, 100, stdin);

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
                    if(option[1] == 'e' || option[1] == '\0')
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
                    printf("ERROR! Please enter a valid option: ");
                    scanf("%s", option);
                    fgets(temp, 100, stdin);
                }
            }

            if(option[0] == 'a' && checkInput <= 0)
            {
                accountno = -1;

                printf("\nEnter the account number: ");
                scanf("%i", &accountno);
                fgets(temp, 100, stdin);
        
                while(accountno <= 0)
                {
                    printf("Invalid accountnumber! Account numbers must be a postive integer.\nEnter the account number: ");
                    scanf("%i", &accountno);
                    fgets(temp, 100, stdin);
                }

                printf("Enter the name: ");
                fgets(name, 25, stdin);
                name[strlen(name) - 1] = '\0';

                for(i = 0; i < strlen(name); i++)
                {
                    if(name[i] == '\t')
                    {
                        printf("You cannot use tab characters!\nEnter the name: ");
                        fgets(name, 25, stdin);
                        name[strlen(name) - 1] = '\0';
                    }
                }

                getaddress(address, 80);

                printf("\nadding record...\n\n");
                addRecord(&start, accountno, name, address);
            }
            else if(option[0] == 'p' && checkInput <= 0)
            {
                printAllRecords(start);
            }
            else if(option[0] == 'f' && checkInput <= 0)
            {
                printf("\nEnter the account number: ");
                scanf("%d", &accountno);
                fgets(temp, 100, stdin);

                while(accountno <= 0)
                {
       	            printf("The account number must be positive: ");
                    scanf("%d", &accountno);
                    fgets(temp, 100, stdin);
       	        } 

                findRecord(start, accountno);
            }
            else if(option[0] == 'd' && checkInput <= 0)
            {
                printf("\nEnter the account number: ");
                scanf("%d", &accountno);
                fgets(temp, 100, stdin);

                while(accountno <= 0)
                {
       	            printf("The account number must be positive: ");
                    scanf("%d", &accountno);
                    fgets(temp, 100, stdin);
                } 

                printf("\ndeleting record...\n\n");
                deleteRecord(&start, accountno);
            }
            else if(option[0] == 'q' && checkInput <= 0)
            {
                quitProgram = 0;
                writefile(start, "list.txt");
                cleanup(&start);
            }
        }
    
    }
    else
    {
        printf("ERROR! check arguments\n");
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

    if(debugmode == 1)
    {
        printf("\n[DEBUG] getaddress()\n\n");
    }

    printf("Enter the address (press <esc> + <new line> when done):\n");
    while(done == 0)
    {
        temp = fgetc(stdin);

        if(temp == 27)
        {
            done = 1;
        }
        else if(temp == '\n')
        {
            if(debugmode == 1)
                printf("[DEBUG] replacing '\\n' with ' '\n");

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
