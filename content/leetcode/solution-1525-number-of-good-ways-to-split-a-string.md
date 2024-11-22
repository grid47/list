
+++
authors = ["grid47"]
title = "Leetcode 1525: Number of Good Ways to Split a String"
date = "2024-06-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1525: Number of Good Ways to Split a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lRVpVUC5mQ4"
youtube_upload_date="2020-09-14"
youtube_thumbnail="https://i.ytimg.com/vi/lRVpVUC5mQ4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSplits(string s) {
        map<char, int> left, right;
        
        int n = s.size();
        for(int i = 0; i < n; i++)
            right[s[i]]++;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            left[s[i]]++;
            right[s[i]]--;
            if(right[s[i]] == 0) right.erase(s[i]);
            if(left.size() == right.size()) cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine the number of ways to split a given string into two non-empty substrings such that both substrings have the same number of distinct characters. For example, for the string "aacaba", it can be split into "a" | "acaba", "aa" | "caba", "aac" | "aba", and so on. We need to count all such valid splits.

### Approach

To solve this problem, we will utilize a two-pointer technique along with hash maps to keep track of the distinct characters on both sides of the split.

1. **Character Count**: We will maintain two maps (or hash maps) to count the frequency of characters in the left and right substrings.
  
2. **Initialize the Right Map**: Initially, populate the right map with the frequency of all characters in the string. This allows us to keep track of characters that are yet to be considered in the left substring.

3. **Iterate and Update**: As we iterate through the string:
   - Move the current character from the right map to the left map.
   - Update the counts accordingly.
   - Check if the number of distinct characters in both maps is equal.

4. **Count Valid Splits**: Each time the number of distinct characters in both substrings is equal, increment the count.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
    int numSplits(string s) {
        map<char, int> left, right;
```
- We define the `Solution` class and the public method `numSplits` which takes a string `s` as input.
- We declare two maps, `left` and `right`, to keep track of the frequency of characters on the left and right sides of the split.

```cpp
        int n = s.size();
        for(int i = 0; i < n; i++)
            right[s[i]]++;
```
- We retrieve the size of the string `n`.
- We populate the `right` map with the frequency of each character in the string by iterating through `s`.

```cpp
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            left[s[i]]++;
            right[s[i]]--;
```
- We initialize a counter `cnt` to count the valid splits.
- We begin another loop to iterate through the string again:
  - For each character `s[i]`, we increment its count in the `left` map.
  - We decrement its count in the `right` map.

```cpp
            if(right[s[i]] == 0) right.erase(s[i]);
```
- If the count of `s[i]` in the `right` map becomes zero, we erase it from the map. This helps in keeping track of distinct characters effectively.

```cpp
            if(left.size() == right.size()) cnt++;
        }
```
- We then check if the sizes of the `left` and `right` maps are equal. If they are, it indicates that we have found a valid split, and we increment the counter `cnt`.

```cpp
        return cnt;
    }
};
```
- Finally, we return the count of valid splits found.

### Complexity

#### Time Complexity
- The time complexity of this solution is \(O(n)\), where \(n\) is the length of the string. This is because we perform a single pass through the string to populate the right map and another pass to compute the valid splits.

#### Space Complexity
- The space complexity is \(O(k)\), where \(k\) is the number of distinct characters in the string. In the worst case, if all characters are distinct, the space used by the hash maps could be equal to the length of the string.

### Conclusion

This solution efficiently counts the number of ways to split a string into two parts with the same number of distinct characters using a combination of hash maps and a linear traversal of the string.

**Key Insights**:
- **Two-pointer Technique**: By maintaining character counts on both sides of the split, we can efficiently check the condition without needing nested loops.
- **Hash Map Usage**: Using maps allows us to dynamically update counts and check sizes in constant time, which is crucial for maintaining performance.
- **Distinct Character Counting**: The solution effectively leverages the properties of distinct character counting to quickly find valid splits.

In summary, this approach demonstrates a clear and efficient method to solve the problem of counting valid splits in a string based on character distinctness, which can be applied to various similar string manipulation problems in competitive programming.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/description/)

---
{{< youtube lRVpVUC5mQ4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
