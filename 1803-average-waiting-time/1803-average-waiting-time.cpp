class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int ar=customers[0][0],ct=customers[0][0];
        double sum=0;
        for(int i=0;i<customers.size();i++){
            if(i==0){
                ct=ar+customers[i][1];
                sum+=ct-ar;
            }
            else{
                ar=max(ct,customers[i][0]);
                ct=ar+customers[i][1];
                sum+=ct-customers[i][0];
            }
        }
        return sum/customers.size();  
    }
};