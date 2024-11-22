
+++
authors = ["grid47"]
title = "Leetcode 557: Reverse Words in a String III"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 557: Reverse Words in a String III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/557.webp"
youtube = "_I57bpDMWnY"
youtube_upload_date="2022-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/_I57bpDMWnY/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/557.webp" 
    alt="A string where the words are reversed, with each word glowing softly as it flips in place."
    caption="Solution to LeetCode 557: Reverse Words in a String III Problem"
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
    string reverseWords(string s) {
        int n = s.size(), prv = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == ' ')
                rev(s, prv, i - 1), prv = i + 1;
            else if(i == n - 1)
                rev(s, prv, i);        
        return s;
    }
    
    void rev(string &s, int i, int j) {
        while(i <= j)
            swap(s[i++], s[j--]);
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to reverse the words in a given string. A word is defined as a sequence of non-space characters separated by spaces. For instance, the string `"The sky is blue"` should be transformed into `"ehT yks si eulb"`, where each word in the string is reversed, but the words remain in their original positions. Additionally, leading and trailing spaces in the input string should be ignored, and multiple spaces between words should not appear in the output.

**Example 1:**

Input: `"The sky is blue"`  
Output: `"ehT yks si eulb"`

**Example 2:**

Input: `"  Hello  world "`  
Output: `"olleH dlrow"`

### Approach

The problem requires reversing each word in the string while preserving the order of the words. To achieve this, we need to:

1. **Iterate through the string**: We need to go through each character in the string and identify the start and end of each word.
2. **Reverse each word**: Once a word is identified, we reverse it.
3. **Skip spaces**: While iterating, we need to skip over spaces and ensure that only valid words are reversed.
4. **Handle edge cases**: The solution should handle multiple spaces, empty strings, and strings that only contain spaces.

### Code Breakdown (Step by Step)

#### 1. **Iterate Through the String**

```cpp
int n = s.size(), prv = 0;
for (int i = 0; i < n; i++)
```

- First, we determine the length of the string (`n`), and initialize a variable `prv` to track the starting index of each word. `prv` will be updated whenever a space is encountered to indicate the start of the next word.

#### 2. **Identify and Reverse Words**

```cpp
if (s[i] == ' ') 
    rev(s, prv, i - 1), prv = i + 1;
else if (i == n - 1) 
    rev(s, prv, i);
```

- If we encounter a space (`s[i] == ' '`), we reverse the word that we have encountered from the position stored in `prv` (the start of the word) to the position just before the space (`i - 1`). After reversing the word, we update `prv` to the position after the space, so it can point to the start of the next word.
  
- If we encounter the last character of the string (`i == n - 1`), we need to reverse the last word. Since there is no space at the end of the string, we reverse the word from `prv` to `i`.

#### 3. **Reversing Each Word**

```cpp
void rev(string &s, int i, int j) {
    while (i <= j)
        swap(s[i++], s[j--]);
}
```

- The `rev` function takes the string `s`, and two indices (`i` and `j`) that represent the boundaries of the word to be reversed. 
- The function swaps the characters at indices `i` and `j`, incrementing `i` and decrementing `j` after each swap. This process continues until `i` exceeds `j`, effectively reversing the word in place.
  
#### 4. **Return the Final String**

```cpp
return s;
```

- After iterating through the entire string and reversing all the words, the modified string `s` is returned, which contains the reversed words but in the original order.

### Complexity

#### Time Complexity:

The time complexity of the solution is **O(n)**, where `n` is the length of the string. This is because:
- We iterate through the string once to identify the start and end of each word.
- Each word is reversed using the `rev` function, and the reversal itself takes linear time relative to the length of the word. In the worst case, the total number of characters we reverse is equal to the length of the entire string.

Thus, the total time complexity is linear, **O(n)**.

#### Space Complexity:

The space complexity is **O(1)**, assuming that the space used by the string `s` is not counted. We are performing the reversal in place, so no additional space is used other than the space needed for the input string. Therefore, the space complexity is constant, **O(1)**.

### Conclusion

The solution provided efficiently solves the problem of reversing the words in a string while maintaining the order of the words. The steps are straightforward: we iterate through the string, identify words, reverse them, and return the modified string.

**Key Points:**
- **In-place word reversal**: The solution performs word reversal in place without needing extra space for a new string.
- **Handles multiple spaces**: Multiple spaces between words and leading/trailing spaces are properly handled.
- **Efficient**: The algorithm runs in **O(n)** time complexity and uses **O(1)** space, making it efficient and suitable for large input sizes.

**Edge Cases Handled:**
- Strings with multiple spaces between words.
- Empty strings.
- Strings with only spaces.
- Strings with a single word.

This approach is simple yet highly effective for reversing the words in a string. By using a two-pointer approach and performing the reversal in place, the solution minimizes space complexity while ensuring correctness.

[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-words-in-a-string-iii/description/)

---
{{< youtube _I57bpDMWnY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
