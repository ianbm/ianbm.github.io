---
layout: project
type: project
image: images/databaseProject.jpg
title: Database Project
permalink: projects/databaseProject
date: 2020-10-07
labels:
  - C
  - C++
summary: I created an application using C and C++
---
<img class="ui medium right floated rounded image" src="/images/databaseProject.jpg">

I took a Program Structure course and in this class, we learned both C and C++ programming languages. In this class, we were assigned two projects. Both projects are the same, except for the language they are written in. The first project was written in C, while the second project was written in C++.

This project involves an interface where users are given the option to add, print all, find, or delete a record from the database. The data is stored in a database in the form of a linked list.

Here is some code from project1 (C):
```js
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
```

And here is some code from project2 (C++):
```js
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
```
