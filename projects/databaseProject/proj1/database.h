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
//  FILE:        database.h
//
//  DESCRIPTION:
//   Contains the function prototypes for the database functions.
//
****************************************************************/

int addRecord (struct record **, int, char [ ],char [ ]);
void printAllRecords(struct record *);
int findRecord (struct record *, int);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
int writefile(struct record *, char []);
void cleanup(struct record **);
