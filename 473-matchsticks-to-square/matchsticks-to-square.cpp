class Solution {
public:
    vector<int> sides;
    bool backtrack(vector<int>& matchsticks,int index,int target){
        if(index==matchsticks.size())return true;
        int stick=matchsticks[index];
        for(int i=0;i<4;i++){
            if(sides[i]+stick>target)continue;
            bool duplicate=false;
            for(int j=0;j<i;j++){
                if(sides[i]==sides[j]){
                    duplicate=true;
                    break;
                }
            }
            if(duplicate)continue;
            sides[i]+=stick;
            if(backtrack(matchsticks,index+1,target))return true;
            sides[i]-=stick;
            if(sides[i]==0)break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4)return false;
        int total=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(total%4!=0)return false;
        int target=total/4;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        if(matchsticks[0]>target)return false;
        sides.assign(4,0);
        return backtrack(matchsticks,0,target);
    }
};