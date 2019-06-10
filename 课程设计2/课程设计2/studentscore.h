#pragma once
#include<string>
using namespace std;

class StudentInformation {
public:
	StudentInformation(string f_name=NULL, string f_sex=NULL, int f_studentid=0, int f_classnum=0);//构造函数
	string getname(void)const { return name; }
	string getsex(void)const { return  sex; }
	int getstudentid(void)const { return studentid; }
	int getclassnum(void)const { return classnum; }
	 void writein(string f_name, string f_sex, int f_studentid, int f_classnum);
private:
	string name;//学生姓名
	string sex;//学生性别
	int studentid;//学生学号
	int classnum;//学生班级
};

class Score {
public:
	Score(int f_chinese=0, int f_math=0, int f_english=0, int f_physics=0, int f_chemistry=0, int f_biology=0);
	int getchinese(void)const { return chinese; }
	int getmath(void)const { return math; }
	int getenglish(void)const { return english; }
	int getphysics(void)const { return physics; }
	int getchemistry(void)const { return chemistry; }
	int getbiology(void)const { return biology; }
	int gettotal(void)const { return total; }
	void writein(int f_chinese, int f_math, int f_english, int f_physics, int f_chemistry, int f_biology);
private:
	int chinese;
	int math;
	int english;
	int physics;
	int chemistry;
	int biology;
	int total;
};

class StudentScore :public StudentInformation, public Score {
public:
	StudentScore(string f_name="NULL", string f_sex="0", int f_studentid=0, int f_classnum=0, int f_chinese=0, int f_math=0, int f_english=0, int f_physics=0, int f_chemistry=0, int f_biology=0);
	int getrank(void)const { return rank; }
	void setrank(int f_rank) { rank = f_rank; }
	void writein(string f_name, string f_sex, int f_studentid, int f_classnum, int f_chinese, int f_math, int f_english, int f_physics, int f_chemistry, int f_biology);
	void show(void)const;
	void display(void);

private:
	int rank;
};