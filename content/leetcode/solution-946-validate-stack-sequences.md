
+++
authors = ["grid47"]
title = "Leetcode 946: Validate Stack Sequences"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 946: Validate Stack Sequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YF5ZWSWvMT0"
youtube_upload_date="2023-04-13"
youtube_thumbnail="https://i.ytimg.com/vi/YF5ZWSWvMT0/maxresdefault.jpg"
comments = true
+++



---
You are given two integer arrays, `pushed` and `popped`, each containing distinct values. The arrays represent the order of elements being pushed onto and popped from an initially empty stack. Your task is to determine if it is possible to obtain the `popped` sequence from the `pushed` sequence through a series of valid stack push and pop operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integer arrays: `pushed` and `popped`. Both arrays contain distinct values, and the length of both arrays is the same.
- **Example:** `Input: pushed = [1, 2, 3, 4, 5], popped = [5, 4, 3, 2, 1]`
- **Constraints:**
	- 1 <= pushed.length <= 1000
	- 0 <= pushed[i] <= 1000
	- All elements in pushed and popped are unique.
	- popped.length == pushed.length
	- popped is a permutation of pushed.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the sequence `popped` can be obtained by performing a sequence of push and pop operations on an initially empty stack, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The input arrays are always valid, and the answer will fit in a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify if the `popped` array can be formed by performing valid stack operations on the `pushed` array.

- 1. Initialize an empty stack to simulate the stack operations.
- 2. Use two pointers, one for traversing `pushed` and another for traversing `popped`.
- 3. For each element in `pushed`, push it onto the stack.
- 4. While the stack is not empty and the top of the stack matches the current element in `popped`, pop the top element from the stack and move the pointer in `popped`.
- 5. Repeat the process until all elements from `pushed` are processed and the stack is empty.
{{< dots >}}
### Problem Assumptions ✅
- The arrays `pushed` and `popped` contain only unique values.
- The arrays are permutations of each other, meaning that `popped` can be re-arranged into `pushed`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: pushed = [1, 2, 3, 4, 5], popped = [5, 4, 3, 2, 1]`  \
  **Explanation:** In this example, we can simulate the stack operations as follows: push(1), push(2), push(3), push(4), push(5), then pop elements in reverse order: pop() -> 5, pop() -> 4, pop() -> 3, pop() -> 2, pop() -> 1. Since the stack operations produce the same order as `popped`, the output is true.

- **Input:** `Input: pushed = [1, 2, 3, 4, 5], popped = [5, 3, 4, 1, 2]`  \
  **Explanation:** In this example, the element 1 cannot be popped before 2. It is not possible to obtain the sequence `popped` by performing valid stack operations on `pushed`, so the output is false.

{{< dots >}}
## Approach 🚀
The approach is to simulate stack operations by iterating over the `pushed` array and checking if the elements can be popped from the stack in the order specified by `popped`.

### Initial Thoughts 💭
- The task involves simulating stack operations and ensuring that the order of pops matches the given sequence.
- The problem can be solved efficiently with a single pass through the arrays.
- Using a stack to simulate the push and pop operations is a straightforward approach.
{{< dots >}}
### Edge Cases 🌐
- If both arrays are empty, the result is true because no operations are needed.
- For large inputs, ensure the solution handles up to 1000 elements efficiently.
- If the arrays are already in the correct order, no operations are needed, and the result is true.
- Make sure that the solution works within the problem constraints, particularly with array lengths up to 1000.
{{< dots >}}
## Code 💻
```cpp
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;
    int i = 1, j = 0;
    stk.push(pushed[0]);
    int n = pushed.size();
    while(i < n) {
        while(j < n && !stk.empty() && stk.top() == popped[j]) {
            j++;
            stk.pop();
        }
        stk.push(pushed[i++]);
    }
    while(j < n && !stk.empty() && stk.top() == popped[j]) {
        j++;
        stk.pop();
    }        
    return stk.empty();
}
```

This function checks if a sequence of stack operations can produce the sequence `popped` from the sequence `pushed`. It uses a stack to simulate pushing and popping, and ensures that the elements are popped in the correct order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	```
	This line declares the function `validateStackSequences`, which takes two vectors: `pushed` (the order in which elements are pushed onto the stack) and `popped` (the desired popping sequence). The function returns a boolean value indicating whether the sequence is valid.

2. **Stack Initialization**
	```cpp
	    stack<int> stk;
	```
	Declare a stack `stk` to simulate the push and pop operations.

3. **Variable Initialization**
	```cpp
	    int i = 1, j = 0;
	```
	Initialize two integer variables: `i` (used to iterate through the `pushed` vector) and `j` (used to iterate through the `popped` vector).

4. **Initial Push**
	```cpp
	    stk.push(pushed[0]);
	```
	Push the first element of the `pushed` vector onto the stack.

5. **Size Calculation**
	```cpp
	    int n = pushed.size();
	```
	Calculate the size of the `pushed` vector and store it in `n`.

6. **Main Loop**
	```cpp
	    while(i < n) {
	```
	Start a loop that continues until `i` reaches the size of the `pushed` vector.

7. **Inner Loop**
	```cpp
	        while(j < n && !stk.empty() && stk.top() == popped[j]) {
	```
	This inner loop checks if the current stack's top matches the current element in `popped` and pops from the stack accordingly.

8. **Increment `j`**
	```cpp
	            j++;
	```
	Increment `j` to check the next element in the `popped` vector after popping the current top element from the stack.

9. **Pop Operation**
	```cpp
	            stk.pop();
	```
	Pop the top element from the stack if it matches the current element in `popped`.

10. **Push Next Element**
	```cpp
	        stk.push(pushed[i++]);
	```
	Push the next element from the `pushed` vector onto the stack and increment `i`.

11. **Final Check**
	```cpp
	    while(j < n && !stk.empty() && stk.top() == popped[j]) {
	```
	After the main loop, check if there are still elements in the stack that match the remaining elements in the `popped` vector.

12. **Increment `j` Again**
	```cpp
	        j++;
	```
	Increment `j` to check the next element in `popped` after popping the current top element from the stack.

13. **Pop Operation Again**
	```cpp
	        stk.pop();
	```
	Pop the top element from the stack if it matches the current element in `popped`.

14. **Return Result**
	```cpp
	    return stk.empty();
	```
	Return true if the stack is empty (all elements have been popped correctly), otherwise return false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we process each element in the arrays once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case when the stack stores all elements, and O(1) in the best case when the stack is empty.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/validate-stack-sequences/description/)

---
{{< youtube YF5ZWSWvMT0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
