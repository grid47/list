
+++
authors = ["grid47"]
title = "Leetcode 2075: Decode the Slanted Ciphertext"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2075: Decode the Slanted Ciphertext in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-the-slanted-ciphertext/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string decodeCiphertext(string et, int rows) {
        cout << et.size() << " " << rows;
        string res = "";
        int col = et.size() / rows;
        int idx = 0;
        string space = "";
        // cout << col << " " << rows << " ";
        while(idx < col - rows + 2) {
            for(int i = 0; i < rows && idx + i + i * col < et.size(); i++) {
                if(et[idx + i + i * col] == ' ')
                    space += ' ';
                else {
                    res += (space + et[idx + i + i * col]);                    
                    space = "";
                }

            }
            idx++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2075.md" >}}
---
{{< youtube vFxVjspTM-0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2079: Watering Plants](https://grid47.xyz/leetcode/solution-2079-watering-plants/) |
| --- |
