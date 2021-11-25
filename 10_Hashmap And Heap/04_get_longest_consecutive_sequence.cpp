// get longest consecutive sequence
/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to print the longest sequence of consecutive elements in the array (ignoring duplicates).

Note -> In case there are two sequences of equal length (and they are also the longest), then print the one for which the starting point of which occurs first in the array.

Input Format
A number n
n1
n2
.. n number of elements

Output Format
Elements of longest sequence of consecutive elements of array in separate lines (ignoring duplicates)

Sample Input
17
12 5 1 2 10 2 13 7 11 8 9 11 8 9 5 6 11

Sample Output
5 6 7 8 9 10 11 12 13
*/

bool findInSet(set<int> &s, int val){

	if(s.find(val) != s.end()){
		return true;
	}

	return false;
}

void getLongestConsecutive(vector<int> &num){

	set<int> s;
	int n = num.size();

	for(int i=0; i<n; i++){
		s.insert(num[i]);
	}

	int longestStreak = 0;
	int startingPoint = 0;

	for(auto val: s){

		if(findInSet(s, val - 1) == false){

			int j = val;
			int curr_streak = 1;

			while(findInSet(s, j+1) == true){
				j++;
				curr_streak++;
			}

			if(curr_streak > longestStreak){
				longestStreak = curr_streak;
				startingPoint = val;
			}
		}
	}

	for(int i=1; i<=longestStreak; i++){
		cout << st <<endl;
		st++;
	}
}