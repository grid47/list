
+++
authors = ["grid47"]
title = "Leetcode 2615: Sum of Distances"
date = "2024-02-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2615: Sum of Distances in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "b620guqinSc"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-distances/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        /*
        
        [1,3,1,1,2]
         0,1,2,3,4
        
         0
           0  
         2   2
         5   3 4
                 0
        */
        
        unordered_map<int, double> mp, cnt;
        int n = nums.size();
        vector<long long> arr(n, 0);
        for(int i = 0; i < n; i++) {
            arr[i] = cnt[nums[i]] * i - mp[nums[i]];
            mp[nums[i]] += i;
            cnt[nums[i]] += 1;
        }
        mp.clear(), cnt.clear();        
        for(int i = n - 1; i >= 0; i--) {
            arr[i] += mp[nums[i]] - cnt[nums[i]] * i;
            mp[nums[i]] += i;
            cnt[nums[i]] += 1;
        }
        return arr;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2615.md" >}}
---
{{< youtube b620guqinSc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2616: Minimize the Maximum Difference of Pairs](https://grid47.xyz/leetcode/solution-2616-minimize-the-maximum-difference-of-pairs/) |
| --- |
