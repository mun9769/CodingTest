#include <bits/stdc++.h>
using namespace std;

vector<string> word_split(string input) {
    int pos = 0;
    vector<string> ret;
    string word = "";
    for(; pos < input.size(); pos++) {
        if(input[pos] == ' '){
            ret.push_back(word);
            word = "";
        } 
        else {
            word.push_back(input[pos]);
        }
    }
    ret.push_back(word);
    return ret;
}

void convert_to_uppercase(char& c) {
    if(c >= 'a' and c <= 'z') {
        c = c - 'a' + 'A';
    }
}

void convert_to_lowercase(char& c) {
    if(c >= 'A' and c <= 'Z') {
        c = c - 'A' + 'a';
    }
}

string solution(string s) {
    string answer = "";
    auto words = word_split(s);
    
    for(string& word: words) {
        convert_to_uppercase(word[0]);
        
        for(int i=1; i<word.size(); i++) {
            convert_to_lowercase(word[i]);
        }
    }
    
    
    for(string word: words) {
        if(word.size() == 0) { answer.push_back(' '); continue; }
        for(auto x: word) answer.push_back(x);
        answer.push_back(' ');
    }
    answer.pop_back();
    
    
    
    return answer;
}