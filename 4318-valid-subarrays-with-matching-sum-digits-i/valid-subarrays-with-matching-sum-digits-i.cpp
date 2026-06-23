class Solution {
public:
    bool valid(long long int sum,int x){
        int first=sum%10;int last=-1;
        while(sum>0){
            last=sum%10;
            sum/=10;
        }
        return first==x && last==x;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();int cnt=0;
        for(int i=0;i<n;i++){
            long long int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(valid(sum,x))cnt++;
            }
        }
        return cnt;
    }
};