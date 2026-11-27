class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int x: nums) cnt[x]++;
        for(auto it: cnt){
            if(it.second>1){
                return true;
            }
        }
        return false;
    }
};