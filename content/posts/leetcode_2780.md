
+++
authors = ["Crafted by Me"]
title = "Leetcode 2780: Minimum Index of a Valid Split"
date = "2017-03-24"
description = "Solution to Leetcode 2780"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-index-of-a-valid-split/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        int dom = -1;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(2 * mp[nums[i]] > n) {
                dom = nums[i];
            }
        }
        
        int frq = mp[dom];
        
        int l = 0, r = frq;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == dom) {
                l++;
                r--;
            }
            if(2 * l > (i + 1) && 2 * r > (n - (i + 1)))
                return i;
        }
        return -1;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

