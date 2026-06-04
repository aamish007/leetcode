class Solution {
public:
    int earliestFinishTime(vector<int>& la, vector<int>& lb, vector<int>& wa, vector<int>& wb) {
       int l=INT_MAX,w=INT_MAX, lw=INT_MAX, wl=INT_MAX;int n=la.size();int m=wb.size();
       for(int i=0;i<n;i++){
            l=min(l,la[i]+lb[i]);
       }
       for(int j=0;j<m;j++){
        lw=min(lw, max(l,wa[j])+wb[j]);
        w=min(w, wa[j]+wb[j]);
       }
       for(int i=0;i<n;i++){
        wl=min(wl, max(w,la[i])+lb[i]);
       }
       return min(wl,lw);
    }
};