class Solution {

public:
    string longestPalindrome(string str) {
        if (str.length() <= 1)
            return str;

        string LPS = "";

        for (int i = 1; i < str.length(); i++) {
            // Odd length palindromes (center at i)
            int low = i;
            int high = i;
            while (low >= 0 && high < str.length() && str[low] == str[high]) {
                low--;
                high++;
            }

            string palindrome = str.substr(low + 1, high - low - 1);
            if (palindrome.length() > LPS.length()) {
                LPS = palindrome;
            }

            // Even length palindromes (center between i-1 and i)
            low = i - 1;
            high = i;
            while (low >= 0 && high < str.length() && str[low] == str[high]) {
                low--;
                high++;
            }

            palindrome = str.substr(low + 1, high - low - 1);
            if (palindrome.length() > LPS.length()) {
                LPS = palindrome;
            }
        }

        return LPS;
    }
};