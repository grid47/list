
+++
authors = ["Crafted by Me"]
title = "Leetcode 2381: Shifting Letters II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2381: Shifting Letters II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shifting-letters-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int n = s.length();
        vector<int> net(n, 0);
        for(auto &x: sh) {
            int k = x[2] == 1? 1 : -1;
            net[x[0]] += k;
           // net[x[0]] %= 26;
            if(x[1] + 1 < n) {
            net[x[1] + 1] -= k;
           // net[x[1] + 1] %= 26;
                }



        }
        
        partial_sum(net.begin(), net.end(), net.begin());
        
        int i = 0;
        for(char &c : s) {
            
            int res = ((c - 'a') + net[i])% 26;
                     res = (res + 26)%26;
            c = 'a' + res;
            i++;
        }
        
        return s;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2382: Maximum Segment Sum After Removals](https://grid47.xyz/posts/leetcode_2382) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

