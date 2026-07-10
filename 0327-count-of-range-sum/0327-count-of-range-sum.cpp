class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long > sum(nums.size()+1);
        long long sums = 0;
        sum[0]=0;
        for (int i = 1; i < nums.size()+1; i++) {
            sums += nums[i-1];
            sum[i] = sums;
        }
        int count=0;
        mergesort(sum, lower, upper, 0,  sum.size()-1,count);
        return count;
    }
    void mergesort(vector<long long>& sum, int lower, int upper, int low, int high,int &count) {
        if (low >= high)
            return ;
        int mid =(low + high) / 2;
        mergesort(sum, lower, upper, low, mid,count);
        mergesort(sum, lower, upper, mid+1, high,count);
        int start_index=mid+1;
        int end_index=mid+1;
        for(int i=low;i<=mid;i++){
            while(start_index<=high && sum[start_index]-sum[i]<lower){
                start_index++;
            }
            while(end_index<=high && sum[end_index]-sum[i]<=upper){
                end_index++;
            }
            count+=end_index-start_index;
        }
        merge(sum, low, mid, high);

    }
    void merge(vector<long long>& sum, int low, int mid, int high) {
        vector<long long> temp;
        int left = low;
        int right = mid+1;
        while (left <= mid && right <= high) {
            if (sum[left] <= sum[right]) {
                temp.push_back(sum[left]);
                left++;
            } else {
                temp.push_back(sum[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(sum[left]);
            left++; 
        }
        while(right<=high){
            temp.push_back(sum[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            sum[i]=temp[i-low];
        }
    }
};