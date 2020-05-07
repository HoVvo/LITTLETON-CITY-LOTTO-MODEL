// Hovhannes Margaryan
// CS/IS 135 - 3817 - Online Class
// Lab 6p1

#include "lotto.h"

using namespace std;

string getUserName()
{
	string name;
	cout << "Please enter your name: " << endl;
	getline(cin, name);
	return name;
}

void createMenu()
{
	cout << "LITTLETON CITY LOTTO MODEL:" << endl;
	cout << _BORDER_ << endl;
	cout << "1) Play Lotto" << endl;
	cout << "q) Quit Program" << endl;
}

char getUserSelection()
{
	char selection;
	cout << "Please make a selection: " ;
	cin >> selection;
	if (selection != '1' && selection != 'q') 
	{
		cout << "Invalid selection" << endl << endl;
	}
	return selection;
}

int getLottoPicksthat(int userTicket[],int count)
{
	int i;
	do
	{
		cout << "Enter item #" << count << ": ";
		cin >> i;

	} while (noDuplicatesthat(userTicket,i,count));
	
	return i;
}

bool noDuplicatesthat(int userTicket[], int n, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (userTicket[i] == n || n > 40) {
			cout << "Invalid entry" << endl;
			return true;
		}
	}
	return false;
}

int genWinNumsthat(int winNumbers[],int count)
{
	int number;
	do
	{
		number = rand() % MAX_ENTRY + 1;

	} while (noDuplicatesfunction(winNumbers, number, count));

	return number;
}

bool noDuplicatesfunction(int winNumbers[], int number , int count)
{
	for (int i = 0; i < count; i++)
	{
		if (winNumbers[i] == number) {
			return true;
		}
	}
	return false;
}

int checkNumbers(int userNumbers[], int lottoNumbers[])
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (userNumbers[i] == lottoNumbers[j])
			{
				count++;
			}
		}
	}
	return count;
}

void displayReport(int userNumbers[], int lottoNumbers[],string userName,int count)
{
	string msg = getLottoStatus(count);

	cout <<endl<< userName <<"'s LOTTO RESULTS" << endl;
	cout <<"---------------------"<< endl;
	cout << "WINNING TICKET NUMBERS: ";
	printNumbers(lottoNumbers);
	cout << userName << "’S TICKET" << setfill(' ')  << setw(10) << ": ";
	printNumbers(userNumbers);

	cout << endl;

	cout << "RESULTS:" << endl;
	cout << "--------" << endl;
	cout << "Number Matches: " << count << endl;
	cout << "Winnings" << setfill(' ') << setw(9) << ": " << msg << endl;

	cout << endl;

}

void printNumbers(int numbers[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << setfill('0') << setw(2) << numbers[i] << " ";
	}
	cout << endl;
}

string getLottoStatus(int count)
{
	string  msg;
	switch (count)
	{
	case 3:
		msg = "FREE TICKET";
		break;
	case 4:
		msg = "NOT BAD - $100";
		break;
	case 5:
		msg = "LUCKY YOU! - $5,000";
		break;
	case 6:
		msg = "GREAT! - $100,000";
		break;
	case 7:
		msg = "JACKPOT - 1 MILLION";
		break;
	default:
		msg = "SORRY NOTHING";
		break;
	}
	return msg;
}
