
+++
authors = ["grid47"]
title = "Leetcode 792: Number of Matching Subsequences"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 792: Number of Matching Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Binary Search","Dynamic Programming","Trie","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/792.webp"
youtube = "0zMujz5SYoE"
youtube_upload_date="2020-08-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0zMujz5SYoE/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/792.webp" 
    alt="A sequence where matching subsequences are counted, with each match glowing softly as it is found."
    caption="Solution to LeetCode 792: Number of Matching Subsequences Problem"
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
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<vector<int>> srch(26);

        for(int i = 0; i < s.size(); i++)
            srch[s[i] - 'a'].push_back(i);
        
        int res = 0;
        
        for(string word : words) {
            int x = -1;
            bool found = true;

            for(char c : word) {
                auto it = upper_bound(srch[c - 'a'].begin(), srch[c - 'a'].end(), x);
                if(it == srch[c - 'a'].end()) {
                    found = false;
                    break;
                } else x = *it;
            }
            
            if(found) res++;
        }
                
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem at hand involves determining how many words from a list are subsequences of a given string `s`. A subsequence is defined as a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

### Approach
To solve this problem efficiently, we can take advantage of precomputed indices for each character in the string `s`. The core idea is to check whether each word in the list `words` is a subsequence of `s` by trying to match its characters one by one, using a technique that avoids checking every possible subsequence directly.

The approach works as follows:
1. **Preprocess the string `s`**: Create a data structure that stores, for each character, the positions of its occurrences in `s`. This allows us to efficiently find the next position where a character can appear.
2. **Check each word**: For each word in the list, use the preprocessed data to check if all its characters appear in order in `s`. This can be done by trying to find each character's next occurrence after the previous one.

### Code Breakdown (Step by Step)

1. **Initialization**:
   ```cpp
   int n = s.size();
   vector<vector<int>> srch(26);
   ```
   Here, we initialize `n` to the size of the string `s`. We also create a 2D vector `srch` of size 26 (one for each letter of the alphabet). This will hold the indices of each character in `s`.

2. **Preprocessing the String `s`**:
   ```cpp
   for(int i = 0; i < s.size(); i++)
       srch[s[i] - 'a'].push_back(i);
   ```
   In this step, we loop through each character of `s` and store the index of each character in the corresponding list within the `srch` vector. The expression `s[i] - 'a'` maps the character to an index between 0 and 25. For example, 'a' will be mapped to index 0, 'b' to index 1, and so on. This ensures that for each character in `s`, we know where it appears.

3. **Checking Each Word in `words`**:
   ```cpp
   int res = 0;
   for(string word : words) {
       int x = -1;
       bool found = true;
   ```
   We initialize `res` to 0, which will keep track of how many words are subsequences of `s`. We then loop through each word in the `words` list. For each word, we initialize `x = -1`, which will store the index of the last matched character in `s`, and `found = true`, a flag to indicate if the word is a subsequence of `s`.

4. **Matching Characters of the Word**:
   ```cpp
   for(char c : word) {
       auto it = upper_bound(srch[c - 'a'].begin(), srch[c - 'a'].end(), x);
       if(it == srch[c - 'a'].end()) {
           found = false;
           break;
       } else x = *it;
   }
   ```
   We iterate through each character `c` in the current word. For each character, we use `upper_bound` on the list of indices for that character in `s` (stored in `srch[c - 'a']`). The `upper_bound` function returns an iterator to the first element that is greater than `x`, where `x` is the index of the last matched character. If no such element is found (i.e., `it == srch[c - 'a'].end()`), it means the word is not a subsequence of `s`, so we set `found = false` and break out of the loop. If a match is found, we update `x` to the new index.

5. **Count the Valid Subsequences**:
   ```cpp
   if(found) res++;
   ```
   After checking all characters in the word, if all characters were successfully matched, we increment the result counter `res`.

6. **Return the Result**:
   ```cpp
   return res;
   ```
   Finally, we return the count of words that are subsequences of `s`.

### Example Walkthrough

Let's go through an example to understand the solution better:

- **Input**:
  ```cpp
  s = "abcde", words = ["a", "bb", "acd", "ace", "bd"]
  ```

- **Preprocessing**:
  - We build the `srch` vector where each character in `s` is mapped to its indices:
    ```
    srch[0] = [0]    // 'a' at index 0
    srch[1] = [1]    // 'b' at index 1
    srch[2] = [2]    // 'c' at index 2
    srch[3] = [3]    // 'd' at index 3
    srch[4] = [4]    // 'e' at index 4
    ```

- **Matching Each Word**:
  1. `"a"`: We match 'a' at index 0, so it’s a subsequence. Increment `res` to 1.
  2. `"bb"`: We match 'b' at index 1 and 'b' again at index 1 (but there is no next occurrence of 'b'). This is not a subsequence. No increment.
  3. `"acd"`: We match 'a' at index 0, 'c' at index 2, and 'd' at index 3. This is a subsequence. Increment `res` to 2.
  4. `"ace"`: We match 'a' at index 0, 'c' at index 2, and 'e' at index 4. This is a subsequence. Increment `res` to 3.
  5. `"bd"`: We match 'b' at index 1, but there is no valid 'd' after it. This is not a subsequence. No increment.

- **Output**:
  The result is `3`, as the valid subsequences are `"a"`, `"acd"`, and `"ace"`.

### Complexity

- **Time Complexity**:
  - The preprocessing step takes **O(n)**, where `n` is the length of the string `s`, since we are iterating through `s` once.
  - For each word, we check every character, and for each character, we perform a binary search on the `srch` array (which contains the indices for each character). Since each binary search takes **O(log n)** time, and there are `m` words with each having at most `l` characters, the overall time complexity for processing the words is **O(m * l * log n)**, where `m` is the number of words and `l` is the average length of the words.
  
  Thus, the overall time complexity is **O(n + m * l * log n)**.

- **Space Complexity**:
  - The space complexity is dominated by the storage of the indices for each character in the string `s`. This takes **O(n)** space, where `n` is the length of `s`. Additionally, the space required to store the words is **O(m * l)**, where `m` is the number of words and `l` is the average length of the words.
  
  Hence, the space complexity is **O(n + m * l)**.

### Conclusion

This solution efficiently determines how many words in a given list are subsequences of a string `s`. By preprocessing the string `s` to store the positions of each character, we can check each word in the list in logarithmic time relative to the size of `s`. This results in a time complexity of **O(n + m * l * log n)**, which is much more efficient than a brute-force approach of checking each subsequence directly.

This method is highly scalable and can handle larger input sizes due to its efficient use of preprocessing and binary search. The space complexity is also reasonable, as it scales linearly with the length of `s` and the total number of characters in the list of words. Overall, this approach provides an optimal solution for checking subsequences in a given string.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-matching-subsequences/description/)

---
{{< youtube 0zMujz5SYoE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
