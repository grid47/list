
+++
authors = ["grid47"]
title = "Leetcode 984: String Without AAA or BBB"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 984: String Without AAA or BBB in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given two integers a and b, generate a string of length a + b such that the string contains exactly a 'a' letters and exactly b 'b' letters, while ensuring the substring 'aaa' and 'bbb' do not appear.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers a and b, representing the number of occurrences of 'a' and 'b' in the desired string.
- **Example:** `a = 2, b = 3`
- **Constraints:**
	- 0 <= a, b <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string s that satisfies the conditions outlined in the problem statement.
- **Example:** `Output: 'abbab'`
- **Constraints:**
	- The output string should have exactly a 'a' letters and b 'b' letters.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to construct a string that follows the specified conditions without violating the 'aaa' and 'bbb' substrings constraint.

- Start by adding 'a' characters in a balanced way with 'b' characters to avoid consecutive 'a' or 'b' characters.
- Ensure that at no point do the number of 'a' characters exceed those of 'b' by more than 2 or vice versa.
- Interleave 'a' and 'b' characters as needed, making sure that the string does not contain 'aaa' or 'bbb'.
{{< dots >}}
### Problem Assumptions ✅
- The string must be constructed in such a way that it adheres to the rules of avoiding 'aaa' and 'bbb'.
{{< dots >}}
## Examples 🧩
- **Input:** `a = 2, b = 3`  \
  **Explanation:** In this case, a valid output is 'abbab', which avoids 'aaa' and 'bbb' while ensuring the correct number of 'a' and 'b' characters.

{{< dots >}}
## Approach 🚀
The solution involves constructing a string by alternating between 'a' and 'b' while ensuring the constraints on consecutive occurrences of 'a' and 'b' are met.

### Initial Thoughts 💭
- We need to construct the string without causing the substring 'aaa' or 'bbb' to appear.
- We can start by interleaving 'a' and 'b', and then adjust the string as necessary to ensure the constraints are maintained.
- A greedy approach can work well, ensuring that we alternate between 'a' and 'b' without violating the constraints.
{{< dots >}}
### Edge Cases 🌐
- If a or b is 0, the string should just consist of the remaining characters.
- If a and b are large (close to 100), the approach should still ensure that no 'aaa' or 'bbb' substrings appear.
- Consider cases where a and b are equal, or where one is much larger than the other.
- Ensure the solution handles cases with both small and large values of a and b.
{{< dots >}}
## Code 💻
```cpp
string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
    if(B > A) return strWithout3a3b(B, A, b, a);
    while(A-- > 0) {
        res += a;
        if(A > B) res += a, A--;
        if(B-->0) res += b;
    }
    return res;
}
```

This code defines a function `strWithout3a3b` that generates a string of `a`s and `b`s such that there are no three consecutive occurrences of either character. It balances the characters to prevent three consecutive identical ones.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
	```
	Defines the function `strWithout3a3b`, which takes two integers `A` and `B`, representing the counts of characters `a` and `b`, respectively, and ensures no three consecutive `a`s or `b`s in the result string.

2. **Recursive Call for Swapping**
	```cpp
	    if(B > A) return strWithout3a3b(B, A, b, a);
	```
	If `B` is greater than `A`, the function swaps the roles of `a` and `b` (and their counts) to ensure the function always processes the character with the larger count first.

3. **Main Loop Start**
	```cpp
	    while(A-- > 0) {
	```
	A loop that runs while there are still `a`s to add to the result string. It decreases the count of `a` with each iteration.

4. **Add Character A**
	```cpp
	        res += a;
	```
	Appends the character `a` to the result string `res`.

5. **Check If More A's Should Be Added**
	```cpp
	        if(A > B) res += a, A--;
	```
	If there are more `a`s remaining than `b`s, the function appends one more `a` to the result and decrements `A`.

6. **Add Character B**
	```cpp
	        if(B-->0) res += b;
	```
	If `B` (count of `b`s) is greater than 0, append a `b` to the result string and decrement `B`.

7. **Return Result**
	```cpp
	    return res;
	```
	Returns the final result string `res` that contains no more than two consecutive `a`s or `b`s.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(a + b)
- **Average Case:** O(a + b)
- **Worst Case:** O(a + b)

The time complexity is linear in the total number of 'a' and 'b' characters, which is the length of the resulting string.

### Space Complexity 💾
- **Best Case:** O(a + b)
- **Worst Case:** O(a + b)

The space complexity is O(a + b), as we need to store the result string of length a + b.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/string-without-aaa-or-bbb/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
