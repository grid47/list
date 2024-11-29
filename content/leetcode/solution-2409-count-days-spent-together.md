
+++
authors = ["grid47"]
title = "Leetcode 2409: Count Days Spent Together"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2409: Count Days Spent Together in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "D12AShvqNfE"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/D12AShvqNfE/maxresdefault.jpg"
comments = true
+++



---
Alice and Bob are traveling to Rome for separate business meetings. You are given four strings representing their travel dates: arriveAlice, leaveAlice, arriveBob, and leaveBob. Each string follows the format 'MM-DD', which represents the month and day of their respective travel dates. Alice will be in Rome from 'arriveAlice' to 'leaveAlice', while Bob will be in the city from 'arriveBob' to 'leaveBob'. Your task is to calculate how many days they will both be in Rome together.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of four strings: arriveAlice, leaveAlice, arriveBob, and leaveBob. Each string represents a date in the format 'MM-DD'.
- **Example:** `arriveAlice = '07-10', leaveAlice = '07-15', arriveBob = '07-12', leaveBob = '07-17'`
- **Constraints:**
	- 1 <= month <= 12
	- 1 <= day <= 31
	- Alice's arrival date is earlier than or equal to their departure date.
	- Bob's arrival date is earlier than or equal to their departure date.
	- The dates are valid within a non-leap year.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the number of days Alice and Bob will both be in Rome together.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the overlap between the two time intervals (one for Alice and one for Bob). The number of days they both spend in Rome together is the length of the intersection of these two intervals.

- 1. Convert the string dates into a day of the year format.
- 2. Find the overlapping range by calculating the maximum of the start dates and the minimum of the end dates.
- 3. If there is an overlap, calculate the number of overlapping days by subtracting the start date of the overlap from the end date.
- 4. Return the total number of overlapping days.
{{< dots >}}
### Problem Assumptions ✅
- The dates provided are valid and fall within the same calendar year.
- Alice and Bob may or may not have overlapping travel dates.
{{< dots >}}
## Examples 🧩
- **Input:** `arriveAlice = '07-10', leaveAlice = '07-15', arriveBob = '07-12', leaveBob = '07-17'`  \
  **Explanation:** In this example, Alice is in Rome from July 10 to July 15, and Bob is in Rome from July 12 to July 17. They will both be in Rome together from July 12 to July 15, which gives 4 days of overlap.

- **Input:** `arriveAlice = '10-01', leaveAlice = '10-31', arriveBob = '11-01', leaveBob = '12-31'`  \
  **Explanation:** In this example, Alice is in Rome in October, and Bob is in Rome from November onwards. There are no overlapping days, so the result is 0.

- **Input:** `arriveAlice = '02-15', leaveAlice = '02-18', arriveBob = '02-16', leaveBob = '02-20'`  \
  **Explanation:** Alice is in Rome from February 15 to February 18, and Bob is in Rome from February 16 to February 20. They overlap from February 16 to February 18, so the result is 3 days.

{{< dots >}}
## Approach 🚀
We will convert the dates into a single day number of the year (from 1 to 365) and then calculate the overlap between Alice's and Bob's travel dates.

### Initial Thoughts 💭
- The challenge is to handle the overlap calculation efficiently.
- We need to account for all valid months and days of a non-leap year.
- A simple solution can be derived by converting the dates into day numbers and calculating the overlap directly.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since all dates are valid.
- Given the constraints, all inputs are manageable, and the solution runs in constant time due to the fixed nature of date operations.
- If there is no overlap, return 0 days.
- If Alice and Bob have identical travel dates, the total days together will be the length of the interval.
- The solution is optimized for constant time complexity due to the simplicity of date conversion and comparison operations.
{{< dots >}}
## Code 💻
```cpp
class Solution {
	// Convert date to respective number in year.
int td(string s) {
    int m = s[1] - '0' + 10*(s[0] - '0');
    int d = s[4] - '0' + 10*(s[3] - '0');
    --m;
    while (m > 0) {
        d += md[m];
        --m;
    }
    return d;
}
public:
int countDaysTogether(string sa1, string sa2, string sb1, string sb2) {
    int a1 = td(sa1), a2 = td(sa2), b1 = td(sb1), b2 = td(sb2);
    int ans = 0;
		// Check all 365 days in year
    for (int i = 0; i < 367; ++i) {
        if (a1 <= i && i <= a2 && b1 <= i && i <= b2) {
            ++ans;
        }
    }
    return ans;
}
```

This is the full implementation of a function `countDaysTogether` that calculates the number of overlapping days between two given date ranges.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	This class is used to solve the problem of counting overlapping days between two date ranges.

2. **Comment**
	```cpp
		// Convert date to respective number in year.
	```
	This comment describes the purpose of the following function, which converts a date string to a day number within the year.

3. **Function Definition**
	```cpp
	int td(string s) {
	```
	The function `td` takes a date string `s` and converts it to a day number within the year.

4. **Operation**
	```cpp
	    int m = s[1] - '0' + 10*(s[0] - '0');
	```
	Extracts the month from the date string and converts it into an integer representation.

5. **Operation**
	```cpp
	    int d = s[4] - '0' + 10*(s[3] - '0');
	```
	Extracts the day from the date string and converts it into an integer representation.

6. **Decrement**
	```cpp
	    --m;
	```
	Decreases the month value by 1, since month indices in the `md` array start from 0.

7. **Loop**
	```cpp
	    while (m > 0) {
	```
	Iterates through the months to accumulate the total number of days up to the specified month.

8. **Operation**
	```cpp
	        d += md[m];
	```
	Adds the number of days in the current month to the total day count `d`.

9. **Decrement**
	```cpp
	        --m;
	```
	Decreases the month index and moves to the previous month.

10. **Return Statement**
	```cpp
	    return d;
	```
	Returns the total day count calculated for the given date.

11. **Access Modifier**
	```cpp
	public:
	```
	Indicates the start of the public section of the class, where the main function is located.

12. **Function Definition**
	```cpp
	int countDaysTogether(string sa1, string sa2, string sb1, string sb2) {
	```
	This function calculates the number of overlapping days between two date ranges.

13. **Function Call**
	```cpp
	    int a1 = td(sa1), a2 = td(sa2), b1 = td(sb1), b2 = td(sb2);
	```
	Calls the `td` function to convert the given date strings into day numbers.

14. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes the `ans` variable to count the number of overlapping days.

15. **Comment**
	```cpp
			// Check all 365 days in year
	```
	This comment explains the upcoming loop, which checks each day of the year to see if it falls within both date ranges.

16. **Loop**
	```cpp
	    for (int i = 0; i < 367; ++i) {
	```
	Loops through all the days in the year (365 days, plus one extra for boundary checking).

17. **Condition**
	```cpp
	        if (a1 <= i && i <= a2 && b1 <= i && i <= b2) {
	```
	Checks if the current day `i` is within both date ranges.

18. **Increment**
	```cpp
	            ++ans;
	```
	Increments the `ans` variable if the current day `i` is within both date ranges.

19. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the number of overlapping days between the two date ranges.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), as the solution uses simple date calculations and comparisons.
- **Average Case:** O(1), as date operations are constant time.
- **Worst Case:** O(1), since there are only four date strings to process.

The solution is optimal with constant time complexity.

### Space Complexity 💾
- **Best Case:** O(1), since no extra space is needed beyond the input dates.
- **Worst Case:** O(1), as only a few variables are used to store date values.

The solution uses constant space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-days-spent-together/description/)

---
{{< youtube D12AShvqNfE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
