class Solution {
public:
    int countTriplets(vector<int>& nums) {

        int res = 0, n = nums.size();
        vector<int> arr(n+1,0);
        for(int i = 1; i < n + 1; i++)
            arr[i] = arr[i -1] ^ nums[i-1];
        for(int i = 0; i < n+1; i++) {
            for(int j = i + 1; j < n+1; j++)
                if(arr[i] == arr[j])
                res += j - i- 1;
            }
        return res;
    }
};