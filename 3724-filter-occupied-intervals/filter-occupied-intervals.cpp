class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& a, int l,
                                                int r) {
        sort(a.begin(), a.end());
        vector<vector<int>> vec;
        int prev = INT_MAX, last = -1;
        for (auto v : a) {
            if (prev != INT_MAX) {
                if ((prev >= v[0]) || prev == v[0] - 1)
                    prev = max(prev, v[1]);
                else {
                    vec.push_back({last, prev});
                    if(prev>=v[1]){prev=INT_MAX;continue;}
                    last = v[0];
                    prev = v[1];
                }
            } else {
                last = v[0];
                prev = v[1];
            }
        }
        if (prev != INT_MAX) {
            vec.push_back({last, prev});
        }
        vector<vector<int>>res;
        for(auto v:vec){
            if(l<=v[0] && r>=v[1])continue;
            else if(r>=v[0] && r<v[1]){
                if(l>v[0])res.push_back({v[0],l-1});
                res.push_back({r+1,v[1]});
            }
            else if(l>v[0] && l<=v[1]){
                res.push_back({v[0], l-1});
                if(r<v[1])res.push_back({r+1,v[1]});
            }else res.push_back(v);
        }
        return res;
    }
};