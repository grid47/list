
+++
authors = ["grid47"]
title = "Leetcode 139: Word Break"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 139: Word Break in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming","Trie","Memoization"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/139.webp"
youtube = "t0svbzZ1PWM"
youtube_upload_date="2021-04-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/t0svbzZ1PWM/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/139.webp" 
    alt="A string breaking into glowing segments, with each segment leading to a valid word in a dictionary."
    caption="Solution to LeetCode 139: Word Break Problem"
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
    vector<int> memo;
    bool wordBreak(string s, vector<string>& dict) {
        map<string, bool> mp;
        for(string d: dict)
            mp[d] = true;
        memo.resize(s.size(), -1);
        return bt(s, 0, mp);
    }
    
    bool bt(string s, int idx, map<string, bool> &mp) {
        
        if(idx == s.size()) return true;
        
        if(memo[idx] != -1) return memo[idx];
        
        for(int i = idx; i < s.size(); i++) {
            if(mp.count(s.substr(idx, i - idx + 1)) && bt(s, i + 1, mp))
                return memo[idx] = true;
        }
        
        return memo[idx] = false;
    }
    
};
{{< /highlight >}}
---

### 🧩 **Understanding the Problem: Word Break**

The problem asks us to determine if a string `s` can be segmented into valid words from a given dictionary `dict`. This means we need to break down the string into space-separated substrings that all exist in the dictionary.

For example:
- **Input**: `s = "leetcode"`, `dict = ["leet", "code"]`
- **Output**: `true` because the string `"leetcode"` can be segmented into the words `"leet"` and `"code"`.

---

### 🔄 **Approach: Dynamic Programming with Memoization**

We can approach this problem using **dynamic programming (DP)** and **memoization** to avoid redundant calculations. This technique will allow us to check all possible segmentations efficiently.

Here’s how we can break it down:

1. **Memoization**: We’ll use a `memo` array to store results for subproblems. If we’ve already computed whether a substring can be segmented, we’ll reuse the result to avoid recalculating.
2. **Backtracking**: We will iterate through the string, trying to match a substring with any word in the dictionary. Once we find a match, we recursively check the remaining part of the string.
3. **Dictionary Lookup**: We store the dictionary words in a **map** for constant-time lookup to check if a substring is a valid word.

By combining memoization and backtracking, we can make this solution more efficient, avoiding redundant checks.

---

### 🖥️ **Code Breakdown: Step-by-Step**

#### 1️⃣ **Initialization of Memoization and Map**

```cpp
vector<int> memo;
bool wordBreak(string s, vector<string>& dict) {
    map<string, bool> mp;
    for(string d: dict)
        mp[d] = true;
    memo.resize(s.size(), -1);
    return bt(s, 0, mp);
}
```

- **Memo Array**: We initialize a `memo` array of size `s.size()`, where each element is initially set to `-1`, meaning no substring has been processed yet. As we compute the results for each substring, we will update this array with `true` or `false` based on whether the substring can be segmented.
- **Dictionary Map**: We convert the `dict` array into a `map` (`mp`), where each word from the dictionary is stored as a key for **constant-time lookup**.
- **Backtracking**: We start the backtracking function `bt` from the first index of the string `s`.

#### 2️⃣ **Backtracking Function (`bt`)**

```cpp
bool bt(string s, int idx, map<string, bool> &mp) {
    if (idx == s.size()) return true;
    if (memo[idx] != -1) return memo[idx];
    
    for (int i = idx; i < s.size(); i++) {
        if (mp.count(s.substr(idx, i - idx + 1)) && bt(s, i + 1, mp))
            return memo[idx] = true;
    }
    
    return memo[idx] = false;
}
```

- **Base Case**: 
   ```cpp
   if (idx == s.size()) return true;
   ```
   If the index `idx` reaches the end of the string, it means we've successfully segmented the string, so we return `true`.
   
- **Memoization Lookup**:
   ```cpp
   if (memo[idx] != -1) return memo[idx];
   ```
   If we’ve already computed the result for this index, we return it to avoid redundant work.

- **Backtracking Loop**:
   ```cpp
   for (int i = idx; i < s.size(); i++) {
       if (mp.count(s.substr(idx, i - idx + 1)) && bt(s, i + 1, mp))
           return memo[idx] = true;
   }
   ```
   We loop through all possible substrings starting from `idx` and check if it exists in the dictionary. If it does, we recursively call `bt` for the remaining part of the string starting at index `i + 1`. This process continues until the string is fully segmented.

- **Return Result**:
   ```cpp
   return memo[idx] = false;
   ```
   If no valid segmentation is found from index `idx`, we mark this index as `false` in the `memo` array and return `false`.

#### 3️⃣ **Final Result**

After backtracking completes, the result will be stored in `memo[0]`, indicating whether the string can be segmented starting from the first index.

---

### 🧮 **Time and Space Complexity**

#### ⏱️ **Time Complexity**:
- **O(n²)**: For each index `idx`, we try all possible substrings from `idx` to `i`. Each substring check takes `O(n)` time. Therefore, the total time complexity is \( O(n^2) \), where `n` is the length of the string.

#### 🧳 **Space Complexity**:
- **O(n)**: We use an array `memo` of size `n` to store results for each index. Additionally, the `map` for the dictionary takes space proportional to the number of words, but this doesn’t affect the overall complexity.

---

### 🎯 **Conclusion: Efficient Segmentation**

This approach is a very efficient way to determine whether a string can be segmented into valid words from a dictionary. The solution employs:
- **Backtracking** to explore all possible ways to segment the string.
- **Memoization** to avoid redundant work by storing previously computed results.

#### Key Insights:
- **Memoization**: Avoids recalculating results for the same substring, optimizing the time complexity.
- **Backtracking**: Explores all potential segmentations while pruning unnecessary computations.
- **Constant-Time Dictionary Lookup**: Using a `map` ensures fast checks when looking for valid words in the dictionary.

This solution works efficiently for moderate-sized strings with a time complexity of \( O(n^2) \), making it suitable for most practical input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/word-break/description/)

---
{{< youtube t0svbzZ1PWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
