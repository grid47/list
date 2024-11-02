
+++
authors = ["Crafted by Me"]
title = "Leetcode 2937: Make Three Strings Equal"
date = "2016-10-18"
description = "Solution to Leetcode 2937"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-three-strings-equal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int l1=s1.length(), l2=s2.length(), l3=s3.length();
		int len=min({l1,l2,l3});
        
        int ans=INT_MAX;
        for(int i=0;i<len;i++){
            if(s1.substr(0,i+1) == s2.substr(0,i+1) && s2.substr(0,i+1) == s3.substr(0,i+1)){
                int c=l1-(i+1)+l2-(i+1)+l3-(i+1);
                ans=min(ans,c);
            }
        }
        
        return (ans==INT_MAX ? -1:ans);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

