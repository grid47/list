
+++
authors = ["grid47"]
title = "Leetcode 2241: Design an ATM Machine"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2241: Design an ATM Machine in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "edP4gaMO80E"
youtube_upload_date="2022-04-16"
youtube_thumbnail="https://i.ytimg.com/vi/edP4gaMO80E/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/design-an-atm-machine/description/)

---
**Code:**

{{< highlight cpp >}}
class ATM {
public:
    vector<long long> note;
    ATM() {
        note.resize(5, 0);
    }
    
    void deposit(vector<int> cnt) {
        for(int i = 0; i < 5; i++)
            note[i] += cnt[i];
    }
    
    vector<int> withdraw(int amnt) {
        int cnt500 = 0, cnt200 = 0, cnt100 = 0, cnt50 = 0, cnt20 = 0;
        int taken = 0;
        if(amnt >= 500) {
            cnt500 = amnt / 500;
            
            if(cnt500 > note[4]) {
                cnt500 = note[4];
            }
            amnt -= (cnt500 * 500);
        }
        if(amnt >= 200) {
            cnt200 = amnt / 200;
            if(cnt200 > note[3]) {
                cnt200 = note[3];
            }
            amnt -= (cnt200 * 200);
        }
        if(amnt >= 100) {
            cnt100 = amnt / 100;
            if(cnt100 > note[2]) {
                cnt100 = note[2];                
            }
            amnt -= (cnt100 * 100);

        }
        if(amnt >= 50) {
            cnt50 = amnt / 50;
            if(cnt50 > note[1]) {
                cnt50 = note[1];                                
            }
            amnt -= (cnt50 * 50);
        }        
        if(amnt >= 20) {
            cnt20 = amnt / 20;
            if(cnt20 > note[0]) {
                cnt20 = note[0];                                
            }
            amnt -= (cnt20 * 20);
        }       
        if(amnt != 0) return vector<int>{-1};
        note[4] -= cnt500;
        note[3] -= cnt200;
        note[2] -= cnt100;
        note[1] -= cnt50;
        note[0] -= cnt20;

        return vector<int>{cnt20, cnt50, cnt100, cnt200, cnt500};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2241.md" >}}
---
{{< youtube edP4gaMO80E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2243: Calculate Digit Sum of a String](https://grid47.xyz/leetcode/solution-2243-calculate-digit-sum-of-a-string/) |
| --- |