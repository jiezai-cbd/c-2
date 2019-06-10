#include"fileoperate.h"
#include"studentscore.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
extern StudentScore student[100];//声明其他文件的全局变量

FileOperate::FileOperate(string f_filename){//构造函数
	filename = f_filename;
}

void FileOperate::fileto(void){
	ifstream f1;
	f1.open(filename, ios::in);//打开studentdata.txt文件
	if (f1.is_open()) {//判断文件是否打开（存在）
		for (int i = 0; i < 100 &&f1.good(); i++) {
			string s_name, s_sex;
			int s_classnum, s_studentid, s_chinese, s_math, s_english, s_physics, s_chemistry, s_biology;
			f1 >> s_classnum >> s_name >> s_sex >> s_studentid >> s_chinese >> s_math >> s_english >> s_physics >> s_chemistry >> s_biology;
			student[i].writein(s_name, s_sex, s_studentid, s_classnum, s_chinese, s_math, s_english, s_physics, s_chemistry, s_biology);
		}
		f1.close();//关闭文件
		return;
	}
	else {
		cerr << "找不到文件！无法导入成绩！" << endl;//输出错误信息
		cin.get();
		return;
	}
}
void FileOperate::tofile(void){
	ofstream fo;
	fo.open(filename,  ios::out);//打开文件
	if (fo.is_open()) {//判断文件是否打开
		for (int i = 0; i < 100 && student[i].getrank() != 0; i++){
			fo << student[i].getclassnum() << ' ';
			fo << student[i].getname() << ' ';
			fo << student[i].getsex() << ' ';
			fo << student[i].getstudentid() << ' ';
			fo << student[i].getchinese() << ' ';
			fo << student[i].getmath() << ' ';
			fo << student[i].getenglish() << ' ';
			fo << student[i].getphysics() << ' ';
			fo << student[i].getchemistry() << ' ';
			fo << student[i].getbiology() << endl;
		}
		fo.close();//关闭文件
		return;
	}
	else {
		cerr << "导出成绩失败！" << endl;//输出错误信息
		cin.get();
		return;
	}
}