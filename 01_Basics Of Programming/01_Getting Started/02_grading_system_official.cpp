#include<iostream>
using namespace std;
int main(int argc, char**argv){
    int marks;
    cin>>marks;
    
    //write your code here
    if(marks > 90)
        cout <<"excellent";
    else if(marks > 80 and marks <= 90)
        cout <<"good";
    else if(marks > 70 and marks <= 80)
        cout <<"fair";
    else if(marks > 60 and marks <= 70)
        cout <<"meets expectations";
    else 
        cout <<"below par";
    
}