#pragma once
#include"studentscore.h"
class Operate {
public:
	Operate( StudentScore* f_student=NULL);
	void addstudent(StudentScore& f_student);//���ѧ����Ϣ
	void sortname(bool mode=0);//������Ĭ����������
	void sortclassnum(bool mode = 0);//���༶Ĭ����������
	void sortstudentid(bool mode = 0);//��ѧ��Ĭ����������
	void sorttotal(bool mode = 1);//���ܷ�Ĭ�Ͻ������򣬲�����
	StudentScore* seekname(string f_name);//����������
	StudentScore* seekstudentid(int f_studentid);//��ѧ�Ų���
	
private:
	StudentScore*  student;//ѧ������ĵ�ַ
};