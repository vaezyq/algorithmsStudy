//Karatsuba整数相乘算法
//completed


#include <iostream>
#include <cmath>
#include <string>

#define main02 main02

using namespace std;

int digits_num(int);

int cal(int x, int y, int n);


string combine(string str1, string str2);

string karatsuba(string x, string y, int n);

void putZero(string *num, int n);

void supplementaryDigits(string &num1, string &num2, int &n);

int main02() {

//    int x, y;
//    cin >> x >> y;
//    int num_1 = digits_num(x);
//    int num_2 = digits_num(y);
//    int n = num_1 > num_2 ? num_1 : num_2;
//    int result = cal(x, y, n);
//    cout << result;


    string num1 = "12";
    string num2 = "1212";
    int n = 0;
    supplementaryDigits(num1, num2, n);


    string result = karatsuba(num1, num2, num1.size());

    int count = 0;
    for (int i = 0; i < result.size(); ++i) {
        if (result[i] == '0') {
            count++;
        }
    }
    if (count > 0) {
        result.erase(0, count);
    }
    cout << result;

    return 0;


}

void supplementaryDigits(string &num1, string &num2, int &n) {


    int digit = max(num1.size(), num2.size());
    int count = 0;
    while (pow(2, count) < digit) {
        count++;
    }
    n = digit = pow(2, count);
    for (int i = num1.size(); i < digit; ++i) {
        num1 = '0' + num1;
    }
    for (int i = num2.size(); i < digit; ++i) {
        num2 = '0' + num2;
    }
}


int cal(int x, int y, int n) {

//    计算a与b的乘积
    if (n == 1) {
        return x * y;
    } else {
        int a = x / pow(10, n / 2);
        int b = x - a * pow(10, n / 2);
        int c = y / pow(10, n / 2);
        int d = y - c * pow(10, n / 2);

        int ac = cal(a, c, n / 2);
        int bd = cal(b, d, n / 2);
        int abcd = cal(a + b, c + d, n / 2) - ac - bd;


        return pow(10, n) * ac + pow(10, n / 2) * abcd + bd;
    }
}


int digits_num(int num) {
    int length = 0;
    while (num) {
        num /= 10;
        length++;
    }
    int count = 0;
    while (pow(2, count) < length) {
        count++;
    }
    return pow(2, count);
}


//单个元素的相乘
string integerMultiplication(string x, string y) {

    int x_int = stoi(x);
    int y_int = stoi(y);
    string result = to_string(x_int * y_int);
    return result;

}

//提高数字的阶数


void putZero(string *num, int n) {

    for (int i = 0; i < n; ++i) {
        *num += "0";
    }
}


string combine(string str1, string str2) {
    string result;
    if (str1.size() > str2.size()) {
        swap(str1, str2);
    }

    int n1 = str1.size();
    int n2 = str2.size();

//    进位
    int carry = 0;
    int j = n2 - 1;


    for (int i = n1 - 1; i >= 0; i--) {

//        字符串和字符串、字符相加，都是在后面补位。但是字符和字符相加，则是简单的相加，因为字符只有一位。
//利用字符相加的特征，可以实现整数相加。
        int sum = ((str1[i] - '0') + (str2[j] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
        j--;
    }

    for (; j >= 0; j--) {

        int sum = ((str2[j] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }


    if (carry != 0) {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());


    return result;

}

string karatsuba(string x, string y, int n) {
    if (n == 1) {
        return integerMultiplication(x, y);
    } else {

        string a = x.substr(0, n / 2);
        string b = x.substr(n / 2);
        string c = y.substr(0, n / 2);
        string d = y.substr(n / 2);


        string ac = karatsuba(a, c, n / 2);
        string bd = karatsuba(b, d, n / 2);
        string ad = karatsuba(a, d, n / 2);
        string bc = karatsuba(b, c, n / 2);


        string ad_plus_bc = combine(ad, bc);


        putZero(&ac, n);
        putZero(&ad_plus_bc, n / 2);


        string result = combine(combine(ac, ad_plus_bc), bd);
        return result;
    }
}





