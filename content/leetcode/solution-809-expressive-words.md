
+++
authors = ["grid47"]
title = "Leetcode 809: Expressive Words"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 809: Expressive Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/809.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/809.webp" 
    alt="A string of words where expressive words glow softly, highlighting their expressive nature."
    caption="Solution to LeetCode 809: Expressive Words Problem"
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
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for(auto &w : words)
            if(check(s, w))
                res++;
        return res;
    }

    bool check(string s, string w) {
        int n = s.size(), m = w.size(), j = 0;
        for(int i = 0; i < n; i++)
            if(j < m && s[i] == w[j]) j++;
            else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]);
            else if (i > 0 && i < n - 1 && s[i -1] == s[i] && s[i] == s[i +1]);
            else return false;
        return j == m;
    }

};
{{< /highlight >}}
---

### Problem Statement
The problem asks to determine how many words from a list of strings are "expressive" words compared to a given string `s`. An expressive word is defined as one where characters in `s` can be "stretched" or "compressed" to match a word in the list. The stretching rule allows a character in `s` to appear one or more times, while compressing allows it to appear exactly once. The goal is to find the number of words in the list that can be transformed into `s` by applying these rules.

### Approach
To solve this problem, we need to check if each word in the list of words can be formed by stretching or compressing the string `s`. The check involves iterating over each character in the string `s` and trying to match it with the characters of the word. If a character in `s` repeats, it should correspond to one or more occurrences of the same character in the word. If the string `s` has a character that is compressed, it must match exactly once in the word.

#### Key Insights:
1. **Character Matching**: We need to match the characters in both `s` and each word in the list, but allow for stretching (repeating characters in `s`).
2. **Matching Criteria**:
    - If two adjacent characters in `s` are the same, they can be stretched into one or more of the same character in the word.
    - If a character in `s` appears more than once consecutively, it should match that character appearing consecutively in the word.
    - If a character in `s` appears only once and the corresponding character in the word appears more than once, the word is not valid.
3. **Validation Function**: We define a function `check()` that validates whether a word can be formed from `s` by checking each character’s match with stretching or compression.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Result Variable
```cpp
int res = 0;
```
- **`res`** keeps track of the number of valid expressive words. It is initialized to 0.

#### Step 2: Iterate Over Each Word in the List
```cpp
for (auto &w : words)
    if (check(s, w))
        res++;
```
- We iterate over each word `w` in the list of words `words`. For each word, we call the `check()` function to validate if the word can be transformed into `s` based on the stretching rules.
- If `check()` returns `true`, it means the word is expressive, so we increment `res`.

#### Step 3: Define the Check Function
```cpp
bool check(string s, string w) {
    int n = s.size(), m = w.size(), j = 0;
    for (int i = 0; i < n; i++)
        if (j < m && s[i] == w[j]) j++;
        else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]);
        else if (i > 0 && i < n - 1 && s[i -1] == s[i] && s[i] == s[i +1]);
        else return false;
    return j == m;
}
```
- **Parameters**: The function `check` takes two strings, `s` (the given string) and `w` (the word to be checked).
- **Variables**: 
  - `n` is the size of `s`.
  - `m` is the size of `w`.
  - `j` is an index to track the current character in `w`.
  
- **Iterate Through `s`**:
  - The function iterates through each character of `s` (indexed by `i`).
  - **Matching Characters**: If the current character `s[i]` matches the current character in `w[j]`, we increment `j` to move to the next character of `w`.
  - **Stretching Check**: If the previous two characters in `s` are the same (`s[i-2] == s[i-1]` and `s[i-1] == s[i]`), this indicates a stretch, and we allow it to match in `w`.
  - **Compression Check**: If the current character `s[i]` is surrounded by the same character (`s[i-1] == s[i] == s[i+1]`), it can be compressed into exactly one character in `w`, allowing it to match.
  - **Return False**: If none of the conditions above are satisfied, the word `w` cannot be formed from `s`, so we return `false`.
  
- **End of Loop**: After the loop finishes, we check if the entire word `w` has been matched (`j == m`). If it has, we return `true`; otherwise, `false`.

#### Step 4: Return the Final Result
```cpp
return res;
```
- After checking all words in the list, we return the value of `res`, which represents the count of expressive words.

### Complexity

#### Time Complexity:
- **`O(n * m)`**, where `n` is the size of the given string `s` and `m` is the average length of the words in the list.
  - For each word, the function `check()` performs a linear scan of the string `s` and the word `w`, making the time complexity for each check linear in terms of the length of `s`.
  - The `for` loop iterates through all words in the list, and for each word, we call `check()`. Therefore, the overall time complexity is **O(n * m)** where `n` is the length of `s` and `m` is the average length of the words.

#### Space Complexity:
- **`O(1)`**: The algorithm uses a constant amount of space apart from the input strings and the list of words. The result is stored in a simple integer variable, and no extra memory is required for each word check.

### Conclusion
This solution efficiently solves the problem of counting expressive words by employing a character matching strategy with support for stretching and compression. The approach works by comparing each word in the list to the string `s` character by character, handling the stretching/compressing cases. The solution utilizes a simple and effective validation function (`check()`) to determine whether a word can be transformed into `s`. The time complexity is manageable, and the space complexity is minimal, making this solution suitable for problems where the input size is large. 

By iterating over the list of words and applying the check for each one, we can determine how many words are expressive in relation to the given string `s`. The implementation ensures that all edge cases, including consecutive repeated characters and compressions, are handled efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/expressive-words/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
