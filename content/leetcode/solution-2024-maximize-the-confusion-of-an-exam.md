
+++
authors = ["grid47"]
title = "Leetcode 2024: Maximize the Confusion of an Exam"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2024: Maximize the Confusion of an Exam in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XYJv2pySK44"
youtube_upload_date="2021-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XYJv2pySK44/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int ans = 1;
        int fidx = 0, tidx = 0, fcnt = 0, tcnt = 0;
        for(int i = 0; i < key.size(); i++) {
            if(key[i] == 'F') fcnt++;
            else tcnt++;
            while(fcnt > k) {
                if(key[tidx] == 'F') fcnt--;
                tidx++;
            }
            ans = max(ans, i - tidx + 1);
            while(tcnt > k) {
                if(key[fidx] == 'T') tcnt--;
                fidx++;
            }
            ans = max(ans, i - fidx + 1);            
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to find the maximum length of a substring within a given string, `key`, which consists of characters 'T' and 'F'. The substring can contain at most `k` 'F' characters, and any number of 'T' characters. Essentially, we want to determine the longest segment of the string where we can replace at most `k` 'F' characters with 'T', while maintaining the sequence of characters.

### Approach

To tackle this problem, we can employ a sliding window (or two-pointer) technique. This method allows us to efficiently explore the string while keeping track of the counts of 'T' and 'F'. Here's the step-by-step breakdown of the approach:

1. **Initialization**: We start by initializing variables to keep track of the maximum length of the substring (`ans`), the frequency of 'F' and 'T' characters within the current window (`fcnt` and `tcnt`), and the indices for the start (`fidx` and `tidx`) of the window.

2. **Iterate Over the String**: We loop through each character in the string using a single pointer (`i`). For each character, we update the counts of 'F' and 'T'.

3. **Adjust Window for 'F' Count**: If the count of 'F' characters exceeds `k`, we increment the starting index of the window (`tidx`) until the count of 'F' is at most `k`. This adjustment ensures that we only consider valid substrings.

4. **Calculate Maximum Length**: After adjusting the window, we calculate the length of the valid substring (where we can have at most `k` 'F' characters) and update `ans` if this new length is greater than the previous maximum.

5. **Adjust Window for 'T' Count**: Similarly, we perform another check for 'T' characters, adjusting the starting index of the window (`fidx`) when the count of 'T' exceeds `k`.

6. **Return Result**: Finally, we return the maximum length found.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

```cpp
class Solution {
public:
```
- The `Solution` class encapsulates the method for solving the problem.

```cpp
    int maxConsecutiveAnswers(string key, int k) {
```
- We define a public method `maxConsecutiveAnswers` that takes a string `key` and an integer `k`.

```cpp
        int ans = 1;
        int fidx = 0, tidx = 0, fcnt = 0, tcnt = 0;
```
- We initialize `ans` to track the maximum length of valid substrings, `fidx` and `tidx` as the starting indices for the window, and `fcnt` and `tcnt` to count occurrences of 'F' and 'T', respectively.

```cpp
        for(int i = 0; i < key.size(); i++) {
```
- We start a loop that iterates through each character in the string `key`.

```cpp
            if(key[i] == 'F') fcnt++;
            else tcnt++;
```
- For each character, we increment the corresponding counter (`fcnt` for 'F' and `tcnt` for 'T') based on whether the character is 'F' or 'T'.

```cpp
            while(fcnt > k) {
                if(key[tidx] == 'F') fcnt--;
                tidx++;
            }
```
- If the count of 'F' exceeds `k`, we adjust the starting index `tidx` to reduce the count of 'F' back to `k` by moving the left boundary of the window to the right.

```cpp
            ans = max(ans, i - tidx + 1);
```
- After adjusting for 'F', we calculate the length of the current valid substring and update `ans` if this length is greater than the previous maximum.

```cpp
            while(tcnt > k) {
                if(key[fidx] == 'T') tcnt--;
                fidx++;
            }
```
- Next, we check the count of 'T'. If it exceeds `k`, we increment the starting index `fidx` to adjust the window accordingly.

```cpp
            ans = max(ans, i - fidx + 1);            
        }
```
- We again calculate the current valid substring's length and update `ans` if needed.

```cpp
        return ans;
    }
};
```
- Finally, we return the maximum length found.

### Complexity

- **Time Complexity**: The time complexity of this solution is O(n), where `n` is the length of the string `key`. This is because each character is processed a constant number of times (once while expanding the window and potentially once while contracting it).
  
- **Space Complexity**: The space complexity is O(1), as we are only using a fixed number of variables to store counts and indices, regardless of the input size.

### Conclusion

In conclusion, the `maxConsecutiveAnswers` method efficiently finds the longest substring that can contain at most `k` 'F' characters by utilizing a sliding window technique. This approach minimizes unnecessary computations by adjusting the window dynamically, ensuring we always have a valid substring. The use of two pointers (or indices) allows us to handle varying conditions in the string without resorting to nested loops, thus achieving optimal performance. This solution effectively demonstrates how to leverage simple counting mechanisms to solve a problem involving substring manipulation within linear time complexity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/)

---
{{< youtube XYJv2pySK44 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
