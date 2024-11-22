
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
+++



---
**Code:**

{{< highlight cpp >}}
int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine how many days are there in common between two date ranges in a year. Given two date intervals (for two different people), we are tasked with counting the number of overlapping days between these intervals, considering that a year has 365 days.

### Approach

To solve this problem, we convert the given date strings into day numbers of the year, where the first day of the year (January 1st) is numbered as `0`, the second day as `1`, and so on. Once we have the date intervals converted to day numbers, we can check how many days overlap between the two given date ranges.

#### Steps Involved:

1. **Date Conversion to Day of Year**: 
    - Convert each given date (in the format `"MM-DD"`) to the corresponding day number in the year. This is done by calculating the number of days that have passed from January 1st to the given date.
    - To achieve this, the code first extracts the month and day from the date string. Then it calculates the cumulative days from the beginning of the year (accounting for the number of days in each month).
  
2. **Count Overlapping Days**: 
    - After converting both date ranges to day numbers (using the helper function `td`), we compare each day in the year to check if it falls within both ranges. If a day is in the intersection of both ranges, it is counted as an overlapping day.

3. **Result Calculation**:
    - Finally, we count how many days overlap between the two date ranges and return the result.

### Code Breakdown (Step by Step)

#### Helper Function `td` - Convert Date to Day of Year

```cpp
int td(string s) {
    int m = s[1] - '0' + 10*(s[0] - '0');  // Month extraction
    int d = s[4] - '0' + 10*(s[3] - '0');  // Day extraction
    --m;  // Adjust month index for 0-based indexing
    while (m > 0) {  // Accumulate days of all months before the given month
        d += md[m];  // Add days of the previous month
        --m;
    }
    return d;  // Return the total number of days since the beginning of the year
}
```

- **Month and Day Extraction**: 
    - The string `s` is in the format `"MM-DD"`, so we first extract the month (`m`) and the day (`d`).
    - We convert the month from a 2-digit string to an integer and subtract 1 to make the month 0-based (January is month `0`).
  
- **Cumulative Day Calculation**:
    - We add the number of days for all the months preceding the given month (using the `md` array that stores the number of days in each month).
  
- **Return the Day of Year**:
    - The function returns the cumulative number of days from January 1st to the given date.

#### Main Function `countDaysTogether` - Calculate Overlapping Days

```cpp
int countDaysTogether(string sa1, string sa2, string sb1, string sb2) {
    int a1 = td(sa1), a2 = td(sa2), b1 = td(sb1), b2 = td(sb2);
    int ans = 0;
    for (int i = 0; i < 367; ++i) {  // Iterate over all days in a year (365 days + 2 for easier boundary handling)
        if (a1 <= i && i <= a2 && b1 <= i && i <= b2) {  // Check if the day is within both ranges
            ++ans;  // Increment count if the day is in both ranges
        }
    }
    return ans;  // Return the total number of overlapping days
}
```

- **Convert Dates to Day Numbers**:
    - The four input dates (`sa1`, `sa2`, `sb1`, `sb2`) are converted to their respective day numbers using the `td` helper function. 
    - `a1` and `a2` are the start and end days of the first range (for the first person), and `b1` and `b2` are for the second range (for the second person).
  
- **Loop Over All Possible Days in a Year**:
    - The loop runs from `0` to `366`, representing the days of the year (from January 1st to December 31st, with an extra day `366` for easier boundary handling).
  
- **Check for Overlap**:
    - For each day `i` in the loop, we check if the day falls within both date ranges. Specifically, the day `i` should lie between `a1` and `a2` (inclusive) and between `b1` and `b2` (inclusive).
  
- **Count Overlapping Days**:
    - If day `i` is in both ranges, we increment the count (`ans`).
  
- **Return the Result**:
    - After checking all days, the function returns the total number of overlapping days as the result.

### Complexity

#### Time Complexity:
- The time complexity of this solution is **O(1)**. The operations performed include:
  - Converting four date strings into day numbers (constant time operations).
  - Iterating over all 367 possible days and checking if each day lies within both date ranges (constant time operations).
- Since all operations inside the loop are constant-time checks, the overall time complexity is **O(1)** for fixed inputs (since the number of days in a year is constant).

#### Space Complexity:
- The space complexity is also **O(1)** because:
  - We are using only a fixed amount of space for the `md` array (which stores the number of days in each month) and other variables (`a1`, `a2`, `b1`, `b2`, and `ans`).
  
Thus, both the time and space complexities are constant, making the solution highly efficient.

### Conclusion

This approach efficiently counts the number of overlapping days between two date ranges in a year. By converting the date strings into day numbers and iterating over all possible days in the year, we can easily check if a given day falls within both date ranges. This solution has constant time and space complexity, making it optimal for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-days-spent-together/description/)

---
{{< youtube D12AShvqNfE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
