
+++
authors = ["grid47"]
title = "Leetcode 2358: Maximum Number of Groups Entering a Competition"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2358: Maximum Number of Groups Entering a Competition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "r_kn18dmnNo"
youtube_upload_date="2022-07-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/r_kn18dmnNo/maxresdefault.webp"
comments = true
+++



---
You are given a positive integer array grades which represents the grades of students. Your goal is to group these students into ordered non-empty groups where:

1. The sum of the grades in the i-th group is less than the sum of the grades in the (i + 1)-th group.
2. The number of students in the i-th group is less than the number of students in the (i + 1)-th group.
Return the maximum number of groups that can be formed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array grades representing the grades of students.
- **Example:** `Input: grades = [4, 1, 8, 3, 6, 7]`
- **Constraints:**
	- 1 <= grades.length <= 100
	- 1 <= grades[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of groups that can be formed.
- **Example:** `Output: 3`
- **Constraints:**
	- The output will always be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Group students such that the total number of students and the sum of their grades satisfy the given conditions for each group.

- Sort the grades array.
- Iterate through the grades, keeping track of the number of students and the sum of their grades for each group.
- Check whether the current group satisfies the condition for being formed. If it does, increment the total number of groups.
{{< dots >}}
### Problem Assumptions ✅
- All grades are positive integers.
- There are enough students to form at least one group.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: grades = [4, 1, 8, 3, 6, 7]`  \
  **Explanation:** In this case, the array is sorted, and the students can be grouped as follows: Group 1: [8] (Sum: 8, Students: 1), Group 2: [6, 7] (Sum: 13, Students: 2), Group 3: [4, 1, 3] (Sum: 8, Students: 3).

- **Input:** `Example 2: grades = [3, 3]`  \
  **Explanation:** In this case, only one group can be formed, as dividing it into two would violate the condition of having a different number of students in each group.

{{< dots >}}
## Approach 🚀
Sort the grades array and try to form the maximum number of groups by checking if each group satisfies the conditions.

### Initial Thoughts 💭
- Sorting the array helps us easily form groups with increasing sums and sizes.
- We need to iterate through the array and ensure that each new group meets the sum and size conditions.
{{< dots >}}
### Edge Cases 🌐
- If there are no grades provided, no groups can be formed.
- Even with the largest input (100 students), sorting and iterating through the array will be efficient.
- If all grades are equal, only one group can be formed.
- Ensure that the groups formed have increasing sizes and sums.
{{< dots >}}
## Code 💻
```cpp
int maximumGroups(vector<int>& nums) {
    
    sort(nums.begin(), nums.end());
    
    int cur_people = 1;
    int cur_grade  = nums[0];
    int tmp_people = 0;
    int tmp_grade = 0;
    int total = 1;
    int n = nums.size();
    for(int i = 1; i < n; i++) {
        if(tmp_people <= cur_people || tmp_grade <= cur_grade) {
            tmp_grade += nums[i];
            tmp_people += 1;
        } else {
            total += 1;
            cur_people = tmp_people;
            cur_grade = tmp_grade;
            tmp_people = 1;
            tmp_grade = nums[i];
        }
    }
    return (tmp_people > cur_people && tmp_grade > cur_grade)? total + 1: total;
}
```

This function calculates the maximum number of groups that can be formed based on a set of grades where the groups are formed with the constraint that the number of people and the sum of grades in each group cannot be smaller than the previous group.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumGroups(vector<int>& nums) {
	```
	Defines the function `maximumGroups`, which takes a vector of integers `nums` and returns an integer representing the maximum number of groups that can be formed.

2. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the vector `nums` in ascending order to allow for the grouping of values based on increasing order of grades.

3. **Variable Initialization**
	```cpp
	    int cur_people = 1;
	```
	Initializes `cur_people` to track the number of people in the current group.

4. **Variable Initialization**
	```cpp
	    int cur_grade  = nums[0];
	```
	Initializes `cur_grade` to the first grade in the sorted array to start building the first group.

5. **Variable Initialization**
	```cpp
	    int tmp_people = 0;
	```
	Initializes `tmp_people` to track the number of people in the temporary group during iteration.

6. **Variable Initialization**
	```cpp
	    int tmp_grade = 0;
	```
	Initializes `tmp_grade` to track the sum of grades in the temporary group during iteration.

7. **Variable Initialization**
	```cpp
	    int total = 1;
	```
	Initializes `total` to 1, since the first group is always formed before the loop starts.

8. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculates the size of the `nums` vector to be used in the loop iteration.

9. **Loop**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Starts a loop from the second element to the last in the sorted `nums` array to attempt grouping people.

10. **Condition Check**
	```cpp
	        if(tmp_people <= cur_people || tmp_grade <= cur_grade) {
	```
	Checks if the number of people and the sum of grades in the current group are still less than or equal to the previous group's values.

11. **Group Update**
	```cpp
	            tmp_grade += nums[i];
	```
	Adds the current grade to the `tmp_grade` for the current temporary group.

12. **Group Update**
	```cpp
	            tmp_people += 1;
	```
	Increments the number of people in the current temporary group.

13. **Else Block**
	```cpp
	        } else {
	```
	If the condition is not satisfied, the current temporary group is complete, and a new group is formed.

14. **Group Transition**
	```cpp
	            total += 1;
	```
	Increments the `total` count of groups when a new group is formed.

15. **Group Transition**
	```cpp
	            cur_people = tmp_people;
	```
	Sets `cur_people` to the number of people in the temporary group to start tracking the new group.

16. **Group Transition**
	```cpp
	            cur_grade = tmp_grade;
	```
	Sets `cur_grade` to the sum of grades in the temporary group to start tracking the new group.

17. **Group Reset**
	```cpp
	            tmp_people = 1;
	```
	Resets `tmp_people` to 1 for the new group starting with the current person.

18. **Group Reset**
	```cpp
	            tmp_grade = nums[i];
	```
	Resets `tmp_grade` to the current person's grade for the new group.

19. **Return Result**
	```cpp
	    return (tmp_people > cur_people && tmp_grade > cur_grade)? total + 1: total;
	```
	Returns the total number of groups formed, adding 1 if the last group formed is valid based on the condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the sorted array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/description/)

---
{{< youtube r_kn18dmnNo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
