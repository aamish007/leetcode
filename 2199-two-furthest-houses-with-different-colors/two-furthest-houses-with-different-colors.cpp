class Solution {
public:
    int maxDistance(vector<int>& colors) {
        unordered_map<int,int>first,last;int index=0;int res=INT_MIN;
        for(int i:colors){
            if(first.find(i)==first.end()){
                first[i]=index;
            }
            last[i]=index;
            index++;
        }
        for(auto it:first){
            for(auto it2:last){
                if(it.first==it2.first)continue;
                res=max(res, abs(it.second-it2.second));
            }
        }
        return res;
    }
};