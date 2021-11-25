// sort k sorted arrays
/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. The array is nearly sorted. Every element is at-max displaced k spots left or right to it's position in the sorted array. Hence it is being called k-sorted array.
4. You are required to sort and print the sorted array.

Note -> You can use at-max k extra space and nlogk time complexity.

Input Format
Input is managed for you

Output Format
Print the elements of sorted array in separate lines.

Constraints
1 <= n <= 30
0 <= n1, n2, .. n elements <= 100
0 < k <= n

Sample Input
9
3 2 4 1 6 5 7 9 8 3
Sample Output
1
2
3
4
5
6
7
8
9
*/

void kSort(vector<int> arr, int n){

	int n = arr.size();
	// min heap
	priority_queue<int, vector<int>, greater<int>> pq;

	// add k+1 elements in pq;

	for(int i=0; i<=k; i++){
		pq.push(arr[i]);
	}

	for(int i=k+1; i<n; i++){

		cout << pq.top() << endl;
		pq.pop();
		pq.push(arr[i]);
	}

	while(pq.size() > 0){

		cout << pq.top() << endl;
		pq.pop();
	}
}