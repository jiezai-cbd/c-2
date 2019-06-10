#include"Operate.h"
#include<iostream>
using namespace std;
Operate::Operate( StudentScore* f_student){
	student = f_student;
}

void Operate::addstudent(StudentScore& f_student){
	int i = -1;
	while ( i < 100 && student[++i].getname() != "NULL");//最多100个学生
	if (i < 100) {
		student[i] = f_student;
		sorttotal();
	}
	else cerr << "人数已满" << endl;
}

void Operate::sortname(bool mode) {
	StudentScore t;
	int n;
	for (int i = 0; i < 100 && student[i].getname() != "NULL"; i++) n = i;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n  - i; j++) {
			if (mode == 0 && student[j].getname() > student[j + 1].getname()) {
				t = student[j];
				student[j] = student[j + 1];
				student[j + 1] = t;
			}
			else if (mode == 1 && student[j].getname() < student[j + 1].getname()) {
				t = student[j];
				student[j] = student[j + 1];
				student[j + 1] = t;
			}
		}
	}
}

void Operate::sortclassnum(bool mode){
	StudentScore t;
	int n;
	for (int i = 0; i < 100 && student[i].getname() != "NULL"; i++) n = i;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n  - i; j++) {
			if (mode == 0 && student[j].getclassnum() > student[j + 1].getclassnum()) {
				t = student[j];
				student[j] = student[j + 1];
				student[j + 1] = t;
			}
			else if (mode == 1 && student[j].getclassnum() < student[j + 1].getclassnum()) {
				t = student[j];
				student[j] = student[j + 1];
				student[j + 1] = t;
			}
		}
	}
}

void Operate::sortstudentid(bool mode){
	StudentScore t;
	int n;
	for (int i = 0; i < 100 && student[i].getname() != "NULL"; i++) n = i;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n  - i; j++) {
			if (mode == 0 && student[j].getstudentid() > student[j + 1].getstudentid()) {
				t = student[j];
				student[j] = student[j + 1];
				student[j + 1] = t;
			}
			else if (mode == 1 && student[j].getstudentid() < student[j + 1].getstudentid()) {
				t = student[j];
				student[j] = student[j + 1];
				student[j + 1] = t;
			}
		}
	}
}

void Operate::sorttotal(bool mode){
	StudentScore t;
	int n=0;
	for (int i = 0; i < 100 && student[i].getname() != "NULL"; i++) n = i;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n  - i;j++) {
			if (mode == 0 && student[j].gettotal() > student[j + 1].gettotal()) {
				t = student[j];
				student[j] = student[j+1];
				student[j+1] = t;
			}
			else if (mode == 1 && student[j].gettotal() < student[j + 1].gettotal()) {
				t = student[j];
				student[j] = student[j+1];
				student[j+1] = t;
			}
		}
	}
	for (int i = 0; i < 100 && student[i].getname() != "NULL"; ) {
		int x = i+1;
		student[i].setrank(x);
		i++;
		while (student[i].gettotal() == student[i - 1].gettotal()) {
			student[i].setrank(x);
			i++;
		}
		
	}
}

StudentScore* Operate::seekname(string f_name){
	sorttotal();
	for (int i = 0; i < 100 && student[i].getname() != "NULL"; i++) {
		if (student[i].getname() == f_name) {
			return &student[i];
		}
	}
	cerr << "查无此人！";
	return NULL;
}

StudentScore* Operate::seekstudentid(int f_studentid){
	sorttotal();
	for (int i = 0; i < 100 && student[i].getname() != "NULL"; i++) {
		if (student[i].getstudentid() == f_studentid) {
			return &student[i];
		}
	}
	cerr << "查无此人！";
	return NULL;
}