
+++
authors = ["Crafted by Me"]
title = "Leetcode 2833: Furthest Point From Origin"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2833: Furthest Point From Origin in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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


---
{{< youtube XD2LVEXo8j8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2834: Find the Minimum Possible Sum of a Beautiful Array](https://grid47.xyz/posts/leetcode_2834) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

