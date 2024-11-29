
+++
authors = ["grid47"]
title = "Leetcode 1156: Swap For Longest Repeated Character Substring"
date = "2024-07-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1156: Swap For Longest Repeated Character Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0kfkOm4b-8I"
youtube_upload_date="2023-01-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0kfkOm4b-8I/maxresdefault.webp"
comments = true
+++



---
You are given a string `text`. You can swap two characters in the string. The task is to find the length of the longest substring with repeated characters after the swap.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `text` containing lowercase English characters.
- **Example:** `Input: text = "abcba"`
- **Constraints:**
	- 1 <= text.length <= 20,000
	- text consists of lowercase English characters only

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the length of the longest substring with repeated characters after one swap.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be the maximum length of a substring with repeated characters after one swap.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the longest substring of repeated characters after performing one swap of any two characters in the string.

- Create an array to track the indices of each character in the string.
- Iterate through each character and calculate the longest repeated substring that can be achieved by swapping characters.
- Consider the best result by swapping any two characters and return the maximum length of the substring.
{{< dots >}}
### Problem Assumptions ✅
- We are allowed to swap exactly two characters in the string.
- Only lowercase English characters are involved.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: text = "abcba"`  \
  **Explanation:** By swapping the first 'b' with the last 'a', we get the string 'ababc'. The longest substring of repeated characters is 'aaa', with a length of 3.

{{< dots >}}
## Approach 🚀
We will use a greedy approach to check for possible swaps and calculate the longest repeated substring in each case.

### Initial Thoughts 💭
- We need to check the effect of swapping characters and calculate the resulting longest repeated substring for each swap.
- A greedy approach might work well here, iterating over possible swaps and computing the result in each case.
{{< dots >}}
### Edge Cases 🌐
- If the string length is 1, the longest repeated substring is the entire string.
- Ensure the solution can handle the largest possible string size efficiently.
- Consider cases where the string is already a substring of repeated characters, so no swap is needed.
- Handle strings with both small and large lengths efficiently.
{{< dots >}}
## Code 💻
```cpp
int maxRepOpt1(string text, int res = 1) {
    vector<vector<int>> idx(26);
    for(int i = 0; i < text.size(); i++)
        idx[text[i] - 'a'].push_back(i);

    for(int n = 0; n < 26; n++) {
        auto cnt = 1, cnt1 = 0, mx = 0;
        for(auto i = 1; i < idx[n].size(); i++) {
            if(idx[n][i] == idx[n][i - 1]+ 1) ++cnt;
            else {
                cnt1 = idx[n][i] == idx[n][i-1] + 2? cnt:0;
                cnt = 1;
            }
            mx = max(mx, cnt + cnt1);
        }
        res = max(res, mx + ( idx[n].size() > mx ? 1 : 0) );
    }
    return res;
}
```

This function implements a solution for the problem 'Maximize the Length of a Repeated Substring After One Operation'. It uses a greedy strategy combined with dynamic tracking of consecutive characters to compute the maximum possible length of a substring that can be achieved by performing at most one operation of swapping a single character.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int maxRepOpt1(string text, int res = 1) {
	```
	Define the function `maxRepOpt1` which calculates the maximum length of a repeated substring that can be obtained by changing at most one character in the string.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> idx(26);
	```
	Declare a 2D vector `idx` with 26 inner vectors, each corresponding to one letter of the alphabet. This will store the indices of occurrences of each letter in the input string.

3. **Loop Initialization**
	```cpp
	    for(int i = 0; i < text.size(); i++)
	```
	Loop through each character of the string `text` to record the indices of each character's occurrence in the corresponding subvector of `idx`.

4. **Index Tracking**
	```cpp
	        idx[text[i] - 'a'].push_back(i);
	```
	For each character in the string, subtract the ASCII value of 'a' to get the index of the character (0 for 'a', 1 for 'b', etc.), and append the current index `i` to the corresponding subvector in `idx`.

5. **Main Loop**
	```cpp
	    for(int n = 0; n < 26; n++) {
	```
	Loop through all 26 possible characters (from 'a' to 'z') to analyze the occurrences of each character in the string.

6. **Variable Initialization**
	```cpp
	        auto cnt = 1, cnt1 = 0, mx = 0;
	```
	Initialize variables: `cnt` to track the length of consecutive occurrences of a character, `cnt1` to track the length of possible gaps, and `mx` to store the maximum length found for the current character.

7. **Loop Through Indices**
	```cpp
	        for(auto i = 1; i < idx[n].size(); i++) {
	```
	Loop through the list of indices for the current character to identify consecutive occurrences and handle potential gaps between occurrences.

8. **Consecutive Check**
	```cpp
	            if(idx[n][i] == idx[n][i - 1]+ 1) ++cnt;
	```
	Check if the current index is exactly one greater than the previous index, indicating a consecutive occurrence. If true, increment the `cnt` variable.

9. **Non-Consecutive Check**
	```cpp
	            else {
	```
	If the current index is not consecutive with the previous one, enter this branch to handle non-consecutive occurrences.

10. **Gap Handling**
	```cpp
	                cnt1 = idx[n][i] == idx[n][i-1] + 2? cnt:0;
	```
	Check if the gap between the current index and the previous one is exactly 1 (indicating one character is missing). If true, set `cnt1` to the value of `cnt` to allow for a potential swap, otherwise reset `cnt1`.

11. **Reset Counter**
	```cpp
	                cnt = 1;
	```
	Reset the `cnt` variable to 1 as the consecutive sequence has been broken.

12. **Max Length Update**
	```cpp
	            mx = max(mx, cnt + cnt1);
	```
	Update the maximum length `mx` by considering the sum of the consecutive length `cnt` and the possible gap length `cnt1`.

13. **Result Update**
	```cpp
	        res = max(res, mx + ( idx[n].size() > mx ? 1 : 0) );
	```
	Update the result `res` by considering the maximum length found for the current character, and if there is one more occurrence of the character, add 1 to the result.

14. **Return Result**
	```cpp
	    return res;
	```
	Return the result `res`, which is the maximum length of the repeated substring that can be obtained with at most one character change.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we may need to check all possible swaps, which could involve iterating over all pairs of characters.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is determined by the storage of indices for each character.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/swap-for-longest-repeated-character-substring/description/)

---
{{< youtube 0kfkOm4b-8I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
