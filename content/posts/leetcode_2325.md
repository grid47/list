
+++
authors = ["Crafted by Me"]
title = "Leetcode 2325: Decode the Message"
date = "2018-06-22"
description = "In-depth solution and explanation for Leetcode 2325: Decode the Message in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---

| Next : [LeetCode #2326: Spiral Matrix IV](https://grid47.xyz/posts/leetcode_2326) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

