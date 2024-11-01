
+++
authors = ["Crafted by Me"]
title = "Leetcode 2913: Subarrays Distinct Element Sum of Squares I"
date = "2016-11-11"
description = "Solution to Leetcode 2913"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumCounts(vector<int>& ar) {
        int n=ar.size();
        int ans=0;
        map<int,int>fr;
        //sort(ar.begin(),ar.end());
        for(int i=0;i<n;i++){
            int val=0;
             map<int,int>fr;
            for(int j=i;j<n;j++){
                if(fr[ar[j]]==0) val++;
                fr[ar[j]]++;
                ans=ans+val*val;
            }
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

