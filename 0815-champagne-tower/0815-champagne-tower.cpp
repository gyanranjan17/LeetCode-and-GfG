class Solution {
public:
    double champagneTower(int p, int qr, int qg) {
        vector<double> curr;
        curr.push_back(p);
        for(int i=1;i<=qr;i++){
            vector<double> next(i+1,0);

            next[0]+=max(0.0,(curr[0]-1)/2);;
            next[i]+=max(0.0,(curr[i-1]-1)/2);
            for(int j=1;j<i;j++)
                next[j]+=max(0.0,(curr[j-1]-1)/2)+max(0.0,(curr[j]-1)/2); 
            curr=next;   
        }
        if(curr[qg]>1) return 1;
        return curr[qg];
    }
};