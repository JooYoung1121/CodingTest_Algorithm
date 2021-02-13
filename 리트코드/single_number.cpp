class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> num_cnt;
        for(auto num : nums){
            num_cnt[num]++;
        }
        
        for(auto nc : num_cnt){
            if(nc.second == 1) return nc.first;
        }
        return 1;
    }
};