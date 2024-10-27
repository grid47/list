
+++
authors = ["Yasir"]
title = "Leetcode 2325: Decode the Message"
date = "2018-06-17"
description = "Solution to Leetcode 2325"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-the-message/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string decodeMessage(string key, string mess) {
        char m[128] = {}, cur = 'a';
        for (char k : key)
            if (isalpha(k) && m[k] == 0)
                m[k] = cur++;
        for (int i = 0; i < mess.size(); ++i)
            mess[i] = m[mess[i]] ?: mess[i];
        return mess;
    }
};
{{< /highlight >}}

