class Solution {
public:
    int kthGrammar(int n, int k) {
        bool fhalf=1;
        n=pow(2,n-1);
        while(n!=1){
            n/=2;
            if(k>n){
                k-=n;
                fhalf=!fhalf;
            }
        }
        if(fhalf==1) return 0;
        return 1;
    }
};