#include<iostream>
#include<string.h>
using namespace std;
void BF() {
	int i, j, k, flag = 0;
	char s[30] = "ababcabccabcacbab";
	char t[10] = "abcac";
	for (i = 0; i <= strlen(s) - strlen(t); i++) {
		for (k = i, j = 0; j < strlen(t); k++, j++) {
			if (s[k] == t[j])
				continue;
			break;
		}
		if (j >= strlen(t)) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		cout << "ƥ��ɹ����±�Ϊ��" << i << endl;
	}
	else
		cout << "ƥ��ʧ��";
}

void getNext(char* t, int length, int next[]) {
	next[0] = -1;
	int i = 0, j = -1;
	while (i < length) {
		if (j == -1 || t[i] == t[j]) {
			next[++i] = ++j;
		}
		else
			j = next[j];
	}
	
}
void KMP() {
	int i = 0, j = 0, flag = 0;
	char s[30] = "ababcabccabcacbab";
	char t[10] = "abcac";
	int length1 = strlen(s);
	int length = strlen(t);
	int next[10] = { 0 };
	getNext(t, length, next);
	while (i < length1 && j < length) {
		if (j == -1 || s[i] == t[j]) {
			j++;
			i++;
		}
		else
			j = next[j];
	}
	if (j == length) {
		cout << "ƥ��ɹ����±�Ϊ��" << i - j << endl;
	}
	else
		cout << "ƥ��ʧ��";
}
int main() {
	BF();
	KMP();
}