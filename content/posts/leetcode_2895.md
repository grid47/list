
+++
authors = ["Yasir"]
title = "Leetcode 2895: Minimum Processing Time"
date = "2016-11-24"
description = "Solution to Leetcode 2895"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-processing-time/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minProcessingTime(vector<int>& t, vector<int>& v) {
        int n=v.size();
        sort(t.begin(),t.end());
        sort(v.begin(),v.end());
        int j=n-1;
        int m=t.size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int c=0;
            while(c<4)
            {
                ans=max(ans,t[i]+v[j]);
                c++;
                j--;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

