
+++
authors = ["Yasir"]
title = "Leetcode 393: UTF-8 Validation"
date = "2023-09-30"
description = "Solution to Leetcode 393"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/utf-8-validation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for(auto c : data) {
            if(count == 0) {
                if((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 3) == 0b11110) count = 3;
                else if (c >> 7) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};
{{< /highlight >}}

