// C++ program to compute factorial of big numbers
#include<iostream>
#include<conio.h>
#include <ctime>
clock_t clockStart;
//#include<vector>
using namespace std;

// Maximum number of digits in output
#define MAX 100000000

//Recursive
class recFact
{
public:
	void recFactDriverBatch(long long);
	void recFactDriverSingle(long long);

private:
	void recFactCalc(long long);
	long long recFactMult(long long, long long res[], long long, long long);
};
void recFact::recFactDriverSingle(long long i)
{
	long long cFact;
	cout << "The factorial of " << i << " is: \n";
	recFactCalc(i);
	cout << "\n";

}
void recFact::recFactDriverBatch(long long i)
{
	long long n = 1;
	while (n <= i)
	{
		cout << "The factorial of " << n << " is: \n";
		recFactCalc(n);
		cout << n << "\n";
		n++;
	}

}
void recFact::recFactCalc(long long n)
{
	// This function finds factorial of large numbers
	// and prints them
	long long res[MAX];
	/*
	if (n == 1)
		return 1;
	else
	{
		return n * recFactCalc(n - 1);
	}
	*/
	// Initialize result
	//res.at(0) = 1;
	//res.push_back(1);
	res[0] = 1;
	//int res_size = sizeof(n);
	int res_size = 1; // size of n

					  // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
	//for (int x = 2; x <= n; x++) THIS WAS AN ERROR - TALK ABOUT IT
	res_size = recFactMult(1, res, res_size, n);


	//cout << "Factorial of given number is \n";
	for (long long i = res_size - 1; i >= 0; i--)
		cout << res[i];

}
long long recFact::recFactMult(long long  x, long long res[], long long res_size, long long n)
{
	long long carry = 0;  // Initialize carry

						  // One by one multiply n with individual digits of res[]
	for (int i = 0; i < res_size; i++)
	{
		long long prod = res[i] * x + carry;


		// Store last digit of 'prod' in res[]  
		res[i] = prod % 10;

		// Put rest in carry
		carry = prod / 10;
	}

	// Put carry in res and increase result size
	while (carry)
	{
		res[res_size] = carry % 10;
		//res.push_back(carry % 10);
		carry = carry / 10;
		res_size++;
	}
	return (x == n) ? res_size : recFactMult((x + 1), res, res_size, n);
}
//End of recursive

//Iterative
class iterFact
{
public:
	void iterFactDriverBatch(int);
	void iterFactDriverSingle(int);

private:
	void iterFactCalc(int);
	long long iterFactMult(long long, long long res[], long long);
};
void iterFact::iterFactDriverSingle(int i)
{
	int cFact;
	cout << "The factorial of " << i << " is: \n";
	iterFactCalc(i);
	cout << "\n";

}
void iterFact::iterFactDriverBatch(int i)
{
	int n = 1;
	while (n <= i)
	{
		cout << "The factorial of " << n << " is: \n";
		iterFactCalc(n);
		cout << n << "\n";
		n++;
	}

}
void iterFact::iterFactCalc(int n)
{
	// This function finds factorial of large numbers
	// and prints them
	long long res[MAX];

	// Initialize result
	//res.at(0) = 1;
	//res.push_back(1);
	res[0] = 1;
	//int res_size = sizeof(n);
	int res_size = 1; // size of n

	// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
	for (int x = 2; x <= n; x++)
		res_size = iterFactMult(x, res, res_size);


	//cout << "Factorial of given number is \n";
	for (long long i = res_size - 1; i >= 0; i--)
		cout << res[i];
}
long long iterFact::iterFactMult(long long  x, long long res[], long long res_size)
{
	long long carry = 0;  // Initialize carry

					// One by one multiply n with individual digits of res[]
	for (int i = 0; i < res_size; i++)
	{
		long long prod = res[i] * x + carry;


		// Store last digit of 'prod' in res[]  
		res[i] = prod % 10;

		// Put rest in carry
		carry = prod / 10;
	}

	// Put carry in res and increase result size
	while (carry)
	{
		res[res_size] = carry % 10;
		//res.push_back(carry % 10);
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}




// This function multiplies x with the number 
// represented by res[].
// res_size is size of res[] or number of digits in the 
// number represented by res[]. This function uses simple 
// school mathematics for multiplication.
// This function may value of res_size and returns the 
// new value of res_size

// Driver program
void main()
{
	int biChoice;
	int choice;
	int num;
	cout << "Would like to calculate a batch of factorials or an individual factorial?\n";
	cout << "1. Batch	2. Individual\n";
	while (!(cin >> biChoice) || biChoice < 1 || biChoice > 2)
	{
		cout << "Please make a listed choice...";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (biChoice == 1)
	{
		cout << "Please enter the maximum number you would like to calculate up to\n";
		while (!(cin >> num) || num < 1)
		{
			cout << "Please enter a valid number (Not Zero (0) or Negative...";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	else if (biChoice == 2)
	{
		cout << "Please enter the number you would like to calculate the factorial of\n";
		while (!(cin >> num) || num < 1)
		{
			cout << "Please enter a valid number (Not Zero (0) or Negative...";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cout << "How would you like to calculate this: \n1. Recursivley (S)\n\nor\n\n2.Iteratively (F)\n";
	while (!(cin >> choice) || choice < 1 || choice > 2)
	{
		cout << "Please make a valid choice...";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (biChoice == 1)//Batch
	{
		switch (choice)
		{
		case 1:
			//Recursive
			recFact recFactStart;
			clockStart = clock();
			recFactStart.recFactDriverBatch(num);
			cout << "\nThis calculation took " << ((clock() - clockStart) / (double)CLOCKS_PER_SEC) << " seconds\n";
			_getch();
			cout << "\n";
			main();
		case 2:
			//Iterative
			iterFact iterFactStart;
			clockStart = clock();
			iterFactStart.iterFactDriverBatch(num);
			cout << "\nThis calculation took " << ((clock() - clockStart) / (double)CLOCKS_PER_SEC) << " seconds\n";
			_getch();
			cout << "\n";
			main();
		default:
			break;
		}
	}
	else if (biChoice == 2)//Single
	{
		switch (choice)
		{
		case 1:
			//Recursive
			recFact recFactStart;
			clockStart = clock();
			recFactStart.recFactDriverSingle(num);
			cout << "\nThis calculation took " << ((clock() - clockStart) / (double)CLOCKS_PER_SEC) << " seconds\n";
			_getch();
			cout << "\n";
			main();
		case 2:
			//Iterative
			iterFact iterFactStart;
			clockStart = clock();
			iterFactStart.iterFactDriverSingle(num);
			cout << "\nThis calculation took " << ((clock() - clockStart) / (double)CLOCKS_PER_SEC) << " seconds\n";
			_getch();
			cout << "\n";
			main();
		default:
			break;
		}
	}
}