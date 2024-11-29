
+++
authors = ["grid47"]
title = "Leetcode 2264: Largest 3-Same-Digit Number in String"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2264: Largest 3-Same-Digit Number in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "vcrOpJQHsSE"
youtube_upload_date="2023-12-04"
youtube_thumbnail="https://i.ytimg.com/vi/vcrOpJQHsSE/maxresdefault.jpg"
comments = true
+++



---
You are given a string `num` representing a large integer. A 'good' integer is defined as a substring of length 3, consisting of only one unique digit. Your task is to find the largest 'good' integer in the string. If no such integer exists, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `num` representing a large integer.
- **Example:** `num = "98711111234"`
- **Constraints:**
	- 3 <= num.length <= 1000
	- num only consists of digits.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest good integer as a string. If no such integer exists, return an empty string.
- **Example:** `Output: "111"`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum substring of length 3 that consists of only one unique digit.

- Iterate through the string starting from index 2 to check all possible substrings of length 3.
- For each substring, check if all characters are the same.
- If a valid substring is found, compare it with the current maximum substring to keep the largest.
- Return the largest valid substring or an empty string if no such substring is found.
{{< dots >}}
### Problem Assumptions ✅
- The string `num` will not be empty, as its length is always at least 3.
{{< dots >}}
## Examples 🧩
- **Input:** `num = "98711111234"`  \
  **Explanation:** In this case, the valid good integers are '111'. The largest good integer is '111', so the output is '111'.

- **Input:** `num = "223335"`  \
  **Explanation:** Here, the good integers are '333' and '222'. The largest good integer is '333', so the output is '333'.

- **Input:** `num = "12345"`  \
  **Explanation:** There are no substrings of length 3 that consist of only one unique digit. Therefore, the output is an empty string.

{{< dots >}}
## Approach 🚀
We will iterate through the string and check for substrings of length 3. If all the characters in the substring are the same, we will check if it's the largest one found so far.

### Initial Thoughts 💭
- We need to consider every substring of length 3 in the given string.
- The condition to check for a 'good' integer is simple: all characters in the substring must be the same.
- We can use a sliding window approach to check every substring of length 3 in one pass through the string.
{{< dots >}}
### Edge Cases 🌐
- The string `num` is guaranteed to have a length of at least 3, so there are no empty inputs.
- The solution should handle large strings efficiently, especially up to 1000 characters.
- Consider strings that have repeated digits like '000' or strings with no valid good integers.
- The solution should work within the time complexity constraints of strings with lengths up to 1000.
{{< dots >}}
## Code 💻
```cpp
string largestGoodInteger(string num) {
    char res = 0;
for(int i = 2; i < num.size(); ++i)
    if (num[i] == num[i - 1] && num[i] == num[i - 2])
        res = max(res, num[i]);
return res == 0 ? "" : string(3, res);
}
```

This function finds the largest good integer in a string, where a good integer is a substring of three consecutive identical digits. If found, it returns the good integer as a string; otherwise, it returns an empty string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string largestGoodInteger(string num) {
	```
	The function `largestGoodInteger` takes a string `num` as input and returns the largest good integer, which is a substring of three consecutive identical digits.

2. **Variable Initialization**
	```cpp
	    char res = 0;
	```
	The variable `res` is initialized to 0. It will hold the largest digit found that forms a good integer.

3. **For Loop**
	```cpp
	for(int i = 2; i < num.size(); ++i)
	```
	A for loop starts from index 2, iterating through the string `num` from the third character onward. This is to check for triplets of consecutive characters.

4. **Condition Check**
	```cpp
	    if (num[i] == num[i - 1] && num[i] == num[i - 2])
	```
	This condition checks if the current character and the previous two characters in the string are identical, indicating a good integer (a substring of three consecutive identical digits).

5. **Update Largest Good Integer**
	```cpp
	        res = max(res, num[i]);
	```
	If a good integer is found (three consecutive identical digits), the maximum of the current largest good integer (`res`) and the new character `num[i]` is stored in `res`.

6. **Return Result**
	```cpp
	return res == 0 ? "" : string(3, res);
	```
	After the loop, if no good integer was found (`res == 0`), the function returns an empty string. Otherwise, it returns a string consisting of the largest good integer, repeated three times.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we check each substring of length 3 once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a constant amount of space for tracking the largest good integer.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/)

---
{{< youtube vcrOpJQHsSE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
