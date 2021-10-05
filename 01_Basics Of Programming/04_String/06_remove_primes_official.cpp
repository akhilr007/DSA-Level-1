// Remove Primes

// 1. You are given an ArrayList of positive integers.
// 2. You have to remove prime numbers from the given ArrayList and return the updated ArrayList.

// Note -> The order of elements should remain same.

// Input Format
// A number N
// arr1
// arr2.. N numbers

// Output Format
// An Arraylist

// Constraints
// 1 <= N <= 10000

// Sample Input
// 4
// 3 12 13 15

// Sample Output
// [12, 15]

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){

	for(int i=0; i<n; i++){

		for(int div=2; div*div<=n; div++){
			if(n % div == 0) return false;
		}
	}
	return true;
}

void removePrimes(vector<int> &v){

	for(int i=0; i<v.size(); i++){

		if(isPrime(v[i])== true){
			v.erase(v.begin()+i);
			i--;
		}
	}
}

int main(){

	int n;
	cin >> n;

	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];

	removePrimes(v);
	cout <<"[";
	for(int i=0; i<v.size()-1; i++){
		cout<<v[i]<<", ";
	}
	cout << v[v.size()-1]<<"]";
	return 0;
}