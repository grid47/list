
+++
authors = ["grid47"]
title = "Leetcode 2707: Extra Characters in a String"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2707: Extra Characters in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ONstwO1cD7c"
youtube_upload_date="2023-09-02"
youtube_thumbnail="https://i.ytimg.com/vi/ONstwO1cD7c/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    set<string> dic;
    string str;
    vector<int> memo;
    int n;
    
    int dp(int idx) {
        
        if(idx == n) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        int ans = INT_MAX;
        
        int len = 1;
        for(int i = idx; i < n; i++) {
            
            string s = str.substr(idx, len);
            
            if(dic.count(s)) {
                ans = min(ans, dp(idx + len));
            } else {
                ans = min(ans, len + dp(idx + len));                
            }
            
            len++;
        }
        
        return memo[idx] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        
        n = s.size();
        str = s;
        memo.resize(n, -1);
        
        for(auto x: dictionary) {
            dic.insert(x);
        }
        
        return dp(0);
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks you to find the minimum number of extra characters that need to be added to a given string `s` such that the resulting string contains only words from a dictionary `dictionary`. Each word in the dictionary can be used multiple times to form substrings of `s`. If some characters cannot be grouped into valid words from the dictionary, those characters are considered "extra" characters.

You are required to return the minimum number of extra characters that would remain after forming valid words from the dictionary.

### Approach

To solve this problem, we use a **dynamic programming** approach. The idea is to use a recursive function to check all possible ways to form valid words from the dictionary and count the number of leftover (or extra) characters.

#### Dynamic Programming Steps

1. **Define State**: 
   We define a state `dp(idx)` which represents the minimum number of extra characters needed to form valid words from the substring starting at index `idx`.

2. **Recursive Relation**:
   - For each starting index `idx`, we try all possible substrings starting from `idx`.
   - If the substring is found in the dictionary, we proceed without adding extra characters (i.e., move to the next substring).
   - If the substring is not in the dictionary, we count it as an extra character and recursively find the minimum extra characters from the next index.

3. **Base Case**: 
   - When `idx` reaches the end of the string, it means we've processed all characters, and no more extra characters are left to be added. So, return `0` as the base case.

4. **Memoization**: 
   To avoid recomputing the results for the same substring repeatedly, we use memoization by storing the result for each index `idx` in the `memo` array.

5. **Iterative Process**:
   We use a loop to check all possible substrings starting from the current index `idx` and recursively calculate the minimum number of extra characters needed.

6. **Final Result**: 
   The final result will be stored in `dp(0)`, which represents the minimum number of extra characters for the entire string.

### Code Breakdown (Step by Step)

#### 1. Member Variables

```cpp
set<string> dic;
string str;
vector<int> memo;
int n;
```

- `dic`: A set to store the dictionary words for quick lookup. This allows constant time check for whether a substring is in the dictionary.
- `str`: The input string `s`.
- `memo`: A memoization table to store the minimum extra characters required for each index in the string.
- `n`: The length of the input string `s`.

#### 2. `dp(int idx)` Function

```cpp
int dp(int idx) {
    if(idx == n) return 0;
    if(memo[idx] != -1) return memo[idx];
    
    int ans = INT_MAX;
    int len = 1;
    for(int i = idx; i < n; i++) {
        string s = str.substr(idx, len);
        if(dic.count(s)) {
            ans = min(ans, dp(idx + len));
        } else {
            ans = min(ans, len + dp(idx + len));
        }
        len++;
    }
    return memo[idx] = ans;
}
```

- **Base Case**: If `idx == n`, return `0` because we've reached the end of the string, meaning no more extra characters need to be added.
- **Memoization**: If `memo[idx]` is not `-1`, it means we've already computed the result for this index, so we return the stored value.
- **Recursive Search**: We initialize the `ans` as a very large number (`INT_MAX`) to keep track of the minimum extra characters. We then iterate through all possible substrings starting from `idx`:
  - For each possible substring, check if it exists in the dictionary:
    - If it exists, recursively calculate the result for the next substring (i.e., move to `idx + len`).
    - If it doesn't exist in the dictionary, count the substring as extra characters (i.e., add `len` to the result).
- **Memoization Update**: Finally, store the result for the current index `idx` in the `memo` table.

#### 3. `minExtraChar(string s, vector<string>& dictionary)` Function

```cpp
int minExtraChar(string s, vector<string>& dictionary) {
    n = s.size();
    str = s;
    memo.resize(n, -1);
    
    for(auto x: dictionary) {
        dic.insert(x);
    }
    
    return dp(0);
}
```

- **Initialization**: 
  - Set `n` to the size of the string `s` and initialize `str` to the input string.
  - Resize the `memo` array to the size of the string and initialize all elements to `-1` to indicate that no subproblem has been solved yet.
- **Dictionary Setup**: Insert all dictionary words into the `dic` set for fast lookup.
- **Final Calculation**: Call the `dp(0)` function to calculate the minimum extra characters from the start of the string.

### Complexity

#### Time Complexity

The time complexity of the solution is **O(n^2)**, where `n` is the length of the input string `s`. This is because, in the worst case, for each index `idx`, we check all possible substrings starting from `idx`, and there are at most `n` such substrings. Hence, the overall complexity is quadratic.

#### Space Complexity

The space complexity is **O(n)** for the `memo` array, which stores the result for each index of the string. The set `dic` also uses space proportional to the number of words in the dictionary, but this is typically much smaller than `n` and does not affect the overall space complexity significantly.

### Conclusion

This solution leverages dynamic programming with memoization to efficiently solve the problem of finding the minimum number of extra characters in the string `s` by trying to form valid words from the dictionary. The time complexity is quadratic, which is reasonable for moderate-sized input strings, and the space complexity is linear in terms of the length of the input string. The solution handles all cases efficiently by recursively trying all substrings and memoizing the results to avoid redundant calculations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/extra-characters-in-a-string/description/)

---
{{< youtube ONstwO1cD7c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
