
+++
authors = ["Crafted by Me"]
title = "Leetcode 1297: Maximum Number of Occurrences of a Substring"
date = "2021-04-15"
description = "In-depth solution and explanation for Leetcode 1297: Maximum Number of Occurrences of a Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        map<int, int> cnt;
        int n = nums.size();
        for(int num : nums)
            cnt[num]++;
        
        for(auto it : cnt) {
            int frq = it.second;
            if(frq > 0)
            for(int i = 0; i < k; i++) {

                  if(cnt[it.first + i] < frq) return false;
                else cnt[it.first + i] -= frq;

            }
        }
        
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1297.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

