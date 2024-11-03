
+++
authors = ["Crafted by Me"]
title = "Leetcode 2712: Minimum Cost to Make All Characters Equal"
date = "2017-05-31"
description = "In-depth solution and explanation for Leetcode 2712: Minimum Cost to Make All Characters Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumCost(string s) {
        /*
        
        0100111
        
        0000000 3 + 2 + 1        
        
        1011111 4 + 2 + 1   if odd len choose middle
        
        0101000
        1011111 3 + 3 + 2 + 1         
        0100000 4 + 3 + 2 + 1 if odd len choose middle
        
        010111
        
        011011
        
        011011  0/ 2 + 3 + 1
                1/ 3 + 2 + 1
        
        010011
        
        010000  2 + 2 + 1
        
        101111  3
        011111  3 + 2
        111111  3 + 2 + 1 = 6
        
        010000  3 = 3
        100000  3 + 2 = 5
        000000  3 + 2 + 1 = 6
        
        */
        
        int n = s.size();
        
        if(n == 1) return 0;
        long long res = 0;

        char k = s[n / 2];
        
        int i, j;
        
        if(n % 2)
            i = n/2 + 1, j = n/2 - 1;
        else i = n/2, j = n / 2 - 1;
            bool ltog = true, rtog = true;
            while(i < n && j >= 0) {
                if(s[i] == k && rtog || s[i] != k && !rtog) {
                } else {
                    rtog = !rtog;
                    res += n - i;
                }
                i++;
                if((s[j] == k && ltog) || (s[j] != k && !ltog)) {
                } else {
                    ltog = !ltog;
                    res += j + 1;
                }
                j--;                
            }
            return res;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2713: Maximum Strictly Increasing Cells in a Matrix](https://grid47.xyz/posts/leetcode_2713) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

