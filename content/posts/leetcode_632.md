
+++
authors = ["Yasir"]
title = "Leetcode 632: Smallest Range Covering Elements from K Lists"
date = "2023-02-05"
description = "Solution to Leetcode 632"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<pair<int, int>> arr;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                arr.push_back({nums[i][j], i});
            }
        }
        int k = nums.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int cnt = 0;
        int j = 0;
        int n = arr.size();
        vector<int> ans = {-100000, 100000};
        for(int i = 0; i < n; i++) {
            mp[arr[i].second]++;
            if(mp[arr[i].second] == 1) cnt++;
            if(cnt == k) {
                while(mp[arr[j].second] > 1) {
                    mp[arr[j].second]--;
                    j++;
                }                
                if(arr[i].first - arr[j].first < ans[1] - ans[0]) {
                    ans = {arr[j].first, arr[i].first};
                }
            }
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

