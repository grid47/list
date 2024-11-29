
+++
authors = ["grid47"]
title = "Leetcode 2160: Minimum Sum of Four Digit Number After Splitting Digits"
date = "2024-04-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2160: Minimum Sum of Four Digit Number After Splitting Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wH9FIi-39-w"
youtube_upload_date="2022-02-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wH9FIi-39-w/maxresdefault.webp"
comments = true
+++



---
You are given a four-digit integer 'num'. Your task is to split this number into two new integers, 'new1' and 'new2', by rearranging its digits. The digits in 'num' must be used in their entirety, and leading zeros are allowed in 'new1' and 'new2'. Your goal is to return the minimum possible sum of 'new1' and 'new2'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer 'num', which is a four-digit number.
- **Example:** `num = 4312`
- **Constraints:**
	- 1000 <= num <= 9999

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the minimum possible sum of the two integers formed by rearranging the digits of 'num'.
- **Example:** `45`
- **Constraints:**
	- The sum of the two integers formed should be the minimum possible sum.

{{< dots >}}
### Core Logic 🔍
**Goal:** Rearrange the digits of 'num' to form two integers, and calculate their sum to minimize the result.

- Convert the integer 'num' to a string to access its digits.
- Sort the digits in ascending order.
- Form two integers by taking alternate digits from the sorted list and summing them.
- Return the sum of the two integers.
{{< dots >}}
### Problem Assumptions ✅
- The integer 'num' is a positive four-digit number.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: num = 4312`  \
  **Explanation:** By rearranging the digits of '4312', we can get pairs like [13, 42], [14, 32], [12, 43]. The smallest sum is obtained by the pair [13, 32], and their sum is 45.

- **Input:** `Example 2: num = 9503`  \
  **Explanation:** By rearranging the digits of '9503', we can get pairs such as [03, 95], [05, 93], [9, 503]. The pair [03, 95] yields the smallest sum of 38.

{{< dots >}}
## Approach 🚀
The approach is to sort the digits of 'num' in ascending order, then form two integers by taking alternate digits. This ensures that the sum of the two integers is minimized.

### Initial Thoughts 💭
- Sorting the digits ensures that we use the smallest available digits first, minimizing the sum.
- After sorting, alternating the digits between the two integers minimizes the sum of the two numbers.
{{< dots >}}
### Edge Cases 🌐
- The input will always be a four-digit number, so no special handling for empty inputs is required.
- As the input is always four digits, there is no need to handle extremely large inputs.
- The input will never have more than four digits, and the result will always be a valid sum.
- Ensure that the solution handles inputs within the range of 1000 to 9999 correctly.
{{< dots >}}
## Code 💻
```cpp
int minimumSum(int num){
    string s = to_string(num);
    sort(s.begin(), s.end());
    int res = (s[0] - '0' + s[1] - '0') * 10 + s[2] - '0' + s[3] - '0';
    return res;
}
```

This function takes a four-digit integer and returns the minimum sum formed by rearranging its digits into two two-digit numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumSum(int num){
	```
	Define a function `minimumSum` that accepts a single integer `num` as an argument.

2. **String Conversion**
	```cpp
	    string s = to_string(num);
	```
	Convert the integer `num` to a string `s` for easy manipulation of individual digits.

3. **Sorting**
	```cpp
	    sort(s.begin(), s.end());
	```
	Sort the string `s` in ascending order to arrange the digits in increasing order.

4. **Computation**
	```cpp
	    int res = (s[0] - '0' + s[1] - '0') * 10 + s[2] - '0' + s[3] - '0';
	```
	Compute the minimum sum by forming two numbers from the sorted digits and summing them.

5. **Return**
	```cpp
	    return res;
	```
	Return the computed result, which is the minimum sum of the two numbers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant because the input size is always fixed at four digits.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only need space to store the digits of the four-digit number.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/)

---
{{< youtube wH9FIi-39-w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
