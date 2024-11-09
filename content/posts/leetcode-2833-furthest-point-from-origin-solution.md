
+++
authors = ["grid47"]
title = "Leetcode 2833: Furthest Point From Origin"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2833: Furthest Point From Origin in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/furthest-point-from-origin/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.length();
        
        int l=0, r=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L' || moves[i]=='_'){
                l--;
            }else{
                l++;
            }
            
            if(moves[i]=='R' || moves[i]=='_'){
                r++;
            }else{
                r--;
            }
        }
        
        if(l<0) l *= -1;
        if(r<0) r *= -1;
		
        return max(l,r);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2833.md" >}}
---
{{< youtube XD2LVEXo8j8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2839: Check if Strings Can be Made Equal With Operations I](https://grid47.xyz/posts/leetcode-2839-check-if-strings-can-be-made-equal-with-operations-i-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
