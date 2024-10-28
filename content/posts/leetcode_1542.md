
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1542: Find Longest Awesome Substring"
date = "2020-08-09"
description = "Solution to Leetcode 1542"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-longest-awesome-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestAwesome(string s) {
        map<int, int> mp;
        int msk = 0;
        int n = s.size();
        int j = 0, ans = 1;
        mp[0] = -1;
        for(int i = 0; i < s.size(); i++) {
            msk ^= (1 << (s[i] - '0'));

            if(mp.count(msk)) ans = max(ans, i - mp[msk]);
            for(int j = 0; j < 10; j++) {
                // if((msk & (1 << j)) == 0) continue;
                msk ^= (1 << j);
                if(mp.count(msk)) ans = max(ans, i - mp[msk]);
                msk ^= (1 << j);                
            }

            if(!mp.count(msk)) mp[msk] = i;
        }

        return ans;

    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

