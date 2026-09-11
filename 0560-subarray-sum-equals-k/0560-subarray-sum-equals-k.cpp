class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0]=1;
        int sum =0;
        int ans =0;

        for(int x: nums){
            sum+=x;

            if(freq.count(sum-k)){
                ans += freq[sum-k];
            }

            freq[sum]++;
        }
        return ans;
    }
};