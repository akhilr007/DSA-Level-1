// 1. You are required to display the prime factorization of a number.
// 2. Take as input a number n.
// 3. Print all its prime factors from smallest to largest.
                               
// Input Format
// n, an integer

// Output Format
// p1  p2  p3  p4.. all prime factors of n

// Constraints
// 2 <= n < 10 ^ 9

// Sample Input
// 1440

// Sample Output
// 2 2 2 2 2 3 3 5

#include <iostream>
using namespace std;

void primeFactorisation(int n){

	long i = 2;
	while(n > 0){

		if(n == 1) break;

		if(n % i == 0){
			cout << i <<" ";
			n /= i;
		}else{
			i++;
		}
	}
}

int main(){
	long n;
	cin >> n;

	primeFactorisation(n);
	return 0;
}