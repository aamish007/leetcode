class Solution {
public:
    char temp(int i){
        char ch=(25-i)+'a';
        return ch;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        int sum=0;
        for(string str:words){
            for(char ch:str){
                int i=ch-'a';
                sum+=weights[i];
            }
            s=s+temp(sum%26);
            sum=0;
        }
        return s;
    }
};