class Solution {
public:
    void recurse(vector<string> &res, int n, int rem, string s){
        if(n==0 && rem==0){
            res.push_back(s);
            return;
        }
        if(n>0){
            string temp=s+'(';
            recurse(res,n-1, rem+1, temp);
        }
        if(rem>0){
            string temp=s+')';
            recurse(res,n, rem-1, temp);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        recurse(res,n, 0, "");
        return res;
    }
};