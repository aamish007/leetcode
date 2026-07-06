class AuthenticationManager {
public:
    int unit;
    unordered_map<string,int>ump;
    AuthenticationManager(int timeToLive) {
        unit=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        ump[tokenId]=currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(ump.find(tokenId)==ump.end())return;
        int val=ump[tokenId];
        if(val+unit>currentTime)ump[tokenId]=currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto it:ump){
            if(it.second+unit>currentTime)count++;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */