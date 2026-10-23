class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        unordered_map<int,int> mp;
        vector<int> ans(n, 0);

        for(int i=0; i<n ; i++){
            mp[nums[i]]++;

            int a = mp[nums[i]];

            if(a < 3){
                ans[count] = nums[i];
                count++;
            }
        }
        nums = ans;
        return count;

    }
};