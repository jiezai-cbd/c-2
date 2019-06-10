#include"studentscore.h"
#include"interface.h"
#include"Operate.h"
#include"fileoperate.h"
#include"account.h"
#include<cstdlib>
#include<conio.h>
#include<iostream>
using namespace std;
extern Operate op;
extern StudentScore student[100];
extern FileOperate fop;
extern Account ac;
void Interface::start(void){
	system("cls");
	system("mode con cols=35 lines=17");
	system("color 06");
	cout << "������������������\n";
	cout << "���      ���ɼ�����ϵͳ��    ���\n";
	cout << "��                              ��\n";
	cout << "���      ������С��С���    ���\n";
	cout << "��                              ��\n";
	cout << "���        ����ʼ�����      ���\n";
	cout << "��                              ��\n";
	cout << "���          ����¼��      1 ���\n";
	cout << "��                              ��\n";
	cout << "���          ��ע���      2 ���\n";
	cout << "��                              ��\n";
	cout << "���        �����ڳ����    3 ���\n";
	cout << "��                              ��\n";
	cout << "���        ���˳������    0 ���\n";
	cout << "������������������\n";
	cout << "���������ֽ��в�����";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1': {
		system("cls");
		if (ac.login()) {
			function();
		}
		else start();
		break;
	}
	case '2': {
		system("cls");
		ac.signin();
		start();
		break;
	}
	case '3': {
		system("cls");
		cout << "����������������������������������\n";
		cout << "��ɼ�����ϵͳ        �汾:1.10 ��\n";
		cout << "����������������������������������\n";
		cout << "�� ���ʱ��:2019/6/2            ��\n";
		cout << "����������������������������������\n";
		cout << "��������          �������1805���\n";
		cout << "��ѧ�ţ�8002118127              ��\n";
		cout << "����ΰ��          �������1805���\n";
		cout << "��ѧ�ţ�8002118126              ��\n";
		cout << "������            �������1805���\n";
		cout << "��ѧ�ţ�8002118130              ��\n";
		cout << "�����ܿ�          �������1805���\n";
		cout << "��ѧ�ţ�8002118125              ��\n";
		cout << "������Ⱥ          �������1805���\n";
		cout << "��ѧ�ţ�8002118124              ��\n";
		cout << "����������������������������������\n";
		_getch();
		start();
		break;
	}
	case '0': {
		exit(0);
		break;
	}
	default:start(); break;
	}
}
void Interface::function(void){
	
	system("cls");
	system("mode con cols=38 lines=27");
	cout << "������������������\n";
	cout << "���      ��ɼ�����ϵͳ��    ���\n";
	cout << "��                              ��\n";
	cout << "���      �����С��С���    ���\n";
	cout << "��                              ��\n";
	cout << "���        ���ܽ����      ���\n";
	cout << "��                              ��\n";
	cout << "���        ����ӳɼ���    1 ���\n";
	cout << "��                              ��\n";
	cout << "���        �����������    2 ���\n";
	cout << "��                              ��\n";
	cout << "���        ��༶�����    3 ���\n";
	cout << "��                              ��\n";
	cout << "���        ��ѧ�������    4 ���\n";
	cout << "��                              ��\n";
	cout << "���        ���ܷ������    5 ���\n";
	cout << "��                              ��\n";
	cout << "���        ������������    6 ���\n";
	cout << "��                              ��\n";
	cout << "���        ������ѧ�š�    7 ���\n";
	cout << "��                              ��\n";
	cout << "���      �񷵻ؿ�ʼ�����  0 ���\n";
	cout << "������������������\n";
	cout << "���������ֽ��в�����";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1': {
		cout << "������ �༶ ���� �Ա� ѧ�� ���� ��ѧ Ӣ�� ���� ��ѧ ���" << endl;
		string s_name, s_sex;
		int s_classnum, s_studentid, s_chinese, s_math, s_english, s_physics, s_chemistry, s_biology;
		cin >> s_classnum >> s_name >> s_sex >> s_studentid >> s_chinese >> s_math >> s_english >> s_physics >> s_chemistry >> s_biology;
		StudentScore t(s_name, s_sex, s_studentid, s_classnum, s_chinese, s_math, s_english, s_physics, s_chemistry, s_biology);
		op.addstudent(t);
		op.sorttotal();
		cout << "�ɼ�����ɹ���" << endl;
		_getch();
		function();
		break;
	}
	case '2': {
		op.sortname();
		show();
		break;
	}
	case '3': {
		op.sortclassnum();
		show();
		break;
	}
	case '4': {
		op.sortstudentid();
		show();
		break;
	}
	case '5': {
		op.sorttotal();
		show();
		break;
	}
	case '6': {
		cout << "������������";
		string s_name;
		cin >> s_name;
		StudentScore *t;
		t=op.seekname(s_name);
		system("cls");
		t->display();
		_getch();
		function();
		break;
	}
	case '7': {
		cout << "������ѧ�ţ�";
		string s_name;
		cin >> s_name;
		StudentScore* t;
		t = op.seekname(s_name);
		system("cls");
		t->display();
		_getch();
		function();
		break;
	}
	case '0': {
		start();
		break;
	}
	default:function(); break;
	}
}
void Interface::show(void){
	system("mode con cols=110 lines=150");
	system("cls");
	cout << "�༶  ����      �Ա�  ѧ��       ����  ��ѧ  Ӣ��  ����  ��ѧ  ����  �ܷ�  ����" << endl;
	for (int i = 0; i < 100 && student[i].getname() != "NULL"; i++) {
		student[i].show();
	}
	_getch();
	function();
}