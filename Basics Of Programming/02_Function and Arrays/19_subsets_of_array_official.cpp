// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are required to print all subsets of arr. Each subset should be
// on separate line. For more clarity check out sample input and output.

// Input Format
// A number n
// n1
// n2
// .. n number of elements

// Output Format
// [Tab separated elements of subset]
// ..
// All subsets

// Constraints
// 1 <= n <= 10
// 0 <= n1, n2, .. n elements <= 10^3

// Sample Input
// 3
// 10
// 20
// 30

// Sample Output
// -	-	-	
// -	-	30	
// -	20	-	
// -	20	30	
// 10	-	-	
// 10	-	30	
// 10	20	-	
// 10	20	30	

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void getSubset(int arr[], int n){

	int limit = pow(2, n);

	for(int i=0; i<limit; i++){
		string set ="";
		int temp = i;

		for(int j=n-1; j>=0; j--){

			int r = temp % 2;
			temp = temp/2;

			if(r == 0){
				set = "-\t" + set;
			}
			else{
				set = to_string(arr[j]) + "\t" + set;
			}
		}

		cout << set << endl;
	}
}

int main(){

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	getSubset(arr, n);
	return 0;
}