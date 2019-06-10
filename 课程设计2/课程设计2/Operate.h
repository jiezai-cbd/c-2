#pragma once
#include"studentscore.h"
class Operate {
public:
	Operate( StudentScore* f_student=NULL);
	void addstudent(StudentScore& f_student);//添加学生信息
	void sortname(bool mode=0);//按姓名默认升序排序
	void sortclassnum(bool mode = 0);//按班级默认升序排序
	void sortstudentid(bool mode = 0);//按学号默认升序排序
	void sorttotal(bool mode = 1);//按总分默认降序排序，并排名
	StudentScore* seekname(string f_name);//按姓名查找
	StudentScore* seekstudentid(int f_studentid);//按学号查找
	
private:
	StudentScore*  student;//学生数组的地址
};