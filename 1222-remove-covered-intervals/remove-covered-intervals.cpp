class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& o) {
        int n=o.size();unordered_set<int>indices;
        for(int i=0;i<n;i++){
            int a=o[i][0], b=o[i][1];
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int c=o[j][0], d=o[j][1];
                if(c>=a && b>=d)indices.insert(j);
            }
        }
        return n-indices.size();
    }
};