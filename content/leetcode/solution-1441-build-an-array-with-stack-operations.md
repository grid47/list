
+++
authors = ["grid47"]
title = "Leetcode 1441: Build an Array With Stack Operations"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1441: Build an Array With Stack Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uK6JvnLUcck"
youtube_upload_date="2020-05-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uK6JvnLUcck/maxresdefault.webp"
comments = true
+++



---
You are given a strictly increasing integer array `target` and an integer `n`. Starting with an empty stack, you can perform two operations: 'Push' to add an integer to the stack and 'Pop' to remove the top element from the stack. A stream of integers from 1 to `n` is provided. Use the stack operations to build the stack so that it contains the elements of `target` in order (from bottom to top). Return the sequence of operations required. Stop processing once the stack equals the `target` array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers `target` and an integer `n`.
- **Example:** `Input: target = [2,4,5], n = 6`
- **Constraints:**
	- 1 <= target.length <= 100
	- 1 <= n <= 100
	- 1 <= target[i] <= n
	- target is strictly increasing.

{{< dots >}}
### Output Specifications 📤
- **Output:** A list of strings representing the stack operations required to build `target`.
- **Example:** `Output: ["Push", "Pop", "Push", "Push", "Push"]`
- **Constraints:**
	- The operations should correctly build the stack to match `target`.

{{< dots >}}
### Core Logic 🔍
**Goal:** Generate the sequence of operations ('Push' and 'Pop') to transform the stack to match `target`.

- Initialize an empty list `ans` to store the operations.
- Iterate through the stream of integers from 1 to `n`.
- For each integer, check if it is in `target`.
- If it is in `target`, perform a 'Push' operation.
- If it is not in `target`, perform both a 'Push' and a 'Pop' operation to remove it immediately.
- Stop processing once all elements of `target` are pushed into the stack.
{{< dots >}}
### Problem Assumptions ✅
- `target` is strictly increasing.
- `n` is large enough to cover all elements in `target`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: target = [2,4,6], n = 6`  \
  **Explanation:** Operations: Push 1 and Pop it (not in target), Push 2 (in target), Push 3 and Pop it (not in target), Push 4 (in target), Push 5 and Pop it (not in target), Push 6 (in target). Output: ["Push", "Pop", "Push", "Push", "Pop", "Push", "Push", "Pop", "Push"].

{{< dots >}}
## Approach 🚀
Use a single loop to traverse integers from 1 to `n` and simulate stack operations based on whether each integer is in `target`.

### Initial Thoughts 💭
- The stack operations must maintain the order of `target`.
- Extra integers not in `target` should be handled with a 'Push' followed by a 'Pop'.
- Simulating operations sequentially ensures that the stack matches `target` without skipping any integers in the stream.
{{< dots >}}
### Edge Cases 🌐
- Input: target = [], n = 5 -> Output: []
- Input: target = [1, 2, ..., 100], n = 100 -> Operations would be ['Push'] repeated 100 times.
- Input: target = [1], n = 1 -> Output: ["Push"]
- target must be strictly increasing.
{{< dots >}}
## Code 💻
```cpp
vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    int currElem=1;
    for(int i=0;i<target.size();i++){
        while(currElem!=target[i]){
            ans.push_back("Push");
            ans.push_back("Pop");
            currElem++;
        }
        ans.push_back("Push");
        currElem++;
    }
    return ans;        
}
```

The `buildArray` function generates a sequence of operations to form the target array from an initial array of 1 to `n`. It uses the operations 'Push' and 'Pop' to simulate a stack-based approach, where elements are pushed into the stack and popped out as needed to match the target array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> buildArray(vector<int>& target, int n) {
	```
	Defines the function `buildArray`, which takes a vector `target` (the target array to match) and an integer `n` (the upper limit for the array) as input. It returns a vector of strings representing the operations ('Push' and 'Pop') required to form the target array.

2. **Variable Initialization**
	```cpp
	    vector<string> ans;
	```
	Initializes an empty vector `ans` to store the sequence of operations ('Push' and 'Pop') that will form the target array.

3. **Variable Initialization**
	```cpp
	    int currElem=1;
	```
	Initializes the variable `currElem` to 1, which represents the current element being processed in the stack-based approach.

4. **Loop**
	```cpp
	    for(int i=0;i<target.size();i++){
	```
	Starts a loop to iterate through each element in the `target` array. The goal is to simulate the stack operations to match each element in the target array.

5. **Condition Check**
	```cpp
	        while(currElem!=target[i]){
	```
	Checks if the current element (`currElem`) is not equal to the current target element (`target[i]`). If they are not equal, additional 'Push' and 'Pop' operations are needed.

6. **Push Operation**
	```cpp
	            ans.push_back("Push");
	```
	Adds a 'Push' operation to the result vector `ans`, simulating pushing the current element (`currElem`) onto the stack.

7. **Pop Operation**
	```cpp
	            ans.push_back("Pop");
	```
	Adds a 'Pop' operation to the result vector `ans`, simulating popping the element off the stack after it has been pushed.

8. **Increment**
	```cpp
	            currElem++;
	```
	Increments `currElem` to represent the next element to be processed in the stack-based approach.

9. **Push Operation**
	```cpp
	        ans.push_back("Push");
	```
	Adds a final 'Push' operation to the result vector `ans` to push the current target element onto the stack.

10. **Increment**
	```cpp
	        currElem++;
	```
	Increments `currElem` to represent the next element after pushing the current target element.

11. **Return Statement**
	```cpp
	    return ans;        
	```
	Returns the result vector `ans`, which contains the sequence of operations ('Push' and 'Pop') needed to build the target array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each integer from the stream is processed exactly once, leading to a linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

No additional data structures are used beyond the result list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/build-an-array-with-stack-operations/description/)

---
{{< youtube uK6JvnLUcck >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
