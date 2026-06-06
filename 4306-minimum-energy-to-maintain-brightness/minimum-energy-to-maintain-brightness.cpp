class Solution {
public:
    void merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>temp;int n=intervals.size();
        for(int i=0;i<n;){
            int l=intervals[i][0], r=intervals[i][1];
            int j=i+1;
            while(j<n && intervals[j][0]<=r){
                r=max(r, intervals[j][1]);
                j++;
            }
            i=j;
            temp.push_back({l,r});
        }
        intervals=temp;
    }
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int bulbs=0;
        if(n==1)bulbs++;
        else{
            for(int i=1;i<n && bulbs*3<brightness;i+=2)bulbs++;
            if(brightness>bulbs*3){
                bulbs++;
            }
        }
        merge(intervals);
        long long energy=0;
        for(auto v:intervals){
            energy+=1LL*(bulbs)*(v[1]-v[0]+1);
        }
        return energy;
    }
};