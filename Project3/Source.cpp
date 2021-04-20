#include <stdio.h>
#include <iostream>

using namespace std;

const char symbols[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int symbolsSize = 52;
int len = 0;
int strCounter = 0;

int isAlphaSymb(char str) {
	for (int i = 0; i < symbolsSize; ++i) {
		if (*&(str) == *(symbols + i)) {
			return true;
		}
	}
	
	return false;
}

char* searchFirstAlphaSubstr(char* str, int& len) {
	len = 0;
	for (; *str && !isAlphaSymb(*str); str++);
	if (*str == ' ' || *str == '\0') return 0;
	char* buffer = str;
	for (len++; *str && *str != ' '; str++, len++);
	return buffer;
}

void delNfirstSymb(char* str, int n) {
	for (char* i = str + n; *str = *i; str++, i++);
}

void insertNfirstSymb(char* str, char symb, int n) {
	str = searchFirstAlphaSubstr(str, len);
	for (int j = 0; j < n; ++j) {
		for (int i = len; i > 0; --i) {
			if (i != 1) *(str + i) = *(str + i - 1);
			else {
				*(str + i) = *(str + i - 1);
				*(str + i - 1) = *&(symb);
			}
		}
	}
}

char* vstavkaSymbPosleBukv(char* str, char symb) {
	int len = 0;
	char* buffer = str;
	bool flag = false;
	while (searchFirstAlphaSubstr(str, len)) {
		if (flag) {
			delNfirstSymb(str, len);
			flag = false;
		}
		else {
			insertNfirstSymb(str, symb, 1);
			str = str + ++len;
			flag = true;
		}
	}
	return buffer;
}

int main(int argc, char* argv[]) {
	char str[1000];
	char symb[1000];

	cout << "enter str: ";
	cin.getline(str, 1000, '\n');

	while (*str != '0' || *(str + 1) != '/0') {

		cout << "enter symb: ";
		cin.getline(symb, 1000, '\n');

		char* str2 = vstavkaSymbPosleBukv(str, *symb);
		if (str2) cout << "new str: " << str2 << '\n';
		else cout << "not change";

		cout << '\n' << "enter 0 or str: ";
		cin.getline(str, 1000, '\n');
	}

	system("PAUSE");
	return 0;
}
