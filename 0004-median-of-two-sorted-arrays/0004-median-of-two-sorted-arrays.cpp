class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int b=0,e=n1;
        double x;
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        while(b<=e){
            int i1=(b+e)/2;
            int i2=(n1+n2+1)/2-i1;
            int min1= (i1>=n1)?INT_MAX:nums1[i1];
            int max1= (i1-1<0) ?INT_MIN:nums1[i1-1];
            int min2= (i2>=n2)?INT_MAX:nums2[i2];
            int max2= (i2-1<0) ?INT_MIN:nums2[i2-1];
            if(max1<=min2 && max2<=min1){
                if((n1+n2)%2==0)
                x= ((double) max(max1,max2)+ min(min1,min2))/2;
                else x= (double) max(max1,max2);
                return x;
            }
            else if(max1>min2)
                e=i1-1;
            else b=i1+1;
        }
        return x;
    }
};