
+++
authors = ["grid47"]
title = "Leetcode 1052: Grumpy Bookstore Owner"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1052: Grumpy Bookstore Owner in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pXFbNuEIn8Q"
youtube_upload_date="2024-06-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pXFbNuEIn8Q/maxresdefault.webp"
comments = true
+++



---
A bookstore owner has a store open for 'n' minutes. During each minute, a certain number of customers enter the store, but the owner may be grumpy and fail to satisfy some customers. The grumpy behavior of the owner is given as a binary array, where 1 means the owner is grumpy and 0 means they are not. The owner has a special technique to remain calm for a specified number of consecutive minutes, but it can only be used once. The goal is to find the maximum number of customers who can be satisfied throughout the day by using this technique.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays: 'customers' and 'grumpy'. The 'customers' array represents the number of customers entering the store during each minute, while the 'grumpy' array indicates whether the owner is grumpy (1) or not (0) during each corresponding minute. You are also given an integer 'minutes' representing the number of consecutive minutes during which the owner can stay calm and not grumpy.
- **Example:** `Input: customers = [2, 3, 1, 4, 6, 2], grumpy = [1, 0, 1, 0, 1, 0], minutes = 2`
- **Constraints:**
	- 1 <= minutes <= n <= 2 * 10^4
	- 0 <= customers[i] <= 1000
	- grumpy[i] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of customers that can be satisfied during the entire day, considering the owner's ability to remain calm for 'minutes' consecutive minutes.
- **Example:** `Output: 13`
- **Constraints:**
	- The result will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The task is to maximize the number of satisfied customers, accounting for both the owner's grumpy minutes and the special technique used to calm the owner for 'minutes' consecutive minutes.

- 1. Compute the total number of satisfied customers without using the calming technique.
- 2. Calculate the additional number of customers that can be satisfied by using the calming technique for each possible set of consecutive minutes.
- 3. Find the maximum number of customers that can be satisfied by combining the satisfied customers and the additional customers from the technique.
{{< dots >}}
### Problem Assumptions ✅
- The owner can only use the calming technique once, for 'minutes' consecutive minutes.
- The number of customers is non-negative and can vary between minutes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: customers = [2, 3, 1, 4, 6, 2], grumpy = [1, 0, 1, 0, 1, 0], minutes = 2`  \
  **Explanation:** Without using the calming technique, the owner satisfies customers during the minutes they are not grumpy. However, by calming the owner during the 3rd and 5th minutes, more customers are satisfied, resulting in a total of 13 customers.

- **Input:** `Input: customers = [5, 1, 2, 3], grumpy = [1, 0, 1, 0], minutes = 1`  \
  **Explanation:** The calming technique is best used during the first or third minute, where the owner is grumpy, resulting in a total of 8 satisfied customers.

{{< dots >}}
## Approach 🚀
The approach is to calculate the total number of customers who are satisfied during the non-grumpy minutes and then determine how the use of the calming technique can increase this number.

### Initial Thoughts 💭
- The grumpy behavior of the owner impacts the satisfaction of the customers during certain minutes.
- The calming technique, when used optimally, can increase the number of satisfied customers.
- We can calculate the total satisfied customers first, then explore how much we can increase this by using the calming technique for the best segment of consecutive minutes.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one customer, so no empty inputs will be provided.
- The algorithm should be efficient enough to handle up to 20,000 customers in linear time.
- If the grumpy array contains all 0s, then no calming technique is needed, and the total number of customers is simply the sum of all customers.
- The input sizes will be manageable within the problem constraints.
{{< dots >}}
## Code 💻
```cpp
int maxSatisfied(vector<int>& cust, vector<int>& gm, int min) {

    int res = 0;
    int n = cust.size();
    vector<int> mins(n, 0), cs(n, 0);
        
    for(int i = 0; i < n; i++) {
        if(i < min)
        mins[0] += cust[i];
        else
        mins[i - min + 1] = mins[i - min] - cust[i - min] + cust[i];
        
        if(i == 0) cs[i] = gm[i] == 0 ? cust[i]: 0;
        else cs[i] = cs[i - 1] + (gm[i] == 0 ? cust[i]:0);
    }
    // for(int i = 0; i < n; i++)
    //     cout << mins[i] << " ";
    // cout << "\n";
    // for(int i = 0; i < n; i++)
    //     cout << cs[i] << " ";
    for(int i = 0; i <= n - min; i++) {
        int ans = (i > 0? cs[i - 1] : 0) + mins[i] + (cs[n - 1] - cs[i + min - 1]);                
        res = max(res, ans); 
    }
    
    return res;
}
```

This function calculates the maximum number of satisfied customers given a customer array and a corresponding 'good mood' array. It uses a sliding window technique with frequency arrays to efficiently compute the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxSatisfied(vector<int>& cust, vector<int>& gm, int min) {
	```
	Define the function 'maxSatisfied' which takes in a vector of customer satisfaction values ('cust'), a vector representing the good mood status ('gm'), and an integer 'min' representing the minimum number of customers to consider.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize the result variable 'res' to 0, which will store the maximum number of satisfied customers.

3. **Determine Array Size**
	```cpp
	    int n = cust.size();
	```
	Store the size of the 'cust' array in the variable 'n', as it is the same length as 'gm'.

4. **Frequency Array Initialization**
	```cpp
	    vector<int> mins(n, 0), cs(n, 0);
	```
	Initialize two arrays, 'mins' and 'cs'. 'mins' is used to store the sum of customers for each valid window, and 'cs' stores the cumulative sum of satisfied customers.

5. **Main Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop that iterates over each customer in the 'cust' array.

6. **Sliding Window Update**
	```cpp
	        if(i < min)
	```
	If the current index is less than 'min', add the customer satisfaction to the 'mins' array.

7. **Updating 'mins' Array**
	```cpp
	        mins[0] += cust[i];
	```
	Add the current customer's satisfaction to the first element of the 'mins' array (indicating the initial window).

8. **Sliding Window Else Condition**
	```cpp
	        else
	```
	For indices greater than or equal to 'min', update the 'mins' array using the sliding window technique.

9. **Sliding Window Update for Remaining Elements**
	```cpp
	        mins[i - min + 1] = mins[i - min] - cust[i - min] + cust[i];
	```
	Update the 'mins' array by removing the contribution of the leftmost customer in the previous window and adding the current customer.

10. **Cumulative Sum Initialization**
	```cpp
	        if(i == 0) cs[i] = gm[i] == 0 ? cust[i] : 0;
	```
	For the first customer, initialize the cumulative sum array 'cs'. If the customer is satisfied (good mood), add their satisfaction to 'cs'.

11. **Cumulative Sum Update**
	```cpp
	        else cs[i] = cs[i - 1] + (gm[i] == 0 ? cust[i] : 0);
	```
	For subsequent customers, add the satisfaction to the cumulative sum based on the good mood status.

12. **Calculate Maximum Satisfaction**
	```cpp
	    for(int i = 0; i <= n - min; i++) {
	```
	Start another loop to calculate the maximum satisfaction by combining the 'mins' and 'cs' arrays.

13. **Result Calculation**
	```cpp
	        int ans = (i > 0 ? cs[i - 1] : 0) + mins[i] + (cs[n - 1] - cs[i + min - 1]);
	```
	Calculate the total satisfaction by adding the previous and current 'cs' values and the current 'mins' value. The result is stored in 'ans'.

14. **Update Maximum Result**
	```cpp
	        res = max(res, ans);
	```
	Update the result 'res' with the maximum satisfaction found so far.

15. **Return the Result**
	```cpp
	    return res;
	```
	Return the maximum number of satisfied customers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of minutes (length of the arrays). This is because we only need to iterate through the arrays a few times.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need for storing intermediate results like the total satisfied customers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/grumpy-bookstore-owner/description/)

---
{{< youtube pXFbNuEIn8Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
