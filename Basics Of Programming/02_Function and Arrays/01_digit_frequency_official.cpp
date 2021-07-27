// 1. You are given a number n.
// 2. You are given a digit d.
// 3. You are required to calculate the frequency of digit d in number n.

// Input Format
// A number n
// A digit d

// Output Format
// A number representing frequency of digit d in number n

// Constraints
// 0 <= n <= 10^9
// 0 <= d <= 9
  
// Sample Input
// 994543234
//  4

// Sample Output
// 3

#include <iostream>
using namespace std;

void getDigitFrequency(int n, int d){

	int count = 0;

	while(n != 0){
		int ld = n % 10;  // last digit extract karo

		if(ld == d){ // compare karo given digit se
			count++;
		}
		n /= 10;
	}

	cout << count<<endl;
}

int main(){
	int n;
	cin >> n;

	int d;
	cin >> d;

	getDigitFrequency(n, d);
	return 0;
}