class Solution {
public:
    void build(int n, int i, int k, int cost, string s, vector<string> & res){
        if(i==n){
            if(cost<=k)res.push_back(s);
            return;
        }
        int m=s.size();
        if(cost+i<=k && (m==0 || s[m-1]=='0')){
            build(n, i+1,k, cost+i, s+"1", res);
        }
        build(n, i+1, k, cost, s+"0", res);
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>res;
        string s="";
        build(n, 0, k, 0, s, res);
        return res;
    }
};