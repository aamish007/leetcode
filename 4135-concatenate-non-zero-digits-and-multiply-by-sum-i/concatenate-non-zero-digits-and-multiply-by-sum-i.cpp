class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0,sum=0;
        int mul=1;
        while(n>0){
            int rem=n%10;
            n/=10;
            if(rem==0)continue;
            sum+=rem;
            x=rem*mul+x;
            mul*=10;
        }
        return sum*x; 
    }
};