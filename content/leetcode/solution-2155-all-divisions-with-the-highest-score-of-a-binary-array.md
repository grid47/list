
+++
authors = ["grid47"]
title = "Leetcode 2155: All Divisions With the Highest Score of a Binary Array"
date = "2024-04-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2155: All Divisions With the Highest Score of a Binary Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jAn_1AC2VMo"
youtube_upload_date="2022-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jAn_1AC2VMo/maxresdefault.webp"
comments = true
+++



---
You are given a binary array 'nums'. You can divide the array at any index 'i' into two parts: 'numsleft' (before index 'i') and 'numsright' (from index 'i' to the end). The division score is the sum of zeros in 'numsleft' and ones in 'numsright'. Your task is to find all indices where the division score is the highest.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary array 'nums' with length 'n'.
- **Example:** `nums = [1, 0, 1, 0]`
- **Constraints:**
	- 1 <= n <= 10^5
	- nums[i] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of indices that give the highest division score.
- **Example:** `[3]`
- **Constraints:**
	- The output should contain all indices where the division score is maximum.

{{< dots >}}
### Core Logic 🔍
**Goal:** Iterate through all possible indices, compute the division score, and track the indices that give the highest score.

- Count the total number of 1's in the array initially.
- Iterate through each possible division index, calculate the number of 0's in 'numsleft' and the number of 1's in 'numsright'.
- Update the highest division score and collect indices that give the highest score.
{{< dots >}}
### Problem Assumptions ✅
- The array 'nums' is non-empty and contains only binary values (0 or 1).
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [1, 0, 1, 0]`  \
  **Explanation:** The division scores at each index are calculated as follows, and the highest score is achieved at indices 3 and 4.

- **Input:** `Example 2: nums = [0, 0, 0]`  \
  **Explanation:** The division score is highest at index 3 where all 0's are left in 'numsleft' and none in 'numsright'.

{{< dots >}}
## Approach 🚀
To solve this problem, we calculate the division score for each index and keep track of the indices with the maximum score.

### Initial Thoughts 💭
- The number of 1's in 'numsright' decreases as we move through the array, while the number of 0's in 'numsleft' increases.
- We can track the number of zeros and ones as we iterate through the array to efficiently calculate the division score.
{{< dots >}}
### Edge Cases 🌐
- The array is non-empty, so no special handling for empty arrays is needed.
- For very large arrays (up to 10^5 elements), the solution should be efficient enough to run in O(n) time.
- Arrays that consist entirely of 0's or 1's will still work as expected.
- Ensure that the solution handles large inputs within the time limits.
{{< dots >}}
## Code 💻
```cpp
vector<int> maxScoreIndices(vector<int>& nums) {
    int n = nums.size();
    int ones = 0;
    for(int i = 0; i < n; i++)
    if (nums[i] == 1) ones++;
    
    int mx = ones;
    vector<int> mxx;
    mxx.push_back(0);

    int zeros = 0;
    
    int prv, cur = mx;
    for(int i = 1; i < n + 1; i++) {
        zeros += ((nums[i - 1] == 0)? 1 : 0);
        ones  -= ((nums[i - 1] == 1)? 1 : 0);

        prv = mx;
        cur = zeros + ones;
        mx  = max(mx, cur);

             if (mx == cur && cur == prv) mxx.push_back(i);
        else if (mx >  prv) {
            mxx.clear();
            mxx.push_back(i);
        }
    }
    
    return mxx;
}
```

This function calculates the maximum score indices based on the count of ones and zeros in the 'nums' array, returning the indices where the score is maximized. It does this by iterating through the array and tracking the number of zeros and ones, updating the maximum score dynamically.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> maxScoreIndices(vector<int>& nums) {
	```
	The function 'maxScoreIndices' is declared with a parameter 'nums', a vector of integers, and returns a vector of integers representing the indices with maximum scores.

2. **Array Size**
	```cpp
	    int n = nums.size();
	```
	Calculate the size of the 'nums' array and store it in the variable 'n'.

3. **Variable Initialization**
	```cpp
	    int ones = 0;
	```
	Initialize a variable 'ones' to count the number of ones in the 'nums' array.

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Start a loop to iterate through all elements of the 'nums' array.

5. **Count Ones**
	```cpp
	    if (nums[i] == 1) ones++;
	```
	Increment the 'ones' counter for each element in the 'nums' array that equals 1.

6. **Score Calculation**
	```cpp
	    int mx = ones;
	```
	Initialize 'mx' with the value of 'ones', which will keep track of the maximum score seen so far.

7. **Vector Initialization**
	```cpp
	    vector<int> mxx;
	```
	Declare a vector 'mxx' to store the indices where the maximum score is reached.

8. **Push Initial Index**
	```cpp
	    mxx.push_back(0);
	```
	Push index 0 into 'mxx' as it is always a valid candidate for the maximum score.

9. **Zero Counter**
	```cpp
	    int zeros = 0;
	```
	Initialize 'zeros' to count the number of zeros encountered during the loop.

10. **Previous and Current Score Initialization**
	```cpp
	    int prv, cur = mx;
	```
	Initialize 'prv' and 'cur' to track the previous and current scores during the iteration.

11. **Loop Through Array**
	```cpp
	    for(int i = 1; i < n + 1; i++) {
	```
	Start a loop that iterates from index 1 to 'n' (inclusive) to calculate the score at each index.

12. **Count Zeros**
	```cpp
	        zeros += ((nums[i - 1] == 0)? 1 : 0);
	```
	Increment the 'zeros' counter if the current element in 'nums' is zero.

13. **Update Ones**
	```cpp
	        ones  -= ((nums[i - 1] == 1)? 1 : 0);
	```
	Decrement the 'ones' counter if the current element in 'nums' is one.

14. **Track Maximum Scores**
	```cpp
	        prv = mx;
	```
	Store the current value of 'mx' in 'prv' to track the previous score.

15. **Current Score Calculation**
	```cpp
	        cur = zeros + ones;
	```
	Calculate the current score by summing the count of zeros and ones.

16. **Update Maximum Score**
	```cpp
	        mx  = max(mx, cur);
	```
	Update 'mx' with the maximum of the previous score and the current score.

17. **Handle Score Ties**
	```cpp
	             if (mx == cur && cur == prv) mxx.push_back(i);
	```
	If the current score is equal to both the previous and the maximum score, add the current index to the 'mxx' vector.

18. **Clear and Update Max Indices**
	```cpp
	        else if (mx >  prv) {
	```
	If the current score is greater than the previous score, clear the 'mxx' vector and add the current index.

19. **Push Updated Index**
	```cpp
	            mxx.push_back(i);
	```
	Push the current index into the 'mxx' vector after the score is updated.

20. **Return Final Indices**
	```cpp
	    return mxx;
	```
	Return the vector 'mxx' containing the indices with the maximum score.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates through the array once, which is efficient for large inputs.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The solution uses a few variables to store the scores and indices, so the space complexity is O(n) in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/)

---
{{< youtube jAn_1AC2VMo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
