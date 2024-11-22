
+++
authors = ["grid47"]
title = "Leetcode 2901: Longest Unequal Adjacent Groups Subsequence II"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2901: Longest Unequal Adjacent Groups Subsequence II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DJaTr0BnG1Q"
youtube_upload_date="2023-10-14"
youtube_thumbnail="https://i.ytimg.com/vi/DJaTr0BnG1Q/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) dp[i].push_back(i);

        int longest_length = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] == groups[j]) continue;
                if (words[i].size() != words[j].size()) continue;
                if (getHammingDistance(words[i], words[j]) != 1) continue;

                if ((dp[j].size() + 1) > dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(i);
                    longest_length = max(longest_length, int(dp[i].size()));
                }
            }
        }

        vector<string> result;
        for (int i = 0; i < n; i++) {
            if (dp[i].size() == longest_length) {
                for (const int& x : dp[i]) result.push_back(words[x]);
                break;
            }
        }
        return result;
    }
private:
    int getHammingDistance(const string& s, const string& t) {
        int dist = 0;
        int k = s.size();
        for (int i = 0; i < k; i++) {
            if (s[i] != t[i]) dist++;
        }
        return dist;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the longest subsequence of words from a given list where each word is part of a unique group and differs from the previous word by exactly one character (i.e., Hamming Distance = 1). Given the constraints, the solution should efficiently compute and return this longest subsequence of words.

### Approach

To tackle this problem, the algorithm employs dynamic programming (DP) to store subsequences as it iterates through each word in the list. Here’s the approach in detail:

1. **Initialize DP Table**:
   - We set up a DP table (`dp`) where each entry `dp[i]` will hold the longest subsequence ending at the `i`-th word.
   - Initially, each `dp[i]` entry contains only the index `i`, indicating each word as a subsequence of itself.

2. **Iterate Through Words**:
   - We iterate over each word `i` from `1` to `n - 1` (where `n` is the total number of words) and check every previous word `j` (from `0` to `i - 1`).
   - The goal here is to check if the word at index `i` can extend the subsequence ending at `j` by meeting the following conditions:
     - **Different Groups**: The two words should belong to different groups (checked using the `groups` array).
     - **Equal Lengths**: The words should have the same length to compare each character.
     - **Hamming Distance of 1**: The words must differ by exactly one character.

3. **Update DP and Track Longest Subsequence**:
   - If the above conditions are satisfied, we check if the subsequence ending at `j` can be extended to form a longer subsequence ending at `i`.
   - If yes, we update `dp[i]` by copying the subsequence from `dp[j]` and appending `i` to it.
   - We also update `longest_length` to track the maximum length of subsequences encountered so far.

4. **Retrieve Result**:
   - Finally, we look for the subsequence in `dp` that has the length equal to `longest_length`.
   - We gather the words corresponding to the indices in this subsequence and return them as the result.

### Code Breakdown (Step by Step)

#### Step 1: Initialize DP Table

```cpp
vector<vector<int>> dp(n);
for (int i = 0; i < n; i++) dp[i].push_back(i);
```

- Here, we initialize `dp`, a vector of vectors, where each `dp[i]` is initialized to hold the index `i`, representing that each word is initially considered as a single-element subsequence.

#### Step 2: Iterate Through Words and Build Subsequences

```cpp
int longest_length = 1;
for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (groups[i] == groups[j]) continue;
        if (words[i].size() != words[j].size()) continue;
        if (getHammingDistance(words[i], words[j]) != 1) continue;
```

- For each word `i`, we look at each previous word `j`. 
- We skip `j` if `groups[i]` equals `groups[j]` (same group), or if the word lengths don’t match, or if the Hamming Distance is not exactly `1`.

#### Step 3: Update DP Array if Conditions are Met

```cpp
if ((dp[j].size() + 1) > dp[i].size()) {
    dp[i] = dp[j];
    dp[i].push_back(i);
    longest_length = max(longest_length, int(dp[i].size()));
}
```

- If extending the subsequence ending at `j` creates a longer subsequence ending at `i`, we update `dp[i]` and record the `longest_length`.

#### Step 4: Retrieve and Return Result

```cpp
vector<string> result;
for (int i = 0; i < n; i++) {
    if (dp[i].size() == longest_length) {
        for (const int& x : dp[i]) result.push_back(words[x]);
        break;
    }
}
return result;
```

- After iterating, we check each entry in `dp` to find a subsequence that matches `longest_length`.
- We then collect the words in this subsequence and return them.

#### Helper Function: Compute Hamming Distance

```cpp
int getHammingDistance(const string& s, const string& t) {
    int dist = 0;
    int k = s.size();
    for (int i = 0; i < k; i++) {
        if (s[i] != t[i]) dist++;
    }
    return dist;
}
```

- This helper function calculates the Hamming Distance between two strings by comparing each character.

### Complexity

#### Time Complexity

- **Main Iteration**: The nested loop that compares each pair of words has a time complexity of `O(n^2)`.
- **Hamming Distance Calculation**: Each call to `getHammingDistance` takes `O(L)`, where `L` is the length of each word. Given `n` words, the worst case is `O(n^2 * L)`.

#### Space Complexity

- **DP Array**: The `dp` array uses `O(n^2)` space, where each `dp[i]` stores the longest subsequence of word indices ending at `i`.

### Conclusion

This solution provides an efficient approach to finding the longest subsequence of words with a Hamming Distance of 1 and different group affiliations. The DP technique optimizes the subsequence formation by checking only necessary conditions and updating the longest subsequence dynamically. This allows the algorithm to perform efficiently, even with larger inputs, while ensuring that the constraints of unique groups and minimal character differences are met.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/)

---
{{< youtube DJaTr0BnG1Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
