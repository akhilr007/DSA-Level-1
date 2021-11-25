// get common elements 2
/*
1. You are given a number n1, representing the size of array a1.
2. You are given n1 numbers, representing elements of array a1.
3. You are given a number n2, representing the size of array a2.
4. You are given n2 numbers, representing elements of array a2.
5. You are required to find the intersection of a1 and a2. To get an idea check the example below:
 
if a1 -> 1 1 2 2 2 3 5
and a2 -> 1 1 1 2 2 4 5
intersection is -> 1 1 2 2 5

Note -> Don't assume the arrays to be sorted. Check out the question video.

Input Format
A number n1
n1 number of elements line separated
A number n2
n2 number of elements line separated

Output Format
All relevant elements of intersection in separate lines
The elements of intersection should be printed in order of their occurence in a2.
*/

bool findInMap(map<int, int> mp, int val){

	if(mp.find(val) != mp.end()){
		return true;
	}
	return false;
}

void getCommonElements(int arr1[], int arr2[], int n1, int n2){

	map<int,int> mp;

	// add arr1 into map and increment 
	for(int i=0; i<n1; i++){
		mp[arr1[i]]++;
	}

	// to find intersection find every element of arr2 into arr1,
	// if present print and decrease the value by 1
	for(int i=0; i<n2; i++){

		int val = arr2[i];

		if(findInMap(mp, val) == true and mp[val] > 0){
			cout << val << endl;
			mp[val]--;
		}
	}
}