class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        if(x>=0)
        {
        while(x>0)
            {
            rev=rev*10 + x%10;
            x=x/10;
            }
            return (rev<pow(2,31)-1 && rev>-pow(2,31))? rev:0 ;
        }
        else 
        {
            int y=abs(x);
            while(y>0)
            {
                rev=rev*10 + y%10;
                y=y/10;
            }
            return (rev<pow(2,31)-1 && rev>-pow(2,31))? -rev:0 ;
        }
    }
};