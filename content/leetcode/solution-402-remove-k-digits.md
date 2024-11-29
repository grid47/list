
+++
authors = ["grid47"]
title = "Leetcode 402: Remove K Digits"
date = "2024-09-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 402: Remove K Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/402.webp"
youtube = "cFabMOnJaq0"
youtube_upload_date="2022-02-18"
youtube_thumbnail="https://i.ytimg.com/vi/cFabMOnJaq0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/402.webp" 
    alt="A string of digits where each one is gently erased one by one, leaving the smallest number behind, glowing softly."
    caption="Solution to LeetCode 402: Remove K Digits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string num representing a non-negative integer and an integer k, remove k digits from num such that the remaining number is the smallest possible integer.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string num representing a non-negative integer and an integer k.
- **Example:** `For num = "35241" and k = 2, the output should be "241".`
- **Constraints:**
	- 1 <= k <= num.length <= 10^5
	- num consists of only digits.
	- num does not contain leading zeros except for the zero itself.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest number possible after removing k digits.
- **Example:** `For num = "100005" and k = 3, the output should be "5".`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove k digits from num such that the remaining number is as small as possible.

- 1. Initialize an empty stack to hold the digits of the resulting number.
- 2. Iterate through the digits of num, comparing each digit with the top of the stack.
- 3. If the current digit is smaller than the stack's top, pop digits from the stack until the current digit is no longer smaller or k removals are reached.
- 4. After processing all digits, if any removals are left, pop the remaining digits from the stack.
- 5. Convert the stack into the final number, ensuring no leading zeros remain.
{{< dots >}}
### Problem Assumptions ✅
- The input is always valid and the given k is not greater than the length of num.
{{< dots >}}
## Examples 🧩
- **Input:** `For num = "35241" and k = 2, remove the digits '3' and '5' to get "241".`  \
  **Explanation:** Removing digits from left to right ensures that we minimize the number by removing larger digits first.

{{< dots >}}
## Approach 🚀
The approach involves using a stack to keep track of the digits of the smallest number as we iterate through the string and remove digits as needed.

### Initial Thoughts 💭
- The problem requires finding the smallest number by removing digits in an optimal way.
- We need to compare the current digit with the top of the stack and remove digits when necessary to form the smallest number.
{{< dots >}}
### Edge Cases 🌐
- For large inputs, ensure the algorithm handles up to 10^5 digits efficiently.
- If the entire number is removed (k equals the length of num), return "0".
- Ensure no leading zeros in the final result, unless the result is zero itself.
{{< dots >}}
## Code 💻
```cpp
string removeKdigits(string num, int k) {
    string ans = "";
    int n = num.size();
    if(num.size() <= k) return "0";
    
    for(char c : num) {
        
        while(!ans.empty() && (ans.back() > c) && k) {
            ans.pop_back();
            k--;
        }
        
        if(!ans.empty() || c != '0') {
            ans.push_back(c);
        }
        
    }
    while(!ans.empty() && k--)
        ans.pop_back();
    if (ans.empty()) return "0";
    while (!ans.empty()) {
        num[n - 1] = ans.back();
        ans.pop_back(), n--;
    }
    return num.substr(n);
    
}
```

This function removes `k` digits from the string `num` to make the resulting number the smallest possible. It uses a stack (`ans`) to track the digits, popping elements to ensure the result is minimal. Finally, the remaining digits are arranged in the result string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string removeKdigits(string num, int k) {
	```
	Define the function `removeKdigits`, which takes a string `num` and an integer `k` to remove `k` digits from `num` to form the smallest possible number.

2. **Variable Initialization**
	```cpp
	    string ans = "";
	```
	Initialize an empty string `ans` to store the digits of the result as we process each character from `num`.

3. **Variable Initialization**
	```cpp
	    int n = num.size();
	```
	Store the length of the input string `num` in the variable `n`.

4. **Edge Case Handling**
	```cpp
	    if(num.size() <= k) return "0";
	```
	Handle the edge case where the length of `num` is less than or equal to `k`. In this case, removing all digits leaves no number, so return "0".

5. **For Loop**
	```cpp
	    for(char c : num) {
	```
	Start a `for` loop to iterate over each character `c` in the string `num`.

6. **Stack Manipulation**
	```cpp
	        while(!ans.empty() && (ans.back() > c) && k) {
	```
	Use a `while` loop to pop elements from the stack `ans` if the last element in `ans` is greater than the current character `c` and there are still digits left to remove (`k` > 0).

7. **Stack Pop Operation**
	```cpp
	            ans.pop_back();
	```
	Pop the top element from the stack `ans` to remove a larger digit and decrease `k`.

8. **Variable Decrement**
	```cpp
	            k--;
	```
	Decrement the counter `k` after removing a digit.

9. **While Loop End**
	```cpp
	        }
	```
	End of the `while` loop that removes digits from the stack `ans`.

10. **Push Operation**
	```cpp
	        if(!ans.empty() || c != '0') {
	```
	Check if the stack is not empty or if the current character `c` is not '0'. This ensures that leading zeros are not added to the result.

11. **Stack Push Operation**
	```cpp
	            ans.push_back(c);
	```
	Push the current character `c` to the stack `ans`.

12. **While Loop**
	```cpp
	    while(!ans.empty() && k--)
	```
	After processing all characters, if there are still digits left to remove, pop elements from the stack until `k` reaches zero.

13. **Stack Pop Operation**
	```cpp
	        ans.pop_back();
	```
	Pop the top element from the stack `ans` to remove any remaining digits.

14. **Edge Case Handling**
	```cpp
	    if (ans.empty()) return "0";
	```
	If the stack is empty after removing digits, return "0" as the result, indicating no digits are left.

15. **While Loop**
	```cpp
	    while (!ans.empty()) {
	```
	Use a `while` loop to process the digits stored in the stack and build the final result.

16. **Result Construction**
	```cpp
	        num[n - 1] = ans.back();
	```
	Assign the top element of the stack `ans` to the last position in the string `num`.

17. **Stack Pop Operation**
	```cpp
	        ans.pop_back(), n--;
	```
	Pop the top element from the stack and decrement `n` to move to the next position in the result.

18. **Return Result**
	```cpp
	    return num.substr(n);
	```
	Return the substring of `num` starting from the position `n`, which contains the final smallest number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we process each digit at most once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the use of a stack to store the digits.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-k-digits/description/)

---
{{< youtube cFabMOnJaq0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
