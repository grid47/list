
+++
authors = ["grid47"]
title = "Leetcode 2414: Length of the Longest Alphabetical Continuous Substring"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2414: Length of the Longest Alphabetical Continuous Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TBVr58ynqsI"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/TBVr58ynqsI/maxresdefault.webp"
comments = true
+++



---
Given a string 's' consisting of lowercase English letters, find the length of the longest substring where the characters are consecutive in the alphabet.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string 's'.
- **Example:** `s = "abcaz"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists of only lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest continuous substring of consecutive letters in the alphabet.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest substring of consecutive letters.

- 1. Initialize a variable 'x' to track the current length of the substring.
- 2. Iterate over the string 's', checking if each character is consecutive to the previous one.
- 3. If the current character is consecutive, increment 'x'.
- 4. If the current character is not consecutive, reset 'x' to 1.
- 5. Keep track of the maximum value of 'x' during the iteration.
{{< dots >}}
### Problem Assumptions ✅
- The string 's' is not empty.
- The input will only contain lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "abacada"`  \
  **Explanation:** The longest continuous alphabetical substring is 'ab', which has a length of 2. The 'ac' and 'ad' substrings are not consecutive.

{{< dots >}}
## Approach 🚀
The approach is to iterate through the string and check for consecutive letters. If consecutive, increase the count. If not, reset and continue.

### Initial Thoughts 💭
- We need to check each character against the previous one to determine if they are consecutive.
- The solution needs to iterate through the string once, so the complexity should be linear.
- This problem can be solved efficiently in linear time, as we only need a single scan through the string.
{{< dots >}}
### Edge Cases 🌐
- The input string will always have at least one character, as per the problem constraints.
- The solution must handle strings of length up to 100,000 efficiently.
- If the string contains only one character, the longest substring is the string itself with a length of 1.
- Ensure the solution runs in linear time due to the size constraints.
{{< dots >}}
## Code 💻
```cpp
int longestContinuousSubstring(string s) {
    int x = 1, ans = 1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i -1] +1) {
            x++;
        } else x = 1;
        ans = max(x, ans);
    }
    return ans;
}
```

This function finds the length of the longest continuous substring where each character is greater than the previous one by 1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int longestContinuousSubstring(string s) {
	```
	Function declaration for 'longestContinuousSubstring'. It takes a string 's' as input.

2. **Variable Initialization**
	```cpp
	    int x = 1, ans = 1;
	```
	Initialize two variables: 'x' to track the length of the current continuous substring, and 'ans' to store the maximum length found.

3. **Loop Start**
	```cpp
	    for(int i = 1; i < s.size(); i++) {
	```
	Loop through the string starting from the second character, checking the relationship between consecutive characters.

4. **Condition Check**
	```cpp
	        if(s[i] == s[i -1] +1) {
	```
	Check if the current character 's[i]' is exactly 1 greater than the previous character 's[i - 1]'.

5. **Increment Counter**
	```cpp
	            x++;
	```
	If the condition is true, increment the length of the current continuous substring.

6. **Reset Counter**
	```cpp
	        } else x = 1;
	```
	If the condition is false, reset the length of the current continuous substring to 1.

7. **Update Maximum**
	```cpp
	        ans = max(x, ans);
	```
	Update the maximum length found so far between the current substring length 'x' and the stored maximum 'ans'.

8. **Return Statement**
	```cpp
	    return ans;
	```
	Return the maximum length of the continuous substring found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we only need to traverse the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few integer variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/)

---
{{< youtube TBVr58ynqsI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
