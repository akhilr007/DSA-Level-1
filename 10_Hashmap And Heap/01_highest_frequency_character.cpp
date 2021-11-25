// get highest frequency character
/*
1. You are given a string str.
2. You are required to find the character with maximum frequency.

Input Format
A string str

Output Format
The character with highest frequency

Constraints
0 < str.length() <= 100
There will be a single character with highest frequency

Sample Input
zmszeqxllzvheqwrofgcuntypejcxovtaqbnqyqlmrwitc

Sample Output
q
*/

// using map
char getHighestFrequency(string str){

	map<char, int> mp;

	for(int i=0; i<str.length(); i++){

		char ch = str[i];
		mp[ch]++;
	}

	int hfc='\0'; // high frequency character
	int freq = INT_MIN;

	for(auto s: str){

		if(mp.find(s) != mp.end()){
			int val = mp[s];

			if(val > freq){
				hfc = s;
				freq = val;
			}
		}
	}

	return hfc;
}

// using array
char getHighestFrequency(string str){

	int maxFreq[256] = {0}; // 256 - ascii size

	char hfc = '\0';
	int freq = INT_MIN;

	for(int i=0; i<str.length(); i++){

		char ch = str[i];

		maxFreq[ch]++;

		if(freq < maxFreq[ch]){
			hfc = ch;
			freq = maxFreq[ch];
		}
	}

	return hfc;
}