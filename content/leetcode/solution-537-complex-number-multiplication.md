
+++
authors = ["grid47"]
title = "Leetcode 537: Complex Number Multiplication"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 537: Complex Number Multiplication in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/537.webp"
+++



[`Problem Link`](https://leetcode.com/problems/complex-number-multiplication/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/537.webp" 
    alt="Two complex numbers multiplying, with each step of the calculation softly glowing as the result is formed."
    caption="Solution to LeetCode 537: Complex Number Multiplication Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/537.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #538: Convert BST to Greater Tree](https://grid47.xyz/leetcode/solution-538-convert-bst-to-greater-tree/) |
| --- |
