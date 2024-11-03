
+++
authors = ["Crafted by Me"]
title = "Leetcode 1545: Find Kth Bit in Nth Binary String"
date = "2020-08-10"
description = "In-depth solution and explanation for Leetcode 1545: Find Kth Bit in Nth Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    char findKthBit(int n, int k) {

        string s = "0";
        
        for(int i = 2; i <= n; i++) {
            string tmp = s;
            s += '1';
            for(int j = tmp.size() - 1; j >= 0; j--) {
                
                s += (tmp[j] == '0') ? '1':'0';
                
            }
        }

        return s[k-1];
    }
};
{{< /highlight >}}


---
{{< youtube 34QYE5HAFy4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target](https://grid47.xyz/posts/leetcode_1546) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

