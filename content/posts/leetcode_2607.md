
+++
authors = ["Crafted by Me"]
title = "Leetcode 2607: Make K-Subarray Sums Equal"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2607: Make K-Subarray Sums Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Sorting","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-k-subarray-sums-equal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    long long solve(vector<int> nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int hit = nums[nums.size() / 2];
        long long res = 0;
        for(int i = 0; i < nums.size(); i++)
            res += abs(hit - nums[i]);
        return res;
    }
    
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        set<int> cnt;
        long long res = 0;
        for(int i = 0; i < n; i++) {
            
            int j = i;
            vector<int> nums;
            while(!cnt.count(j)) {
                cnt.insert(j);
                nums.push_back(arr[j]);
                j = (j + k) % n;
            }
            res += solve(nums);
        }
        
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube aBMFrPs2I5c >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2608: Shortest Cycle in a Graph](https://grid47.xyz/posts/leetcode_2608) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
