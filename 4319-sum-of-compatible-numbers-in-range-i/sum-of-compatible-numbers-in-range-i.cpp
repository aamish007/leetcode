class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int s=max(1,n-k);int count=0;
        for(int i=s;i<=(n+k);i++){
            if((n&i)==0 && abs(n-i)<=k)count+=i;
        }
        return count;
    }
};