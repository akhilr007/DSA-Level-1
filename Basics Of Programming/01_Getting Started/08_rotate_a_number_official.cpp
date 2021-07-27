// 1. You are given two numbers n and k. You are required to rotate n, k times to the right. If k is positive, rotate to the right i.e. remove rightmost digit and make it leftmost. Do the reverse for negative value of k. Also k can have an absolute value larger than number of digits in n.
// 2. Take as input n and k.
// 3. Print the rotated number.
// 4. Note - Assume that the number of rotations will not cause leading 0's in the result. e.g. such an input will not be given
//    n = 12340056
//    k = 3
//    r = 05612340

// Input Format
// "n" where n is any integer.
// "K" where k is any integer.

// Output Format
// "r", the rotated number

// Constraints
// 1 <= n < 10^9
// -10^9 < k < 10^9

// Sample Input
// 562984
// 2

// Sample Output
// 845629

#include <iostream>
using namespace std;

void rotateNumber(int n, int k){

	int nod = 0;
	int temp = n;
	while(temp > 0){
		temp = temp/10;
		nod++;
	}

	// agar number n se jyada hai to nod se mod kar lo
	k = k % nod;
	// agar zero se kam hai to nod + k kar do 
	if(k < 0){
		k = k + nod;
	}

	int div = 1;
	int mult = 1;
	for(int i = 1; i <= nod; i++){
		if(i <= k){
			div = div*10; // jisse hume number ko divide karna hai
		}else{
			mult = mult*10; // jisse hume last ke extracted number se multiply karna hai
		}
	}

	int q = n / div;
	int r = n % div;

	r = (r * mult) + q;
	cout << r << endl;

}

int main(){
	int n, k;
	cin >> n >> k;

	rotateNumber(n, k);
	return 0;
}