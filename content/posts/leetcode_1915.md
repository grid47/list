
+++
authors = ["Crafted by Me"]
title = "Leetcode 1915: Number of Wonderful Substrings"
date = "2019-08-06"
description = "In-depth solution and explanation for Leetcode 1915: Number of Wonderful Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-wonderful-substrings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        map<int, int> mp;
        mp[0] = 1;
        int msk = 0;
        long long ans = 0;
        for(int i = 0; i < word.size(); i++) {
            
            int idx = word[i] - 'a';
            msk ^= (1 << idx);
            ans += mp[msk];
            for(int j = 0; j < 10; j++) {
                int lf = msk ^ (1 << j);
                ans += mp[lf];
                }
            mp[msk]++;
            }
        
        return ans;
    }
};
{{< /highlight >}}


---


"| 1916: Count Ways to Build Rooms in an Ant Colony |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

