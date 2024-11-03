
+++
authors = ["Crafted by Me"]
title = "Leetcode 2865: Beautiful Towers I"
date = "2016-12-29"
description = "In-depth solution and explanation for Leetcode 2865: Beautiful Towers I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/beautiful-towers-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    #define ll long long
    
    long long maximumSumOfHeights(vector<int>& a) {
        int n=a.size();
        
       ll int ans=0;
        for(int i=0;i<n;i++){
            ll int sum = a[i];
            int prev=a[i];
            for(int j=i-1;j>=0;j--){
                prev = min(a[j],prev);
                sum += prev;
            }
            prev=a[i];
            for(int j=i+1;j<n;j++){
                prev = min(a[j],prev);
                sum += prev;
            }
            
            if(sum > ans) ans=sum;
        }
        
        return ans;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2866: Beautiful Towers II](https://grid47.xyz/posts/leetcode_2866) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

