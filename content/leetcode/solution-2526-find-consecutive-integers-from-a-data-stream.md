
+++
authors = ["grid47"]
title = "Leetcode 2526: Find Consecutive Integers from a Data Stream"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2526: Find Consecutive Integers from a Data Stream in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Queue","Counting","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3VXPkJ8bInY"
youtube_upload_date="2023-01-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3VXPkJ8bInY/maxresdefault.webp"
comments = true
+++



---
You need to implement a DataStream class that processes a stream of integers and checks whether the last k integers in the stream are equal to a specified value.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers: `value`, the target value to check for, and `k`, the number of consecutive integers to be checked.
- **Example:** `[3, 4]`
- **Constraints:**
	- 1 <= value, num <= 10^9
	- 1 <= k <= 10^5
	- At most 10^5 calls will be made to consec.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value: `true` if the last k integers are equal to the target value, otherwise `false`. If fewer than k integers have been parsed, return `false`.
- **Example:** `false`
- **Constraints:**
	- The output is a boolean value representing the result of the consec method.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if the last k integers in the stream are equal to the target value.

- Store the target value and the integer k.
- Maintain a count of consecutive integers equal to the target value.
- For each call to consec(), add the integer to the stream and update the count. If the count reaches k, return true. If not, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input values are within the given constraints.
- The number of consec calls will not exceed 10^5.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, 4], [3], [3], [3], [4]`  \
  **Explanation:** The DataStream object is initialized with value 3 and k = 4. It returns false until 4 consecutive values of 3 are encountered.

- **Input:** `[5, 2], [5], [5]`  \
  **Explanation:** The DataStream object is initialized with value 5 and k = 2. It returns false initially, then returns true after two consecutive values of 5.

{{< dots >}}
## Approach 🚀
Use a counter to track the number of consecutive occurrences of the target value. Reset the counter when the current value is not equal to the target.

### Initial Thoughts 💭
- A simple solution involves tracking consecutive integers and resetting the count when the condition fails.
- We will use a counter to store the number of consecutive target values and return true when the counter reaches k.
{{< dots >}}
### Edge Cases 🌐
- There are no cases with empty inputs as each consec method call requires a number to be added.
- Ensure that the solution can handle large inputs efficiently, especially when there are up to 10^5 consec calls.
- Handle cases where k is 1 or the input numbers are equal to the target value.
- Ensure that the solution meets the time complexity constraints and handles the maximum number of consec calls.
{{< dots >}}
## Code 💻
```cpp
int val, k, cnt = 0;
DataStream(int value, int k) {
    val = value;
    this->k = k;
}

bool consec(int num) {
    if(val == num) cnt = min(k, cnt+1);
    else {
        cnt = 0;
    }
    return k == cnt;
}
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
```

This code implements a DataStream class that tracks consecutive occurrences of a value. The 'consec' function returns true when the value has appeared consecutively 'k' times.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int val, k, cnt = 0;
	```
	This initializes three integer variables: 'val' to store the value, 'k' for the threshold number of consecutive appearances, and 'cnt' to track the current count of consecutive appearances, initially set to 0.

2. **Constructor**
	```cpp
	DataStream(int value, int k) {
	```
	This is the constructor of the DataStream class, which initializes the 'val' and 'k' variables when an instance of the class is created.

3. **Variable Assignment**
	```cpp
	    val = value;
	```
	This assigns the passed 'value' to the 'val' variable, which will be the number tracked for consecutive occurrences.

4. **Variable Assignment**
	```cpp
	    this->k = k;
	```
	This assigns the passed 'k' value (threshold for consecutive occurrences) to the instance variable 'k'.

5. **Method Definition**
	```cpp
	bool consec(int num) {
	```
	This is the definition of the 'consec' method, which checks if the given number 'num' has appeared consecutively 'k' times.

6. **Condition Check**
	```cpp
	    if(val == num) cnt = min(k, cnt+1);
	```
	This checks if the current 'num' matches 'val'. If true, it increments 'cnt' (count of consecutive appearances), but ensures that 'cnt' does not exceed the threshold 'k'.

7. **Reset Count**
	```cpp
	        cnt = 0;
	```
	If 'num' is not equal to 'val', the count of consecutive appearances is reset to 0.

8. **Return Statement**
	```cpp
	    return k == cnt;
	```
	This checks if 'cnt' (the current consecutive count) equals 'k'. If true, the method returns true, indicating that 'num' has appeared 'k' times consecutively.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant for each consec call as it involves updating a counter and checking a condition.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only store a few integer variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/)

---
{{< youtube 3VXPkJ8bInY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
