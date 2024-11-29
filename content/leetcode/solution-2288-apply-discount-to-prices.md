
+++
authors = ["grid47"]
title = "Leetcode 2288: Apply Discount to Prices"
date = "2024-03-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2288: Apply Discount to Prices in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7W1Wzpfa1tg"
youtube_upload_date="2022-05-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/7W1Wzpfa1tg/maxresdefault.webp"
comments = true
+++



---
You are given a sentence, which contains words that may include prices represented by a dollar sign ('$') followed by a sequence of digits. For each word in the sentence that represents a price, apply a given discount percentage and update the word. The price should be updated with exactly two decimal places. The goal is to return a modified sentence where the updated prices reflect the discount.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string sentence where words are separated by single spaces. Each word may represent a price in the form of a dollar sign followed by digits. An integer discount is also provided, which is the percentage of discount to be applied to the prices.
- **Example:** `Input: sentence = "apple $100 orange $200 banana", discount = 20`
- **Constraints:**
	- 1 <= sentence.length <= 105
	- sentence consists of lowercase English letters, digits, '$', and spaces.
	- All words in the sentence are separated by a single space.
	- Prices will be positive numbers without leading zeros.
	- 0 <= discount <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the modified sentence where each price word has been updated with the discount applied. The updated price should have exactly two decimal places.
- **Example:** `Output: "apple $80.00 orange $160.00 banana"`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to apply a discount to each word representing a price and update the price accordingly. The price should be formatted with two decimal places.

- Step 1: Split the sentence into words.
- Step 2: For each word, check if it represents a price (starts with '$' followed by digits).
- Step 3: If the word is a price, calculate the new price after applying the discount.
- Step 4: Format the discounted price to two decimal places and update the word in the sentence.
- Step 5: Join the words back together to form the modified sentence and return it.
{{< dots >}}
### Problem Assumptions ✅
- All words representing prices are valid, meaning they are correctly formatted with a dollar sign followed by digits.
- The discount will always be between 0 and 100, inclusive.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: sentence = "apple $100 orange $200 banana", discount = 20`  \
  **Explanation:** Here, '$100' will be discounted by 20%, resulting in '$80.00'. '$200' will be discounted by 20%, resulting in '$160.00'. The final sentence will be: 'apple $80.00 orange $160.00 banana'.

- **Input:** `Input: sentence = "item $50 item2 $30", discount = 10`  \
  **Explanation:** In this case, '$50' will be discounted by 10%, resulting in '$45.00'. '$30' will be discounted by 10%, resulting in '$27.00'. The final sentence will be: 'item $45.00 item2 $27.00'.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to iterate through the words in the sentence, identify the ones that represent prices, and apply the discount percentage to those prices while ensuring that the updated prices are formatted correctly.

### Initial Thoughts 💭
- We need to process each word to check if it represents a price.
- The challenge is to handle formatting of the price to exactly two decimal places.
- We can use string manipulation to extract and update prices, and then use a formatting function to ensure the correct number of decimal places.
{{< dots >}}
### Edge Cases 🌐
- An empty sentence will not be provided based on the problem constraints.
- The solution must handle sentences with up to 100,000 characters efficiently.
- If the discount is 0, no change will be applied to any prices.
- If the discount is 100, all prices will become $0.00.
- All prices will be valid and formatted correctly.
{{< dots >}}
## Code 💻
```cpp
string discountPrices(string sentence, int discount) {
    auto doit = [&](string word) {
        int n = word.size();
        if( n == 1 || word[0] != '$')
        return word;

        long long num = 0;
        for(int i = 1; i < word.size(); i++) {
            if(!isdigit(word[i])) return word;
            num = num * 10 + (word[i] - '0');
        }

        stringstream ss2;
        double discountPercentag = (100 - discount) / 100.00;
        ss2 << fixed << setprecision(2) << (discountPercentag * num);
        return "$" + ss2.str();

    };

    string res, word;
    stringstream ss(sentence);
    while(ss >> word) {
        res += doit(word) + " ";
    }
    res.pop_back();
    return res;
}
```

The function `discountPrices` calculates the discounted price for each price in a sentence that starts with a dollar sign ('$'). The function iterates over the sentence, identifies prices, applies the discount, and returns the modified sentence with updated prices.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string discountPrices(string sentence, int discount) {
	```
	The function `discountPrices` is declared, taking a `sentence` string and an integer `discount` as input. It returns a string with discounted prices where applicable.

2. **Define Helper Function**
	```cpp
	    auto doit = [&](string word) {
	```
	A lambda function `doit` is defined to process each word in the sentence. This function applies the discount if the word represents a price (starting with '$').

3. **Get Word Length**
	```cpp
	        int n = word.size();
	```
	The size of the word is stored in the variable `n` to check if the word contains a price.

4. **Check if Word is Price**
	```cpp
	        if( n == 1 || word[0] != '$')
	```
	If the word is not a price (it either doesn't start with a '$' or is too short to be a valid price), the function returns the word unchanged.

5. **Return Word if Not Price**
	```cpp
	        return word;
	```
	If the word is not a price, return the original word as-is.

6. **Initialize Number Variable**
	```cpp
	        long long num = 0;
	```
	A variable `num` is initialized to store the numeric value of the price (excluding the '$' sign).

7. **Iterate Over Price Digits**
	```cpp
	        for(int i = 1; i < word.size(); i++) {
	```
	A loop iterates over the characters in the word (starting from the second character) to extract the numeric value.

8. **Check if Character is Digit**
	```cpp
	            if(!isdigit(word[i])) return word;
	```
	If a character is not a digit, return the original word as it's not a valid price.

9. **Build Number from Digits**
	```cpp
	            num = num * 10 + (word[i] - '0');
	```
	The number `num` is constructed by iterating over each digit of the price and converting it to an integer.

10. **Initialize Discount Calculation**
	```cpp
	        stringstream ss2;
	```
	A stringstream `ss2` is initialized to store the discounted price formatted to two decimal places.

11. **Calculate Discounted Price**
	```cpp
	        double discountPercentag = (100 - discount) / 100.00;
	```
	The discount percentage is calculated by subtracting the given `discount` from 100, then dividing by 100 to get the decimal form.

12. **Apply Discount and Format**
	```cpp
	        ss2 << fixed << setprecision(2) << (discountPercentag * num);
	```
	The discounted price is calculated by multiplying the original price by the discount percentage. The result is formatted to two decimal places using `stringstream`.

13. **Return Discounted Price**
	```cpp
	        return "$" + ss2.str();
	```
	The discounted price is converted to a string, prepended with the '$' sign, and returned.

14. **Initialize Result Variables**
	```cpp
	    string res, word;
	```
	Two variables `res` and `word` are initialized. `res` will store the final result, and `word` will hold each individual word from the sentence.

15. **Create String Stream for Sentence**
	```cpp
	    stringstream ss(sentence);
	```
	A stringstream `ss` is created from the `sentence` to facilitate word-by-word processing.

16. **Process Each Word**
	```cpp
	    while(ss >> word) {
	```
	A while loop is used to extract each word from the sentence.

17. **Update Result with Processed Word**
	```cpp
	        res += doit(word) + " ";
	```
	For each word, the `doit` function is called to apply the discount if the word is a price, and the result is appended to `res`.

18. **Remove Extra Space**
	```cpp
	    res.pop_back();
	```
	The last space is removed from the result string `res` after processing all the words.

19. **Return Final Result**
	```cpp
	    return res;
	```
	The final sentence with discounted prices is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the sentence, as we need to process each word once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the length of the sentence, as we store the words in memory.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/apply-discount-to-prices/description/)

---
{{< youtube 7W1Wzpfa1tg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
