
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2607: Make K-Subarray Sums Equal"
date = "2017-09-09"
description = "Solution to Leetcode 2607"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

