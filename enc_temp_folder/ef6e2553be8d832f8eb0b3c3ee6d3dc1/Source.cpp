// C++ program to compute factorial of big numbers
#include<iostream>
#include<conio.h>
//#include<vector>
using namespace std;

// Maximum number of digits in output
#define MAX 100000000


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
	for (int i = 0; i<res_size; i++)
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
	cout << "1. Batch	2. Indivdual\n";
	cin >> biChoice;
	if (biChoice == 1)
	{
		cout << "Please enter the maximum number you would like to calculate up to\n";
		cin >> num;
	}else if (biChoice == 2)
	{
		cout << "Please enter the number you would like to calculate the factorial of\n";
		cin >> num;
	}
	else
	{
		cout << "Please choose again...\n";
		main();
	}
	cout << "How would you like to calculate this: \n1. Iterativley\nOR\n2.Recursivley\n";
	cin >> choice;
	if (biChoice == 1)//Batch
	{
		switch (choice)
		{
		case 1:
			//Do stuff iteratively
			_getch();
			cout << "\n";
			main();
		case 2:
			//Recursive
			iterFact recFactStart;
			recFactStart.iterFactDriverBatch(num);
			_getch();
			cout << "\n";
			main();
		default:
			main();
			break;
		}
	}
	else if (biChoice == 2)//Single
	{
		switch (choice)
		{
		case 1:
			//Do stuff iteratively
			_getch();
			cout << "\n";
			main();
		case 2:
			//Recursive
			iterFact recFactStart;
			recFactStart.iterFactDriverSingle(num);
			_getch();
			cout << "\n";
			main();
		default:
			main();
			break;
		}
	}
}