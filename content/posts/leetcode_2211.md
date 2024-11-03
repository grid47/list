
+++
authors = ["Crafted by Me"]
title = "Leetcode 2211: Count Collisions on a Road"
date = "2018-10-14"
description = "In-depth solution and explanation for Leetcode 2211: Count Collisions on a Road in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-collisions-on-a-road/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countCollisions(string dir) {
        int l = 0, r = dir.size() - 1;
        int n = dir.size();
        while(l < n && dir[l] == 'L')
            l++;
        
        while(r >= 0 && dir[r] == 'R')
            r--;
        
        int cnt = 0;
        for(int i = l; i <= r; i++)
            if(dir[i] != 'S')
                cnt++;
        
        return cnt;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2212: Maximum Points in an Archery Competition](https://grid47.xyz/posts/leetcode_2212) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

