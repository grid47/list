
+++
authors = ["grid47"]
title = "Leetcode 767: Reorganize String"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 767: Reorganize String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/767.webp"
youtube = "2g_b1aYTHeg"
youtube_upload_date="2021-12-27"
youtube_thumbnail="https://i.ytimg.com/vi/2g_b1aYTHeg/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/767.webp" 
    alt="A string where letters are reorganized, glowing softly as each valid move is made."
    caption="Solution to LeetCode 767: Reorganize String Problem"
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
    string reorganizeString(string s) {
        int mfq = 0, i = 0;
        
        vector<int> frq(26, 0);
        for(char c: s)
            if (++frq[c - 'a'] > frq[mfq])
                mfq = c - 'a';
        
        // if mfq over bounds return ""
        if(2 * frq[mfq] - 1 > s.size()) return "";
        /*  dist mfq across
            dist rest across */
        while(frq[mfq]) {
            s[i] = 'a' + mfq;
            i += 2;
            frq[mfq]--;
        }

        for(int j = 0; j < 26; j++) {
            while(frq[j]) {
                if(i >= s.size()) i = 1;
                s[i] = 'a' + j;
                frq[j]--;
                i += 2;
            }
        }
        
        return s;
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to reorganize a string `s` in such a way that no two adjacent characters are the same. If it is not possible to rearrange the string to satisfy this condition, the function should return an empty string. For example:

- Input: `"aab"`
- Output: `"aba"`

The goal is to find an efficient way to rearrange the string, or determine when it's impossible to do so, while making sure that no two identical characters are adjacent.

### Approach

To solve the problem, we can employ a greedy algorithm. Here's the high-level strategy:

1. **Frequency Count**: First, we need to calculate the frequency of each character in the string. This will help us identify if it's possible to reorganize the string. If any character appears more than half the length of the string (rounded up), it's impossible to rearrange the string, and we should return an empty string.

2. **Greedy Rearrangement**: After we determine that rearranging is possible, we will use the most frequent character first and place it in every other position. Then, we will place the remaining characters in the gaps created by the most frequent character.

3. **Rearranging Step**: 
   - We start by placing the most frequent character in the even-indexed positions.
   - Then, we proceed to place the remaining characters in the odd-indexed positions.

By ensuring that the most frequent character is placed first and spaced out as much as possible, we can prevent consecutive occurrences of the same character.

### Code Breakdown (Step by Step)

#### Step 1: Frequency Count

```cpp
vector<int> frq(26, 0);
for(char c: s)
    if (++frq[c - 'a'] > frq[mfq])
        mfq = c - 'a';
```

- We create an array `frq` of size 26 to store the frequency of each character in the string `s`.
- We also maintain a variable `mfq` to track the index of the character with the maximum frequency.
- As we iterate over the string, we update the frequency count of each character and check if the current character has a higher frequency than the previous maximum. If so, we update `mfq`.

#### Step 2: Check for Feasibility

```cpp
if(2 * frq[mfq] - 1 > s.size()) return "";
```

- After calculating the frequency of each character, we check if the most frequent character can be placed in the string such that no two identical characters are adjacent.
- If the count of the most frequent character is greater than half the size of the string (rounded up), then it's impossible to reorganize the string without having two adjacent identical characters. In this case, we return an empty string `""`.

#### Step 3: Place the Most Frequent Character

```cpp
while(frq[mfq]) {
    s[i] = 'a' + mfq;
    i += 2;
    frq[mfq]--;
}
```

- We now proceed to place the most frequent character (indexed by `mfq`) in the string. We start placing it in every other position, i.e., at even indices.
- For each placement, we decrement the frequency of the most frequent character (`frq[mfq]--`) and move to the next available position (`i += 2`).

#### Step 4: Place the Remaining Characters

```cpp
for(int j = 0; j < 26; j++) {
    while(frq[j]) {
        if(i >= s.size()) i = 1;
        s[i] = 'a' + j;
        frq[j]--;
        i += 2;
    }
}
```

- After placing all occurrences of the most frequent character, we proceed to place the remaining characters.
- For each character (from `a` to `z`), we check if it still has occurrences left (i.e., `frq[j]` is non-zero). If so, we place it in the next available position.
- If we reach the end of the string (i.e., `i >= s.size()`), we reset the position to 1 (odd indices) to fill the gaps between the already placed characters.
- We continue this process until all characters are placed.

#### Step 5: Return the Result

```cpp
return s;
```

- Once all characters are placed successfully, we return the rearranged string `s`.

### Complexity

#### Time Complexity:

- **O(n)**: The time complexity is linear with respect to the length of the string `n`. This is because:
  - We first iterate through the string to count the frequency of each character, which takes O(n) time.
  - Then, we iterate over the characters to place them in the result string, which takes another O(n) time.
  - The complexity is dominated by the linear pass through the string and frequency array.

#### Space Complexity:

- **O(1)**: The space complexity is constant because we only use a fixed-size array `frq` of size 26 to store character frequencies and a few integer variables. The space used does not depend on the size of the input string.

### Conclusion

This solution provides an efficient approach to solving the problem of rearranging a string such that no two adjacent characters are the same. The greedy approach ensures that the most frequent character is spaced out as much as possible, preventing consecutive identical characters. The algorithm works in linear time with constant space, making it both time and space-efficient for large inputs.

- **Time Complexity**: **O(n)**, where `n` is the size of the input string.
- **Space Complexity**: **O(1)**, as we use only a fixed number of auxiliary variables.

By implementing this approach, we can successfully reorganize the string or determine if it's impossible to do so efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/reorganize-string/description/)

---
{{< youtube 2g_b1aYTHeg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
