class Solution {
public:
    string processStr(string s) {
        string str="";
        for(char ch:s){
            if(ch>='a' && ch<='z')str+=ch;
            else if(ch=='*'){
                if(str.size()>0)str.pop_back();
            }
            else if(ch=='#')str=str+str;
            else{
                reverse(str.begin(), str.end());
            }
        }
        return str;
    }
};