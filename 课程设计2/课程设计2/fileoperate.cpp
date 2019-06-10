#include"fileoperate.h"
#include"studentscore.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
extern StudentScore student[100];//���������ļ���ȫ�ֱ���

FileOperate::FileOperate(string f_filename){//���캯��
	filename = f_filename;
}

void FileOperate::fileto(void){
	ifstream f1;
	f1.open(filename, ios::in);//��studentdata.txt�ļ�
	if (f1.is_open()) {//�ж��ļ��Ƿ�򿪣����ڣ�
		for (int i = 0; i < 100 &&f1.good(); i++) {
			string s_name, s_sex;
			int s_classnum, s_studentid, s_chinese, s_math, s_english, s_physics, s_chemistry, s_biology;
			f1 >> s_classnum >> s_name >> s_sex >> s_studentid >> s_chinese >> s_math >> s_english >> s_physics >> s_chemistry >> s_biology;
			student[i].writein(s_name, s_sex, s_studentid, s_classnum, s_chinese, s_math, s_english, s_physics, s_chemistry, s_biology);
		}
		f1.close();//�ر��ļ�
		return;
	}
	else {
		cerr << "�Ҳ����ļ����޷�����ɼ���" << endl;//���������Ϣ
		cin.get();
		return;
	}
}
void FileOperate::tofile(void){
	ofstream fo;
	fo.open(filename,  ios::out);//���ļ�
	if (fo.is_open()) {//�ж��ļ��Ƿ��
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
		fo.close();//�ر��ļ�
		return;
	}
	else {
		cerr << "�����ɼ�ʧ�ܣ�" << endl;//���������Ϣ
		cin.get();
		return;
	}
}