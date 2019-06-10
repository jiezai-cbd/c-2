#include"studentscore.h"
#include"Operate.h"
#include"interface.h"
#include"fileoperate.h"
#include"account.h"
#include<iostream>
using namespace std;
StudentScore student[100];//学生成绩的数组，最多100个学生
Operate op = Operate(student);//将学生成绩数组的地址传入类对象中，用于对数组的操作
FileOperate fop = FileOperate();
Account ac;
Interface interface;
int main(void) {
	fop.fileto();//调用成员函数将文件内容导入到数组中
	op.sorttotal();//对导入的数据进行排序并添加排名
	interface.start();//进入开始界面
	fop.tofile();//将数组的内容导入到文件中
	cin.get();
	return 0;
}