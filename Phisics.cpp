#include <bits/stdc++.h>
using namespace std;

int toInt(char c) {
	return ((c - '0') < 10) ? c - '0' : (int) c - 55;
}

char toChar(int i) {
	return (i < 10) ? char(i + '0') : char(i + 55);
}

double toDecimal(string num, int base) {
	double ans = 0;
	int index = num.find('.');
	if (index != -1) {
		int x = index - 1;
		for (int i = 0; i < index; i++) {
			ans += toInt(num[i]) * pow(base, x--);
		}

		for (int i = index + 1, j = 1; i < num.size(); i++, j++) {
			ans += toInt(num[i]) * pow(base, -j);
		}
	} else {
		int x = num.size() - 1;
		for (int i = 0; i < num.size(); i++) {
			ans += toInt(num[i]) * pow(base, x--);
		}
	}

	return ans;
}

string toBase(double num, int base) {
	string ans = "";
	long long n = num;
	num -= n;
	while (n > 0) {
		ans += toChar(n % base);
		n /= base;
	}
	reverse(ans.begin(), ans.end());
	if (num == 0) {
		return ans;
	}
	ans += '.';
	int x;
	int maxFraction = 10;
	while (num != 0 && maxFraction--) {
		num *= base;
		x = num;
		ans += toChar(x);
		num -= x;
	}

	return ans;
}

string Sum_Two_Binary(string x, string y) {
	int index1 = x.find('.'), index2 = y.find('.');
	string after_digit1 = "", after_digit2 = "", before_digit1 = "",
			before_digit2 = "";
	if (index1 != -1) {
		after_digit1 = x.substr(x.find('.') + 1, x.size() + 1);
		before_digit1 = x.substr(0, x.find('.'));
	} else
		before_digit1 = x;
	if (index2 != -1) {
		after_digit2 = y.substr(y.find('.') + 1, y.size() + 1);
		before_digit2 = y.substr(0, y.find('.'));
	} else
		before_digit2 = y;
	while (after_digit1.size() != after_digit2.size()) {
		if (after_digit1.size() < after_digit2.size())
			after_digit1 = after_digit1 + '0';
		if (after_digit2.size() < after_digit1.size())
			after_digit2 = after_digit2 + '0';
	}
	while (before_digit1.size() != before_digit2.size()) {
		if (before_digit1.size() < before_digit2.size())
			before_digit1 = '0' + before_digit1;
		if (before_digit2.size() < before_digit1.size())
			before_digit2 = '0' + before_digit2;
	}
	string sum_after_digit = "", sum_before_digit = "", res = "";
	int rem = 0;
	for (int i = after_digit1.size() - 1; i >= 0; i--) {
		if ((after_digit1[i] - '0') + (after_digit2[i] - '0') + rem == 0)
			sum_after_digit = '0' + sum_after_digit, rem = 0;
		else if ((after_digit1[i] - '0') + (after_digit2[i] - '0') + rem == 1)
			sum_after_digit = '1' + sum_after_digit, rem = 0;
		else if ((after_digit1[i] - '0') + (after_digit2[i] - '0') + rem == 2)
			sum_after_digit = '0' + sum_after_digit, rem = 1;
		else if ((after_digit1[i] - '0') + (after_digit2[i] - '0') + rem == 3)
			sum_after_digit = '1' + sum_after_digit, rem = 1;
	}
	for (int i = before_digit1.size() - 1; i >= 0; i--) {
		if ((before_digit1[i] - '0') + (before_digit2[i] - '0') + rem == 0)
			sum_before_digit = '0' + sum_before_digit, rem = 0;
		else if ((before_digit1[i] - '0') + (before_digit2[i] - '0') + rem == 1)
			sum_before_digit = '1' + sum_before_digit, rem = 0;
		else if ((before_digit1[i] - '0') + (before_digit2[i] - '0') + rem == 2)
			sum_before_digit = '0' + sum_before_digit, rem = 1;
		else if ((before_digit1[i] - '0') + (before_digit2[i] - '0') + rem == 3)
			sum_before_digit = '1' + sum_before_digit, rem = 1;
	}
	if (rem == 1)
		sum_before_digit = '1' + sum_before_digit;
	if (sum_after_digit.size() == 0)
		return sum_before_digit;
	else
		return sum_before_digit + '.' + sum_after_digit;
}

string First_Complement(string x) {
	for (int i = 0; i < x.size(); i++) {
		x[i] = ((1 - (x[i] - '0')) + '0');
	}
	return x;
}

string Second_Complement(string x) {
	bool z = false;
	for (int i = x.size() - 1; i >= 0; i--) {
		if (x[i] == '1' && !z)
			z = true;
		else if (z && x[i] != '.') {
			x[i] = ((1 - (x[i] - '0')) + '0');
		}
	}
	return x;
}

string Subtract_Two_Binary(string x, string y) {
	int index1 = x.find('.'), index2 = y.find('.');
	string after_digit1 = "", after_digit2 = "", before_digit1 = "",
			before_digit2 = "";
	if (index1 != -1) {
		after_digit1 = x.substr(x.find('.') + 1, x.size() + 1);
		before_digit1 = x.substr(0, x.find('.'));
	} else
		before_digit1 = x;
	if (index2 != -1) {
		after_digit2 = y.substr(y.find('.') + 1, y.size() + 1);
		before_digit2 = y.substr(0, y.find('.'));
	} else
		before_digit2 = y;
	while (after_digit1.size() != after_digit2.size()) {
		if (after_digit1.size() < after_digit2.size())
			after_digit1 = after_digit1 + '0';
		if (after_digit2.size() < after_digit1.size())
			after_digit2 = after_digit2 + '0';
	}
	while (before_digit1.size() != before_digit2.size()) {
		if (before_digit1.size() < before_digit2.size())
			before_digit1 = '0' + before_digit1;
		if (before_digit2.size() < before_digit1.size())
			before_digit2 = '0' + before_digit2;
	}
	if (after_digit1.size() == 0) {
		x = before_digit1;
		y = before_digit2;
	} else {
		x = before_digit1 + '.' + after_digit1;
		y = before_digit2 + '.' + after_digit2;
	}
	y = Second_Complement(y);
	string sum = Sum_Two_Binary(x, y);
	if (sum.size() > x.size())
		return "(" + sum.substr(1, sum.size() + 1) + ")";
	else
		return "-(" + Second_Complement(sum) + ")";
}

string Multiply_Two_Binary(string x, string y) {
	vector<string> v;
	string X = "", Y = "";
	bool z = false;
	int mark = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '.') {
			z = true;
			continue;
		}
		if (z)
			mark++;
		X += x[i];
	}
	z = false;
	for (int i = 0; i < y.size(); i++) {
		if (y[i] == '.') {
			z = true;
			continue;
		}
		if (z)
			mark++;
		Y += y[i];
	}
	for (int i = Y.size() - 1; i >= 0; i--) {
		if (Y[i] == '1')
			v.push_back(X);
		X = X + '0';
	}
	string sum = "0";
	for (int i = 0; i < v.size(); i++) {
		sum = Sum_Two_Binary(sum, v[i]);
	}
	if (mark == 0)
		return sum;
	else {
		string Mult = "";
		for (int i = sum.size() - 1; i >= 0; i--) {
			if (mark == 0)
				Mult = '.' + Mult;
			Mult = sum[i] + Mult;
			mark--;
		}
		if (Mult[0] == '.')
			return "0" + Mult;
		else
			return Mult;
	}
}

string Divide_Two_Binary(string x, string y) {
    double a=toDecimal(x,2);
    double b=toDecimal(y,2);
	return toBase(a/b,2);
}

int main() {

	string x, y;
	cin >> x >> y;
	cout << Sum_Two_Binary(x, y) << endl;
	cout << Subtract_Two_Binary(x, y) << endl;
	cout << Multiply_Two_Binary(x, y) << endl;
	cout << Divide_Two_Binary(x, y) << endl;

	return 0;
}
