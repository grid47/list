
+++
authors = ["grid47"]
title = "Leetcode 2124: Check if All A's Appears Before All B's"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2124: Check if All A's Appears Before All B's in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "RgzM3HRkdp8"
youtube_upload_date="2022-01-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RgzM3HRkdp8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
bool checkString(string s) {
        return s.find("ba")==string::npos;
    }
};
{{< /highlight >}}
---

### Problem Statement

The function `checkString` is designed to check if a given string `s` has all instances of the character `a` appearing before any instance of the character `b`. In other words, it verifies if the string maintains an "all `a`s before all `b`s" order. If any occurrence of `b` appears before an `a`, the function should return `false`; otherwise, it should return `true`.

### Approach

The solution leverages a straightforward approach by searching for the substring "ba" in the input string `s`. The substring "ba" would indicate a violation of the "all `a`s before all `b`s" order. By checking if "ba" exists in the string, we can quickly determine whether the ordering condition is violated. The function uses `std::string::find` to search for "ba", which returns `string::npos` if "ba" is not found. If "ba" is found, it means the string does not meet the required order, and the function returns `false`. If "ba" is not found, the function returns `true`, indicating the order is correct.

### Code Breakdown (Step by Step)

1. **Class Definition**: `class Solution` defines a class named `Solution`. This is standard in coding platforms like LeetCode, where the method is part of a solution class for encapsulation.

2. **Method Signature**: The method `bool checkString(string s)` is a public member function that takes a single string parameter `s` and returns a boolean value.

3. **Main Check Logic**: Inside `checkString`, the key operation is `s.find("ba") == string::npos`.
   - **`s.find("ba")`**: This call searches the string `s` for the first occurrence of the substring "ba".
   - **Comparison with `string::npos`**: `std::string::npos` is a constant in C++ representing a non-position (an invalid position). If `s.find("ba")` returns `string::npos`, it means "ba" was not found in `s`, indicating that `s` maintains the correct order of `a`s before `b`s. If "ba" is found, the condition fails, and the method returns `false`.

4. **Return Statement**: The function returns `true` if "ba" is not found (indicating all `a`s appear before all `b`s), or `false` otherwise.

### Complexity

- **Time Complexity**: The time complexity of the function is `O(n)`, where `n` is the length of the string `s`. This is because `std::string::find` performs a linear scan of the string to search for the substring "ba".
- **Space Complexity**: The space complexity is `O(1)` since the function uses a constant amount of extra space, without any auxiliary data structures.

### Conclusion

This code provides an efficient solution to check if all `a`s in a string appear before all `b`s by leveraging the presence or absence of the substring "ba". This concise approach avoids iterating through the string multiple times and offers a solution in linear time. The function performs the task in a single line, making it both compact and effective. This solution is suitable for cases where the input string is large, as it maintains optimal performance with `O(n)` time complexity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/)

---
{{< youtube RgzM3HRkdp8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
