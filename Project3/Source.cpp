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
	int cnt = 0;
	char* pntr;
	for (int i = 0; i < static_cast<int>(strlen(str)); ++i) {
		if (cnt >= strCounter) {
			if (isAlphaSymb(*(str + i))) {
				for (int j = i; j < static_cast<int>(strlen(str)); ++j) {
					if (!isAlphaSymb(*(str + j))) {
						break;
					}
					++len;
				}
				strCounter++;
				pntr = *(&str + i);
				return pntr;
			}
		}
		++cnt;
	}
	return 0;
}

void delNfirstSymb(char* str, int n) {
	for (int i = n-1; i >= 0; --i) {
		*(str + i + 1) = *(str+i);
	}
}

void insertNfirstSymb(char* str, char symb, int n) {
	int bufer = 0;
	char* pointer;
	pointer = searchFirstAlphaSubstr(str, len);
	bufer = static_cast<int>(strlen(pointer));
	for (int j = 0; j < n; ++j) {
		for (int i = static_cast <int> (strlen(pointer)); i > 0; --i) {
			if (i != 1) {
				*(pointer + i) = *(pointer + i - 1);
			}
			else {
				*(pointer + i) = *(pointer + i - 1);
				*(pointer + i - 1) = *&(symb);
				*(pointer + bufer + 1) = '\0';
			}
			
		}
	}
}

char* vstavkaSymbPosleBukv(char* str, char symb) {
	int counter = 0;
	char* pntr;
	if (!isAlphaSymb(*(str)))
		return 0;
	while (true) {
		if (counter % 2 == 0) {
			insertNfirstSymb(str, symb, 1);
		}
		else {
			pntr = searchFirstAlphaSubstr(str, len);
			delNfirstSymb(pntr, len);
		}
		counter++;
	}
	return (&*(str));
}

int main(int argc, char* argv[]) {
	char str[1000];
	char symb[1000];
	char* uk;
	int i = 0;

	cout << "Ââåäèòå ñòðîêó: ";
	cin.getline(str, 1000, '\n');

	cout << "Ââåäèòå ñèìâîë: ";
	cin.getline(symb, 1000, '\n');

	uk = vstavkaSymbPosleBukv(str, *symb);

	while (*(uk + i)) {
		cout << *(uk + i) << " ";
		++i;
	}
	cout << '\n';

	system("PAUSE");
	return 0;
}
