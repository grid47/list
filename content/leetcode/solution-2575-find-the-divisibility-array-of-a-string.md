
+++
authors = ["grid47"]
title = "Leetcode 2575: Find the Divisibility Array of a String"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2575: Find the Divisibility Array of a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kizI7M64xXQ"
youtube_upload_date="2023-02-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kizI7M64xXQ/maxresdefault.webp"
comments = true
+++



---
Given a string word consisting of digits and an integer m, return an array where each element is 1 if the numeric value of the prefix word[0,...,i] is divisible by m, otherwise 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string word and an integer m.
- **Example:** `For example, word = '2020', m = 4.`
- **Constraints:**
	- 1 <= n <= 10^5
	- word consists of digits from 0 to 9
	- 1 <= m <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array of 0s and 1s where each element denotes whether the corresponding prefix of word is divisible by m.
- **Example:** `For word = '123456789' and m = 7, the output is [0, 0, 0, 0, 0, 0, 0, 1, 0].`
- **Constraints:**
	- The length of the divisibility array is the same as the length of word.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if each prefix of the string word is divisible by m.

- 1. Initialize a variable num to store the current numeric value of the prefix.
- 2. For each digit in word, update num by multiplying the previous value by 10 and adding the current digit.
- 3. Check if num is divisible by m, if yes, set div[i] = 1, otherwise div[i] = 0.
{{< dots >}}
### Problem Assumptions ✅
- The word string is non-empty and consists of digits from '0' to '9'.
{{< dots >}}
## Examples 🧩
- **Input:** `For word = '2020' and m = 4, the output is [0, 1, 0, 1].`  \
  **Explanation:** The prefixes '20' and '2020' are divisible by 4.

{{< dots >}}
## Approach 🚀
The approach uses the cumulative computation of the prefix numeric values and checks for divisibility with m.

### Initial Thoughts 💭
- The problem requires checking divisibility for multiple prefixes efficiently.
- We can compute each prefix number iteratively and check divisibility in constant time.
{{< dots >}}
### Edge Cases 🌐
- The input word will always have at least one character.
- For large inputs (word length up to 10^5), the approach ensures efficient computation by processing each character in linear time.
- If m is a large number, ensure the calculations do not overflow (use modulo operation).
- Handle edge cases such as very small or very large values of m.
{{< dots >}}
## Code 💻
```cpp
vector<int> divisibilityArray(string word, int m) {
    int n = word.size();
    vector<int> ans(n, 0);
    long num = 0;
    for(int i = 0; i < n; i++) {
        num = num * 10 + (word[i] - '0');
        num %= m;
        if(num % m == 0) ans[i] = 1;
        else ans[i] = 0;
    }
    return ans;
}
```

This function computes an array where each index corresponds to whether the number formed by the prefix of the input string is divisible by a given integer `m`. It iterates through each character of the string and performs modular arithmetic to check divisibility.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> divisibilityArray(string word, int m) {
	```
	Declares the function `divisibilityArray` with a string input `word` and integer `m` as parameters. Returns a vector of integers.

2. **Initialize Length**
	```cpp
	    int n = word.size();
	```
	Calculates the size of the input string `word` and stores it in variable `n`.

3. **Initialize Result Array**
	```cpp
	    vector<int> ans(n, 0);
	```
	Creates a vector `ans` of size `n`, initialized with zeros, to store the divisibility results.

4. **Initialize Variable**
	```cpp
	    long num = 0;
	```
	Initializes a variable `num` to 0, which will be used to compute the cumulative number modulo `m`.

5. **Iterate String**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through each character of the string `word`.

6. **Update Cumulative Value**
	```cpp
	        num = num * 10 + (word[i] - '0');
	```
	Updates the cumulative number `num` by adding the current character's numerical value.

7. **Apply Modulo Operation**
	```cpp
	        num %= m;
	```
	Applies the modulo operation to `num` to ensure it remains within the range of `m`.

8. **Check Divisibility**
	```cpp
	        if(num % m == 0) ans[i] = 1;
	```
	Checks if `num` is divisible by `m`. If true, sets the corresponding index in `ans` to 1.

9. **Set Non Divisible**
	```cpp
	        else ans[i] = 0;
	```
	If `num` is not divisible by `m`, sets the corresponding index in `ans` to 0.

10. **Return Result**
	```cpp
	    return ans;
	```
	Returns the vector `ans` containing the divisibility results.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we process each character of the word exactly once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the array storing the divisibility results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/)

---
{{< youtube kizI7M64xXQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
