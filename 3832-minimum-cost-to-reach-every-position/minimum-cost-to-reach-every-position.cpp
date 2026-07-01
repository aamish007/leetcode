class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int ans=INT_MAX;int i=0;int n=cost.size();
        while(i<n){
            ans=min(ans, cost[i]);
            cost[i]=ans;i++;
        }
        return cost;
    }
};