
+++
authors = ["Yasir"]
title = "Leetcode 3121: Count the Number of Special Characters II"
date = "2016-04-12"
description = "Solution to Leetcode 3121"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> ch(26, 0);
        for(char x: word) {
            if(isupper(x)) {
                if(ch[x - 'A'] == -1) continue;
                if(ch[x - 'A'] != 1 && ch[x - 'A'] != 2)  {
                  ch[x - 'A'] = -1;
                    continue;  
                }
                ch[x - 'A'] = 2;
            } else {
                if(ch[x - 'a'] == -1) continue;                
                if(ch[x - 'a'] == 2) {
                  ch[x - 'a'] = -1;
                    continue;  
                } 
                ch[x - 'a'] = 1;
            }
            // cout << x << " ";
            // for(int i = 0; i < 26; i++) {
            //     cout << ch[i] << " ";
            // }
            // cout << "\n";
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            // cout << ch[i] << " ";
            if(ch[i] == 2)
                cnt++;
        }
        return cnt;        
    }
};
{{< /highlight >}}

