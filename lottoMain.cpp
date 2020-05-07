// lottoMain.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Hovhannes Margaryan
// CS/IS 135 - 3817 - Online Class
// Lab 6p1

/*Pseudocode
  * Create variables >> int winNumbersCount, userTicketarray[7], winningNumsarray[7]; string userName; char userSelection;
  * userName = function getUserName()
                          Create variable string name
                          Display Please enter your name: 
                          Ask for name
                          return name
  * do
      Call function createMenu()
                      Display LITTLETON CITY LOTTO MODEL:
                      Display ---------------------------
                      Display 1) Play Lotto
                      Display q) Quit Program
      userSelection = function getUserSelection()
                                  Create variable char selection
                                  Display Please make a selection: 
                                  Ask for selection
                                  if selection is not equal 1 and selection is not equal q
                                               Display Invalid selection
                                  returne selection
     if userSelection equal 1
        for i = 0; i < 7; i++
            userTicketarray[i] = function getLottoPicksthat(userTicketarray,i + 1);
                                             create variable i
                                             do
                                               Display Enter item # + i
                                               Ask for i
                                             while function noDuplicatesthat() is false
                                             return i
            winningNumsarray[i] = function genWinNumsthat(winningNumsarray,i + 1);
                                              create variable number
                                              do
                                                number = rand() % MAX_ENTRY + 1
                                              while function noDuplicatesfunction() is false
                                              return number
       winNumbersCount = function checkNumbers(userTicketarray, winningNumsarray); 
                                     create variable count = 0
                                     for int i = 0; i < 7; i++
                                         for int j = 0; j < 7; j++
                                            if userNumbers[i] is equal lottoNumbers[j]
                                               count ++
                                     return count
       call function displayReport(userTicketarray, winningNumsarray,userName,winNumbersCount);
                       
    while userSelection is not equal 'q'
*/

#include "lotto.h"

using namespace std;

int main()
{
    int winNumbersCount, userTicketarray[SIZE], winningNumsarray[SIZE];
    string userName;
    char userSelection;
    srand(13);

    userName = getUserName();

    do
    {
        createMenu();
        userSelection = getUserSelection();
        if (userSelection == '1')
        {
            for (int i = 0; i < SIZE; i++)
            {
                userTicketarray[i] = getLottoPicksthat(userTicketarray,i + 1);
                winningNumsarray[i] = genWinNumsthat(winningNumsarray,i + 1);
            }

            winNumbersCount = checkNumbers(userTicketarray, winningNumsarray);
            displayReport(userTicketarray, winningNumsarray,userName,winNumbersCount);

        }
        else
        {
          //  cout << "Quiting the program...";
        }


    } while (userSelection != 'q');

    return 0;
}


