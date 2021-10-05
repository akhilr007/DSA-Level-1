/*1. You've to display the digits of a number.
2. Take as input "n", the number for which digits have to be displayed.
3. Print the digits of the number line-wise.

Input Format
"n" where n is any integer.

Output Format
d1
d2
d3
... digits of the number

Constraints
1 <= n < 10^9

Sample Input
65784383

Sample Output
6
5
7
8
4
3
8
3
*/

#include <iostream>
#include <math.h>
using namespace std;

void printDigits(int n){

	int count = 0;
	int temp = n;

	// diya hua number count karne ke liye
	while(temp > 0){
		temp /= 10;
		count ++;
	}
	// number ko divide karne ke lie
	int div = pow(10, count-1); 

	while(div > 0){

		int q = n / div;  // eg 656/100 result = 6 quotient me aa jayga
		cout << q << endl; // print karna hai

		n = n % div;   // apna number ko saamne se chota karne ke liye
		div = div / 10; // div ko back se chota karne ke liye
	}

}

int main(){
	int n;
	cin >> n;

	printDigits(n);
	return 0;
}