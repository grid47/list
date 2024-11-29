
+++
authors = ["grid47"]
title = "Leetcode 457: Circular Array Loop"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 457: Circular Array Loop in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/457.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/457.webp" 
    alt="A glowing circular array where elements move in a loop, with each cycle softly illuminated as it repeats."
    caption="Solution to LeetCode 457: Circular Array Loop Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are playing a game with a circular array where each element indicates how many steps to move forward or backward. Determine if there exists a cycle in the array where the cycle has more than one element and all elements in the cycle move in the same direction. Return true if such a cycle exists, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a circular array of non-zero integers where each element specifies the number of steps to move forward or backward.
- **Example:** `nums = [2, -1, 1, 2, 2]`
- **Constraints:**
	- 1 <= nums.length <= 5000
	- -1000 <= nums[i] <= 1000
	- nums[i] != 0

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean indicating whether there exists a valid cycle in the array.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean indicating whether a valid cycle exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify if there is a cycle in the array that satisfies the conditions outlined above.

- 1. Start iterating over the array, marking visited elements.
- 2. Follow the directions specified by the values at each index, checking for a cycle.
- 3. Ensure that the cycle formed involves moving entirely in one direction (either all forward or all backward).
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, -1, 1, 2, 2]`  \
  **Explanation:** There is a valid cycle starting at index 0, which leads to indices 2, 3, and back to 0, forming a valid cycle.

- **Input:** `nums = [-1, -2, -3, -4, -5, 6]`  \
  **Explanation:** There are no valid cycles as the only cycle is of size 1, which is not valid.

{{< dots >}}
## Approach 🚀
The solution involves tracking each element's direction and checking if it forms a valid cycle according to the problem's requirements.

### Initial Thoughts 💭
- The array is circular, so each element can wrap around to the start or end.
- A cycle can be detected by tracking movements and ensuring the same direction for all cycle elements.
{{< dots >}}
### Edge Cases 🌐
- If the array has only one element, return false.
- Ensure that the solution works efficiently with input arrays up to the maximum size of 5000.
- If the array contains alternating positive and negative values, ensure that no cycle is falsely identified.
- Handle large inputs efficiently, ensuring an O(n) time complexity solution with constant space.
{{< dots >}}
## Code 💻
```cpp
bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return false;
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) continue;

        int j = i, k = getIdx(i, nums);
        while(nums[k] * nums[i] > 0 && nums[getIdx(k, nums)] * nums[i] > 0) {
            if(j == k) {
                if(j == getIdx(j, nums)) break;
                return true;
            }
            j = getIdx(j, nums);
            k = getIdx(getIdx(k, nums), nums);
        }

        j = i;
        int val = nums[i];
        while(nums[j] * val > 0) {
            int next = getIdx(j, nums);
            nums[j] = 0;
            j = next;
        }
    }
    return false;
}

int getIdx(int i, vector<int> &nums) {
    int n = nums.size();
    return i + nums[i] >= 0? (i + nums[i]) % n: n + ((i + nums[i]) % n);
}
```

The `circularArrayLoop` function checks if there exists a cycle in a circular array, where each element points to the next index based on its value. The function uses a slow and fast pointer technique to detect cycles and a helper function `getIdx` to handle the circular indexing.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool circularArrayLoop(vector<int>& nums) {
	```
	Defines the `circularArrayLoop` function, which takes a vector `nums` and returns a boolean indicating whether a cycle exists in the array.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes variable `n` to store the size of the input array `nums`.

3. **Edge Case Handling**
	```cpp
	    if(n == 1) return false;
	```
	Checks if the size of the array is 1. A single element cannot form a cycle, so the function returns `false`.

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop that iterates over each element in the array `nums`.

5. **Edge Case Handling**
	```cpp
	        if(nums[i] == 0) continue;
	```
	Skips the current element if it is 0, as it cannot contribute to a valid cycle.

6. **Variable Initialization**
	```cpp
	        int j = i, k = getIdx(i, nums);
	```
	Initializes two pointers: `j` (the slow pointer) starting at index `i`, and `k` (the fast pointer) calculated using the `getIdx` helper function.

7. **While Loop**
	```cpp
	        while(nums[k] * nums[i] > 0 && nums[getIdx(k, nums)] * nums[i] > 0) {
	```
	Enters a while loop that runs as long as the elements at the slow and fast pointers (`nums[i]`, `nums[k]`) have the same sign (either both positive or both negative), meaning they are moving in the same direction.

8. **Cycle Detection**
	```cpp
	            if(j == k) {
	```
	Checks if the slow pointer (`j`) and the fast pointer (`k`) meet, indicating a potential cycle.

9. **Cycle Detection**
	```cpp
	                if(j == getIdx(j, nums)) break;
	```
	If the slow pointer meets itself (i.e., points to its own index), the loop breaks because it’s not part of a valid cycle.

10. **Cycle Detection**
	```cpp
	                return true;
	```
	If the slow pointer meets the fast pointer and the cycle is valid, the function returns `true`, indicating a cycle has been found.

11. **Pointer Update**
	```cpp
	            j = getIdx(j, nums);
	```
	Moves the slow pointer (`j`) to the next index calculated by the `getIdx` helper function.

12. **Pointer Update**
	```cpp
	            k = getIdx(getIdx(k, nums), nums);
	```
	Moves the fast pointer (`k`) to the next index, jumping two steps ahead by calling `getIdx` twice.

13. **Pointer Reset**
	```cpp
	        j = i;
	```
	Resets the slow pointer (`j`) back to the current index `i`.

14. **Variable Initialization**
	```cpp
	        int val = nums[i];
	```
	Stores the value at `nums[i]` in the variable `val` to help mark the elements as visited.

15. **Marking Visited**
	```cpp
	        while(nums[j] * val > 0) {
	```
	Enters a while loop to mark all elements in the current cycle as visited (setting them to 0), preventing revisiting them in future iterations.

16. **Pointer Update**
	```cpp
	            int next = getIdx(j, nums);
	```
	Calculates the next index in the cycle using the `getIdx` helper function.

17. **Marking Visited**
	```cpp
	            nums[j] = 0;
	```
	Marks the current element as visited by setting it to 0.

18. **Pointer Update**
	```cpp
	            j = next;
	```
	Moves the slow pointer (`j`) to the next index in the cycle.

19. **Return Statement**
	```cpp
	    return false;
	```
	Returns `false` if no cycle was detected in the array.

20. **Helper Function**
	```cpp
	int getIdx(int i, vector<int> &nums) {
	```
	Defines the helper function `getIdx`, which calculates the next index in the circular array using modulo arithmetic.

21. **Helper Function**
	```cpp
	    int n = nums.size();
	```
	Gets the size of the array `nums`.

22. **Helper Function**
	```cpp
	    return i + nums[i] >= 0? (i + nums[i]) % n: n + ((i + nums[i]) % n);
	```
	Returns the next index after applying the circular wrap-around logic using modulo arithmetic.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we iterate through the array once, checking for cycles.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as no extra space is required apart from a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/circular-array-loop/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
