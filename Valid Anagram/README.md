🔤 Check if Two Strings are Anagrams
📌 Problem Statement

Given two strings, check whether they are anagrams of each other.

👉 Two strings are anagrams if they contain the same characters with the same frequency, but possibly in a different order.

🧠 Examples
✅ Example 1
Input:  CAT, ACT
Output: true
Explanation: Both strings have same characters with same frequency.
❌ Example 2
Input:  RULES, LESRT
Output: false
Explanation: Frequency of characters does not match.
🚀 Approach 1: Brute Force (Sorting)
💡 Idea

Sort both strings and compare them character by character.

🔍 Algorithm

If lengths are different → return false

Sort both strings

Compare each character

If all match → return true, else false

🧾 Code (C++)
#include <bits/stdc++.h>
using namespace std;

bool CheckAnagrams(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";

    if (CheckAnagrams(Str1, Str2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
⏱️ Complexity Analysis
Type	Complexity
Time	O(N log N)
Space	O(1)
⚡ Approach 2: Optimal (Frequency Count)
💡 Idea

Use a frequency array to count characters.

🔍 Algorithm

If lengths are different → return false

Create array freq[26] = {0}

Increment count for first string

Decrement count for second string

If all values are 0 → anagram

🧾 Code (C++)
#include <bits/stdc++.h>
using namespace std;

bool CheckAnagrams(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    int freq[26] = {0};

    for (int i = 0; i < str1.length(); i++) {
        freq[str1[i] - 'A']++;
    }

    for (int i = 0; i < str2.length(); i++) {
        freq[str2[i] - 'A']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

int main() {
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";

    if (CheckAnagrams(Str1, Str2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
⏱️ Complexity Analysis
Type	Complexity
Time	O(N)
Space	O(1)
🆚 Comparison
Feature	Brute Force	Optimal
Approach	Sorting	Frequency Count
Time	O(N log N) ❌	O(N) ✅
Space	O(1)	O(1)
Efficiency	Moderate	Best
