
+++
authors = ["grid47"]
title = "Leetcode 3146: Permutation Difference between Two Strings"
date = "2023-12-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3146: Permutation Difference between Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "fHFotCayOiU"
youtube_upload_date="2024-05-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fHFotCayOiU/maxresdefault.webp"
comments = true
+++



---
You are given two strings, `s` and `t`, where every character occurs at most once in both strings and `t` is a permutation of `s`. The permutation difference between `s` and `t` is defined as the sum of the absolute differences between the index of each character in `s` and the index of the occurrence of the same character in `t`. Your task is to compute the permutation difference between `s` and `t`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings `s` and `t`.
- **Example:** `Example 1:
Input: s = "xys", t = "syx"
Output: 2`
- **Constraints:**
	- 1 <= s.length <= 26
	- Each character occurs at most once in `s`.
	- t is a permutation of `s`.
	- s consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the permutation difference between `s` and `t`.
- **Example:** `Example 1:
Input: s = "xys", t = "syx"
Output: 2`
- **Constraints:**
	- The output should be the sum of the absolute differences of character indices in `s` and `t`.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the permutation difference, iterate over each character in `s` and find the corresponding index in `t`, then calculate the absolute difference in indices.

- Iterate through each character in string `s`.
- For each character in `s`, find its index in string `t`.
- Compute the absolute difference between the indices of each character in `s` and `t`.
- Sum these absolute differences and return the result.
{{< dots >}}
### Problem Assumptions ✅
- The input strings `s` and `t` are permutations of each other.
- Each character in `s` and `t` occurs only once.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** For `s = "abc"` and `t = "bac"`, the permutation difference is the sum of absolute differences between indices of characters: |0 - 1| + |1 - 0| + |2 - 2| = 2.

- **Input:** `Example 2:`  \
  **Explanation:** For `s = "abcdef"` and `t = "dfecba"`, the permutation difference is: |0 - 4| + |1 - 3| + |2 - 5| + |3 - 2| + |4 - 1| + |5 - 0| = 12.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves iterating through the string `s`, locating the index of each character in `t`, and calculating the sum of the absolute differences of indices.

### Initial Thoughts 💭
- The problem requires comparing character positions in two strings and calculating the sum of the differences.
- Since `t` is a permutation of `s`, the character order is shuffled, and finding the index difference will give the required result.
{{< dots >}}
### Edge Cases 🌐
- Both strings `s` and `t` will never be empty.
- The solution should handle strings of length up to 26 efficiently.
- The solution should handle cases where characters are shifted by several positions in `t`.
- Ensure the solution handles cases where `s` and `t` are minimal (length 1).
{{< dots >}}
## Code 💻
```cpp
int findPermutationDifference(string s, string t) {
    int sum=0;
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<t.length();j++)
        {
            if(s[i]==t[j])
             sum+=abs(i-j);
        }
    }
    return sum;
}
```

This is the complete code for the function 'findPermutationDifference', which calculates the sum of absolute differences in indices of matching characters between two strings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int findPermutationDifference(string s, string t) {
	```
	Defines the function header for 'findPermutationDifference', taking two string parameters 's' and 't'.

2. **Variable Declaration**
	```cpp
	    int sum=0;
	```
	Initializes a variable 'sum' to store the total of the absolute differences between the indices of matching characters.

3. **Outer Loop**
	```cpp
	    for(int i=0;i<s.length();i++)
	```
	Starts the outer loop that iterates through each character in string 's'.

4. **Inner Loop**
	```cpp
	        for(int j=0;j<t.length();j++)
	```
	Starts the inner loop that iterates through each character in string 't'.

5. **Condition Check**
	```cpp
	            if(s[i]==t[j])
	```
	Checks if the characters at position 'i' in string 's' and position 'j' in string 't' are equal.

6. **Sum Calculation**
	```cpp
	             sum+=abs(i-j);
	```
	If the characters are equal, it calculates the absolute difference between their indices and adds it to 'sum'.

7. **Return Statement**
	```cpp
	    return sum;
	```
	Returns the value of 'sum', which contains the total of the absolute differences between the indices of matching characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, where `n` is the length of the input strings, as each character is processed once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to storing the indices of characters in `t`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/permutation-difference-between-two-strings/description/)

---
{{< youtube fHFotCayOiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
