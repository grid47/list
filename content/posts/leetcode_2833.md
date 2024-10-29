
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2833: Furthest Point From Origin"
date = "2017-01-27"
description = "Solution to Leetcode 2833"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

