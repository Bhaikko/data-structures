#include <iostream>
#include <string>

int makeEqualLength(std::string& str1, std::string& str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; i++) {
            str1 = '0' + str1;
        }
        return len2;
    } else if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            str2 = '0' + str2;
        }
        return len1;
    } else {    
        return len1;
    }
}

std::string add(std::string first, std::string second)
{
    std::string result;

    int length = makeEqualLength(first, second);
    int carry = 0;

    for (int i = length - 1; i >= 0; i--) {
        int firstBit = first[i] - '0';
        int secondBit = second[i] - '0';

        // ^ is XOR operation
        int sum = (firstBit ^ secondBit ^ carry) + '0';
        result = (char)sum + result;
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    if (carry) {
        result = '1' + result;
    }
    return result;
}

int multiplySingleBit(std::string a, std::string b)
{
    return (a[0] - '0') * (b[0] - '0');
}

long int multiply(std::string first, std::string second)
{
    int n = makeEqualLength(first, second);

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return multiplySingleBit(first, second);
    }

    int firstHalf = n / 2;
    int secondHalf = n - firstHalf;

    std::string firstStringFirstHalf = first.substr(0, firstHalf);
    std::string firstStringSecondHalf = first.substr(firstHalf, secondHalf);

    std::string secondStringFirstHalf = second.substr(0, firstHalf);
    std::string secondStringSecondHalf = second.substr(firstHalf, secondHalf);

    long int p1 = multiply(firstStringFirstHalf, secondStringFirstHalf);
    long int p2 = multiply(firstStringSecondHalf, secondStringSecondHalf);
    long int p3 = multiply(add(firstStringFirstHalf, firstStringSecondHalf), add(secondStringFirstHalf, secondStringSecondHalf));

    return p1 * (1 << (2 * secondHalf)) + (p3 - p1 - p2) * (1 << secondHalf) + p2;
}

int main()
{
    std::cout << multiply("1100", "1010") << std::endl;

    return 0;
}