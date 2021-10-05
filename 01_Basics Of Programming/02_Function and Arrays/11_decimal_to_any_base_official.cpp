// 1. You are given a decimal number n.
// 2. You are given a base b.
// 3. You are required to convert the number n into its corresponding value in base b.

// Input Format
// A number n
// A base b

// Output Format
// A number representing corresponding value of n in number system of base b

// Constraints
// 0 <= d <= 512
// 2 <= b <= 10
  
// Sample Input
// 57
// 2

// Sample Output
// 111001

#include <iostream>
#include <math.h>
using namespace std;

int getBaseValue(int n, int b){

	int baseValue = 0;
	int power = 0;

	while(n > 0){

		// step 1 : take remainder
		int rem = n % b;

		// step 2: calculate value by multiplying rem with (n)^power
		baseValue += rem * pow(10, power);
		power++;

		// step 2 : reduce n by dividing it with b
		n = n / b;
	}

	return baseValue;
}

int main(){

	int n, b; // n->decimal number, b->base to which number needs to be converted
	cin >> n >> b;

	int ans = getBaseValue(n, b);
	cout << ans << endl;

	return 0;

}