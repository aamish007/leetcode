class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a=false,b=false, c=false;
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]==target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2])a=true;
            if(triplets[i][0]<=target[0] && triplets[i][1]==target[1] && triplets[i][2]<=target[2])b=true;
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]==target[2])c=true;
        }
        return a && b && c;
    }
};