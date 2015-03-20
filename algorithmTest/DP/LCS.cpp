#include <iostream>
#include <algorithm>
#include <limits.h>
#include <iterator>
#include <ostream>
#include <string>

using namespace std;

int minDistance(string word1, string word2) {
        
    int d[word1.size()];
    if(word2.find(string(word[0])) != string::npos){
        d[0] = 1;
    }
    else{
        d[0] = 0;
    }
    
    for(int i = 1; i < word1.size(); i++){
        if(d[i - 1] == 0){
            if(word2.find(string(word[i])) != string::npos){
                d[i] = 1;
            }
            else{
                d[i] = 0;
            }
        }
        else{
            string str = word2.substr(i - d[i - 1], d[i - 1] + 1);
            if(word2.find(str) != string::npos){
                d[i] = d[i-1] + 1;
            }
            else{
                if(word2.find(string(word[i])) != string::npos){
                    d[i] = 1;
                }
                else{
                    d[i] = 0;
                }
            }
        }
    }
    
    int max = INT_MIN;
    for(int i = 0; i < word1.size(); i++){
        if(max < d[i]) max = d[i];
    }
    
    return word2.size() - max;
}

int main(void){
	string s = "yang";
	strint t = "peng";
	cout<<minDistance(s, t)<<endl;
	return 0;
}