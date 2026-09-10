class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        
        vector<int> ans;

    for(int i=0;i<k;i++){
        int maxFreq = 0;
        int maxNum = 0;
        for(auto& p: freq){
            if(p.second > maxFreq){
                maxFreq = p.second;
                maxNum = p.first;
            }
        }
        ans.push_back(maxNum);
        freq.erase(maxNum);
    }
    return ans;
    }
};