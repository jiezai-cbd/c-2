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
	cout << "☆★☆★☆★☆★☆★☆★☆★☆★☆\n";
	cout << "★☆      ◆成绩管理系统◆    ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆      ◆程序小白小组◆    ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ◆开始界面◆      ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆          ◆登录◆      1 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆          ◆注册◆      2 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ◆关于程序◆    3 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ◆退出程序◆    0 ☆★\n";
	cout << "☆★☆★☆★☆★☆★☆★☆★☆★☆\n";
	cout << "请输入数字进行操作：";
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
		cout << "▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼\n";
		cout << "○成绩管理系统        版本:1.10 ○\n";
		cout << "△▲△▲△▲△▲△▲△▲△▲△▲△\n";
		cout << "○ 完成时间:2019/6/2            ○\n";
		cout << "▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼\n";
		cout << "○饶梓阳          软件工程1805班○\n";
		cout << "○学号：8002118127              ○\n";
		cout << "○王伟杰          软件工程1805班○\n";
		cout << "○学号：8002118126              ○\n";
		cout << "○王江            软件工程1805班○\n";
		cout << "○学号：8002118130              ○\n";
		cout << "○朱宪可          软件工程1805班○\n";
		cout << "○学号：8002118125              ○\n";
		cout << "○王绍群          软件工程1805班○\n";
		cout << "○学号：8002118124              ○\n";
		cout << "△▲△▲△▲△▲△▲△▲△▲△▲△\n";
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
	cout << "☆★☆★☆★☆★☆★☆★☆★☆★☆\n";
	cout << "★☆      ●成绩管理系统●    ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆      ●程序小白小组●    ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ●功能界面●      ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ●添加成绩●    1 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ●姓名排序●    2 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ●班级排序●    3 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ●学号排序●    4 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ●总分排序●    5 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ●搜索姓名●    6 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆        ●搜索学号●    7 ☆★\n";
	cout << "☆                              ☆\n";
	cout << "★☆      ●返回开始界面●  0 ☆★\n";
	cout << "☆★☆★☆★☆★☆★☆★☆★☆★☆\n";
	cout << "请输入数字进行操作：";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1': {
		cout << "请输入 班级 姓名 性别 学号 语文 数学 英语 物理 化学 生物：" << endl;
		string s_name, s_sex;
		int s_classnum, s_studentid, s_chinese, s_math, s_english, s_physics, s_chemistry, s_biology;
		cin >> s_classnum >> s_name >> s_sex >> s_studentid >> s_chinese >> s_math >> s_english >> s_physics >> s_chemistry >> s_biology;
		StudentScore t(s_name, s_sex, s_studentid, s_classnum, s_chinese, s_math, s_english, s_physics, s_chemistry, s_biology);
		op.addstudent(t);
		op.sorttotal();
		cout << "成绩导入成功！" << endl;
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
		cout << "请输入姓名：";
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
		cout << "请输入学号：";
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
	cout << "班级  姓名      性别  学号       语文  数学  英语  物理  化学  生物  总分  排名" << endl;
	for (int i = 0; i < 100 && student[i].getname() != "NULL"; i++) {
		student[i].show();
	}
	_getch();
	function();
}