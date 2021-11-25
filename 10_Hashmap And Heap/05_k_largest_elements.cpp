// k largest elements
/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are given a number k.
4. You are required to find and print the k largest elements of array in increasing order.

Input Format
Input is managed for you

Output Format
Print the k largest elements of array in increasing order in separate lines.

Constraints
1 <= n <= 30
0 <= n1, n2, .. n elements <= 100
0 < k <= n

Sample Input
13
12 62 22 15 37 99 11 37 98 67 31 84 99
4

Sample Output
84
98
99
99
*/

vector<int> findKthLargest(vector<int> const& arr, int k) {
    
    int n = arr.size();
    priority_queue<int> pq; // max heap
  
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }
    
    vector<int> res(k);
    for(int i=k-1; i>=0; i--){
        
        res[i] = pq.top();
        pq.pop();
    }
    
    return res;

}
