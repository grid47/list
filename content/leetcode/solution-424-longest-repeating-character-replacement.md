
+++
authors = ["grid47"]
title = "Leetcode 424: Longest Repeating Character Replacement"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 424: Longest Repeating Character Replacement in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/424.webp"
youtube = "tkNWKvxI3mU"
youtube_upload_date="2024-03-09"
youtube_thumbnail="https://i.ytimg.com/vi/tkNWKvxI3mU/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/424.webp" 
    alt="A string with a character being replaced to form the longest substring, glowing softly with each change."
    caption="Solution to LeetCode 424: Longest Repeating Character Replacement Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> ma;
        int res = 0, j = 0, mx = 0;
        for(int i =  0; i < s.size(); i++) {
            ma[s[i]]++;
            mx = max(mx, ma[s[i]]);
            if(i - j + 1 > mx + k) {
                ma[s[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the length of the longest substring in a given string `s` that can be transformed into a substring where all characters are the same, by replacing at most `k` characters. We are provided a string `s` and an integer `k`, representing the maximum number of character replacements allowed. The goal is to determine the length of the longest possible substring after performing the replacements.

### Approach

To solve this problem efficiently, we can use the **sliding window technique** combined with a frequency count of characters. The idea is to maintain a window of characters such that:
1. The number of replacements needed to make all characters within the window identical does not exceed `k`.
2. We aim to maximize the length of the window under this constraint.

Here’s how the approach works step by step:
1. **Sliding Window**: We maintain a window defined by two pointers, `j` (the start of the window) and `i` (the end of the window). The window will expand as we iterate over the string with the `i` pointer, and we adjust the `j` pointer to maintain the validity of the window.
2. **Character Count**: As we expand the window by moving `i`, we count the frequency of each character in the window using a `map`. The frequency count helps determine how many characters in the current window are not equal to the most frequent character.
3. **Replacement Condition**: The key observation is that if the number of characters that need to be changed to make all characters the same in the window exceeds `k`, we adjust the window by moving `j` to the right, thereby shrinking the window until the condition is satisfied again.
4. **Max Length Calculation**: During each iteration, we calculate the length of the current window and update the result if the length is greater than the previous maximum.

### Code Breakdown (Step by Step)

#### Step 1: Initialization

```cpp
map<char, int> ma;
int res = 0, j = 0, mx = 0;
```
- We initialize a map `ma` to store the frequency count of characters within the current window.
- `res` is used to keep track of the maximum length of the valid substring found.
- `j` is the starting pointer of the sliding window.
- `mx` stores the maximum frequency of any character within the current window.

#### Step 2: Expanding the Window

```cpp
for(int i = 0; i < s.size(); i++) {
    ma[s[i]]++;
    mx = max(mx, ma[s[i]]);
```
- We start iterating over the string `s` using the `i` pointer.
- For each character `s[i]`, we increment its count in the map `ma`.
- We also update `mx` to be the maximum frequency of any character in the current window (from `j` to `i`).

#### Step 3: Checking Window Validity

```cpp
if(i - j + 1 > mx + k) {
    ma[s[j]]--;
    j++;
}
```
- The condition `i - j + 1 > mx + k` checks if the length of the current window exceeds the number of allowed replacements (`k`). If it does, this means we need more than `k` replacements to make all characters the same in the window.
- In this case, we shrink the window by incrementing `j` (move the left pointer of the window) and reducing the frequency count of the character at `s[j]`.

#### Step 4: Update Maximum Length

```cpp
res = max(res, i - j + 1);
```
- After adjusting the window, we update the result `res` with the maximum length of the valid substring found so far. The length of the current window is `i - j + 1`.

#### Step 5: Return the Result

```cpp
return res;
```
- Finally, we return the value of `res`, which is the length of the longest substring where we can make all characters the same with at most `k` replacements.

### Complexity

#### Time Complexity:
- The time complexity of this algorithm is **O(n)**, where `n` is the length of the string `s`. This is because both the `i` and `j` pointers move from the start to the end of the string, and each pointer moves at most `n` times. The `map` operations (insertion and updating the frequency) are efficient with average time complexity of **O(1)**, as the number of unique characters is limited to the alphabet size (which is constant).

#### Space Complexity:
- The space complexity is **O(1)** with respect to the input size, as the map `ma` stores the frequency of characters, and the maximum number of unique characters in the string is limited (26 lowercase English letters). Therefore, the space used by the map is constant.

### Conclusion

The given solution efficiently solves the problem of finding the longest substring that can be transformed into a string with identical characters using at most `k` replacements. The sliding window technique combined with character frequency counting allows us to explore the solution in linear time, making the algorithm optimal for large inputs. With a space complexity of **O(1)**, the solution is also memory-efficient.

By utilizing this approach, we ensure that we handle both the constraints of the problem and edge cases, such as strings with all identical characters or strings where replacements are not needed.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-repeating-character-replacement/description/)

---
{{< youtube tkNWKvxI3mU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
