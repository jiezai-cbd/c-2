#include"account.h"
#include<iostream>
#include<conio.h>
#include<cctype>
using namespace std;
Account::Account(){
	memset(accountnum, 0, 8);
	memset(password, 0, 8);
}
bool Account::signin(void){
	char ch;
	int i = 0;;
	cout << "�������˺ţ�-------\b\b\b\b\b\b\b";
	while(i<7){
		ch = _getch();
		if (isdigit(ch)) {
			cout << ch;
			accountnum[i] = ch;
			i++;
		}
		else ;
	}
	cout << endl;
	cout << "���������룺-------\b\b\b\b\b\b\b";
	i = 0;
	while(i<7) {
		ch = _getch();
		if (isdigit(ch)) {
			cout << '*';
			password[i] = ch;
			i++;
		}
		else;
	}
	cout << endl;
	char p[8];
	memset(p, 0, 8);
	cout << "���ٴ��������룺-------\b\b\b\b\b\b\b";
	i = 0;
	while(i<7) {
		ch = _getch();
		if (isdigit(ch)) {
			cout << '*';
			p[i] = ch;
			i++;
		}
	}
	cout << endl;
	if (strcmp(password, p) != 0) {
		cout << "������������벻һ�£�" << endl;
		_getch();
		return false;
	}
	else {
		cout << "ע��ɹ���" << endl;
		_getch();
		return true;
	}
}
bool Account::login(void) const{
	char ch,a[8],p[8];
	memset(a, 0, 8);
	memset(p, 0, 8);
	cout << "�������˺ţ�-------\b\b\b\b\b\b\b";
	int i = 0;
	while (i < 7) {
		ch = _getch();
		if (isdigit(ch)) {
			cout << ch;
			a[i] = ch;
			i++;
		}
	}
	cout << endl;
	cout << "���������룺-------\b\b\b\b\b\b\b";
	i = 0;
	while (i < 7) {
		ch = _getch();
		if (isdigit(ch)) {
			cout << '*';
			p[i] = ch;
			i++;
		}
	}
	cout << endl;
	if (strcmp(accountnum, a) == 0 && strcmp(password, p) == 0) {
		cout << "��¼�ɹ�!" << endl;
		_getch();
		return true;
	}
	else {
		cerr << "�˺Ż������������" << endl;
		return false;
	}
}