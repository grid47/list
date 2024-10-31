
+++
authors = ["Crafted by Me"]
title = "Leetcode 1658: Minimum Operations to Reduce X to Zero"
date = "2020-04-18"
description = "Solution to Leetcode 1658"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = -1;
        long sum = -x;
        for(int y: nums) sum += y;
        int n = nums.size();
        if (sum == 0) return n;
        
        map<int, int> mp;
        mp[0] = -1;
        int s = 0;
        for(int i = 0; i < n; i++) {
            s += nums[i];
            if(mp.count(s - sum)) {
                res = max(res, i - mp[s - sum]);
            }
            mp[s] = i;
        }
        
        return res == -1? res :n - res;        
    }
};
{{< /highlight >}}



---

{{< youtube iPqrN6Bb-NI >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

