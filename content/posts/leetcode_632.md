
+++
authors = ["Crafted by Me"]
title = "Leetcode 632: Smallest Range Covering Elements from K Lists"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 632: Smallest Range Covering Elements from K Lists in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Hash Table","Sliding Window","Heap"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/)

---

**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/632.md" >}}
---
{{< youtube L_0aPFMgGpU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #633: Sum of Square Numbers](https://grid47.xyz/posts/leetcode_633) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

