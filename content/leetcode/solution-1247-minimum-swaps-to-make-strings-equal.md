
+++
authors = ["grid47"]
title = "Leetcode 1247: Minimum Swaps to Make Strings Equal"
date = "2024-07-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1247: Minimum Swaps to Make Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy"]
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
You are given two strings s1 and s2 of equal length consisting only of 'x' and 'y'. Your task is to make these two strings equal by swapping characters between the two strings. Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings s1 and s2 of equal length, containing only 'x' and 'y'.
- **Example:** `s1 = "yy", s2 = "xx"`
- **Constraints:**
	- 1 <= s1.length, s2.length <= 1000
	- s1.length == s2.length
	- s1, s2 only contain 'x' and 'y'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of swaps required to make s1 and s2 equal, or -1 if it is impossible.
- **Example:** `1`
- **Constraints:**
	- Return -1 if it is impossible to make the strings equal.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the minimum number of swaps needed to make the two strings equal.

- Count the number of occurrences where 'x' in s1 corresponds to 'y' in s2, and vice versa.
- Check if the total number of mismatches can be resolved by swapping, ensuring the number of mismatches of 'x' and 'y' are even.
- Return the number of swaps needed or -1 if it is impossible.
{{< dots >}}
### Problem Assumptions ✅
- Both strings are non-empty and have equal lengths.
{{< dots >}}
## Examples 🧩
- **Input:** `s1 = "yy", s2 = "xx"`  \
  **Explanation:** One swap is enough to make the strings equal: Swap s1[0] and s2[1].

{{< dots >}}
## Approach 🚀
The solution involves counting the mismatched positions and determining the minimum swaps needed to resolve them.

### Initial Thoughts 💭
- If the total number of mismatches between 'x' and 'y' is odd, it is impossible to solve.
- To solve the problem, we can identify the mismatches and calculate the swaps accordingly.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that both strings have at least 1 character.
- For large inputs, ensure the solution handles the time complexity efficiently.
- If the two strings are already equal, the number of swaps is 0.
- Ensure the solution handles strings of maximum length correctly.
{{< dots >}}
## Code 💻
```cpp
int minimumSwap(string s1, string s2) {
    int xy = 0, yx = 0;
    for(int i = 0; i < s1.size(); i++) {
             if(s1[i] == 'x' && s2[i] == 'y') xy++;
        else if(s1[i] == 'y' && s2[i] == 'x') yx++;
    }

    if(xy % 2 != yx % 2) return -1;
    return xy/2 + yx/2 + (xy%2) * 2;
}
```

The function `minimumSwap` calculates the minimum number of swaps needed to make two strings `s1` and `s2` identical. The solution counts mismatched 'x' and 'y' characters and checks if the number of such mismatches is even, as only an even number of mismatches can be resolved through swaps.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumSwap(string s1, string s2) {
	```
	The function `minimumSwap` is defined to compute the minimum number of swaps to make the two strings `s1` and `s2` identical. The function takes two strings as input.

2. **Variable Initialization**
	```cpp
	    int xy = 0, yx = 0;
	```
	Two integer variables `xy` and `yx` are initialized to 0. These variables will count mismatched pairs where 'x' is in `s1` and 'y' is in `s2` (`xy`), and where 'y' is in `s1` and 'x' is in `s2` (`yx`).

3. **Loop Through Strings**
	```cpp
	    for(int i = 0; i < s1.size(); i++) {
	```
	A loop is used to iterate over each character of the strings `s1` and `s2`.

4. **Count XY Mismatches**
	```cpp
	             if(s1[i] == 'x' && s2[i] == 'y') xy++;
	```
	If the character at the current position in `s1` is 'x' and the character at the same position in `s2` is 'y', increment the `xy` counter.

5. **Count YX Mismatches**
	```cpp
	        else if(s1[i] == 'y' && s2[i] == 'x') yx++;
	```
	If the character at the current position in `s1` is 'y' and the character at the same position in `s2` is 'x', increment the `yx` counter.

6. **Check for Even Mismatches**
	```cpp
	    if(xy % 2 != yx % 2) return -1;
	```
	If the number of mismatches of type `xy` and `yx` are not both even, it's impossible to resolve them with swaps, so the function returns -1.

7. **Calculate Minimum Swaps**
	```cpp
	    return xy/2 + yx/2 + (xy%2) * 2;
	```
	The minimum number of swaps is calculated by dividing the mismatches by 2 (since each swap resolves one pair of mismatches) and adding 2 if there's one leftover pair (because it takes two swaps to resolve).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the length of the strings, O(n), where n is the length of the strings.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as no additional space is used apart from counters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
