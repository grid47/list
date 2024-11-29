
+++
authors = ["grid47"]
title = "Leetcode 341: Flatten Nested List Iterator"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 341: Flatten Nested List Iterator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Tree","Depth-First Search","Design","Queue","Iterator"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/341.webp"
youtube = "4ILiBgLokM8"
youtube_upload_date="2023-10-20"
youtube_thumbnail="https://i.ytimg.com/vi/4ILiBgLokM8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/341.webp" 
    alt="A nested list unfolding and flattening into a 1D array, with each item softly glowing as it appears."
    caption="Solution to LeetCode 341: Flatten Nested List Iterator Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a nested list of integers nestedList, where each element can either be an integer or a sublist containing integers or other sublists. Implement an iterator to flatten this nested list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a nested list of integers where each element is either an integer or a list of integers.
- **Example:** `nestedList = [[2,3],4,[5,6]]`
- **Constraints:**
	- 1 <= nestedList.length <= 500
	- The integer values in the nested list are within the range [-10^6, 10^6].

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a list of integers that is the flattened version of the nested list.
- **Example:** `[2, 3, 4, 5, 6]`
- **Constraints:**
	- The flattened list should maintain the order of the elements from the original nested list.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement an iterator that flattens the nested list efficiently.

- Use a stack to keep track of the current position in the nested list.
- For each call to next(), move to the next element in the flattened list.
- For each call to hasNext(), check if there are more elements left to return in the nested list.
{{< dots >}}
### Problem Assumptions ✅
- The input list may contain nested sublists of various depths.
{{< dots >}}
## Examples 🧩
- **Input:** `nestedList = [[2,3],4,[5,6]]`  \
  **Explanation:** The input nested list contains sublists and integers. The iterator should flatten this list to return the integers in the order [2, 3, 4, 5, 6].

- **Input:** `nestedList = [1, [2, [3, 4]]]`  \
  **Explanation:** The input list has nested sublists. The iterator should flatten it to return the integers in the order [1, 2, 3, 4].

{{< dots >}}
## Approach 🚀
The approach to flattening the nested list is to use a stack to iteratively traverse the elements and flatten them.

### Initial Thoughts 💭
- The nested list contains integers and sublists of integers.
- A stack can help manage the state of the iterator and allow efficient traversal through the nested list.
{{< dots >}}
### Edge Cases 🌐
- If the nested list is empty, the iterator should immediately return false from hasNext() and not produce any output.
- For larger nested lists, the solution must avoid excessive recursion and handle deeply nested sublists efficiently.
- Consider cases where the nested list contains only integers or only empty sublists.
- The iterator should not exceed O(n) time complexity, where n is the total number of integers in the flattened list.
{{< dots >}}
## Code 💻
```cpp
NestedIterator(vector<NestedInteger> &nestedList) {
    begins.push(nestedList.begin());
    ends.push(nestedList.end());
}

int next() {
    hasNext();
    return (begins.top()++)->getInteger();
}

bool hasNext() {
    while (begins.size()) {
        if (begins.top() == ends.top()) {
            begins.pop();
            ends.pop();
        } else {
            auto x = begins.top();
            if (x->isInteger())
                return true;
            begins.top()++;
            begins.push(x->getList().begin());
            ends.push(x->getList().end());
        }
    }
    return false;
}

private:
stack<vector<NestedInteger>::iterator> begins, ends;
```

This class implements a nested iterator for a list that can contain both integers and lists. It uses two stacks to track the current position in the nested list. The `next()` function retrieves the next integer, while `hasNext()` checks if there are more integers available in the nested structure.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Constructor**
	```cpp
	NestedIterator(vector<NestedInteger> &nestedList) {
	```
	The constructor takes a reference to a vector of `NestedInteger` objects, representing a potentially nested list, and initializes two stacks to keep track of the current and end iterators for each list level.

2. **Push Begin Iterator**
	```cpp
	    begins.push(nestedList.begin());
	```
	The begin iterator for the first level of the nested list is pushed onto the `begins` stack.

3. **Push End Iterator**
	```cpp
	    ends.push(nestedList.end());
	```
	The end iterator for the first level of the nested list is pushed onto the `ends` stack.

4. **Next Function Declaration**
	```cpp
	int next() {
	```
	The `next()` function retrieves the next integer in the nested structure, if available.

5. **HasNext Call**
	```cpp
	    hasNext();
	```
	Calls `hasNext()` to ensure there is an integer available before proceeding to retrieve it.

6. **Return Integer**
	```cpp
	    return (begins.top()++)->getInteger();
	```
	The next integer is retrieved from the top of the `begins` stack by advancing the iterator and calling `getInteger()` on the current `NestedInteger` object.

7. **HasNext Function Declaration**
	```cpp
	bool hasNext() {
	```
	The `hasNext()` function checks if there are more integers available in the nested list.

8. **While Loop Start**
	```cpp
	    while (begins.size()) {
	```
	This `while` loop continues as long as there are elements in the `begins` stack, indicating that there are more levels in the nested list to explore.

9. **Check End of Current List**
	```cpp
	        if (begins.top() == ends.top()) {
	```
	Checks if the current iterator has reached the end of the current list level.

10. **Pop Iterators**
	```cpp
	            begins.pop();
	```
	If the iterator has reached the end, both the `begins` and `ends` iterators for that level are popped off the stacks.

11. **Pop End Iterator**
	```cpp
	            ends.pop();
	```
	Pops the end iterator for the current level.

12. **Else Block Start**
	```cpp
	        } else {
	```
	If the current iterator has not reached the end, continue processing the current element.

13. **Check if Integer**
	```cpp
	            auto x = begins.top();
	```
	Grabs the current `NestedInteger` from the top of the `begins` stack.

14. **Return True if Integer**
	```cpp
	            if (x->isInteger())
	```
	Checks if the current `NestedInteger` is an integer. If it is, the function returns `true`, indicating that the next integer is available.

15. **Return True**
	```cpp
	                return true;
	```
	Returns `true` indicating that the next integer is available.

16. **Increment Iterator**
	```cpp
	            begins.top()++;
	```
	Advances the iterator to the next element in the current list.

17. **Push Next Level Begin Iterator**
	```cpp
	            begins.push(x->getList().begin());
	```
	If the current `NestedInteger` is a list, pushes the begin iterator of the nested list onto the `begins` stack.

18. **Push Next Level End Iterator**
	```cpp
	            ends.push(x->getList().end());
	```
	Pushes the end iterator of the nested list onto the `ends` stack.

19. **Return False**
	```cpp
	    return false;
	```
	Returns `false` if there are no more integers available in the nested structure.

20. **Private Declaration**
	```cpp
	private:
	```
	Declares the private section of the class.

21. **Private Data Members**
	```cpp
	stack<vector<NestedInteger>::iterator> begins, ends;
	```
	Two stacks are declared to keep track of iterators for traversing the nested list: `begins` holds the current iterators, and `ends` holds the end iterators for each level.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because each integer is visited once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the stack used for traversal and the result storage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/flatten-nested-list-iterator/description/)

---
{{< youtube 4ILiBgLokM8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
