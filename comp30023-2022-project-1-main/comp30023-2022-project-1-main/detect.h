#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMPTY -2

int invoke(int argc, char *argv[]);

char* get_path(int argc, char *argv[]);

int task_1(char* file_path);

// implementation of a graph structure mainly based on 
// geeks for geeks version (05.01.22) viewable at:
// https://www.geeksforgeeks.org/graph-and-its-representations/?ref=gcse

// struct to rep an adj list node
struct alnode {
    int dest;
    struct aln* next;
};

// struct to rep adj list
struct al {
    struct alnode* head;
};

// struct to rep graph as an array of adj lists.
// size of array v no. of vertices.
struct graph {
    int v;
    struct al* array;
};

// function to create new adj list node
struct alnode* newalnode(int dest);








