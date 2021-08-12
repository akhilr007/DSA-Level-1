// All Indices Of Array

// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number x. 
// 4. You are required to find the all indices at which x occurs in array a.
// 5. Return an array of appropriate size which contains all indices at which x occurs in array a.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

// Input Format
// A number n
// n1
// n2
// .. n number of elements
// A number x

// Output Format
// Return the array of indices from the allIndices function. Display is managed for you.

// Constraints
// 1 <= n <= 10^4
// 0 <= n1, n2, .. n elements <= 10 ^ 3
// 0 <= x <= 10 ^ 3

// Sample Input
// 6
// 15
// 11
// 40
// 4
// 4
// 9
// 4

// Sample Output
// 3
// 4

#include <iostream>
#include <vector>
using namespace std;

vector<int> res;

vector<int> findAllIndices(int arr[], int idx, int n, int x){

	if(idx == n){
		vector<int> bres;
		return bres;
	}

	if(arr[idx] == x){
		res.push_back(idx);
	}

	findAllIndices(arr, idx+1, n, x);
	return res;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int x;
	cin >> x;

	vector<int> ans = findAllIndices(arr, 0, n, x);
	
	if(ans.size() == 0){
	    cout << endl;
	    return 0;
	}
	
	for(auto x: ans){
		cout << x << endl;
	}
}