
+++
authors = ["grid47"]
title = "Leetcode 3042: Count Prefix and Suffix Pairs I"
date = "2024-01-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3042: Count Prefix and Suffix Pairs I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Trie","Rolling Hash","String Matching","Hash Function"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wDPL8oM9rO8"
youtube_upload_date="2024-02-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wDPL8oM9rO8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> wds;
    
    bool pre(int i, int j) {
        int p = 0, q = 0;
        if(wds[j].size() < wds[i].size()) return false;
        while(p < wds[i].size() && q < wds[j].size() && wds[i][p] == wds[j][q]) {
            p++; q++;
        }
        return p == wds[i].size();
    }
    
    bool post(int i, int j) {
        int p = wds[i].size() - 1, q = wds[j].size() - 1;
        if(p > q) return false;
        while(p >= 0  && q >= 0 && wds[i][p] == wds[j][q]) {
            p--; q--;
        }
        return p == -1;
    }    
    
    int countPrefixSuffixPairs(vector<string>& w) {
        wds = w;
        int n = w.size(), cnt = 0;
        
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(pre(i, j) && post(i, j)) cnt++;
        
        return cnt;
        
    }
};
{{< /highlight >}}
---

### Problem Statement:

Given a list of strings, the task is to count the number of pairs of strings where one string is a prefix and a suffix of the other. Specifically, for each string pair `(i, j)`, check if:
1. String `wds[i]` is a prefix of string `wds[j]`.
2. String `wds[i]` is also a suffix of string `wds[j]`.

The goal is to return the count of such pairs.

### Approach:

To solve this problem, we will need to implement two functions: `pre` and `post` that check if one string is a prefix or a suffix of another. Once these helper functions are defined, we will iterate through all pairs of strings in the list and use these functions to check the condition for each pair. If both conditions are satisfied, we increment the count.

#### Key Concepts:
- **Prefix**: A string `A` is a prefix of string `B` if the beginning of `B` matches the whole string `A`.
- **Suffix**: A string `A` is a suffix of string `B` if the ending of `B` matches the whole string `A`.
- **String Iteration**: To compare the prefix and suffix, we use simple iteration over the characters of the two strings.

### Code Breakdown:

#### Step 1: Define Helper Functions - `pre` and `post`
```cpp
bool pre(int i, int j) {
    int p = 0, q = 0;
    if(wds[j].size() < wds[i].size()) return false;
    while(p < wds[i].size() && q < wds[j].size() && wds[i][p] == wds[j][q]) {
        p++; q++;
    }
    return p == wds[i].size();
}

bool post(int i, int j) {
    int p = wds[i].size() - 1, q = wds[j].size() - 1;
    if(p > q) return false;
    while(p >= 0  && q >= 0 && wds[i][p] == wds[j][q]) {
        p--; q--;
    }
    return p == -1;
}
```

- **`pre(int i, int j)`**:
    - This function checks if string `wds[i]` is a prefix of string `wds[j]`. 
    - We start by comparing the characters of both strings from the beginning. If all characters of `wds[i]` match the starting characters of `wds[j]`, then `wds[i]` is a prefix of `wds[j]`.
    - The function returns `true` if the prefix condition is satisfied (i.e., all characters of `wds[i]` match the start of `wds[j]`), and `false` otherwise.

- **`post(int i, int j)`**:
    - This function checks if string `wds[i]` is a suffix of string `wds[j]`. 
    - We start by comparing the characters from the end of both strings. If all characters of `wds[i]` match the ending characters of `wds[j]`, then `wds[i]` is a suffix of `wds[j]`.
    - The function returns `true` if the suffix condition is satisfied (i.e., all characters of `wds[i]` match the end of `wds[j]`), and `false` otherwise.

#### Step 2: Main Function - `countPrefixSuffixPairs`
```cpp
int countPrefixSuffixPairs(vector<string>& w) {
    wds = w;
    int n = w.size(), cnt = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(pre(i, j) && post(i, j)) cnt++;
    
    return cnt;
}
```

- **`countPrefixSuffixPairs(vector<string>& w)`**:
    - The main function takes a vector of strings `wds` (renamed `w` in the argument) and counts the pairs of strings where one is both a prefix and a suffix of the other.
    - We store the input vector `w` in a class variable `wds` to be used by the helper functions `pre` and `post`.
    - We iterate over all pairs `(i, j)` where `i < j` to avoid counting the same pair twice.
    - For each pair, we call both `pre(i, j)` and `post(i, j)` to check if `wds[i]` is both a prefix and a suffix of `wds[j]`. If both conditions are satisfied, we increment the count `cnt`.
    - Finally, we return the count of valid pairs.

### Time Complexity:

1. **Prefix and Suffix Check (Functions `pre` and `post`)**:
    - Both `pre` and `post` functions iterate over the characters of the strings involved in the comparison. In the worst case, each of these functions takes `O(m)` time, where `m` is the size of the larger string.
    - Thus, the total time complexity for checking both the prefix and suffix conditions for a pair of strings is `O(m)`.

2. **Double Loop Iteration**:
    - The function iterates over all pairs of strings `(i, j)` where `i < j`. There are `O(n^2)` such pairs where `n` is the number of strings in the input.
    - For each pair, the `pre` and `post` functions are called, which takes `O(m)` time for each pair, where `m` is the average length of the strings.

3. **Overall Time Complexity**:
    - The total time complexity is the product of the number of pairs `O(n^2)` and the time taken to check each pair `O(m)` (where `m` is the maximum length of a string).
    - Therefore, the overall time complexity is **O(n^2 * m)**, where `n` is the number of strings and `m` is the length of the longest string in the list.

### Space Complexity:

- The space complexity is dominated by the input storage, which is `O(n * m)`, where `n` is the number of strings and `m` is the average length of each string.
- Additionally, there are variables used for indexing and storing the results, but they do not significantly impact the space complexity.

### Conclusion:

This solution efficiently solves the problem of counting pairs of strings that are both prefixes and suffixes of each other. The use of helper functions `pre` and `post` ensures that each pair is checked in linear time relative to the length of the strings. The overall time complexity is quadratic in the number of strings, making it feasible for moderately sized input lists. By optimizing string comparison with efficient iteration, this approach achieves correctness and performance while keeping the space usage manageable.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/)

---
{{< youtube wDPL8oM9rO8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
