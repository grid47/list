
+++
authors = ["grid47"]
title = "Leetcode 2525: Categorize Box According to Criteria"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2525: Categorize Box According to Criteria in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "dIciftyQXHo"
youtube_upload_date="2023-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/dIciftyQXHo/maxresdefault.jpg"
comments = true
+++



---
Given the dimensions and mass of a box, categorize it based on the following conditions: If any dimension is >= 10,000 or the volume is >= 1,000,000,000, the box is 'Bulky'. If the mass is >= 100, the box is 'Heavy'. The box can be categorized as 'Both', 'Heavy', 'Bulky', 'Neither', or a combination of the categories.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of four integers: `length`, `width`, `height`, and `mass`, representing the dimensions and mass of the box.
- **Example:** `length = 1200, width = 150, height = 800, mass = 150`
- **Constraints:**
	- 1 <= length, width, height <= 100,000
	- 1 <= mass <= 1,000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string representing the category of the box: 'Bulky', 'Heavy', 'Both', 'Neither', or a combination of these.
- **Example:** `Output: 'Heavy'`
- **Constraints:**
	- The output is a string representing the box's category.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the category of the box based on the provided dimensions and mass.

- Calculate the volume of the box by multiplying `length * width * height`.
- Check if the box satisfies the 'Bulky' condition (any dimension >= 10,000 or volume >= 1,000,000,000).
- Check if the box satisfies the 'Heavy' condition (mass >= 100).
- Return the appropriate category based on the conditions.
{{< dots >}}
### Problem Assumptions ✅
- The input values are within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `length = 1200, width = 150, height = 800, mass = 150`  \
  **Explanation:** The box has mass >= 100, so it is categorized as 'Heavy'.

- **Input:** `length = 900, width = 900, height = 300, mass = 20`  \
  **Explanation:** The box does not satisfy either 'Bulky' or 'Heavy', so it is categorized as 'Neither'.

- **Input:** `length = 10000, width = 10000, height = 10000, mass = 50`  \
  **Explanation:** The box is 'Bulky' due to the large dimensions, but not 'Heavy' due to its mass.

{{< dots >}}
## Approach 🚀
To categorize the box, calculate its volume and check the conditions for 'Bulky' and 'Heavy'. Return the appropriate category based on the conditions.

### Initial Thoughts 💭
- We need to check both the box's volume and mass to determine its category.
- The solution requires simple conditional checks to determine the category.
{{< dots >}}
### Edge Cases 🌐
- There are no cases with empty inputs since all values are provided.
- Ensure that the input dimensions and mass are within the allowed constraints.
- If the mass is exactly 100 or the volume is exactly 1,000,000,000, handle those cases properly.
- The solution must be efficient enough to handle the largest possible inputs.
{{< dots >}}
## Code 💻
```cpp
string categorizeBox(int length, int width, int height, int mass) {
    bool bulky = false, heavy = false;
    double v = (double) length * width * height;
    if(length >= 10000 || width >= 10000 || 
       height >= 10000 || v >= 1000000000)
        bulky = true;
    if(mass >= 100)
        heavy = true;
    string category;
        if(bulky && heavy)
            category = "Both";
        else if (!bulky && !heavy)
            category = "Neither";
        else if (bulky)
            category = "Bulky";
        else if (heavy)
            category = "Heavy";
    return category;
}
```

This function categorizes a box based on its dimensions and mass into one of the categories: 'Bulky', 'Heavy', 'Both', or 'Neither'. It calculates the volume and checks if the dimensions and mass exceed certain thresholds.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string categorizeBox(int length, int width, int height, int mass) {
	```
	This defines the function 'categorizeBox' that takes four parameters: 'length', 'width', 'height', and 'mass', and returns a string representing the category of the box.

2. **Variable Initialization**
	```cpp
	    bool bulky = false, heavy = false;
	```
	This initializes two boolean variables, 'bulky' and 'heavy', which will be used to check whether the box meets certain size and mass criteria.

3. **Volume Calculation**
	```cpp
	    double v = (double) length * width * height;
	```
	This calculates the volume 'v' of the box by multiplying its 'length', 'width', and 'height'. The result is cast to a 'double' for precision.

4. **Dimension Check**
	```cpp
	    if(length >= 10000 || width >= 10000 || 
	```
	This checks if any of the box's dimensions (length, width, or height) exceed the threshold of 10,000 units, which would categorize it as bulky.

5. **Dimension Check**
	```cpp
	       height >= 10000 || v >= 1000000000)
	```
	This checks if the box's volume exceeds 1,000,000,000 cubic units, or if any dimension exceeds 10,000, marking it as bulky.

6. **Set Bulky Flag**
	```cpp
	        bulky = true;
	```
	If the box meets the bulky conditions (large dimension or large volume), the 'bulky' flag is set to true.

7. **Mass Check**
	```cpp
	    if(mass >= 100)
	```
	This checks if the mass of the box is greater than or equal to 100 units. If true, the 'heavy' flag is set to true.

8. **Set Heavy Flag**
	```cpp
	        heavy = true;
	```
	If the mass of the box exceeds 100 units, the 'heavy' flag is set to true.

9. **Category Declaration**
	```cpp
	    string category;
	```
	This declares a string variable 'category' that will hold the final result based on the box's classification.

10. **Both Conditions Check**
	```cpp
	        if(bulky && heavy)
	```
	This checks if the box is both bulky and heavy. If true, the category is set to 'Both'.

11. **Assign Category 'Both'**
	```cpp
	            category = "Both";
	```
	If the box is both bulky and heavy, the category is set to 'Both'.

12. **Neither Conditions Check**
	```cpp
	        else if (!bulky && !heavy)
	```
	This checks if the box is neither bulky nor heavy. If true, the category is set to 'Neither'.

13. **Assign Category 'Neither'**
	```cpp
	            category = "Neither";
	```
	If the box is neither bulky nor heavy, the category is set to 'Neither'.

14. **Bulky Condition Check**
	```cpp
	        else if (bulky)
	```
	This checks if the box is only bulky (but not heavy). If true, the category is set to 'Bulky'.

15. **Assign Category 'Bulky'**
	```cpp
	            category = "Bulky";
	```
	If the box is bulky, the category is set to 'Bulky'.

16. **Heavy Condition Check**
	```cpp
	        else if (heavy)
	```
	This checks if the box is only heavy (but not bulky). If true, the category is set to 'Heavy'.

17. **Assign Category 'Heavy'**
	```cpp
	            category = "Heavy";
	```
	If the box is heavy, the category is set to 'Heavy'.

18. **Return Category**
	```cpp
	    return category;
	```
	This returns the final category string, which indicates the classification of the box.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant because the operations performed are simple calculations and comparisons.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we are only storing a few integer variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/categorize-box-according-to-criteria/description/)

---
{{< youtube dIciftyQXHo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
