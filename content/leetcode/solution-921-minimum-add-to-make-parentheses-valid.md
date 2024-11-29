
+++
authors = ["grid47"]
title = "Leetcode 921: Minimum Add to Make Parentheses Valid"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 921: Minimum Add to Make Parentheses Valid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EPr9X0Y3vmo"
youtube_upload_date="2021-02-19"
youtube_thumbnail="https://i.ytimg.com/vi/EPr9X0Y3vmo/maxresdefault.jpg"
comments = true
+++



---
You are given a string consisting of parentheses. In one move, you can insert a parenthesis (either '(' or ')') at any position in the string. Your task is to return the minimum number of moves required to make the string valid, meaning all parentheses are properly balanced.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string of parentheses, with each character being either '(' or ')'.
- **Example:** `Input: s = "(()))"`
- **Constraints:**
	- 1 <= s.length <= 1000
	- Each character in s is either '(' or ')'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the minimum number of moves required to make the parentheses string valid.
- **Example:** `Output: 1`
- **Constraints:**
	- The string will contain only '(' and ')'.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate how many parentheses need to be added in order to balance the string.

- Traverse through the string character by character.
- Use a stack to keep track of unmatched opening parentheses '('.
- For each closing parenthesis ')', pop from the stack if there is a matching opening parenthesis, otherwise count it as a required move.
- At the end, the stack will contain unmatched opening parentheses, and the number of required moves will be equal to the size of the stack.
{{< dots >}}
### Problem Assumptions ✅
- The input string contains only parentheses.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "())"`  \
  **Explanation:** The string has one unmatched closing parenthesis. To balance it, we need to insert one opening parenthesis at the beginning. So, the answer is 1.

- **Input:** `Input: s = "((("`  \
  **Explanation:** The string has three unmatched opening parentheses. To balance it, we need to insert three closing parentheses at the end. So, the answer is 3.

{{< dots >}}
## Approach 🚀
The approach involves using a stack to keep track of unmatched parentheses while traversing the string. We also count the required moves for unmatched closing parentheses and opening parentheses.

### Initial Thoughts 💭
- We can use a stack to efficiently manage unmatched parentheses.
- By traversing the string once, we can determine the minimum moves needed.
- A stack is a good choice for tracking unmatched opening parentheses. For unmatched closing parentheses, we can simply count the number of insertions needed.
{{< dots >}}
### Edge Cases 🌐
- The input string will always have at least one character, so we don't need to handle empty strings.
- The algorithm should handle up to 1000 characters efficiently.
- If the string contains only one unmatched opening or closing parenthesis, it will need one move to balance.
- The input string will only contain parentheses, and we will always need to insert parentheses to balance it.
{{< dots >}}
## Code 💻
```cpp
int minAddToMakeValid(string s) {
    int res = 0;
    stack<int> stk;
    for(char &a : s) {
        if(a == '(') {
            stk.push(a);
        } else {
            if(stk.empty()) {
                res++;
            } else {
                stk.pop();
            }
        }
    }
    
    res += stk.size();
    return res;
}
```

The function 'minAddToMakeValid' calculates the minimum number of parentheses to add in order to make the given string 's' valid. It uses a stack to track open parentheses and ensures the balance is maintained by counting unmatched parentheses.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minAddToMakeValid(string s) {
	```
	Define the function 'minAddToMakeValid', which takes a string 's' and returns an integer representing the number of parentheses needed to balance the string.

2. **Variable Declaration**
	```cpp
	    int res = 0;
	```
	Declare an integer variable 'res' to keep track of the number of parentheses to be added for balancing the string.

3. **Stack Declaration**
	```cpp
	    stack<int> stk;
	```
	Declare a stack 'stk' to help track the open parentheses.

4. **Loop**
	```cpp
	    for(char &a : s) {
	```
	Iterate through each character 'a' in the input string 's'.

5. **Condition**
	```cpp
	        if(a == '(') {
	```
	Check if the current character is an opening parenthesis '('.

6. **Stack Operation**
	```cpp
	            stk.push(a);
	```
	If the character is an opening parenthesis, push it onto the stack.

7. **Else Condition**
	```cpp
	        } else {
	```
	If the current character is not an opening parenthesis, proceed with the else block.

8. **Empty Stack Check**
	```cpp
	            if(stk.empty()) {
	```
	Check if the stack is empty, indicating there is no matching opening parenthesis for the closing parenthesis.

9. **Increment Result**
	```cpp
	                res++;
	```
	If the stack is empty (no matching opening parenthesis), increment 'res' as one more parenthesis is needed to balance.

10. **Stack Pop**
	```cpp
	            } else {
	```
	If the stack is not empty, it means there is a matching opening parenthesis for the closing parenthesis.

11. **Pop Stack**
	```cpp
	                stk.pop();
	```
	Pop the matching opening parenthesis from the stack, as the pair is balanced.

12. **Stack Size Addition**
	```cpp
	    res += stk.size();
	```
	After processing all characters, add the number of unmatched opening parentheses left in the stack to 'res'.

13. **Return Statement**
	```cpp
	    return res;
	```
	Return the final count of parentheses that need to be added to make the string valid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only need to traverse the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In the worst case, we may need to store up to n unmatched parentheses in the stack. Hence, the space complexity is O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/)

---
{{< youtube EPr9X0Y3vmo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
