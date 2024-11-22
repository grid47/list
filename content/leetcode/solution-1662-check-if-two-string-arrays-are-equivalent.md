
+++
authors = ["grid47"]
title = "Leetcode 1662: Check If Two String Arrays are Equivalent"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1662: Check If Two String Arrays are Equivalent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ejBwc2oE7ck"
youtube_upload_date="2023-12-01"
youtube_thumbnail="https://i.ytimg.com/vi/ejBwc2oE7ck/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        for(auto x:word1)
            a += x;
        for(auto x:word2)
            b += x;
       
        if(a == b)
            return 1;
        
        return 0;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine whether two string arrays, `word1` and `word2`, can be considered equal by concatenating the strings in each array. Each array contains multiple strings, and the goal is to check if the concatenated string formed from the elements of `word1` is the same as the concatenated string formed from the elements of `word2`. The function should return `true` if they are equal and `false` otherwise.

### Approach

To solve this problem, we can follow a straightforward approach:

1. **Initialize two strings**: Create two empty strings to hold the concatenated results of the string arrays `word1` and `word2`.
2. **Concatenate elements**: Iterate through each array and concatenate its elements into the respective string.
3. **Compare the strings**: After concatenating both arrays, compare the two strings.
4. **Return the result**: Return `true` if the strings are equal; otherwise, return `false`.

This approach is efficient and easy to understand, leveraging the string concatenation capabilities of the C++ Standard Library.

### Code Breakdown (Step by Step)

Let's break down the implementation step by step:

```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
```
- The `Solution` class defines a public method `arrayStringsAreEqual`, which takes two parameters: `word1` and `word2`, both of type `vector<string>`. These vectors represent the arrays of strings that we need to compare.

```cpp
        string a,b; // Initialize two empty strings
```
- We declare two empty strings `a` and `b`. These strings will be used to store the concatenated results of `word1` and `word2`, respectively.

```cpp
        for(auto x:word1) // Iterate through word1
            a += x; // Concatenate elements into string a
```
- A range-based for loop iterates through each string `x` in `word1`. For each string, we append it to the string `a` using the `+=` operator. This results in `a` holding the complete concatenated string from `word1`.

```cpp
        for(auto x:word2) // Iterate through word2
            b += x; // Concatenate elements into string b
```
- Similarly, we iterate through each string `x` in `word2` and concatenate it to the string `b`, resulting in `b` holding the complete concatenated string from `word2`.

```cpp
        if(a == b) // Compare the two concatenated strings
            return 1; // Return true if they are equal
```
- We compare the two concatenated strings `a` and `b`. If they are equal, we return `true` (represented as `1` in C++).

```cpp
        return 0; // Return false if they are not equal
    }
};
```
- If the strings are not equal, we return `false` (represented as `0` in C++).

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n + m)\), where \(n\) is the total number of characters in `word1`, and \(m\) is the total number of characters in `word2`. This is because we are traversing through each array once to concatenate the strings.
  
- **Space Complexity**: The space complexity is \(O(n + m)\) as well, due to the storage of the concatenated strings `a` and `b`. This space is needed to hold the final results before comparison.

### Conclusion

The `arrayStringsAreEqual` method efficiently determines whether two arrays of strings are equivalent by concatenating their elements and comparing the resulting strings. The approach is simple yet effective, utilizing the power of C++ string manipulation to achieve the goal with minimal overhead.

**Key Takeaways**:
1. **Simplicity**: The solution's simplicity makes it easy to implement and understand, ideal for situations where readability is a priority.
2. **Efficiency**: With linear time complexity, this approach is efficient for reasonably sized inputs, making it suitable for many practical scenarios.
3. **C++ Features**: The use of range-based loops and string concatenation showcases some of the modern features of C++ that enhance code clarity and conciseness.

Overall, this implementation is an excellent example of using basic data structures to solve a problem efficiently, demonstrating that sometimes the simplest solutions are the most effective. The logic is straightforward, allowing for quick debugging and potential extensions should the problem requirements evolve.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/)

---
{{< youtube ejBwc2oE7ck >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
