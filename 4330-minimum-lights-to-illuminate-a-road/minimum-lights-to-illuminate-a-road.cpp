class Solution {
public:
    int minLights(vector<int>& lights) {
        int count=0,n=lights.size();vector<int>light(n+1);
        for(int i=0;i<n;i++){
            if(lights[i]){
                int l=max(0,i-lights[i]);
                int r=min(n-1, i+lights[i]);
                light[l]++;light[r+1]--;
            }
        }
        for(int i=0;i<=n;i++){
            if(i>0)light[i]+=light[i-1];
        }
        for(int i=0;i<n;){
            if(light[i]){i++;continue;}
            if(i+2<n && !light[i] && !light[i+1] && !light[i+2]){count++;i+=3;}
            else if(i+1<n && !light[i] && !light[i+1]){count++;i+=2;}
            else {
                count++;i++;
            }
        }
        return count;
    }
};