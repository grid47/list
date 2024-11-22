
+++
authors = ["grid47"]
title = "Leetcode 2027: Minimum Moves to Convert String"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2027: Minimum Moves to Convert String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "hCuwkDkAXYM"
youtube_upload_date="2021-10-03"
youtube_thumbnail="https://i.ytimg.com/vi/hCuwkDkAXYM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.length(), count = 0;
        while (i < n) {
            if (s[i] == 'O')
                i++;
            else
                count++, i += 3;
        }
        return count;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the minimum number of moves required to clear a string consisting of 'X' and 'O' characters. In each move, when encountering an 'X', we can clear that character along with the next two characters, effectively removing a sequence of three characters ('X' and the two characters immediately following it). The goal is to minimize the total number of moves required to eliminate all 'X' characters from the string.

### Approach

To solve this problem, we can utilize a straightforward iterative approach. We will traverse the string character by character, and every time we encounter an 'X', we will count it as a move and skip the next two characters since they will also be cleared in that move. If we encounter an 'O', we simply move to the next character. Here’s a step-by-step breakdown of the approach:

1. **Initialization**: Start with an index (`i`) set to 0 to track our position in the string, a variable (`count`) initialized to 0 to count the number of moves.

2. **Iterate Through the String**: Use a loop to iterate through each character in the string until we reach the end.

3. **Count Moves**:
   - If the current character is 'O', we move to the next character by incrementing `i`.
   - If the current character is 'X', we increment our move count (`count`), and skip the next two characters by advancing `i` by 3 (i.e., `i += 3`).

4. **Return Result**: After iterating through the string, we return the total count of moves.

### Code Breakdown (Step by Step)

Here is a detailed breakdown of the code implementation:

```cpp
class Solution {
public:
```
- We define the `Solution` class, which contains our method for solving the problem.

```cpp
    int minimumMoves(string s) {
```
- The method `minimumMoves` takes a string `s` as its parameter.

```cpp
        int i = 0, n = s.length(), count = 0;
```
- We initialize the index `i` to 0, `n` to the length of the string, and `count` to 0 for tracking the number of moves.

```cpp
        while (i < n) {
```
- We start a while loop that continues until `i` reaches the length of the string.

```cpp
            if (s[i] == 'O')
                i++;
```
- If the current character at index `i` is 'O', we simply move to the next character by incrementing `i`.

```cpp
            else
                count++, i += 3;
```
- If the current character is 'X', we increment our move count (`count`), and skip to the character three positions ahead (`i += 3`), effectively clearing 'X' and the next two characters.

```cpp
        }
        return count;
    }
};
```
- Once the loop exits (when all characters have been processed), we return the total move count.

### Complexity

- **Time Complexity**: The time complexity of this solution is O(n), where `n` is the length of the string `s`. This is because we are effectively scanning the string in a single pass, with each character being processed a constant number of times.

- **Space Complexity**: The space complexity is O(1), as we are only using a fixed number of variables (for indices and counters), independent of the input size.

### Conclusion

In conclusion, the `minimumMoves` method efficiently determines the minimum number of moves required to clear all 'X' characters from the string by utilizing a linear scanning approach. The logic of skipping characters when clearing an 'X' ensures that we account for the three-character clearing mechanism correctly. This solution demonstrates how a straightforward iteration can lead to an efficient and effective algorithm for problems involving string manipulation and counting. The implementation is optimal in terms of both time and space complexity, making it suitable for larger inputs as well.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-moves-to-convert-string/description/)

---
{{< youtube hCuwkDkAXYM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
