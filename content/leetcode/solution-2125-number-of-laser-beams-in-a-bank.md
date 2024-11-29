
+++
authors = ["grid47"]
title = "Leetcode 2125: Number of Laser Beams in a Bank"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2125: Number of Laser Beams in a Bank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","String","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KLeKv59LAFY"
youtube_upload_date="2024-01-03"
youtube_thumbnail="https://i.ytimg.com/vi/KLeKv59LAFY/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D binary grid, where '1' represents a security device and '0' represents an empty cell. A laser beam can be formed between two devices if they are located on two different rows and no security device is in any row between them. The task is to find the total number of laser beams that can be formed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a grid of '1's and '0's where each string in the array represents a row in the grid.
- **Example:** `bank = ["10101", "00000", "10101"]`
- **Constraints:**
	- 1 <= m, n <= 500
	- Each element of bank is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of laser beams that can be formed.
- **Example:** `Input: bank = ["10101", "00000", "10101"] Output: 4`
- **Constraints:**
	- m == bank.length
	- n == bank[i].length
	- bank[i][j] is either '0' or '1'.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of laser beams that can be formed by finding pairs of security devices that are on different rows with no devices in between.

- For each row in the grid, count the number of security devices.
- For each pair of rows with security devices, compute the number of beams as the product of the device counts in those rows.
{{< dots >}}
### Problem Assumptions ✅
- The grid may have rows or columns that are completely empty of security devices.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: bank = ["011001", "000000", "010100", "001000"]`  \
  **Explanation:** The laser beams can be formed between devices on different rows, without any devices in between rows. The total number of beams is 8.

- **Input:** `Input: bank = ["000", "111", "000"]`  \
  **Explanation:** No beams can be formed because the devices are on the same row, and there are no devices on different rows.

{{< dots >}}
## Approach 🚀
To solve this problem, iterate through the grid row by row, counting the number of devices in each row. For every pair of rows with devices, compute the number of laser beams as the product of the number of devices in those rows.

### Initial Thoughts 💭
- Only rows with at least one device contribute to the beam count.
- We need to avoid counting beams between rows with no devices.
{{< dots >}}
### Edge Cases 🌐
- If the grid is empty or has no devices, the result will be 0.
- Ensure the solution handles grids with maximum dimensions (500x500) efficiently.
- If a row has no devices, it should be skipped in the computation of beam counts.
- The solution should be optimized to handle the grid's maximum size.
{{< dots >}}
## Code 💻
```cpp
int numberOfBeams(vector<string> bank) {

    int res = 0, m = bank.size(), n = bank[0].size();

    int cnt = 0, prv = 0;
    for (auto b : bank) 
    {
        cnt = 0;
        for(int i = 0; i < n; i++)
            if (b[i] == '1') cnt++;
        if(cnt > 0) {
            res += prv * cnt;
            prv = cnt;
        }
    }
    return res;
}
```

This function calculates the number of beams between columns that contain at least one '1'. It iterates through each row of the bank, counts the number of '1's in that row, and multiplies the previous count of '1's by the current count, adding the result to the final answer.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfBeams(vector<string> bank) {
	```
	This line defines the function 'numberOfBeams' which takes a vector of strings 'bank' as input. Each string represents a row in the bank, where '1' indicates the presence of a beam.

2. **Variable Initialization**
	```cpp
	    int res = 0, m = bank.size(), n = bank[0].size();
	```
	This line initializes three variables: 'res' to store the result, 'm' to store the number of rows in the bank, and 'n' to store the number of columns (the length of the first row).

3. **Variable Initialization**
	```cpp
	    int cnt = 0, prv = 0;
	```
	This line initializes 'cnt' (to count the number of '1's in the current row) and 'prv' (to store the previous row's count of '1's).

4. **Row Iteration**
	```cpp
	    for (auto b : bank) 
	```
	This line starts a loop that iterates over each row 'b' in the 'bank'.

5. **Row Processing**
	```cpp
	        cnt = 0;
	```
	This line resets 'cnt' to 0 before counting the '1's in the current row.

6. **Column Iteration**
	```cpp
	        for(int i = 0; i < n; i++)
	```
	This line starts a loop that iterates over each column 'i' in the current row.

7. **Column Processing**
	```cpp
	            if (b[i] == '1') cnt++;
	```
	This line checks if the current column contains a '1' and, if so, increments the 'cnt' counter.

8. **Check for Valid Count**
	```cpp
	        if(cnt > 0) {
	```
	This line checks if there are any '1's in the current row. If so, it proceeds with the calculation.

9. **Result Calculation**
	```cpp
	            res += prv * cnt;
	```
	This line adds the product of the previous row's '1' count ('prv') and the current row's '1' count ('cnt') to the result ('res').

10. **Update Previous Count**
	```cpp
	            prv = cnt;
	```
	This line updates 'prv' to the current row's '1' count ('cnt'), to be used in the next iteration.

11. **Return Result**
	```cpp
	    return res;
	```
	This line returns the final result, which is the total number of beams calculated from all rows.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

We need to scan each row and count the devices, which takes O(n) time for each row. Thus, the time complexity is O(m * n), where m is the number of rows and n is the number of columns.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/)

---
{{< youtube KLeKv59LAFY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
