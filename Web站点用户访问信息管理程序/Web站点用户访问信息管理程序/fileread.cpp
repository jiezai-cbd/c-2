#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include"fileread.h"
#include"holder.h"
using namespace std;
extern Holder holder;
void Fileread::read() {
	int key, value;
	fstream f;
	f.open("webdata.txt");
	if (!f.is_open()) {                          //后期改为异常处理
		cout << "打开文件错误！" << endl;
		return;
	}
	while (!f.eof()) {
		f >> key >> value;
		hold.insert(make_pair(key,value));
		holder.hold_value_to_key.insert(make_pair(value, key));
	}
	f.close();//本程序无需输入操作，故直接关闭文件
}
void Fileread::test(){
	multimap<int, int>::iterator it;
	it = hold.begin();
	cout << "hold_map_test" << endl;
	while (it != hold.end())
	{
		cout<<it->first<<" "<<it->second;
		it++;
		cout << endl;
	}
	cout << endl;

}
