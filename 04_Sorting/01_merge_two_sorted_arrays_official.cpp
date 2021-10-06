// merge two sorted arrays
/*
1. You are given two sorted arrays(a,b) of integers.
2. You have to merge them and form one sorted array.
3. You have to do it in linear time complexity.

Input Format

An Integer n 
a1
a2..n integers

An integer m
b1
b2..m integers

Output Format
Check the sample output and question video.

Constraints
1 <= N <= 10^8
-10^9 <= a[i],b[i] <= 10^9

Sample Input
4
-2 
5 
9 
11
3
4 
6 
8

Sample Output
-2
4
5
6
8
9
11

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &a, vector<int> &b){

	int n = a.size();
	int m = b.size();

	int i = 0, j = 0, k = 0;

	// our resultant array
	vector<int> c(n+m);

	while(i < n && j < m){

		if(a[i] <= b[j]){

			c[k] = a[i];
			i++;
			k++;
		}
		else{
			c[k] = b[j];
			j++;
			k++;
		}
	}

	// if any of our array has not been traversed fully
	while(i < n){
		c[k] = a[i];
		i++;
		k++;
	}

	while(j < m){
		c[k] = b[j];
		j++;
		k++;
	}

	return c;
}

void input(vector<int> &arr){

	for(int i=0; i<arr.size(); i++){
		cin >> arr[i];
	}
}

int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	input(a);

	int m;
	cin >> m;
	vector<int> b(m);
	input(b);

	vector<int> c = mergeTwoSortedArrays(a, b);
	for(auto x: c){
		cout << x << endl;
	}

	return 0;
}
