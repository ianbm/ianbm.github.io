/*****************************************************************
//
//  NAME:        Ian Manzano
//
//  HOMEWORK:    project 2
//
//  CLASS:	 ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        December 3, 2020
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   This file contains the llist class and protoypes for the
//       llist functions.
//
****************************************************************/

#ifndef LLIST_H
#define LLIST_H

class llist
{
private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    void        cleanup();

public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord(int, char [ ],char [ ]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
    friend ostream& operator<<(ostream&, const llist&);
};

#endif
