
+++
authors = ["grid47"]
title = "Leetcode 1239: Maximum Length of a Concatenated String with Unique Characters"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1239: Maximum Length of a Concatenated String with Unique Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d4SPuvkaeoo"
youtube_upload_date="2021-09-22"
youtube_thumbnail="https://i.ytimg.com/vi/d4SPuvkaeoo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for(auto &s: arr) {
            bitset<26> a;
            for(char x: s)
                a.set(x-'a');
            int n = a.count();
            if(n < s.size()) continue;
            for(int i = dp.size() -1; i >= 0; i--) {
                bitset c = dp[i];
                if ((c&a).any()) continue;
                dp.push_back(c|a);
                res = max(res, (int) c.count()+n);
                
            }
        }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The objective of the problem is to find the maximum length of a concatenated string formed from an array of strings, such that all characters in the resulting string are unique. Each string in the input array can be used at most once. The challenge lies in ensuring that no character appears more than once in the final concatenated string while maximizing its length.

### Approach
To tackle this problem, we can use a bit manipulation technique. Each string will be represented as a bitset, where each bit indicates the presence or absence of a character (from 'a' to 'z'). By utilizing a bitset, we can efficiently check for character overlaps between strings.

1. **Bitset Representation**: Each string is converted into a bitset of size 26 (one for each letter in the alphabet). If a character is present in the string, the corresponding bit in the bitset is set to 1.

2. **Dynamic Programming**: We maintain a dynamic programming array (`dp`) which stores all possible unique character combinations formed by the strings processed so far.

3. **Combination Logic**: For each string's bitset representation, we attempt to combine it with all previously stored bitsets in `dp`. If there is no overlap (i.e., the AND operation between two bitsets is zero), we can combine them.

4. **Count Unique Characters**: After each valid combination, we calculate the total number of unique characters and keep track of the maximum length found.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
```
- **Lines 1-4**: We define the `Solution` class and declare the public method `maxLength`, which takes a vector of strings `arr` as input. We initialize a vector of bitsets `dp`, starting with an empty bitset to represent the initial state. A variable `res` is initialized to store the maximum length of unique characters found.

```cpp
        for(auto &s: arr) {
            bitset<26> a;
            for(char x: s)
                a.set(x-'a');
```
- **Lines 5-8**: We loop through each string `s` in the array. For each string, we create a bitset `a` and set bits corresponding to each character in the string. The expression `x - 'a'` converts a character to its corresponding index (0 for 'a', 1 for 'b', etc.).

```cpp
            int n = a.count();
            if(n < s.size()) continue;
```
- **Lines 9-10**: We count the number of unique characters in the string using `a.count()`. If the count is less than the string's length (indicating duplicate characters), we skip the current string with `continue`.

```cpp
            for(int i = dp.size() -1; i >= 0; i--) {
                bitset c = dp[i];
                if ((c&a).any()) continue;
```
- **Lines 11-14**: We loop through the `dp` array in reverse. For each stored bitset `c`, we check if there is any overlap with the current string's bitset `a` using the AND operation. If there is an overlap, we skip the combination.

```cpp
                dp.push_back(c|a);
                res = max(res, (int) c.count()+n);
```
- **Lines 15-16**: If the bitsets can be combined, we push the new bitset (resulting from the OR operation between `c` and `a`) into the `dp` array. We then update `res` with the maximum length found, calculated as the count of characters in `c` plus the count of characters in `a`.

```cpp
            }
        }
        return res;
    }
};
```
- **Lines 17-20**: After processing all strings, we return the maximum length stored in `res`.

### Complexity
1. **Time Complexity**: The time complexity of this solution is \( O(n \cdot m) \), where \( n \) is the number of strings in the input array and \( m \) is the average length of the strings. This complexity arises because for each string, we potentially check against all previously stored combinations in `dp`.

2. **Space Complexity**: The space complexity is \( O(2^k) \) in the worst case, where \( k \) is the number of unique characters present across all strings. This accounts for the size of the `dp` vector that stores unique character combinations.

### Conclusion
The `maxLength` function effectively utilizes bit manipulation and dynamic programming to find the maximum length of a concatenated string with unique characters from an array of strings. By representing each string as a bitset, the solution allows for efficient overlap checks and combinations. This approach not only ensures correctness but also maintains performance, making it suitable for solving similar problems involving character uniqueness and permutations. The simplicity of the bitset operations leads to a clear and concise implementation, contributing to both readability and maintainability of the code.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/)

---
{{< youtube d4SPuvkaeoo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
