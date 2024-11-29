
+++
authors = ["grid47"]
title = "Leetcode 2191: Sort the Jumbled Numbers"
date = "2024-04-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2191: Sort the Jumbled Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rmkF2mxPoZM"
youtube_upload_date="2024-07-24"
youtube_thumbnail="https://i.ytimg.com/vi/rmkF2mxPoZM/maxresdefault.jpg"
comments = true
+++



---
You are given a mapping array where each index represents a digit, and the value at each index represents the mapped digit in a shuffled decimal system. You are also given an integer array 'nums'. Your task is to sort the array 'nums' in non-decreasing order based on the mapped values of each element. While sorting, the original integers in 'nums' should not be changed, only their mapped values should be considered for sorting.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: an integer array 'mapping' and an integer array 'nums'.
- **Example:** `Input: mapping = [2,4,0,7,1,9,6,3,8,5], nums = [352,124,718]`
- **Constraints:**
	- mapping.length == 10
	- 0 <= mapping[i] <= 9
	- All values of mapping[i] are unique.
	- 1 <= nums.length <= 3 * 10^4
	- 0 <= nums[i] < 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the array 'nums' sorted in non-decreasing order based on the mapped values of the elements.
- **Example:** `Output: [124,352,718]`
- **Constraints:**
	- The elements in 'nums' should be sorted based on their mapped values and not be replaced by them.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to sort the numbers in 'nums' by their mapped values, where each digit of a number is replaced by the corresponding value in the 'mapping' array.

- For each number in 'nums', generate its mapped value by replacing each digit according to the 'mapping' array.
- Store the mapped values along with the original numbers and their indices.
- Sort the numbers based on their mapped values while preserving their original relative order when mapped values are the same.
- Return the sorted array based on the original numbers.
{{< dots >}}
### Problem Assumptions ✅
- The mapping array has unique digits, meaning no digit maps to the same value.
- The numbers in 'nums' are valid integers that follow the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: mapping = [2,4,0,7,1,9,6,3,8,5], nums = [352,124,718]`  \
  **Explanation:** For each number in 'nums', the digits are mapped according to the 'mapping' array. After mapping, we get the values 822 for 352, 214 for 124, and 278 for 718. Sorting these mapped values results in the order [214,822,278], corresponding to the original numbers [124,352,718].

- **Input:** `Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]`  \
  **Explanation:** In this case, the mapping does not change the digits because mapping[i] = i. Thus, 789 maps to 789, 456 maps to 456, and 123 maps to 123. Sorting the values results in [123, 456, 789], which is the correct output.

{{< dots >}}
## Approach 🚀
The approach involves generating the mapped values for each element in 'nums' by applying the 'mapping' array and then sorting the elements based on those mapped values.

### Initial Thoughts 💭
- We need to generate the mapped value for each number by replacing its digits according to the 'mapping' array.
- Sorting the elements based on their mapped values is a key aspect, while maintaining the original order when mapped values are the same.
- We can achieve this by converting each number into a string, applying the mapping to each digit, and then sorting the numbers based on the mapped results.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one number in 'nums', so empty inputs are not a concern.
- Ensure the solution works for large inputs, up to 30,000 numbers in 'nums'.
- Consider cases where all digits in 'nums' map to the same value or where the mapping array results in no change to the numbers.
- Ensure that the solution meets time complexity constraints, especially for large inputs.
{{< dots >}}
## Code 💻
```cpp
vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<pair<int, int>> tmp;
    
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        
        int num = nums[i];
        
        string str = to_string(num);
        string formed = "";
        for(int j = 0; j < str.size(); j++)
            formed += to_string(mapping[str[j]- '0']);
        int val = stoi(formed);
        tmp.push_back({ val, i });
        
    }
    
    sort(tmp.begin(), tmp.end());
    
    vector<int> ans;
    for(int i = 0; i < n; i++)
        ans.push_back(nums[tmp[i].second]);
    
    return ans;
    
}
```

This function sorts the list 'nums' based on a 'mapping' array, where each digit in the numbers of 'nums' is replaced by its corresponding value in 'mapping'. The function returns the sorted list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
	```
	Defines the function 'sortJumbled' which takes a vector 'mapping' and a vector 'nums' as inputs, and returns the sorted version of 'nums' after replacing each digit with its corresponding value from 'mapping'.

2. **Variable Initialization**
	```cpp
	    vector<pair<int, int>> tmp;
	```
	Initializes a vector of pairs 'tmp' to store pairs of transformed numbers and their original indices.

3. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculates the size of the 'nums' vector and stores it in the variable 'n'.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through each element of the 'nums' vector.

5. **Element Access**
	```cpp
	        int num = nums[i];
	```
	Accesses the 'i'th element of the 'nums' vector and stores it in the variable 'num'.

6. **String Conversion**
	```cpp
	        string str = to_string(num);
	```
	Converts the integer 'num' to a string 'str'.

7. **String Initialization**
	```cpp
	        string formed = "";
	```
	Initializes an empty string 'formed' to build the transformed version of 'num'.

8. **Loop through Digits**
	```cpp
	        for(int j = 0; j < str.size(); j++)
	```
	Iterates through each digit of the string 'str'.

9. **Digit Transformation**
	```cpp
	            formed += to_string(mapping[str[j]- '0']);
	```
	For each digit 'str[j]', replaces it with the corresponding value from the 'mapping' vector and appends it to 'formed'.

10. **String Conversion**
	```cpp
	        int val = stoi(formed);
	```
	Converts the transformed string 'formed' back to an integer and stores it in 'val'.

11. **Storing Transformed Data**
	```cpp
	        tmp.push_back({ val, i });
	```
	Pushes the transformed integer 'val' and its original index 'i' as a pair into the 'tmp' vector.

12. **Sorting**
	```cpp
	    sort(tmp.begin(), tmp.end());
	```
	Sorts the 'tmp' vector based on the transformed values of the numbers.

13. **Result Vector Initialization**
	```cpp
	    vector<int> ans;
	```
	Initializes an empty vector 'ans' to store the final sorted numbers.

14. **Loop through Sorted Data**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Iterates through the sorted 'tmp' vector to extract the numbers in their original order.

15. **Extracting Sorted Numbers**
	```cpp
	        ans.push_back(nums[tmp[i].second]);
	```
	Pushes the original number from 'nums' (using the index stored in 'tmp[i].second') into the 'ans' vector.

16. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the sorted 'ans' vector containing the original numbers in the desired order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n), where n is the length of 'nums'.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the mapped values and the original numbers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-the-jumbled-numbers/description/)

---
{{< youtube rmkF2mxPoZM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
