
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2354: Number of Excellent Pairs"
date = "2018-05-20"
description = "Solution to Leetcode 2354"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-excellent-pairs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        set<int> cnt;
        vector<int> arr;
        for(int i = 0; i < n; i++)
            if(cnt.count(nums[i])) continue;
            else {
                arr.push_back(__builtin_popcount(nums[i]));
                cnt.insert(nums[i]);
            }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] * 2 >= k) {
                
                ans += 2 * (arr.size() - (i + 1));
                ans++;

            } else {

                int x = k - arr[i];

                auto it = lower_bound(arr.begin(), arr.end(), x);
                if(it == arr.end()) continue;

                int y = arr.end() - it;
                ans += 2 * y;
            }
        }
        if(arr.back() * 2 >= k) ans++;
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

