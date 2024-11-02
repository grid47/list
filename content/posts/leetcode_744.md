
+++
authors = ["Crafted by Me"]
title = "Leetcode 744: Find Smallest Letter Greater Than Target"
date = "2022-10-20"
description = "Solution to Leetcode 744"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for(int i = 0; i < letters.size(); i++) {
            if(letters[i] > target) {
                ans = letters[i];
                break;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/744.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

