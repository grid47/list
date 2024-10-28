
+++
authors = ["Yasir"]
title = "Leetcode 1904: The Number of Full Rounds You Have Played"
date = "2019-08-13"
description = "Solution to Leetcode 1904"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numberOfRounds(string login, string logout) {
        
        int in = (((login[0] - '0') * 10 + (login[1]- '0')) * 60) + ((login[3] - '0') * 10 + (login[4] - '0'));
        int out = (((logout[0] - '0') * 10 + (logout[1]- '0')) * 60) + ((logout[3] - '0') * 10 + (logout[4] - '0'));
        // cout << in << " " << out;
        int cnt = 0;
        if(in > out) {
            for(int i = 0; i < 24 * 60; i += 15) {
                if(i + 15 <= out || i >= in) cnt++;
            }
            return cnt;
        }

        for(int i = 0; i < 24 * 60; i += 15) {
            // cout << "\n" << i; 
            if(i >= in && (i + 15) <= out) cnt++;
        }
        return cnt;
        
        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

