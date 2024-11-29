
+++
authors = ["grid47"]
title = "Leetcode 2381: Shifting Letters II"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2381: Shifting Letters II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "dWp_egpuwbU"
youtube_upload_date="2022-08-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/dWp_egpuwbU/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` consisting of lowercase English letters and a 2D array `shifts`. Each entry in the array represents a shift operation, where a segment of the string from `starti` to `endi` (inclusive) is shifted forward if `directioni` is 1, or backward if `directioni` is 0. A forward shift means replacing a character with the next letter in the alphabet (wrapping around from 'z' to 'a'), and a backward shift means replacing a character with the previous letter (wrapping around from 'a' to 'z'). You need to return the final string after all shifts are applied.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` of lowercase English letters and a 2D integer array `shifts` where each entry contains [starti, endi, directioni].
- **Example:** `s = 'abc', shifts = [[0, 1, 0], [1, 2, 1], [0, 2, 1]]`
- **Constraints:**
	- 1 <= s.length, shifts.length <= 50000
	- shifts[i].length == 3
	- 0 <= starti <= endi < s.length
	- 0 <= directioni <= 1
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the final string after applying all shifts as described in the problem.
- **Example:** `Output: 'ace'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to apply the shifts efficiently, ensuring the correct forward or backward shifting of characters based on the direction specified.

- 1. Initialize an array to track the net shift at each index.
- 2. Iterate through the shifts array and update the net shifts at the corresponding start and end indices.
- 3. Calculate the cumulative shift for each character using the net shift array.
- 4. Apply the shifts to the string, taking care to wrap around alphabetically.
{{< dots >}}
### Problem Assumptions ✅
- The input string and shifts are valid and conform to the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'abc', shifts = [[0, 1, 0], [1, 2, 1], [0, 2, 1]]`  \
  **Explanation:** First, shift the characters from index 0 to 1 backward ('a' becomes 'z', 'b' becomes 'a'). Now s = 'zac'. Next, shift the characters from index 1 to 2 forward ('a' becomes 'b'). Now s = 'zbd'. Finally, shift the characters from index 0 to 2 forward ('z' becomes 'a', 'b' becomes 'c'). Now s = 'ace'.

- **Input:** `Input: s = 'dztz', shifts = [[0, 0, 0], [1, 1, 1]]`  \
  **Explanation:** First, shift the character at index 0 backward ('d' becomes 'c'). Now s = 'cztz'. Next, shift the character at index 1 forward ('z' becomes 'a'). Now s = 'catz'.

{{< dots >}}
## Approach 🚀
The problem can be solved by efficiently managing the shifts using a net shift array to track changes at specific indices. The shifts are applied cumulatively, and the final characters are updated in a single pass.

### Initial Thoughts 💭
- We can avoid directly modifying the string multiple times by using a net shift array.
- By using the net shift array and calculating cumulative shifts, we can apply all the operations efficiently.
{{< dots >}}
### Edge Cases 🌐
- The input string will never be empty, as the length of `s` is at least 1.
- For large inputs, the solution must efficiently handle up to 50,000 shifts and string length.
- If all shifts are either forward or backward on the entire string, the solution should handle these efficiently.
- Ensure the solution works within the time and space limits for inputs of size up to 50,000.
{{< dots >}}
## Code 💻
```cpp
string shiftingLetters(string s, vector<vector<int>>& sh) {
    int n = s.length();
    vector<int> net(n, 0);
    for(auto &x: sh) {
        int k = x[2] == 1? 1 : -1;
        net[x[0]] += k;
       // net[x[0]] %= 26;
        if(x[1] + 1 < n) {
        net[x[1] + 1] -= k;
       // net[x[1] + 1] %= 26;
            }



    }
    
    partial_sum(net.begin(), net.end(), net.begin());
    
    int i = 0;
    for(char &c : s) {
        
        int res = ((c - 'a') + net[i])% 26;
                 res = (res + 26)%26;
        c = 'a' + res;
        i++;
    }
    
    return s;
}
```

This function shifts the letters of the string based on the shifting operations provided in the `sh` vector, which contains shift ranges. It computes the final shifted string after applying all shifts in sequence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string shiftingLetters(string s, vector<vector<int>>& sh) {
	```
	Define the function that accepts a string `s` and a 2D vector `sh` containing the shift operations.

2. **Variable Initialization**
	```cpp
	    int n = s.length();
	```
	Store the length of the string `s` in the variable `n`.

3. **Variable Initialization**
	```cpp
	    vector<int> net(n, 0);
	```
	Create a vector `net` initialized with zeros, which will be used to accumulate the net shifts for each position in the string.

4. **Loop Start**
	```cpp
	    for(auto &x: sh) {
	```
	Iterate over each shift operation in the `sh` vector.

5. **Logic**
	```cpp
	        int k = x[2] == 1? 1 : -1;
	```
	Determine the direction of the shift: if `x[2]` is 1, the shift is forward (increment by 1), otherwise, it is backward (decrement by 1).

6. **Update Net Shifts**
	```cpp
	        net[x[0]] += k;
	```
	Apply the shift at the starting index `x[0]` of the range by adding the shift direction `k`.

7. **Condition Check**
	```cpp
	        if(x[1] + 1 < n) {
	```
	Check if the end of the shift range (`x[1] + 1`) is within bounds of the string.

8. **Update Net Shifts**
	```cpp
	        net[x[1] + 1] -= k;
	```
	Apply the inverse shift at the position right after the end of the range `x[1] + 1`.

9. **Accumulate Shifts**
	```cpp
	    partial_sum(net.begin(), net.end(), net.begin());
	```
	Use `partial_sum` to compute the cumulative shifts for each position in the string.

10. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initialize a variable `i` to track the current index while modifying the string.

11. **Loop Start**
	```cpp
	    for(char &c : s) {
	```
	Iterate over each character `c` in the string `s`.

12. **Calculation of Result**
	```cpp
	        int res = ((c - 'a') + net[i]) % 26;
	```
	Calculate the new character by adding the net shift to the character's original position, then applying modulo 26 to ensure it stays within the alphabet.

13. **Handling Negative Results**
	```cpp
	                 res = (res + 26) % 26;
	```
	Ensure the result is always a positive value by adding 26 before applying modulo 26.

14. **Update Character**
	```cpp
	        c = 'a' + res;
	```
	Convert the shifted result back to a character by adding it to the ASCII value of 'a'.

15. **Update Index**
	```cpp
	        i++;
	```
	Increment the index `i` to move to the next character in the string.

16. **Return Result**
	```cpp
	    return s;
	```
	Return the modified string after all shifts have been applied.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is linear with respect to the length of the string and the number of shifts.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we use an array to track the shifts at each index in the string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shifting-letters-ii/description/)

---
{{< youtube dWp_egpuwbU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
