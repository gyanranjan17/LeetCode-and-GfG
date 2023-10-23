class Solution {
public:
    bool isPowerOfFour(long long n) {
        long long count=0,x=0;
        if((n&(n-1))==0)
            x++;
       while(n>0)
       {
           n=n>>1;
           count++;
       }
       if((count%2!=0) && (x==1))
       return true;
       return false;
    }
};