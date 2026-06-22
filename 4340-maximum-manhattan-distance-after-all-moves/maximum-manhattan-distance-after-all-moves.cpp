class Solution {
public:
    int maxDistance(string moves) {
        int x=0,y=0,cnt=0;
        for(char ch:moves){
            if(ch=='L')x--;
            else if(ch=='R')x++;
            else if(ch=='U')y++;
            else if(ch=='D')y--;
            else cnt++;
        }
        x=abs(x);y=abs(y);
        return x+y+cnt;
    }
};