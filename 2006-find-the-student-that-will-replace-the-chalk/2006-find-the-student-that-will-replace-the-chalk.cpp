class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
            if(sum>k) return i;
        }
        int r=k%sum;
        for(int i=0;i<chalk.size();i++){
            r-=chalk[i];
            if(r<0) return i;
        }
        return 0;
    }
};