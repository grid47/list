
+++
authors = ["grid47"]
title = "Leetcode 1540: Can Convert String in K Moves"
date = "2024-06-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1540: Can Convert String in K Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3psLUZqiGx0"
youtube_upload_date="2020-08-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3psLUZqiGx0/maxresdefault.webp"
comments = true
+++



---
You are given two strings `s` and `t` and a number `k`. Your task is to convert string `s` into string `t` using no more than `k` moves. In each move, you can choose an index `j` (1-based) from string `s` and shift the character at that index by `i` positions, where `i` is the current move number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings `s` and `t`, both of length n, and an integer `k`.
- **Example:** `s = 'abc', t = 'bcd', k = 6`
- **Constraints:**
	- 1 <= s.length, t.length <= 10^5
	- 0 <= k <= 10^9
	- s, t contain only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if it's possible to convert `s` into `t` in no more than `k` moves. Otherwise, return `false`.
- **Example:** `Output: true`
- **Constraints:**
	- The conversion is possible if the total shifts required for each character are within the available `k` moves.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if it's possible to convert `s` into `t` with no more than `k` moves.

- 1. Iterate over the strings `s` and `t` to calculate the shift required for each character in `s` to match the corresponding character in `t`.
- 2. Track the frequency of shifts needed for each character and ensure that no shift exceeds the available number of moves `k`.
{{< dots >}}
### Problem Assumptions ✅
- The strings `s` and `t` contain only lowercase English letters.
- The maximum number of moves `k` is large enough that if the conversion is possible, it should be possible to calculate the solution.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abc', t = 'bcd', k = 6`  \
  **Explanation:** You can shift each character in `s` to the corresponding character in `t` within 6 moves.

- **Input:** `s = 'xyz', t = 'yza', k = 5`  \
  **Explanation:** Shifting 'x' to 'y' in 1 move, 'y' to 'z' in 2 moves, and 'z' to 'a' in 3 moves fits within 5 moves.

{{< dots >}}
## Approach 🚀
We need to check if it's possible to convert `s` into `t` in no more than `k` moves, by shifting characters at specific indices.

### Initial Thoughts 💭
- Each shift wraps around the alphabet.
- The key is determining if the total required shifts can fit within the `k` moves.
- Consider the difference between each character of `s` and `t`. If the number of moves required exceeds `k` for any character, return false.
{{< dots >}}
### Edge Cases 🌐
- Ensure that the strings are not empty.
- Handle cases where `s` and `t` are very large, up to 10^5 characters.
- Check for cases where `k = 0` (no moves allowed).
- Ensure that the strings are of equal length.
{{< dots >}}
## Code 💻
```cpp
bool canConvertString(string s, string t, int k) {
    if(s.size() != t.size()) return false;
    int n = s.size();
    vector<int> cnt(n, 0);
    vector<int> frq(26, 0);
    for(int i = 0; i < n; i++) {
        if(t[i] > s[i]) {
            cnt[i] = t[i] - s[i];
        } else if(t[i] < s[i]) {
            cnt[i] = 26 - (s[i] - t[i]);
        }
        // cout << cnt[i] << " ";
        frq[cnt[i] % 26]++;
    }

    for(int i = 1; i < 26; i++) {
        // cout << frq[i] << " ";
        if(frq[i] == 0) continue;
        long net = (long) (i + (frq[i] - 1)  * 26);
        if( net > k) return false;
    }
    
    return true;
}
```

This function checks if it is possible to convert string `s` to string `t` within `k` steps, where each step involves shifting a character in `s` to match the corresponding character in `t`. The function calculates the required shifts for each character and ensures that they do not exceed the allowed steps `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool canConvertString(string s, string t, int k) {
	```
	This is the function declaration for `canConvertString`, which takes two strings `s` and `t`, and an integer `k` representing the maximum number of allowed shifts.

2. **Condition Check**
	```cpp
	    if(s.size() != t.size()) return false;
	```
	Checks if the lengths of the strings `s` and `t` are different. If they are, it's impossible to convert `s` to `t`, so the function returns `false`.

3. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	Initializes `n` to the length of string `s`, which is also the length of string `t` (as the function already checks for size equality).

4. **Array Initialization**
	```cpp
	    vector<int> cnt(n, 0);
	```
	Initializes a vector `cnt` of size `n` to store the number of shifts required for each character in `s` to match the corresponding character in `t`.

5. **Array Initialization**
	```cpp
	    vector<int> frq(26, 0);
	```
	Initializes a vector `frq` of size 26 (for each letter of the alphabet) to count how often each shift amount occurs.

6. **For Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop starts, iterating through each character of the strings `s` and `t`.

7. **Conditional Check**
	```cpp
	        if(t[i] > s[i]) {
	```
	Checks if the character in `t` is lexicographically greater than the character in `s`. If true, a forward shift is needed.

8. **Shift Calculation**
	```cpp
	            cnt[i] = t[i] - s[i];
	```
	Calculates the number of shifts required to convert `s[i]` to `t[i]`. If `t[i]` is greater, this is a simple difference.

9. **Else If Check**
	```cpp
	        } else if(t[i] < s[i]) {
	```
	Checks if the character in `t` is lexicographically smaller than in `s`. If true, a backward shift is needed.

10. **Shift Calculation**
	```cpp
	            cnt[i] = 26 - (s[i] - t[i]);
	```
	Calculates the number of backward shifts required to convert `s[i]` to `t[i]`. The 26 represents the number of letters in the alphabet.

11. **Frequency Count**
	```cpp
	        frq[cnt[i] % 26]++;
	```
	Increments the count for the shift amount `cnt[i]`, ensuring that the shifts wrap around correctly by using modulo 26.

12. **For Loop**
	```cpp
	    for(int i = 1; i < 26; i++) {
	```
	A loop that checks each shift amount (from 1 to 25) to ensure that all shifts can be performed within `k` steps.

13. **Conditional Check**
	```cpp
	        if(frq[i] == 0) continue;
	```
	Skips the iteration if there are no shifts required for the current shift amount `i`.

14. **Shift Validation**
	```cpp
	        long net = (long) (i + (frq[i] - 1)  * 26);
	```
	Calculates the total number of steps required to perform all shifts for a particular shift amount `i`.

15. **Conditional Check**
	```cpp
	        if( net > k) return false;
	```
	Checks if the total number of steps for the current shift amount exceeds the allowed steps `k`. If it does, the function returns `false`.

16. **Return Statement**
	```cpp
	    return true;
	```
	Returns `true` if all shifts can be performed within the allowed steps `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We need to iterate over each character of the strings to calculate the required shifts.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use additional space to track shifts and frequencies.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/can-convert-string-in-k-moves/description/)

---
{{< youtube 3psLUZqiGx0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
