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
//  FILE:        record.h
//
//  DESCRIPTION:
//   Defines a structure called record
//
****************************************************************/

struct record
{
    int accountno;
    char name[25];
    char address[80];
    struct record* next;
};
