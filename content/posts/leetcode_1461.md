
+++
authors = ["Crafted by Me"]
title = "Leetcode 1461: Check If a String Contains All Binary Codes of Size K"
date = "2020-11-01"
description = "Solution to Leetcode 1461"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/)

---

{{< youtube qU32rTy_kOM >}}

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.size();
        set<int> cnt;
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            if(i < k) {
                tmp = tmp * 2 + (s[i] == '0'? 0: 1);
                continue;
            }
            cnt.insert(tmp);
            tmp *= 2;
            tmp &= ((1 << k) - 1);            
            tmp += (s[i] == '0'? 0: 1);
        }
        cnt.insert(tmp);
        // cout << cnt.size() << " " << (1 << k);
        return cnt.size() == (1 << k);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

