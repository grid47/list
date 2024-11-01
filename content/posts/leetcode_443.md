
+++
authors = ["Crafted by Me"]
title = "Leetcode 443: String Compression"
date = "2023-08-17"
description = "Solution to Leetcode 443"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/string-compression/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() < 2) return chars.size();
        int i = 0, j = 0;
        while(i < chars.size()) {
            chars[j] = chars[i];
            int cnt = 0;
            while(i < chars.size() && chars[i] == chars[j]) {
                cnt++;
                i++;
            }

            if(cnt == 1) {
                j++;
            } else {
                string cntt = to_string(cnt);
                for(auto ch: cntt) {
                    chars[++j] = ch;
                }
                j++;
            }
        }
        return j;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/443.md" >}}
- by gpt
        
---
{{< youtube JHTqvUTZzqM >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

