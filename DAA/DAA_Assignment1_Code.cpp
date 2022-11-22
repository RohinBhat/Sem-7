#include <bits/stdc++.h>
using namespace std;

int recursiveFib(int n)
{
	if (n == 0 or n == 1)
		return n;

	return recursiveFib(n - 1) + recursiveFib(n - 2);
}

int iterativeFib(int n)
{
	if (n == 0 or n == 1)
		return n;

	int fib1 = 0;
	int fib2 = 1;
	int fib3;

	for (int i = 2; i <= n; i++)
	{
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;
	}

	return fib3;
}

int main()
{
	int option;
	int n;
	bool flag = true;
	while (flag)
	{
		cout << "--------- MENU ---------" << endl;
		cout << "1. Recursive Fibonacci" << endl;
		cout << "2. Iterative Fibonacci" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter Option:" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Enter a number: ";
			cin >> n;
			cout << recursiveFib(n) << endl;
			break;

		case 2:
			cout << "Enter a number: ";
			cin >> n;
			cout << iterativeFib(n) << endl;
			break;

		case 3:
			cout << "Terminated" << endl;
			flag = false;
			break;

		default:
			cout << "Invalid Input" << endl;
			break;
		}
	}
}