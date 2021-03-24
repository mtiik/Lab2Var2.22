#include <stdio.h>
#include <iostream>

using namespace std;

const char symbols[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int symbolsSize = 52;

bool isAlphaSymb(char str) {
	int size = static_cast<int>(strlen(str));
	bool flag = false;
	for (int i = 0; i < size; ++i){
		for(int j = 0; j < symbolsSize; j++) {
			if (str[i] == symbols[j])
				flag = true;
		}
		if (!flag)
			return 0;
		else
			flag = false;
	}
	return true;
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
		for (int j = 1; j <= static_cast<int>(strlen(str)); ++j) {
			str[j - 1] = str[j];
		}
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

char* insertSymbAfterAlpha(char* str, char* symb) {
	int* symbAdr;
	char strPiece[1000];
	int len = 0, k = 0;
	bool flag = false;
	for (int i = 0; i < static_cast<int>(strlen(str)); ++i) {
		symbAdr = searchFirstAlphaSubstr(str, &len);
		if (flag) {
			insertNfirstSymb(str, symb, 1);
			flag = false;
		}
		else {
			for (int i = 0; i < static_cast<int>(strlen(str)); ++i) {
				if (static_cast<int*>((void*)str[i]) == symbAdr) {
					for (int j = 0; j < len; j++) {
						strPiece[j] = str[i + k];

						++k;
					}
					break;
				}
			}
			delNfirstSymb(strPiece, len);

			flag = true;
		}
	}
}

int main(int argc, char* argv[]) {
	char str[1000];
	char symb[1000];
	int n, len = 0;

	cout << "Ââåäèòå ñòðîêó: ";
	cin.getline(str, 1000, '\n');

	cout << "Ââåäèòå ñèìâîë: ";
	cin.getline(symb, 1000, '\n');

	cin >> n;

	insertNfirstSymb(str, symb, n);

	cout << str;
	
	int* symbAdr = searchFirstAlphaSubstr(str, &len);

	system("PAUSE");
	return 0;
}
