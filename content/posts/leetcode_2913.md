
+++
authors = ["Yasir"]
title = "Leetcode 2913: Subarrays Distinct Element Sum of Squares I"
date = "2016-11-06"
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

{{< highlight html >}}
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

