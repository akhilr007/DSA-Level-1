// Get Kpc
// 1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
// 2. The following list is the key to characters map :
//     0 -> .;
//     1 -> abc
//     2 -> def
//     3 -> ghi
//     4 -> jkl
//     5 -> mno
//     6 -> pqrs
//     7 -> tu
//     8 -> vwx
//     9 -> yz
// 3. Complete the body of getKPC function - without changing signature - to get the list of all words that could be produced by the keys in str.
// Use sample input and output to take idea about output.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

// Input Format
// A string str

// Output Format
// Contents of the arraylist containing words as shown in sample output

// Constraints
// 0 <= str.length <= 10
// str contains numbers only

// Sample Input
// 78
// P
// Sample Output
// [tv, tw, tx, uv, uw, ux]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string code[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx","yz"};

vector<string> getKPC(string str){

    if(str.length() == 0){
        vector<string> bans;
        bans.push_back("");
        return bans;
    }

    char ch = str[0];
    string ros = str.substr(1);

    vector<string> rans = getKPC(ros);
    vector<string> myAns;

    string myCode = code[ch-'0'];

    for(int i=0; i<myCode.length(); i++){

        char mch = myCode[i];

        for(int j=0; j<rans.size(); j++){
            myAns.push_back(mch + rans[j]);
        }
    }

    return myAns;
}

int main(){

    string str;
    cin >> str;

    vector<string> ans = getKPC(str);
    cout<<"[";
    for(int i=0; i<ans.size()-1; i++){
        cout << ans[i]<<", ";
    }
    cout << ans[ans.size()-1] <<"]";

    return 0;
}