#pragma once
#include<map>
#include"fileread.h"


using namespace std;
extern Fileread fileread;
class Holder {
public:
	/*·列出所有年份中指定的某一天的所有访问者。
·列出某年某天的所有访问者。
·得出某个访问者在某年或某天的访问次数。
·列出某天或某年中前n个访问最频繁的访问者，n由用户指定。
·分别以IP地址、访问日期或访问年度为顺序将文件中的内容输出到标准输出流。
*/
	/*map<int, int*/ void sort_date();
	void show_date();//在interface中将调用show()展示排序好的信息
	void show_id();//show()方法不负责清屏
	void show_key(int );
	void show_value_to_key(int);
	void show_data_sort(int,int);
	void test();
	multimap<int, int> hold_date;//所有数据按日期排序
	multimap<int, int> hold_id;//所有数据按id排序，map默认按key排序，故直接将读入的map赋值即可
	multimap<int, int> hold_day;
	multimap<int, int> hold_person;//没用的，不要管
	multimap<int, int> hold_value_to_key;
	multimap<int, int> hold_f;
	map<int, int> hold_s;
	//各种排好序的map；
};

