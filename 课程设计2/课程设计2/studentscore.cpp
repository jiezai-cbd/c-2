#include"studentscore.h"
#include<iostream>
using namespace std;

StudentInformation::StudentInformation(string f_name, string f_sex, int f_studentid, int f_classnum) :name(f_name), sex(f_sex), studentid(f_studentid), classnum(f_classnum) { }

void StudentInformation::writein(string f_name, string f_sex, int f_studentid, int f_classnum) {
	name = f_name;
	sex = f_sex;
	studentid = f_studentid;
	classnum = f_classnum;
}

Score::Score(int f_chinese, int f_math, int f_english, int f_physics, int f_chemistry, int f_biology) :chinese(f_chinese), math(f_math), english(f_english), physics(f_physics), chemistry(f_chemistry), biology(f_biology) {
	total = chinese + math + english + physics + chemistry + biology;
}

void Score::writein(int f_chinese, int f_math, int f_english, int f_physics, int f_chemistry, int f_biology) {
	chinese = f_chinese;
	math = f_math;
	english = f_english;
	physics = f_physics;
	chemistry = f_chemistry;
	biology = f_biology;
	total = chinese + math + english + physics + chemistry + biology;
}

StudentScore::StudentScore(string f_name, string f_sex, int f_studentid, int f_classnum, int f_chinese, int f_math, int f_english, int f_physics, int f_chemistry, int f_biology) :StudentInformation(f_name, f_sex, f_studentid, f_classnum), Score() {
	Score::writein(f_chinese, f_math, f_english, f_physics, f_chemistry, f_biology);
	rank = 0;
}


void StudentScore::writein(string f_name, string f_sex, int f_studentid, int f_classnum, int f_chinese, int f_math, int f_english, int f_physics, int f_chemistry, int f_biology) {
	StudentInformation::writein(f_name, f_sex, f_studentid, f_classnum);
	Score::writein(f_chinese, f_math, f_english, f_physics, f_chemistry, f_biology);
	rank = 0;
}


void StudentScore::show(void) const {
	cout << getclassnum() << "     ";
	cout << getname() << "\t";
	cout << getsex() << "    ";
	cout << getstudentid() << "  ";
	cout << getchinese() << "    ";
	cout << getmath() << "    ";
	cout << getenglish() << "    ";
	cout << getphysics() << "    ";
	cout << getchemistry() << "    ";
	cout << getbiology() << "    ";
	cout << gettotal() << "   ";
	cout << getrank() << endl;
}

void StudentScore::display(void) {
	cout << "班级：" << getclassnum() << endl;
	cout << "姓名：" << getname() << endl;
	cout << "性别：" << getsex() << endl;
	cout << "学号：" << getstudentid() << endl;
	cout << "语文成绩：" << getchinese() << endl;
	cout << "数学成绩：" << getmath() << endl;
	cout << "英语成绩：" << getenglish() << endl;
	cout << "物理成绩：" << getphysics() << endl;
	cout << "化学成绩：" << getchemistry() << endl;
	cout << "生物成绩：" << getbiology() << endl;
	cout << "总分：" << gettotal() << endl;
	cout << "排名：" << getrank() << endl;
}