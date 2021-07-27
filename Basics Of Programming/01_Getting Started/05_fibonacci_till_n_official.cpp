// 1. You've to print first n fibonacci numbers.
// 2. Take as input "n", the count of fibonacci numbers to print.
// 3. Print first n fibonacci numbers.

// Input Format
// n

// Output Format
// 0
// 1
// 1
// 2
// 3
// 5
// 8
// .. first n fibonaccis

// Constraints
// 1 <= n < 40

// Sample Input
// 10

// Sample Output
// 0
// 1
// 1
// 2
// 3
// 5
// 8
// 13
// 21
// 34

#include <iostream>
using namespace std;

void printFibonacci(int n){

	int a = 0;
	int b = 1;

	cout << a << endl;
	cout << b << endl;

	for(int i = 2; i < n; i++){
		cout << a+b << endl;
		int temp = a+b;
		a = b;
		b = temp;
	}
}

int main(){

	int n;
	cin >> n;

	printFibonacci(n);
	return 0;
}