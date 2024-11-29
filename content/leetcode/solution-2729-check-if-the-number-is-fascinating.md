
+++
authors = ["grid47"]
title = "Leetcode 2729: Check if The Number is Fascinating"
date = "2024-02-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2729: Check if The Number is Fascinating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "B1JUo4KREiU"
youtube_upload_date="2023-06-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/B1JUo4KREiU/maxresdefault.webp"
comments = true
+++



---
You are given a three-digit integer n. We define a number as fascinating if, when you concatenate n, 2 * n, and 3 * n, the resulting number contains all digits from 1 to 9 exactly once and does not contain any zeros.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A three-digit integer n.
- **Example:** `n = 192`
- **Constraints:**
	- 100 <= n <= 999

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the number is fascinating, otherwise return false.
- **Example:** `true`
- **Constraints:**
	- The result will be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if the concatenated number contains all digits from 1 to 9 exactly once without zeros.

- Concatenate n, 2 * n, and 3 * n into a single string.
- Check if the string contains exactly the digits 1 to 9 with no repetitions or zeros.
{{< dots >}}
### Problem Assumptions ✅
- n is always a valid three-digit number.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** For n = 192, concatenating 192, 384, and 576 gives 192384576, which contains all digits from 1 to 9 exactly once.

- **Input:** `Example 2`  \
  **Explanation:** For n = 100, concatenating 100, 200, and 300 gives 100200300, which contains zeros and doesn't satisfy the conditions.

{{< dots >}}
## Approach 🚀
The approach is to check if the concatenated number contains all the digits from 1 to 9 exactly once without any zeros.

### Initial Thoughts 💭
- The concatenated result must contain exactly the digits 1 through 9.
- We need to check if the concatenated string has the correct digits and no zeros.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since n is always a three-digit number.
- n is always between 100 and 999, so no large inputs to consider.
- Check for numbers like 100 or multiples that result in zeros in the concatenation.
- n must be a valid three-digit number.
{{< dots >}}
## Code 💻
```cpp
bool isFascinating(int n) {
    int n1 = 2 * n;
    int n2 = 3 * n;
    vector<bool> yes(10, false); 
    string s = to_string(n) + to_string(n1) + to_string(n2);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') return false;
        if(yes[s[i] - '0']) return false;
        yes[s[i] - '0'] = true;
    }
    return true;
}
```

This function checks if a number `n` is a fascinating number. A number is fascinating if the concatenation of `n`, `2*n`, and `3*n` contains all digits from 1 to 9 exactly once.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isFascinating(int n) {
	```
	The function `isFascinating` is defined, taking an integer `n` and returning a boolean indicating whether `n` is a fascinating number.

2. **Variable Initialization**
	```cpp
	    int n1 = 2 * n;
	```
	The variable `n1` is initialized to `2 * n`, which is used to create the concatenated string for further checks.

3. **Variable Initialization**
	```cpp
	    int n2 = 3 * n;
	```
	The variable `n2` is initialized to `3 * n`, representing the third part of the concatenated string.

4. **Array Initialization**
	```cpp
	    vector<bool> yes(10, false); 
	```
	A vector `yes` is initialized with 10 elements, all set to `false`. This will be used to track whether a digit from 1 to 9 has already appeared in the concatenated string.

5. **String Concatenation**
	```cpp
	    string s = to_string(n) + to_string(n1) + to_string(n2);
	```
	The integers `n`, `n1`, and `n2` are converted to strings and concatenated together to form the string `s`.

6. **Loop Start**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	A loop is initiated to iterate over each character of the concatenated string `s`.

7. **Zero Check**
	```cpp
	        if(s[i] == '0') return false;
	```
	If any character in the string is '0', the function returns `false`, as a fascinating number cannot contain the digit '0'.

8. **Repetition Check**
	```cpp
	        if(yes[s[i] - '0']) return false;
	```
	If the digit has already appeared in the string (tracked by the `yes` array), the function returns `false`, ensuring all digits are unique.

9. **Mark Digit as Seen**
	```cpp
	        yes[s[i] - '0'] = true;
	```
	The corresponding index in the `yes` vector is set to `true` to mark that digit as seen.

10. **Return True**
	```cpp
	    return true;
	```
	If the loop completes without returning `false`, the function returns `true`, indicating that the number `n` is a fascinating number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant since the operations do not depend on the size of the input beyond simple arithmetic and string checks.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only store a few integer variables and a string of fixed length.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-the-number-is-fascinating/description/)

---
{{< youtube B1JUo4KREiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
