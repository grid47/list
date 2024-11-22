
+++
authors = ["grid47"]
title = "Leetcode 1208: Get Equal Substrings Within Budget"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1208: Get Equal Substrings Within Budget in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3lsT1Le526U"
youtube_upload_date="2024-05-28"
youtube_thumbnail="https://i.ytimg.com/vi/3lsT1Le526U/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int equalSubstring(string s, string t, int mxc) {
        vector<int> nums(s.size(), 0);
        for(int i = 0; i < s.size(); i++) {
            nums[i] = abs(s[i] - t[i]);
        }
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            mxc -= nums[i];
            while(mxc < 0) {
                mxc += nums[j++];
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The goal of the problem is to find the length of the longest substring that can be transformed from string `s` to string `t` with at most `mxc` character changes. Each character change in the substring can be thought of as a cost associated with the absolute difference between the characters in the two strings. For example, changing an 'a' to a 'd' incurs a cost of `3` because `| 'a' - 'd' | = 3`. We need to return the maximum length of the substring for which the total cost does not exceed `mxc`.

### Approach
To solve the problem, we can use a sliding window (or two-pointer) technique. The approach can be broken down into the following steps:
1. **Calculate Cost**: Create a list of costs for changing each character in `s` to the corresponding character in `t`.
2. **Sliding Window**: Utilize two pointers to maintain a window that keeps track of the total cost of changes. Adjust the window size based on whether the cost exceeds `mxc`.
3. **Maximize Length**: Throughout the process, keep track of the maximum length of valid substrings found.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int mxc) {
```
- **Lines 1-3**: Define the `Solution` class and the method `equalSubstring`, which takes two strings, `s` and `t`, and an integer `mxc` representing the maximum allowed cost of changes.

```cpp
        vector<int> nums(s.size(), 0);
        for(int i = 0; i < s.size(); i++) {
            nums[i] = abs(s[i] - t[i]);
        }
```
- **Lines 4-8**: Create a vector `nums` to store the cost of transforming each character from `s` to `t`. The absolute difference between characters at the same index is calculated and stored in `nums`. This results in a new array where each element corresponds to the cost of transforming the character in `s` to the character in `t`.

```cpp
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            mxc -= nums[i];
```
- **Lines 9-12**: Initialize `res` to hold the maximum length of the substring found, and `j` as the start of the sliding window. The outer `for` loop iterates over each index `i` in `nums`. In each iteration, the cost of the current character transformation is subtracted from `mxc`, reflecting the addition of this transformation cost to the current window.

```cpp
            while(mxc < 0) {
                mxc += nums[j++];
            }
```
- **Lines 13-15**: A `while` loop is employed to ensure that if the accumulated cost exceeds `mxc`, we slide the left end of the window (moving `j` to the right) and adjust `mxc` by adding back the costs of characters that are being excluded from the window.

```cpp
            res = max(res, i - j + 1);
        }
```
- **Lines 16-18**: After potentially adjusting the window size, we calculate the length of the current valid substring as `i - j + 1`. We update `res` to keep track of the maximum length found during the iterations.

```cpp
        return res;
    }
};
```
- **Lines 19-21**: Finally, return the result `res`, which contains the length of the longest substring that can be transformed under the specified constraints.

### Complexity
1. **Time Complexity**:
   - The solution iterates through the string twice, once to calculate costs and once to adjust the window size. Hence, the overall time complexity is \(O(n)\), where \(n\) is the length of the string `s`.

2. **Space Complexity**:
   - The space complexity is also \(O(n)\) due to the additional vector `nums` that stores the transformation costs for each character. In the worst case, this vector will have the same length as the input string.

### Conclusion
The `equalSubstring` function provides an efficient way to determine the maximum length of a substring that can be transformed from `s` to `t` with limited changes. By employing the sliding window technique, the solution manages to maintain a linear time complexity, making it suitable for larger strings. This approach efficiently balances between character transformation costs and the desired length of the substring, demonstrating the effectiveness of two-pointer techniques in solving similar string manipulation problems. Overall, this solution is both clear in its logic and efficient in its execution.

[`Link to LeetCode Lab`](https://leetcode.com/problems/get-equal-substrings-within-budget/description/)

---
{{< youtube 3lsT1Le526U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
