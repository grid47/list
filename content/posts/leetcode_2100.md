
+++
authors = ["Crafted by Me"]
title = "Leetcode 2100: Find Good Days to Rob the Bank"
date = "2019-02-01"
description = "Solution to Leetcode 2100"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {

        int n = sec.size();
        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = 0;
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(sec[i] <= sec[i - 1])
                cnt++;
            else cnt = 0;
            pre[i] = cnt;
        }
        
        suf[n - 1] = 0;
        cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            if(sec[i] <= sec[i + 1])
                cnt++;
            else cnt = 0;
            suf[i] = cnt;
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (pre[i] >= time && suf[i] >= time)
                ans.push_back(i);
        }
        
        return ans;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

