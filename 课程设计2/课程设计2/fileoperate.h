#pragma once
#include<string>
using namespace std;
class FileOperate {
public:
	FileOperate(string f_filename = "studentdata.txt");
	void fileto(void);
	void tofile(void);
private:
	string filename;
};