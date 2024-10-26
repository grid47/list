
+++
authors = ["Yasir"]
title = "Leetcode 443: String Compression"
date = "2023-08-11"
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

{{< highlight html >}}
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

