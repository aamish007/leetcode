class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>use;
        unordered_set<char>check;
        for(char ch: word){
            if(ch>='a' && ch<='z')use.insert(ch);
        }
        int num=0;
        for(char ch:word){
            if(ch>='A' && ch<='Z'){
                int i=ch;
                char c=(char)i+32;
                if(use.count(c) && !check.count(c)){num++;check.insert(c);
        }}}
        return num;
    }
};