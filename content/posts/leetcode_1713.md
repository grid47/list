
+++
authors = ["Crafted by Me"]
title = "Leetcode 1713: Minimum Operations to Make a Subsequence"
date = "2020-02-24"
description = "In-depth solution and explanation for Leetcode 1713: Minimum Operations to Make a Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        
        map<int, int> h;
        for(int i = 0; i < target.size(); i++)
            h[target[i]] = i;
        
        vector<int> stk;
        for(int num: arr) {
            
            if(!h.count(num)) continue;
            
            if(stk.size() == 0 || h[num] > stk.back()) {
                stk.push_back(h[num]);
                continue;
            }
            
            int l = 0, r = stk.size() - 1;
            
            while(l < r) {
                int mid = l + (r - l) / 2;
                
                if(stk[mid] < h[num])
                    l = mid + 1;
                else r = mid;
            }
            
            stk[l] = h[num];

        }
        
        return target.size() - stk.size();
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1714: Sum Of Special Evenly-Spaced Elements In Array](https://grid47.xyz/posts/leetcode_1714) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

