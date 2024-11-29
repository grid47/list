
+++
authors = ["grid47"]
title = "Leetcode 1860: Incremental Memory Leak"
date = "2024-05-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1860: Incremental Memory Leak in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BoIe1HDe83c"
youtube_upload_date="2021-05-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BoIe1HDe83c/maxresdefault.webp"
comments = true
+++



---
You are given two memory sticks with certain amounts of available memory. A program runs and allocates increasing amounts of memory to the stick with more available memory. If neither stick has enough memory to allocate the required amount, the program crashes. Determine when the program crashes and the remaining memory on each stick.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, memory1 and memory2, representing the available memory on the two sticks.
- **Example:** `memory1 = 5, memory2 = 6`
- **Constraints:**
	- 0 <= memory1, memory2 <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array with three elements: the crash time (the second at which the program crashes), the remaining memory on the first stick, and the remaining memory on the second stick.
- **Example:** `[4, 0, 2]`
- **Constraints:**
	- The program crashes when one of the memory sticks cannot allocate the required memory.

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate the memory allocation process until the program crashes. At each second, allocate memory to the stick with more available memory, or to the first stick if both sticks have the same available memory. Stop when neither stick has enough memory to allocate.

- At each second, compare the available memory on both sticks.
- Allocate i bits to the stick with more available memory.
- If both sticks have the same available memory, allocate to the first stick.
- If neither stick has enough memory to allocate i bits, return the crash time and the remaining memory on both sticks.
{{< dots >}}
### Problem Assumptions ✅
- Both memory sticks have a non-negative amount of memory.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: memory1 = 5, memory2 = 6`  \
  **Explanation:** The memory is allocated as follows: At the 1st second, 1 bit is allocated to stick 2 (memory2 = 5). At the 2nd second, 2 bits are allocated to stick 2 (memory2 = 3). At the 3rd second, 3 bits are allocated to stick 1 (memory1 = 2). At the 4th second, 4 bits are allocated to stick 2 (memory2 = -1). The program crashes here.

{{< dots >}}
## Approach 🚀
The solution involves simulating the memory allocation process, allocating memory in increasing amounts, and stopping when the program crashes due to insufficient memory.

### Initial Thoughts 💭
- The program allocates memory to the stick with more available memory.
- By simulating the memory allocation process and checking if both sticks have enough memory, we can determine when the program crashes.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs to handle, as memory1 and memory2 will always be non-negative.
- If the values for memory1 or memory2 are extremely large, the loop may run for a large number of iterations.
- The program should handle cases where one memory stick has zero memory.
- The program should return the correct result even for edge cases.
{{< dots >}}
## Code 💻
```cpp
vector<int> memLeak(int mem1, int mem2) {
    int i = 1;
    while(i <= mem1 || i <= mem2) {
        if(mem1 >= mem2) {
            mem1 -= i;
        } else mem2 -= i;
        i++;
    }
    return vector<int>{i, mem1, mem2};
}
```

The function `memLeak` simulates a memory leak process where two memory blocks are reduced iteratively by increasing amounts, starting from 1. The function returns the iteration count `i` and the remaining memory for both blocks once no further reduction is possible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> memLeak(int mem1, int mem2) {
	```
	Define the function `memLeak`, which takes two integer inputs `mem1` and `mem2`, representing the memory blocks.

2. **Variable Initialization**
	```cpp
	    int i = 1;
	```
	Initialize the variable `i` to 1, which represents the amount of memory to be subtracted in each iteration.

3. **While Loop Condition**
	```cpp
	    while(i <= mem1 || i <= mem2) {
	```
	Start a `while` loop that continues as long as either memory block has sufficient memory to subtract (i.e., `i` is less than or equal to `mem1` or `mem2`).

4. **If Condition**
	```cpp
	        if(mem1 >= mem2) {
	```
	Check if `mem1` is greater than or equal to `mem2`. If true, reduce `mem1` by `i`.

5. **Memory Reduction (mem1)**
	```cpp
	            mem1 -= i;
	```
	Subtract the value of `i` from `mem1`.

6. **Else Condition**
	```cpp
	        } else mem2 -= i;
	```
	If the `if` condition is false, subtract the value of `i` from `mem2`.

7. **Increment i**
	```cpp
	        i++;
	```
	Increment the value of `i` to gradually increase the memory reduction in each iteration.

8. **Return Statement**
	```cpp
	    return vector<int>{i, mem1, mem2};
	```
	Return a vector containing the iteration count `i`, and the remaining memory in both `mem1` and `mem2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, the program runs for n seconds, where n is the time before the program crashes.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only store the memory values and the current second.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/incremental-memory-leak/description/)

---
{{< youtube BoIe1HDe83c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
