
+++
authors = ["grid47"]
title = "Leetcode 524: Longest Word in Dictionary through Deleting"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 524: Longest Word in Dictionary through Deleting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/524.webp"
youtube = "tvaZ8-WobKE"
youtube_upload_date="2019-10-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tvaZ8-WobKE/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/524.webp" 
    alt="A string where characters are deleted to form the longest word from a dictionary, with each step glowing softly."
    caption="Solution to LeetCode 524: Longest Word in Dictionary through Deleting Problem"
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
    string findLongestWord(string s, vector<string>& d) {
        
        string ans;
        for(int i = 0; i < d.size(); i++) {
            
            int pi = 0, pj = 0;
            
            for(; pi < s.size() && pj < d[i].size(); pi++) {
                pj += s[pi] == d[i][pj];
            }
            
            if(pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && ans > d[i])))
                ans = d[i];
            
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the longest word in a given dictionary (`d`) that can be formed by deleting some characters from a given string `s` without rearranging the remaining characters. If multiple words can be formed with the same length, the lexicographically smallest word should be returned. The challenge is to efficiently check each word from the dictionary against `s` and determine which word is the longest and lexicographically smallest.

### Approach

1. **Iterate Through Each Word in the Dictionary**:
   - For each word in the dictionary (`d`), check if it can be formed by deleting characters from the string `s` while preserving the order of characters.

2. **Two-Pointer Technique**:
   - Use two pointers to check each word:
     - `pi`: A pointer for iterating over characters in `s`.
     - `pj`: A pointer for iterating over characters in the current dictionary word `d[i]`.
   - For each character in `s`, if it matches the current character in the dictionary word, move both pointers forward. Otherwise, just move the `pi` pointer forward in `s`.
   - If `pj` reaches the end of `d[i]`, it means `d[i]` can be formed by deleting characters from `s`.

3. **Update the Result Based on Conditions**:
   - If the current dictionary word meets the criteria (either being longer than the current answer or lexicographically smaller in case of a tie), update `ans` to store the new word.

4. **Return the Result**:
   - Once all words in the dictionary have been checked, return `ans`, which will hold the longest lexicographically smallest word that can be formed.

### Code Breakdown (Step by Step)

#### Step 1: Initialize `ans` Variable

```cpp
string ans;
```

- The variable `ans` will store the longest and lexicographically smallest word found.

#### Step 2: Iterate Through Each Word in the Dictionary

```cpp
for(int i = 0; i < d.size(); i++) {
```

- Loop through each word in the dictionary `d`.

#### Step 3: Use Two Pointers to Check Subsequence Condition

```cpp
int pi = 0, pj = 0;
for(; pi < s.size() && pj < d[i].size(); pi++) {
    pj += s[pi] == d[i][pj];
}
```

- Initialize `pi` and `pj` to 0. Use these pointers to check if `d[i]` can be formed from `s`.
- For each character in `s`, if it matches the current character in `d[i]`, move both pointers forward.
- If `pj` reaches the end of `d[i]`, it means `d[i]` can be created by deleting characters from `s`.

#### Step 4: Update the Result Based on Word Length and Lexicographical Order

```cpp
if(pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && ans > d[i])))
    ans = d[i];
```

- Check if the word is valid by verifying `pj` reached the end of `d[i]`.
- If it’s valid and longer than `ans`, update `ans` to `d[i]`.
- If `d[i]` and `ans` have the same length, update `ans` to the lexicographically smaller word.

#### Step 5: Return the Result

```cpp
return ans;
```

- Finally, return `ans`, which will hold the longest word that can be formed by deleting characters from `s`.

### Complexity

- **Time Complexity**: `O(n * m)`, where `n` is the number of words in the dictionary and `m` is the average length of each word. For each word in the dictionary, we check if it can be formed by deleting characters in `s` (up to `O(m)`).
  
- **Space Complexity**: `O(1)`, as we only store a few variables and the answer.

### Conclusion

The solution uses a straightforward approach of checking each word in the dictionary and employing a two-pointer technique to determine if the word can be formed by deleting characters from `s`. This approach is optimal for the problem and ensures that the longest and lexicographically smallest word is returned in an efficient manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/)

---
{{< youtube tvaZ8-WobKE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
