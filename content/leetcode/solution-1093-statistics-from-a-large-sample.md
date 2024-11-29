
+++
authors = ["grid47"]
title = "Leetcode 1093: Statistics from a Large Sample"
date = "2024-07-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1093: Statistics from a Large Sample in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Probability and Statistics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "05WQZvhYcAg"
youtube_upload_date="2020-01-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/05WQZvhYcAg/maxresdefault.webp"
comments = true
+++



---
You are given a dataset of integers in the range [0, 255], represented by an array `count` where `count[k]` denotes the frequency of number `k` in the dataset. From this dataset, compute the following statistics: minimum, maximum, mean, median, and mode.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array `count` of size 256, where each element `count[k]` represents the frequency of number `k` in the dataset.
- **Example:** `[0, 5, 0, 2, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`
- **Constraints:**

{{< dots >}}
### Output Specifications 📤
- **Output:** An array containing the five statistics in the following order: minimum, maximum, mean, median, and mode.
- **Example:** `[1.0, 6.0, 2.2, 2.0, 1.0]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the minimum, maximum, mean, median, and mode of the dataset based on the provided count array.

- Calculate the minimum and maximum by iterating over the count array and identifying the smallest and largest indices with non-zero counts.
- Calculate the mean by computing the total sum of the dataset and dividing by the total number of elements.
- Determine the median by finding the middle element (or average of two middle elements if the number of elements is even).
- Find the mode by identifying the number with the highest frequency.
{{< dots >}}
### Problem Assumptions ✅
- The array count will always contain at least one non-zero value.
- The sum of the values in the count array will never be zero.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [0, 5, 0, 2, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`  \
  **Explanation:** In this example, the dataset has the numbers 1, 2, 3, 4 with respective frequencies: 5, 2, 3, 4. The minimum value is 1, the maximum is 6, the mean is approximately 2.2, the median is 2, and the mode is 1.

{{< dots >}}
## Approach 🚀
The goal is to extract the required statistics (minimum, maximum, mean, median, mode) from the count array, ensuring accurate computation of each statistic.

### Initial Thoughts 💭
- The dataset is represented as the count of each number in the range [0, 255].
- Efficient traversal of the count array is crucial for optimal performance.
- I will first identify the minimum and maximum by scanning the count array.
- Next, I will calculate the total sum of the dataset and divide by the total number of elements to compute the mean.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty, as it always contains 256 elements.
- Handle cases where the total count can be very large (up to 10^9).
- Ensure accurate handling of large numbers in the count array.
- The sum of the counts can be large, so the solution must be efficient in terms of both time and space.
{{< dots >}}
## Code 💻
```cpp

double getKth(vector<int> &cnt, int k) {
    int x = 0;
    for(int i = 0; i < 256; i++) {
        x += cnt[i];
        if(x >= k) return i;
    }
    return 256;
}

vector<double> sampleStats(vector<int>& cnt) {
    double mn = 257, mx = -1, sum = 0, mode, frq = 0, median;
    int x = 0;
    for(int i = 0; i < 256; i++) {
        if(cnt[i] > 0) {
            mn = min(mn, (double)i);
            mx = i;
            sum += (double)cnt[i] * i;
            if(frq < cnt[i]) {
                frq = cnt[i];
                mode = i;
            }
            x += cnt[i];                 
        }
    }

    if(x % 2 == 0) {
        double a = getKth(cnt, x / 2);
        double b = getKth(cnt, x / 2 + 1);
        median = (a + b) / 2;
    } else median = getKth(cnt, x/ 2 + 1);
    
    return vector<double> {mn, mx, sum / x, median, mode };
}
```

This code calculates various statistical measures from a frequency count of values (cnt), such as minimum, maximum, mean, median, and mode.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	double getKth(vector<int> &cnt, int k) {
	```
	Defines the function to find the k-th smallest element based on a cumulative count array.

2. **Variable Initialization**
	```cpp
	    int x = 0;
	```
	Initializes a variable x to keep track of the cumulative count while iterating through the frequency array.

3. **Looping through Array**
	```cpp
	    for(int i = 0; i < 256; i++) {
	```
	Iterates through the frequency array to calculate the cumulative count.

4. **Cumulative Sum**
	```cpp
	        x += cnt[i];
	```
	Adds the frequency count of the current value to the cumulative sum.

5. **Conditional Check**
	```cpp
	        if(x >= k) return i;
	```
	Checks if the cumulative sum has reached or exceeded the desired k-th value. If so, returns the index.

6. **Return Fallback**
	```cpp
	    return 256;
	```
	If no value meets the condition, return 256 as a default (out-of-bound value).

7. **Function Definition**
	```cpp
	vector<double> sampleStats(vector<int>& cnt) {
	```
	Defines the function to calculate and return various statistics based on the frequency array.

8. **Variable Initialization**
	```cpp
	    double mn = 257, mx = -1, sum = 0, mode, frq = 0, median;
	```
	Initializes variables to track minimum, maximum, sum, mode, frequency, and median values.

9. **Frequency Count**
	```cpp
	    int x = 0;
	```
	Initializes a counter to accumulate the total number of elements.

10. **Looping through Array**
	```cpp
	    for(int i = 0; i < 256; i++) {
	```
	Iterates through the frequency array to calculate various statistics.

11. **Conditional Check**
	```cpp
	        if(cnt[i] > 0) {
	```
	Checks if the current value has a non-zero frequency.

12. **Update Minimum Value**
	```cpp
	            mn = min(mn, (double)i);
	```
	Updates the minimum value if a smaller value is encountered.

13. **Update Maximum Value**
	```cpp
	            mx = i;
	```
	Updates the maximum value with the current value.

14. **Sum Calculation**
	```cpp
	            sum += (double)cnt[i] * i;
	```
	Calculates the total sum of all values weighted by their frequencies.

15. **Update Mode**
	```cpp
	            if(frq < cnt[i]) {
	```
	Checks if the current frequency is greater than the previously recorded frequency.

16. **Set Mode**
	```cpp
	                frq = cnt[i];
	```
	Updates the frequency with the current highest frequency.

17. **Set Mode Value**
	```cpp
	                mode = i;
	```
	Updates the mode with the current value.

18. **Update Total Count**
	```cpp
	            x += cnt[i];                 
	```
	Accumulates the total count of elements.

19. **Check for Even Total Count**
	```cpp
	    if(x % 2 == 0) {
	```
	Checks if the total count is even to compute the median.

20. **Calculate Median for Even Count**
	```cpp
	        double a = getKth(cnt, x / 2);
	```
	Calculates the first element for median calculation.

21. **Calculate Median for Even Count**
	```cpp
	        double b = getKth(cnt, x / 2 + 1);
	```
	Calculates the second element for median calculation.

22. **Compute Median**
	```cpp
	        median = (a + b) / 2;
	```
	Computes the median as the average of the two elements.

23. **Calculate Median for Odd Count**
	```cpp
	    } else median = getKth(cnt, x/ 2 + 1);
	```
	Computes the median directly for odd total counts.

24. **Return Final Results**
	```cpp
	    return vector<double> {mn, mx, sum / x, median, mode };
	```
	Returns the calculated statistics as a vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of non-zero values in the count array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since the problem only requires a few additional variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/statistics-from-a-large-sample/description/)

---
{{< youtube 05WQZvhYcAg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
