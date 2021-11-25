// median priority queue
/*
1. You are required to complete the code of our MedianPriorityQueue class. The class should mimic the behaviour of a PriorityQueue and give highest priority to median of it's data.
2. Here is the list of functions that you are supposed to complete
2.1. add -> Should accept new data.
2.2. remove -> Should remove and return median value, if available or print "Underflow" otherwise and return -1
2.3. peek -> Should return median value, if available or print "Underflow" otherwise and return -1
2.4. size -> Should return the number of elements available
3. Input and Output is managed for you.

Note -> If there are even number of elements in the MedianPriorityQueue, consider the smaller median as median value.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
None

Sample Input
add 10
add 20
add 30
add 40
peek
add 50
peek
remove
peek
remove
peek
remove
peek
remove
peek
quit

Sample Output
20
30
30
20
20
40
40
10
10
50

*/

class MedianPriorityQueue{
public:
	// make left max heap and right min heap
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;

	void push(int val){

		// in right value will be added if its size is greater than 0 and val is greater than its peek value
		if(right.size() > 0 && val > right.top()){

			right.push(val);
		}
		else{
			left.push(val);
		}

		// never allow difference b/w left and right sizes to be 2, since it will then not allow 
		// us to find the median
		if(left.size() - right.size() == 2){
			int rem = left.top();
			left.pop();
			right.push(rem);
		} 
		else if(right.size() - left.size() == 2){
			int rem = right.top();
			right.pop();
			left.push(rem);
		}
	}

	int top(){

		if(size() == 0){
			cout <<"Underflow"<<endl;
			return -1;
		}
		else if(left.size() >= right.size()){
			return left.top();
		}
		else{
			return right.top();
		}
	}

	int pop(){

		if(size() == 0){
			cout <<"Underflow"<<endl;
			return -1;
		}
		else if(left.size() >= right.size()){
			int val = left.top();
			left.pop();
			return val;
		}
		else{
			int val = right.top();
			right.pop();
			return val;
		}
	}

	int size(){
		return left.size() + right.size();
	}

};