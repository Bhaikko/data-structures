#include <iostream>
#include <string>
#include <cmath>

int rabinKarp(std::string pattern, std::string text)
{
    int n = text.length();
    int m = pattern.length();

    int i, j;
    int pHash = 0;
    int tHash = 0;

    int base = 26;

    for (i = 0; i < m; i++) {
        pHash += base * pattern[i];
        tHash += base * text[i];
    }

    for (i = 0; i <= n - m; i++) {
        if (pHash == tHash) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            if (j == m) {
                std::cout << "Pattern found at index " << i <<std::endl; 
            }
        }
        
        tHash -= base * text[i];
        tHash += base * text[i + m];
        
    }

}

int naive(std::string pattern, std::string text) 
{
    int m = pattern.length();
    int n = text.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            return i;
        }
        
    }

    return -1;
    
}

void lps(std::string pattern, int* lps)
{
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(std::string pattern, std::string text)
{
    int m = pattern.length();
    int n = text.length();

    int lpsArray[m];
    lps(pattern, lpsArray);

    int i = 0; 
    int j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            std::cout << "Pattern found at " << i - j << std::endl;
            j = lpsArray[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lpsArray[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main()
{
    std::string text = "AABAACAADAABAAA";
    std::string pattern = "ABA";

    // std::cout << naive(pattern, text) << std::endl;
    rabinKarp(pattern, text);
    kmp(pattern, text);

    return 0;

}