class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid;
        int n=nums.size();
        int lo=0, high=n-1;
        while(lo<=high){
            mid=(lo+high)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target) lo=mid+1;
            else high=mid-1;
        }return-1;
    }
};