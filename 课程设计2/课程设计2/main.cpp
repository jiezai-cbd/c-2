#include"studentscore.h"
#include"Operate.h"
#include"interface.h"
#include"fileoperate.h"
#include"account.h"
#include<iostream>
using namespace std;
StudentScore student[100];//ѧ���ɼ������飬���100��ѧ��
Operate op = Operate(student);//��ѧ���ɼ�����ĵ�ַ����������У����ڶ�����Ĳ���
FileOperate fop = FileOperate();
Account ac;
Interface interface;
int main(void) {
	fop.fileto();//���ó�Ա�������ļ����ݵ��뵽������
	op.sorttotal();//�Ե�������ݽ��������������
	interface.start();//���뿪ʼ����
	fop.tofile();//����������ݵ��뵽�ļ���
	cin.get();
	return 0;
}