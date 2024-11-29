
+++
authors = ["grid47"]
title = "Leetcode 2208: Minimum Operations to Halve Array Sum"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2208: Minimum Operations to Halve Array Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4HrGj7pwQww"
youtube_upload_date="2022-03-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4HrGj7pwQww/maxresdefault.webp"
comments = true
+++



---
You are given an array nums of positive integers. In each operation, you can reduce any number in the array by half. Your goal is to return the minimum number of operations required to reduce the sum of the array by at least half.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums containing positive integers.
- **Example:** `nums = [5, 19, 8, 1]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^7

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to reduce the sum of nums by at least half.
- **Example:** `For input nums = [5, 19, 8, 1], the output is 3.`
- **Constraints:**
	- The output should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Minimize the number of operations to reduce the sum of nums by at least half.

- Calculate the initial sum of the array.
- Use a max-heap to repeatedly reduce the largest number in the array by half.
- Keep track of the number of operations until the sum is reduced by at least half.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums is not empty.
- All elements in nums are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 19, 8, 1]`  \
  **Explanation:** By reducing 19 to 9, then 9 to 4, and 8 to 4, we reduce the sum by at least half, using 3 operations.

- **Input:** `nums = [3, 8, 20]`  \
  **Explanation:** By reducing 20 to 10, then 10 to 5, and 3 to 1.5, we reduce the sum by at least half, using 3 operations.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to repeatedly reduce the largest elements in the array until the sum is reduced by at least half. A greedy approach using a max-heap allows us to efficiently pick the largest number to halve.

### Initial Thoughts 💭
- The larger the number we reduce, the more significant the reduction in the total sum.
- We can use a max-heap to always halve the largest element and track the number of operations.
{{< dots >}}
### Edge Cases 🌐
- The array cannot be empty, as the input is constrained to contain at least one number.
- For large arrays, efficient use of heaps and careful handling of large values is required.
- If all elements are very small compared to others, fewer operations will be needed.
- The algorithm should handle input sizes up to 10^5 efficiently.
{{< dots >}}
## Code 💻
```cpp

int halveArray(vector<int>& nums) {
    int n = nums.size();
    double sum = 0;
    priority_queue<double, vector<double>, less<double>> pq;
    for(int i = 0; i < n; i++){
        pq.push(nums[i]);
        sum += nums[i];
    }
    
    sum = sum / 2;
    
    double tmp = 0;
    int cnt = 0;
    while(tmp < sum && !pq.empty()) {

        double x = (pq.top() / 2);
        tmp += x;

        pq.pop();
        pq.push(x);

        cnt++;
    }
    
    return cnt;
}
```

This function attempts to halve an array's total sum by repeatedly halving the largest elements and counting the operations needed to achieve the desired sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int halveArray(vector<int>& nums) {
	```
	Function declaration with the input parameter 'nums', a vector of integers.

2. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculate the size of the input array to iterate over all elements.

3. **Sum Initialization**
	```cpp
	    double sum = 0;
	```
	Initialize the sum variable to accumulate the total sum of the array elements.

4. **Priority Queue**
	```cpp
	    priority_queue<double, vector<double>, less<double>> pq;
	```
	A max-heap priority queue is initialized to store the elements of the array for efficient access to the largest element.

5. **Iteration Start**
	```cpp
	    for(int i = 0; i < n; i++){
	```
	Loop over all the elements of the array to populate the priority queue and calculate the total sum.

6. **Push to Queue**
	```cpp
	        pq.push(nums[i]);
	```
	Push each element of the array into the priority queue.

7. **Sum Update**
	```cpp
	        sum += nums[i];
	```
	Accumulate the sum of the array elements.

8. **Calculate Half**
	```cpp
	    sum = sum / 2;
	```
	Set the target sum to half of the total sum of the array.

9. **Temporary Sum Initialization**
	```cpp
	    double tmp = 0;
	```
	Initialize the temporary sum to track the running total of the halved elements.

10. **Counter Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize a counter variable to count how many operations (halving steps) are performed.

11. **Loop Start**
	```cpp
	    while(tmp < sum && !pq.empty()) {
	```
	Start a loop that continues until the temporary sum exceeds the target or the priority queue is empty.

12. **Find Largest Element**
	```cpp
	        double x = (pq.top() / 2);
	```
	Retrieve the largest element from the priority queue and halve it.

13. **Update Temporary Sum**
	```cpp
	        tmp += x;
	```
	Add the halved value to the temporary sum.

14. **Pop and Push**
	```cpp
	        pq.pop();
	```
	Remove the top element (largest element) from the priority queue.

15. **Reinsert Halved Value**
	```cpp
	        pq.push(x);
	```
	Push the halved value back into the priority queue for further processing.

16. **Increment Counter**
	```cpp
	        cnt++;
	```
	Increment the counter to track the number of operations performed.

17. **Return Result**
	```cpp
	    return cnt;
	```
	Return the count of operations performed to halve the array to the target sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the heap operations for each element in the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the elements in the heap.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/)

---
{{< youtube 4HrGj7pwQww >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
