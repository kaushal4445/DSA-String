✨ Sum of Beauty of All Substrings
📌 Problem Statement

The beauty of a string is defined as:

(frequency of most frequent character) - (frequency of least frequent character)
👉 Exclude characters that do not appear.

Given a string s, return the sum of beauty values of all possible substrings.

🧠 Example
Input:  s = "xyx"
Output: 2
🔍 Explanation

Substrings:

"x" → beauty = 0

"y" → beauty = 0

"x" → beauty = 0

"xy" → (1 - 1) = 0

"yx" → (1 - 1) = 0

"xyx" → (2 - 1) = 1

👉 Total Beauty Sum = 2

🚀 Approach (Brute Force + Optimization)
💡 Idea

Generate all substrings

Maintain a frequency map

For each substring:

Find max frequency

Find min frequency (non-zero)

Add (max - min) to result

🔍 Algorithm

Loop through each starting index i

Initialize frequency map

Extend substring using index j

Update frequency of s[j]

Find:

maxi → maximum frequency

mini → minimum frequency

Add (maxi - mini) to sum

Return total sum

🧾 Code (C++)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        // Loop over all substrings
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                // Increase frequency of current character
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                // Find max and min frequency
                for (auto it : freq) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                // Add difference to sum
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    string s = "xyx";
    cout << "Beauty Sum: " << sol.beautySum(s) << endl;
    return 0;
}
⏱️ Complexity Analysis
🕒 Time Complexity

Outer loop → O(n)

Inner loop → O(n)

Frequency scan → O(26) (constant)

👉 Overall: O(n²)

💾 Space Complexity

Frequency map stores at most 26 characters

👉 O(1) (constant space)

🔑 Key Concepts
🔸 unordered_map<char, int>

Stores frequency of characters:

freq[s[j]]++;
🔸 it.second
for (auto it : freq)

it.first → character

it.second → frequency

Used to calculate:

mini = min(mini, it.second);
maxi = max(maxi, it.second);
🆚 Optimization Insight

Instead of unordered_map, you can use:

int freq[26] = {0};

✔ Faster than map
✔ Better constant time performance
