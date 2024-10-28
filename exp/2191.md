#include <string.h>
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> tmp;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            
            int num = nums[i];
            
            string str = to_string(num);
            string formed = "";
            for(int j = 0; j < str.size(); j++)
                formed += to_string(mapping[str[j]- '0']);
            int val = stoi(formed);
            tmp.push_back({ val, i });
            
        }
        
        sort(tmp.begin(), tmp.end());
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
            ans.push_back(nums[tmp[i].second]);
        
        return ans;
        
    }
};