// Hovhannes Margaryan
// CS/IS 135 - 3817 - Online Class
// Lab 6p1

#ifndef lotto_h
#define lotto_h

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <stdlib.h>

using std::string;

const int SIZE = 7;
const int MAX_ENTRY = 40;
const string _BORDER_ = "---------------------------";

string getUserName();
void createMenu();
char getUserSelection();
int getLottoPicksthat(int[],int);
bool noDuplicatesthat(int[], int,int);
int genWinNumsthat(int[],int);
bool noDuplicatesfunction(int[], int, int);
int checkNumbers(int[], int[]);
void displayReport(int[],int[], string,int);
void printNumbers(int[]);
string getLottoStatus(int);


#endif

