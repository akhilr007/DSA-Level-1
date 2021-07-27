// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. The two arrays represent digits of two numbers.
// 6. You are required to find the difference of two numbers represented by two arrays and print the arrays. a2 - a1

// Assumption - number represented by a2 is greater.

// Input Format
// A number n1
// n1 number of elements line separated
// A number n2
// n2 number of elements line separated

// Output Format
// A number representing difference of two numbers (a2 - a1), represented by two arrays.

// Constraints
// 1 <= n1, n2 <= 100
// 0 <= a1[i], a2[i] < 10
// number reresented by a1 is smaller than number represented by a2

// Sample Input
// 3
// 2
// 6
// 7
// 4
// 1
// 0
// 0
// 0

// Sample Output
// 7
// 3
// 3

#include <iostream>
#include <vector>
using namespace std;

void difference(vector<int> a, vector<int> b, int n1, int n2){

	vector<int> diff(n2); // diff cant be greater than b

	int i = a.size()-1;
	int j = b.size()-1;
	int k = diff.size()-1;

	int c = 0;

	while(k >= 0){
		int val = 0;

		int av = (i >= 0) ? a[i]:0;

		if(b[j] + c >= av){
			diff[k] = b[j] + c - av;
			c = 0;
		}
		else{
			diff[k] = b[j] + c + 10 - av;
			c = -1;
		}

		i--;
		j--;
		k--;
	}

	// leading zeroes ke liye
	int idx = 0;
	while(idx < diff.size()){
		if(diff[idx] == 0){
			idx++;
		}
		if(diff[idx] != 0){
			break;
		}
	}

	while(idx < diff.size()){
		cout << diff[idx] << endl;
		idx++;
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
	vector<int> b(n2);  // b is greater than a
	for(int i=0; i<n2; i++){
		cin >> b[i];
	}

	difference(a, b, n1, n2);
	return 0;
}