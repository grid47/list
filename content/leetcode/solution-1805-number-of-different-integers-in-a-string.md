
+++
authors = ["grid47"]
title = "Leetcode 1805: Number of Different Integers in a String"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1805: Number of Different Integers in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "1vZ2c92YgOc"
youtube_upload_date="2021-03-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1vZ2c92YgOc/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numDifferentIntegers(string w) {
        unordered_set<string> s{""};    
        for (int i = 0, j = 0; j <= w.size(); ++j) {
            if (j < w.size() && isdigit(w[j]))
                i += i < j && w[i] == '0';
            else {
                s.insert(w.substr(i, j - i));
                i = j + 1;
            }
        }
        return s.size() - 1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to find the number of different integers present in a given string `w`. The string may contain letters, digits, and possibly some special characters. The integers should be extracted from the string, ignoring leading zeros, and the uniqueness of the integers should be maintained in the counting process.

### Approach

To solve this problem, we will employ the following steps:

1. **Initialization**: We will use an unordered set to store unique integers extracted from the string. This set allows us to efficiently handle duplicate values.

2. **Iterate Through the String**: We will traverse the string character by character. When we encounter digits, we will determine the complete integer that can be formed.

3. **Extracting Integers**: We will extract the integers by slicing the string whenever we reach a non-digit character. Additionally, we will ensure that leading zeros are not counted, meaning we will skip any leading zeros when forming the integer.

4. **Store Unique Integers**: Each unique integer will be stored in the set.

5. **Count and Return**: Finally, we will return the size of the set minus one to account for the empty string, which is the default initialization of the set.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
    int numDifferentIntegers(string w) {
        unordered_set<string> s{""};    
```
- We define a class `Solution` with a public method `numDifferentIntegers` that takes a string `w` as input.
- We initialize an unordered set `s` that will hold unique strings representing integers. The set is initialized with an empty string to handle cases where no integers are found.

```cpp
        for (int i = 0, j = 0; j <= w.size(); ++j) {
            if (j < w.size() && isdigit(w[j]))
```
- We set up a loop where `i` and `j` are indices to traverse the string `w`.
- The loop runs until `j` reaches the end of the string (`w.size()`).
- The condition checks if the current character `w[j]` is a digit using the `isdigit` function.

```cpp
                i += i < j && w[i] == '0';
```
- This line adjusts the index `i` if the current character is a digit.
- Specifically, if `i` is less than `j` (meaning we are in a number) and the character at `i` is '0', we increment `i` to skip leading zeros.
  
```cpp
            else {
                s.insert(w.substr(i, j - i));
                i = j + 1;
            }
```
- If we reach a non-digit character (or the end of the string), we extract the substring from index `i` to `j`, representing the number we have formed.
- This substring is then inserted into the unordered set `s`.
- We also reset `i` to `j + 1` to prepare for the next segment of the string.

```cpp
        return s.size() - 1;
    }
};
```
- After processing the entire string, we return the size of the set `s` minus one to exclude the empty string we initially added.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(n)\), where \(n\) is the length of the string `w`. This is because we traverse the string exactly once.
  
- **Space Complexity**: The space complexity is also \(O(n)\) in the worst case, where all characters are digits and we could potentially store all integers as separate entries in the set.

### Conclusion

This solution efficiently extracts unique integers from a string containing various characters using an unordered set to ensure that each integer is counted only once. By carefully managing the indices and handling leading zeros, the implementation correctly identifies and counts all distinct integers present in the input string.

The algorithm demonstrates the utility of string manipulation and set data structures in solving problems related to counting and uniqueness, which is a common theme in competitive programming and algorithm design. 

Overall, this approach is not only optimal but also clear and concise, making it a solid solution for the problem of counting different integers in a mixed-character string.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-different-integers-in-a-string/description/)

---
{{< youtube 1vZ2c92YgOc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
