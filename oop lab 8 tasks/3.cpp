#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

    static BigInteger addAbs(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        result.digits.clear();
        int carry = 0;
        size_t n = max(a.digits.size(), b.digits.size());
        for (size_t i = 0; i < n || carry; i++) {
            int x = carry;
            if (i < a.digits.size()) x += a.digits[i];
            if (i < b.digits.size()) x += b.digits[i];
            result.digits.push_back(x % 10);
            carry = x / 10;
        }
        result.removeLeadingZeros();
        return result;
    }

    static BigInteger subtractAbs(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        result.digits.clear();
        int borrow = 0;
        for (size_t i = 0; i < a.digits.size(); i++) {
            int x = a.digits[i] - borrow;
            if (i < b.digits.size()) x -= b.digits[i];
            if (x < 0) {
                x += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(x);
        }
        result.removeLeadingZeros();
        return result;
    }

    static bool absLess(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size()) {
            return a.digits.size() < b.digits.size();
        }
        for (int i = a.digits.size() - 1; i >= 0; i--) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] < b.digits[i];
            }
        }
        return false;
    }

public:
    BigInteger() {
        digits.push_back(0);
        isNegative = false;
    }

    BigInteger(const string& number) {
        isNegative = false;
        digits.clear();
        int i = 0;
        if (number[0] == '-') {
            isNegative = true;
            i = 1;
        }
        for (int j = number.length() - 1; j >= i; j--) {
            digits.push_back(number[j] - '0');
        }
        removeLeadingZeros();
    }

    friend istream& operator>>(istream& is, BigInteger& num) {
        string s;
        is >> s;
        num = BigInteger(s);
        return is;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.isNegative) os << "-";
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            os << num.digits[i];
        }
        return os;
    }

    BigInteger operator+(const BigInteger& other) const {
        BigInteger result;
        if (isNegative == other.isNegative) {
            result = addAbs(*this, other);
            result.isNegative = isNegative;
        } else {
            if (absLess(*this, other)) {
                result = subtractAbs(other, *this);
                result.isNegative = other.isNegative;
            } else {
                result = subtractAbs(*this, other);
                result.isNegative = isNegative;
            }
        }
        result.removeLeadingZeros();
        return result;
    }

    BigInteger operator-(const BigInteger& other) const {
        BigInteger temp = other;
        temp.isNegative = !temp.isNegative;
        return *this + temp;
    }

    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (isNegative) {
            return absLess(other, *this);
        }
        return absLess(*this, other);
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(other < *this);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }
};

int main() {
    BigInteger a, b;
    cin >> a >> b;

    cout << "A + B = " << (a + b) << endl;
    cout << "A - B = " << (a - b) << endl;

    if (a == b) cout << "A == B" << endl;
    if (a != b) cout << "A != B" << endl;
    if (a < b) cout << "A < B" << endl;
    if (a > b) cout << "A > B" << endl;

    return 0;
}
