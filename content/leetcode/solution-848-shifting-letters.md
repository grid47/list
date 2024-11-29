
+++
authors = ["grid47"]
title = "Leetcode 848: Shifting Letters"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 848: Shifting Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
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
You are given a string `s` of lowercase English letters and an array `shifts`, where `shifts[i]` represents the number of times to shift the first `i + 1` characters of `s`. The shift operation for a letter means moving to the next letter in the alphabet, and if the letter is 'z', it wraps around to 'a'. After applying all the shifts, return the final string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` consisting of lowercase English letters and an integer array `shifts` of the same length. Each element of `shifts[i]` represents how many times you need to shift the first `i + 1` letters of `s`.
- **Example:** `Input: s = 'abc', shifts = [3, 5, 9]`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists of lowercase English letters.
	- shifts.length == s.length
	- 0 <= shifts[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the final string after applying all the shifts to `s` as specified by the array `shifts`.
- **Example:** `Output: 'rpl'`
- **Constraints:**
	- The final string is derived by applying the shifts progressively to the characters of `s`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the final string after applying all the shifts to the string `s`.

- Step 1: Process the shifts array by calculating cumulative shifts from the end of the string towards the beginning.
- Step 2: For each character in `s`, apply the shift operation by moving the character forward in the alphabet by the corresponding number of shifts (considering the wrap-around).
- Step 3: Return the resulting string after all shifts have been applied.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` contains only lowercase English letters.
- The length of the string `s` and the array `shifts` will always match.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'abc', shifts = [3, 5, 9]`  \
  **Explanation:** Initially, the string is 'abc'. After shifting the first 1 letter by 3, it becomes 'dbc'. Then, shifting the first 2 letters by 5 results in 'igc'. Finally, shifting the first 3 letters by 9 gives 'rpl'. Hence, the final result is 'rpl'.

- **Input:** `Input: s = 'aaa', shifts = [1, 2, 3]`  \
  **Explanation:** The string starts as 'aaa'. After shifting the first 1 letter by 1, it becomes 'b'. Then, shifting the first 2 letters by 2 gives 'd'. Finally, shifting the first 3 letters by 3 results in 'gfd'. Thus, the final result is 'gfd'.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we process the shifts in reverse order and apply cumulative shifts progressively to each character in the string.

### Initial Thoughts 💭
- The shifts for each character depend on the sum of shifts from the previous positions.
- Instead of repeatedly applying shifts from the start, we can accumulate shifts from the last character and apply them once in one pass.
- By calculating cumulative shifts backwards, we avoid redundant calculations and reduce the complexity of applying shifts.
{{< dots >}}
### Edge Cases 🌐
- The input string `s` will not be empty as per the problem constraints.
- Ensure the solution can handle the upper constraint where the length of `s` is 10^5 and shift values can be as large as 10^9.
- If the shift value is 0 for any index, the corresponding character will not be altered.
- The solution should be optimized to handle large shift values efficiently.
{{< dots >}}
## Code 💻
```cpp
string shiftingLetters(string s, vector<int>& shifts) {

    int n = shifts.size();
    for(int i = n - 2; i >= 0; i--)
    shifts[i] = (shifts[i] + shifts[i + 1] ) % 26;

    for(int i = 0; i < s.size(); i++)
    s[i] = 'a' + ((s[i] - 'a'+ shifts[i]) % 26);

    return s;
}
```

This function shifts the letters in the string `s` based on the shifts provided in the `shifts` vector, where each shift is cumulative from the end to the start.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string shiftingLetters(string s, vector<int>& shifts) {
	```
	The function `shiftingLetters` takes a string `s` and a vector `shifts` that specifies how much to shift each letter in `s`.

2. **Get Vector Size**
	```cpp
	    int n = shifts.size();
	```
	The size of the `shifts` vector is stored in `n`.

3. **Backward Cumulative Shifts**
	```cpp
	    for(int i = n - 2; i >= 0; i--)
	```
	Iterate backward through the `shifts` vector, from second-to-last element to the first.

4. **Cumulative Shift Update**
	```cpp
	    shifts[i] = (shifts[i] + shifts[i + 1] ) % 26;
	```
	Update each shift to include the shift of the next letter, making it cumulative. The modulo 26 ensures the shift stays within the bounds of the alphabet.

5. **Iterate Through String**
	```cpp
	    for(int i = 0; i < s.size(); i++)
	```
	Loop through each character in the string `s`.

6. **Apply Shift to Character**
	```cpp
	    s[i] = 'a' + ((s[i] - 'a'+ shifts[i]) % 26);
	```
	Shift each character in `s` by the corresponding value in the `shifts` vector, ensuring it wraps around the alphabet using modulo 26.

7. **Return Result**
	```cpp
	    return s;
	```
	Return the shifted string `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we only need to process the string once and calculate the shifts in one pass.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the shifts array and the modified string `s`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shifting-letters/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
