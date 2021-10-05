// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. The two arrays represent digits of two numbers.
// 6. You are required to add the numbers represented by two arrays and print the
// arrays.

// Input Format
// A number n1
// n1 number of elements line separated
// A number n2
// n2 number of elements line separated

// Output Format
// A number representing sum of two numbers, represented by two arrays.

// Constraints
// 1 <= n1, n2 <= 100
// 0 <= a1[i], a2[i] < 10

// Sample Input
// 5
// 3 1 0 7 5
// 6
// 1 1 1 1 1 1

// Sample Output
// 1 4 2 1 8 6

#include <iostream>
#include <vector>
using namespace std;

void sumArray(vector<int> a, vector<int> b, int n1, int n2){

	vector<int> sum(n1 > n2 ? n1:n2);

	int i = a.size()-1;
	int j = b.size()-1;
	int k = sum.size()-1;

	int carry = 0;

	while(k >= 0){

		int val = carry;

		if(i >= 0){
			val += a[i];
		}

		if(j >= 0){
			val += b[j];
		}

		carry = val / 10;
		val = val % 10;

		sum[k] = val;

		i--;
		j--;
		k--;
	}

	if(carry != 0){
		cout << carry << endl;
	}

	for(int x: sum){
		cout << x << endl;
	}
}

int main(){

	int n1;
	cin >> n1;

	vector<int> a(n1);
	for(int i=0; i<n1; i++){
		cin >> a[i];
	}

	int n2;
	cin >> n2;
	vector<int> b(n2);
	for(int i=0; i<n2; i++){
		cin >> b[i];
	}

	sumArray(a, b, n1, n2);
	return 0;
}