class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int cmp = target - nums[i];
            if(mp.find(cmp) != mp.end()){
                return {mp[cmp],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};