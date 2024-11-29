
+++
authors = ["grid47"]
title = "Leetcode 2960: Count Tested Devices After Test Operations"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2960: Count Tested Devices After Test Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "77lcjZ2prk8"
youtube_upload_date="2023-12-11"
youtube_thumbnail="https://i.ytimg.com/vi/77lcjZ2prk8/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array batteryPercentages representing the battery levels of devices. Perform tests on each device in order, testing a device if its battery percentage is greater than 0 and decrementing the battery percentage of all subsequent devices by 1. Return the number of devices that can be tested after performing the operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array 'batteryPercentages' of length 'n'. Each element in the array represents the battery percentage of a device.
- **Example:** `batteryPercentages = [3, 2, 1, 5, 4]`
- **Constraints:**
	- 1 <= n <= 100
	- 0 <= batteryPercentages[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of devices that can be tested based on the described operations.
- **Example:** `4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To count how many devices will be tested after performing the described operations on the array.

- Initialize a counter for tested devices.
- Iterate over the array from left to right.
- For each device, check if its battery percentage is greater than 0. If so, test the device and decrement all subsequent devices' battery percentages by 1, ensuring they do not go below 0.
- Track and update the count of devices that have been tested.
{{< dots >}}
### Problem Assumptions ✅
- The array will always contain at least one device.
- All battery percentages are valid within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: batteryPercentages = [3, 2, 1, 5, 4]`  \
  **Explanation:** The sequence of operations results in 4 devices being tested. Each test operation reduces the battery of subsequent devices.

- **Input:** `Input: batteryPercentages = [1, 0, 0, 1]`  \
  **Explanation:** Only two devices are tested, as the others have battery percentages of 0.

{{< dots >}}
## Approach 🚀
We will use a greedy approach to simulate the test process for each device and count how many devices can be tested.

### Initial Thoughts 💭
- The key is to track the battery percentage changes as we process each device.
- We will iterate through the devices, and each time we test a device, we must adjust the battery percentages of all subsequent devices.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one device in the input, so no need to handle empty arrays.
- Ensure that the solution handles arrays with up to 100 devices efficiently.
- Consider the case where all battery percentages are 0 (no devices will be tested).
- The solution should run efficiently even for the upper bound of input sizes.
{{< dots >}}
## Code 💻
```cpp
int countTestedDevices(vector<int>& batteryPercentages) {
    int ans = 0;
    for(auto b: batteryPercentages) ans += (b > ans)?1: 0;
    return ans;
}
```

This function counts the number of devices in the 'batteryPercentages' array that have a battery percentage greater than the number of devices tested so far.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countTestedDevices(vector<int>& batteryPercentages) {
	```
	Defines the function 'countTestedDevices' that takes a vector 'batteryPercentages' and returns the count of devices whose battery percentage is greater than the number of devices counted so far.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes the variable 'ans' to 0. This variable will store the count of devices with battery percentages greater than the count of devices tested so far.

3. **For Loop Start**
	```cpp
	    for(auto b: batteryPercentages) ans += (b > ans)?1: 0;
	```
	Starts a for loop that iterates through each battery percentage in 'batteryPercentages'. If the current battery percentage 'b' is greater than 'ans', it increments 'ans' by 1. This is a form of counting devices whose battery percentage exceeds the previous count.

4. **Return Result**
	```cpp
	    return ans;
	```
	Returns the value of 'ans', which represents the total number of devices that have a battery percentage greater than the number of devices counted so far.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the batteryPercentages array. Each device is processed once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a few extra variables for tracking the count of tested devices and the battery percentages.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-tested-devices-after-test-operations/description/)

---
{{< youtube 77lcjZ2prk8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
