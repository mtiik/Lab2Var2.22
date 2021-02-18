#include <stdio.h>
#include <iostream>

using namespace std;

bool isAlphaSymb(char str) {
	return isalpha(str);
}

int* searchFirstAlphaSubstr(char* str, int* len) {
	void* addr;
	for (int i = 0; i < static_cast<int>(strlen(str)); ++i) {
		if (isAlphaSymb(str[i])) {
			for (int j = i; j < static_cast<int>(strlen(str)); ++j) {
				if (isAlphaSymb(str[j])) {
					++*len;
				}
			}
			addr = &str[i];
			return static_cast <int*> (addr);
			break;
		}
	}
	return 0;
}

void delNfirstSymb(char* str, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; str[j-1] = str[j]; ++j);
	}
}

void insertNfirstSymb(char* str, char* symb, int n) {
	int bufer = 0;
	for (int j = 0; j < n; ++j) {
		bufer = static_cast<int>(strlen(str));
		for (int i = bufer; i > 0; --i) {
			if (i != 1) {
				str[i] = str[i - 1];
			}
			else {
				str[i] = str[i - 1];
				str[i - 1] = symb[0];
				str[bufer + 1] = '\0';
			}
			
		}
	}
}

//char* insertSymbAfterAlpha(char* str, char symb) {
//	int* symbAdr;
//	int len = 0;
//	bool flag = false;
//	for (int i = 0; i < static_cast<int>(strlen(str)); ++i) {
//		symbAdr = searchFirstAlphaSubstr(str, &len);
//		if (flag) {
//
//		}
//		else {
//			flag = false;
//		}
//	}
//}

int main(int argc, char* argv[]) {
	char str[1000];
	char symb[1000];
	int n = 2, len = 0;

	cout << "Введите строку: ";
	cin.getline(str, 1000, '\n');

	cout << "Введите символ: ";
	cin.getline(symb, 1000, '\n');
	
	int* symbAdr = searchFirstAlphaSubstr(str, &len);

	// delNfirstSymb(str, n);

	insertNfirstSymb(str, symb, n);
	cout << str;
	return 0;
}