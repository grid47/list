
+++
authors = ["Crafted by Me"]
title = "Leetcode 2595: Number of Even and Odd Bits"
date = "2017-09-25"
description = "In-depth solution and explanation for Leetcode 2595: Number of Even and Odd Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-even-and-odd-bits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int a=0,b=0;
        int c=0;
        while(n>0)
        {
            if(c%2==0)
            {
                if(n%2==1)
                {
                    a++;
                }
            }
            else
            {
                if(n%2==1) b++;
            }
            n=n/2;
            c++;
            
        }
        return {a,b};
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2596: Check Knight Tour Configuration](https://grid47.xyz/posts/leetcode_2596) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

