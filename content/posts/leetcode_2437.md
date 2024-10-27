
+++
authors = ["Yasir"]
title = "Leetcode 2437: Number of Valid Clock Times"
date = "2018-02-25"
description = "Solution to Leetcode 2437"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-valid-clock-times/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if(time[4] == '?') ans = ans * 10;
        if(time[3] == '?') ans = ans * 6;
        
        if(time[0] == '?' && time[1] == '?') ans = ans * 24;
        else{
            if(time[1] == '?'){ 
                if(time[0] == '2' ) ans = ans * 4;
                else ans = ans * 10;
            }
            if(time[0] == '?'){
                if(time[1] < '4') ans = ans * 3;
                else ans = ans * 2;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

