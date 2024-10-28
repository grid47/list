class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        int sum = 0, lsize = INT_MAX, result = INT_MAX;
        mp[0] = -1;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            mp[sum] = i;
        }
        sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(mp.count(sum - target)) 
            lsize = min(lsize, i - mp[sum-target]);

            if(mp.count(sum + target) && lsize < INT_MAX)
            result = min(result, mp[sum + target] -i +lsize);


        }

        return result == INT_MAX ? -1: result;
    }
};