
+++
authors = ["grid47"]
title = "Leetcode 2607: Make K-Subarray Sums Equal"
date = "2024-02-20"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2607.md" >}}
---
{{< youtube aBMFrPs2I5c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2609: Find the Longest Balanced Substring of a Binary String](https://grid47.xyz/posts/leetcode-2609-find-the-longest-balanced-substring-of-a-binary-string-solution/) |
| --- |
