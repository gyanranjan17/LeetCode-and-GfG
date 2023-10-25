class Solution {
public:
    int kthGrammar(int n, int k) {
        int c=0;
        n=pow(2,n-1);
        while(n!=1){
            n/=2;
            if(k>n){
                k-=n;
                c++;
            }
        }
        if(c%2) return 1;
        return 0;
    }
};