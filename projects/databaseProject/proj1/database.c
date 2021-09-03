
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
//  FILE:        database.c
//
//  DESCRIPTION:
//   This file defines the database functions.
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"
extern int debugmode;
int addRecord (struct record **, int, char [],char []);

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   The addRecord function
//                 Adds a record to the database in descending
//                      order based on the account number.
//
//  Parameters:    pstart (struct record **) : contains the start pointer
//                 accountno (int) : contains the account number
//                 name (char *) : contains the name
//                 address (char *) : contains the address
//
//  Return values:  0 : failed to add record
//                  1 : successfully added record
//
****************************************************************/

int addRecord (struct record ** pstart, int uaccountno, char * uname, char * uaddress)
{
    struct record * temp;
    struct record * before;
    struct record * after;
    int added;
    int done;

    if(debugmode == 1)
    {
     	printf("\n[DEBUG] called addRecord() function...\n");
    }

    added = 0;
    temp = malloc(sizeof(struct record));

    (*temp).accountno = uaccountno;
    strcpy((*temp).name, uname);
    strcpy((*temp).address, uaddress);
    (*temp).next = NULL;
    done = 0;

    if(*pstart == NULL || uaccountno > (**pstart).accountno)
    {
        added = 1;
        (*temp).next = *pstart;
        *pstart = temp;
    }
    else
    {
        before = *pstart;
        after = (**pstart).next;

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
//  Function name: printAllRecords
//
//  DESCRIPTION:   The printAllRecords function
//                 Prints all records from the database.
//
//  Parameters:    start (struct record *) : contains the record
//
//  Return values:  
//
****************************************************************/

void printAllRecords(struct record * start)
{
    struct record * temp;
    int done;

    if(debugmode == 1)
    {
     	printf("\n[DEBUG] called printAllRecords() function...\n");
        printf("[DEBUG] Printing all records in the database...\n\n");
    }

    temp = start;
    done = 0;

    if(start == NULL)
        printf("\nThe list is empty!\n");
    else
    {
        while(done == 0)
        {
            printf("\nAccount Number: %d\n", (*temp).accountno);
            printf("Name: %s\n", (*temp).name);
            printf("Address: %s\n\n", (*temp).address);
            temp = (*temp).next;

            if(temp == NULL)
                done = 1;
        }
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   The findRecord function
//                 Finds and prints record(s) from the database
//                      with the provided account number.
//
//  Parameters:    start (struct record *) : contains the record
//                 accountno (int) : contains the account number
//
//  Return values:  0 : record not found
//                  1 : record found
//
****************************************************************/

int findRecord (struct record * start, int uaccountno)
{
    struct record * temp;
    int done;
    int found;

    if(debugmode == 1)
    {
        printf("\n[DEBUG] called findRecord() function...\n");
        printf("[DEBUG] Account Number: %d\n", uaccountno);
        printf("[DEBUG] searching database for account number %d\n\n", uaccountno);
    }

    temp = start;
    done = 0;
    found = 0;

    if(start == NULL)
        printf("\nThe list is empty!\n");
    else
    {
     	while(done == 0)
        {
            if((*temp).accountno == uaccountno)
            {
                printf("\nAccount Number: %d\n", (*temp).accountno);
                printf("Name: %s\n", (*temp).name);
                printf("Address: %s\n\n", (*temp).address);
                found = 1;
            }

            if((*temp).next == NULL)
                done = 1;
            else
                temp = (*temp).next;
        }

        if(found == 0)
            printf("\nCould not find a record with account number %d in the list\n", uaccountno);
    }

    return found;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   The deleteRecord function
//                 Deletes alls record from the database with the
//                      provided account number.
//
//  Parameters:    start (struct record **) : contains the start pointer
//                 accountno (int) : contains the account number
//
//  Return values:  0 : nothing deleted
//                  1 : record(s) deleted
//
****************************************************************/

int deleteRecord(struct record ** pstart, int uaccountno)
{
    struct record * temp;
    struct record * previous;
    int found;
    int done;

    if(debugmode == 1)
    {
        printf("\n[DEBUG] called deleteRecord() function...\n");
     	printf("[DEBUG] Account Number: %d\n", uaccountno);
        printf("[DEBUG] searching database for account number %d\n", uaccountno);
    }

    temp = *pstart;
    found = 0;
    done = 0;

    if(pstart == NULL)
        printf("\nThe list is empty!\n");
    else
    {
        while(done == 0)
        {
            if(temp == NULL)
                done = 1;
            else if((**pstart).accountno == uaccountno)
            {
                if(debugmode == 1)
                    printf("[DEBUG] deleting account...\n\n");

                previous = *pstart;
                temp = (**pstart).next;
                *pstart = temp;
                free(previous);
                found = 1;
            }
            else if((*temp).accountno == uaccountno)
            {
                if(debugmode == 1)
       	       	    printf("[DEBUG] deleting account...\n\n");

                (*previous).next = (*temp).next;
                free(temp);
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
//                      *This is a stub function
//
//  Parameters:    start (struct record **) : contains the start pointer
//                 filename (char *) : contains the file name
//                      
//  Return values:  0 : file not found
//                  1 : file found
//
****************************************************************/

int readfile(struct record ** pstart, char * filename)
{
    int uaccountno;
    char uname[25];
    char uaddress[80];
    int found;
    FILE * filein;

    if(debugmode == 1)
    {
        printf("\n[DEBUG] called readfile() function...");
        printf("[DEBUG] filename: %s\n\n", filename);
    }

    found = 1;
    filein = fopen(filename, "r");

    if(filein == NULL)
    {
        found = 0;
    }
    else
    {
        while(fscanf(filein, "%d\n", &uaccountno) != EOF)
        {
            fgets(uname, 25, filein);
            if(uname[strlen(uname) - 1] == '\n')
                uname[strlen(uname) - 1] = '\0';

            fgets(uaddress, 80, filein);
            if(uaddress[strlen(uaddress) - 1] == '\n')
                uaddress[strlen(uaddress) - 1] = '\0';

            if(debugmode == 1)
            {
                printf("[DEBUG] adding account...\n");
                printf("[DEBUG] Account Number: %d\n", uaccountno);
                printf("[DEBUG] Name: %s\n", uname);
                printf("[DEBUG] Address: %s\n\n", uaddress);
            }

            addRecord(pstart, uaccountno, uname, uaddress);
        }

        fclose(filein);
    }

    return found;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   The deleteRecord function
//                 Deletes a record from the database.
//                      *This is a stub function
//
//  Parameters:    start (struct record *) : contains the record
//                 filename (char *) : contains the file name
//                      
//  Return values:  0 : file not found
//                  1 : file found
//  
****************************************************************/

int writefile(struct record * start, char * filename)
{
    struct record * temp;
    int found;
    FILE * fileout;

    if(debugmode == 1)
    {
       	printf("\n[DEBUG] called writefile() function...\n");
       	printf("[DEBUG]	filename: %s\n\n", filename);
    }

    found = 1;
    fileout = fopen(filename, "w");
    temp = start;

    if(fileout == NULL)
    {
        found = 0;
    }
    else
    {
        while(temp != NULL)
        {
            if(debugmode == 1)
            {
                printf("[DEBUG] saving account...\n");
                printf("[DEBUG] Account Number: %d\n", (*temp).accountno);
                printf("[DEBUG] Name: %s\n", (*temp).name);
                printf("[DEBUG] Address: %s\n\n", (*temp).address);
            }

            fprintf(fileout, "%d\n", (*temp).accountno);
            fprintf(fileout, "%s\n", (*temp).name);
            fprintf(fileout, "%s\n", (*temp).address);

            temp = (*temp).next;
        }
    }

    fclose(fileout);

    return found;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   The deleteRecord function
//                 Deletes a record from the database.
//                      *This is a stub function
//
//  Parameters:    start (struct record **) : contains the start pointer
//                      
//  Return values: 
//  
****************************************************************/

void cleanup(struct record ** pstart)
{
    struct record * temp;
    struct record * after;

    if(debugmode == 1)
       	printf("\n[DEBUG] called cleanup() function...\n\n");

    temp = *pstart;

    while(temp != NULL)
    {
        if(debugmode == 1)
        {
            printf("[DEBUG] deleting account...\n");
            printf("[DEBUG] Account Number: %d\n", (*temp).accountno);
            printf("[DEBUG] Name: %s\n", (*temp).name);
            printf("[DEBUG] Address: %s\n\n", (*temp).address);
        }

        after = (*temp).next;
        free(temp);
        temp = after;
    }

    *pstart = NULL;
}
