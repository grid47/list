
+++
authors = ["Yasir"]
title = "Leetcode 537: Complex Number Multiplication"
date = "2023-05-09"
description = "Solution to Leetcode 537"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/complex-number-multiplication/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string r1, img1, r2, img2;
        int i = 0;
        while(num1[i] != '+') {
            r1 += num1[i];
            i++;
        }
        img1 = num1.substr(i + 1, num1.size() -1);
        i = 0;
        while(num2[i] != '+') {
            r2 += num2[i];
            i++;
        }
        img2 = num2.substr(i + 1, num2.size() -1);
        int re1 = stoi(r1);
        int re2 = stoi(r2);
        int ig1 = stoi(img1);
        int ig2 = stoi(img2);

        i = re1 * re2 - ig1 * ig2;
        int g = re1 * ig2 + re2 * ig1;

        return to_string(i) + "+" + to_string(g) + "i";
    }
};
{{< /highlight >}}

