
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2865: Beautiful Towers I"
date = "2016-12-26"
description = "Solution to Leetcode 2865"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
