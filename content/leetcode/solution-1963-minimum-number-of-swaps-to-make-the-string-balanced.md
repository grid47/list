
+++
authors = ["grid47"]
title = "Leetcode 1963: Minimum Number of Swaps to Make the String Balanced"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1963: Minimum Number of Swaps to Make the String Balanced in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3YDBT9ZrfaU"
youtube_upload_date="2021-08-08"
youtube_thumbnail="https://i.ytimg.com/vi/3YDBT9ZrfaU/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s` of even length `n`. The string contains exactly `n/2` opening brackets `[` and `n/2` closing brackets `]`. A string is called balanced if for every opening bracket there exists a corresponding closing bracket, with each closing bracket having a matching opening bracket before it. Your task is to return the minimum number of swaps needed to make the string balanced.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` of even length `n` consisting only of the characters `[` and `]`.
- **Example:** `s = "][]["`
- **Constraints:**
	- 2 <= n <= 10^6
	- s[i] is either '[' or ']'
	- The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of swaps required to make the string balanced.
- **Example:** `Output: 1`
- **Constraints:**
	- The output must be a single integer representing the minimum number of swaps.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of swaps by calculating how many unbalanced opening and closing brackets there are in the string.

- Step 1: Iterate through the string and use a stack to track unmatched opening brackets.
- Step 2: Whenever a closing bracket is found, check if there is an unmatched opening bracket to pair it with.
- Step 3: Count the number of unmatched opening brackets and compute the necessary swaps.
{{< dots >}}
### Problem Assumptions ✅
- The input string will always contain an equal number of opening and closing brackets.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = '][][', Output: 1`  \
  **Explanation:** In this example, the first closing bracket `]` needs to be swapped with the last opening bracket `[`. After the swap, the string becomes balanced.

- **Input:** `Input: s = ']]][[[', Output: 2`  \
  **Explanation:** In this case, we need two swaps to balance the string. First, swap the 1st and 4th brackets, then swap the 2nd and 5th.

{{< dots >}}
## Approach 🚀
The problem can be solved by using a stack to manage unmatched opening brackets and keeping track of the number of swaps required.

### Initial Thoughts 💭
- We only need to handle unmatched brackets. Each unmatched closing bracket requires a corresponding opening bracket before it.
- Using a stack to simulate the process of pairing opening and closing brackets will allow us to efficiently compute the number of necessary swaps.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least two brackets in the input string.
- Ensure that the solution handles the upper constraint of up to 10^6 brackets efficiently.
- If the string is already balanced, no swaps are needed.
- Handle all valid input cases where the string contains exactly equal numbers of opening and closing brackets.
{{< dots >}}
## Code 💻
```cpp
int minSwaps(string s) {
    stack<char> stk;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(s[i] == '[') stk.push(i);
        else if(!stk.empty()) stk.pop();
    }
    
    return (stk.size() + 1) / 2;
}
```

This function calculates the minimum number of swaps required to balance a string containing only the characters '[' and '].

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minSwaps(string s) {
	```
	The function `minSwaps` is defined, which takes a string `s` containing only '[' and ']' and calculates the minimum number of swaps to balance the string.

2. **Stack Initialization**
	```cpp
	    stack<char> stk;
	```
	A stack `stk` is initialized to help track unmatched '[' characters.

3. **String Length Calculation**
	```cpp
	    int n = s.length();
	```
	The length of the string `s` is stored in the variable `n`.

4. **Loop Through String**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop begins to iterate through the string `s` from index 0 to `n-1`.

5. **Push to Stack**
	```cpp
	        if(s[i] == '[') stk.push(i);
	```
	If the current character is '[', its index is pushed onto the stack.

6. **Pop from Stack**
	```cpp
	        else if(!stk.empty()) stk.pop();
	```
	If the current character is ']' and the stack is not empty, the most recent unmatched '[' character is popped from the stack.

7. **Final Calculation**
	```cpp
	    return (stk.size() + 1) / 2;
	```
	The number of unmatched '[' characters left in the stack is used to calculate the minimum number of swaps. The formula `(stk.size() + 1) / 2` computes this.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We process each character in the string exactly once, so the time complexity is linear in the size of the input string.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

In the worst case, the stack will store all unmatched opening brackets, resulting in linear space complexity.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/)

---
{{< youtube 3YDBT9ZrfaU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
