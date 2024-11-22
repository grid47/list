
+++
authors = ["grid47"]
title = "Leetcode 1784: Check if Binary String Has at Most One Segment of Ones"
date = "2024-05-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1784: Check if Binary String Has at Most One Segment of Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "CRjRphrOkNA"
youtube_upload_date="2021-03-07"
youtube_thumbnail="https://i.ytimg.com/vi/CRjRphrOkNA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkOnesSegment(string s) {

        // without leading zeros mean starting with 1s
        // if another set of one comes, there be definitely a 01
        // thats all
        return string::npos == s.find("01");
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine whether a binary string contains a single contiguous segment of `1`s. The string consists only of characters `0` and `1`. A string is considered to have a single segment of `1`s if:
- It starts with `1` (without leading zeros).
- It contains only one uninterrupted series of `1`s, with `0`s either at the beginning, end, or between the segments but not splitting the `1`s into multiple segments.

For example:
- The string `"110"` has a single segment of `1`s.
- The string `"1001"` does not have a single segment of `1`s, as it contains two segments separated by `0`s.
- The string `"000"` has no segments of `1`s and is considered valid because it doesn't contradict the condition.

### Approach

The solution to this problem can be approached using a straightforward string manipulation technique. Specifically, the key insight is to identify if the string contains the substring `"01"`. The presence of this substring indicates that there is a transition from a segment of `1`s to `0`s, followed by another segment of `1`s, thus violating the condition for a single contiguous segment of `1`s.

The steps involved in the approach are:
1. Use the `find` function to search for the substring `"01"` in the input string.
2. If `"01"` is found, return `false`, indicating that there are multiple segments of `1`s.
3. If `"01"` is not found, return `true`, indicating that the string contains a single contiguous segment of `1`s or none at all.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
```
- A class `Solution` is defined with a public method `checkOnesSegment` that takes a string `s` as input.

```cpp
        // without leading zeros mean starting with 1s
        // if another set of one comes, there be definitely a 01
        // thats all
```
- A comment explaining the logic of the solution: if there is no leading zero and the string has another segment of `1`s, then it will definitely contain the substring `"01"`.

```cpp
        return string::npos == s.find("01");
    }
};
```
- The line utilizes the `find` method of the string class to check for the occurrence of the substring `"01"`.
- `string::npos` is a constant representing a non-position, which indicates that the substring was not found. 
- The expression `string::npos == s.find("01")` evaluates to `true` if `"01"` is not found in the string, meaning there is a single segment of `1`s or none.
- The method returns `true` if there is only one segment of `1`s; otherwise, it returns `false`.

### Complexity

- **Time Complexity**: 
  - The time complexity of this solution is \(O(n)\), where \(n\) is the length of the string. The `find` method scans through the string to locate the substring `"01"`, which requires examining each character in the worst case.

- **Space Complexity**: 
  - The space complexity is \(O(1)\) as we are not using any additional data structures that grow with the size of the input string. The only memory used is for the string itself and a few local variables.

### Conclusion

The solution effectively solves the problem of checking for a single contiguous segment of `1`s in a binary string with minimal complexity. By leveraging string manipulation techniques, it achieves the desired functionality in an efficient manner.

This implementation provides a clear example of how to apply basic string operations to solve a problem related to segments in binary representations. The simplicity of the approach also highlights the importance of understanding string properties, especially in programming challenges involving sequences of characters. 

Overall, this code serves as a strong reference for similar problems involving string segments and is beneficial for individuals looking to enhance their understanding of string manipulation and efficient problem-solving strategies.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/)

---
{{< youtube CRjRphrOkNA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
