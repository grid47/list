
+++
authors = ["grid47"]
title = "Leetcode 1170: Compare Strings by Frequency of the Smallest Character"
date = "2024-07-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1170: Compare Strings by Frequency of the Smallest Character in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        vector<int> bp(26, 0), ans(w.size(), 0), res(q.size(), 0);
        
        int j = 0;
        for(auto s: w) {
            bp= vector<int>(26, 0);
            for(char x: s) {
                bp[x - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                if(bp[i] > 0) {
                    ans[j] = bp[i];
                    break;
                }
            }
            j++;
        }
        
        sort(ans.begin(), ans.end());
        
        j = 0;
        for(auto s: q) {
            bp= vector<int>(26, 0);
            for(char x: s) {
                bp[x - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                if(bp[i] > 0) {
                    res[j] = bp[i];
                    break;
                }
            }
            j++;
        }
        // for(auto x: res)
        //     cout << x << " ";
        // cout << "\n";        
        vector<int> ret(q.size(), 0);
        for(int i = 0; i < res.size(); i++) {
            int qr = res[i];
            auto it = upper_bound(ans.begin(), ans.end(), qr);
            ret[i] = ans.end() - it;
            // cout << ret[i] << " ";
        }
        return ret;
    }
};
{{< /highlight >}}
---


### Problem Statement
The `numSmallerByFrequency` function takes two inputs:
1. `q` – an array of query words.
2. `w` – an array of words for comparison.

For each word in `q`, the function calculates the frequency of its smallest character, then compares it to the frequencies of the smallest characters in `w`. For each word in `q`, the result is the count of words in `w` whose smallest character frequency is greater than that of the query word. This result is returned as an array of integers.

### Approach
This function uses the following key steps:
1. **Calculate Frequency of Smallest Character**: For each word in `w` and `q`, find the frequency of the smallest character.
2. **Sort and Count**: Sort the frequency results from `w` to allow efficient counting using binary search.
3. **Binary Search for Comparison**: For each frequency calculated for `q`, use binary search to find how many frequencies in `w` are greater than it.

### Code Breakdown (Step by Step)

Let’s examine the implementation in detail:

```cpp
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        vector<int> bp(26, 0), ans(w.size(), 0), res(q.size(), 0);
        
        int j = 0;
        for(auto s: w) {
            bp = vector<int>(26, 0);
            for(char x: s) {
                bp[x - 'a']++;
            }
```

- **Line 3-11**: Initialize `bp` to store character frequencies, `ans` for smallest character frequencies of `w`, and `res` for frequencies in `q`.
- This loop iterates over each word in `w`. `bp` is reset to track frequencies of each character for the current word `s`.

```cpp
            for(int i = 0; i < 26; i++) {
                if(bp[i] > 0) {
                    ans[j] = bp[i];
                    break;
                }
            }
            j++;
        }
```

- **Lines 12-18**: This inner loop identifies the smallest character by checking from ‘a’ (index `0`) onward. The frequency of the smallest character for each word `s` is stored in `ans`.

```cpp
        sort(ans.begin(), ans.end());
```

- **Line 19**: Sort `ans` to enable efficient counting later with binary search.

```cpp
        j = 0;
        for(auto s: q) {
            bp = vector<int>(26, 0);
            for(char x: s) {
                bp[x - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                if(bp[i] > 0) {
                    res[j] = bp[i];
                    break;
                }
            }
            j++;
        }
```

- **Lines 21-33**: This second loop calculates the smallest character frequency for each word in `q` and stores it in `res`, following the same process as for `w`.

```cpp
        vector<int> ret(q.size(), 0);
        for(int i = 0; i < res.size(); i++) {
            int qr = res[i];
            auto it = upper_bound(ans.begin(), ans.end(), qr);
            ret[i] = ans.end() - it;
        }
        return ret;
    }
```

- **Lines 35-41**: For each frequency in `res`, we use `upper_bound` to count how many elements in `ans` are greater than it. The difference between the end of `ans` and the position of `it` gives the count. The results are stored in `ret`, which is returned at the end.

### Complexity
1. **Time Complexity**: \(O((m + n) \times 26 + m \log m + n \log m)\), where:
   - Calculating character frequencies for each string is \(O(26 \times (m + n))\).
   - Sorting `ans` is \(O(m \log m)\).
   - Binary searching for each query frequency is \(O(n \log m)\).
2. **Space Complexity**: \(O(m + n)\), for storing results in `ans`, `res`, and `ret`.

### Conclusion
The `numSmallerByFrequency` function efficiently counts how many words in `w` have a greater smallest character frequency than each word in `q`. The solution leverages sorting and binary search to handle large input sizes effectively, making it a suitable choice for similar problems requiring frequency-based comparisons.

[`Link to LeetCode Lab`](https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
