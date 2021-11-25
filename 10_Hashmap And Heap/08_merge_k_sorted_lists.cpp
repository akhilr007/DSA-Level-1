// merge k sorted lists
/*
1. You are given a list of lists, where each list is sorted.
2. You are required to complete the body of mergeKSortedLists function. The function is expected to merge k sorted lists to create one sorted list.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
Space complextiy = O(k)
Time complexity = nlogk
where k is the number of lists and n is number of elements across all lists.

Sample Input
4
5
10 20 30 40 50
7
5 7 9 11 19 55 57
3
1 2 3
2
32 39

Sample Output
1 2 3 5 7 9 10 11 19 20 30 32 39 40 50 55 57 
*/
typedef pair<int, pair<int, int>> ppi; // val listNumber index

vector<int> mergeKSortedLists(vector<vector<int>> lists){

	vector<int> ml; // merged lists

	// create min heap
	priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

	for(int i=0; i<lists.size(); i++){
		pq.push({lists[i][0], {i, 0} });
	}

	while(pq.size() > 0){

		ppi curr = pq.top();
		pq.pop();

		ml.push_back(curr.first);

		int ln = curr.second.first;
		int i = curr.second.second;

		if(i < lists[ln].size()){
			pq.push({lists[ln][i], {ln, i} });
		}
	}

	return ml;
}