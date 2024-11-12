
+++
authors = ["grid47"]
title = "Leetcode 2937: Make Three Strings Equal"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2937: Make Three Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2937.md" >}}
---
{{< youtube 7F8GNWVlYgM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2938: Separate Black and White Balls](https://grid47.xyz/posts/leetcode-2938-separate-black-and-white-balls-solution/) |
| --- |
