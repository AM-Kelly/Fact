// C++ program to compute factorial of big numbers
#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

// Maximum number of digits in output
#define MAX 500

class recFact
{
public:
	void recFactDriver(int);

private:
	void recFactCalc(int);
	int recFactMult(int, vector<int> res, int);
};

void recFact::recFactDriver(int n)
{
	recFactCalc(n);
}

void recFact::recFactCalc(int n)
{
	// This function finds factorial of large numbers
	// and prints them
	vector<int> res;

	// Initialize result
	//res.at(0) = 1;
	res.push_back(1);
	//res[0] = 1;
	//int res_size = sizeof(n);
	int res_size = 1; // size of n

	// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
	for (int x = 2; x <= n; x++)
		res_size = recFactMult(x, res, res_size);
	

	cout << "Factorial of given number is \n";
	for (int i = res_size - 1; i >= 0; i--)
		cout << res.at(i);
}
int recFact::recFactMult(int x, vector<int> res, int res_size)
{
	int carry = 0;  // Initialize carry

					// One by one multiply n with individual digits of res[]
	for (int i = 0; i<res_size; i++)
	{
		int prod = res.at(i) * x + carry;
		

		// Store last digit of 'prod' in res[]  
		res.at(i) = prod % 10;

		// Put rest in carry
		carry = prod / 10;
	}

	// Put carry in res and increase result size
	while (carry)
	{
		//res.at(res_size) = carry % 10;
		res.push_back(carry % 10);
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
	int choice;
	int num;
	cout << "Enter a number you would like to calculate the factorial of.\n";
	cin >> num;
	cout << "\nWould you like to calculate this: \n1. Iterativley\nOR\n2.Recursivley\n";
	cin >> choice;
	switch (choice)
	{
	case 1: 
		//Do stuff iteratively
		_getch();
		cout << "\n";
		main();
	case 2:
		//Recursive
		recFact recFactStart;
		recFactStart.recFactDriver(num);
		_getch();
		cout << "\n";
		main();
	default:
		main();
		break;
	}
}