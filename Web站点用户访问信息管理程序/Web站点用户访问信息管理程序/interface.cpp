/*
Web站点用户访问信息管理程序
某个WWW站点将来访用户的信息记录到一个文本文件，该文件的格式如下 :
< Visitor's IP Address>  <day of year>  <year>
	其中访问日期用某一年的第几天表示，如下是若干有效的记录 :(年和天统一用一个数字与标准数字之间之差来表示，标准数字为0，表示
	0000年0月0日，默认每年360天，每月30天)
	140.192.16.8(1)  34  1998   例如该日期用数字1998*30+34表示，a*360+b，0<=b<360
	129.78.55.6(2)   3   1999
	140.192.34.6(3)  35  1998
	文件中可以包含相同的记录，相同的记录表示某个访问者在某一天多次访问该站点，访问者的身份以其IP地址来鉴别。
	设计一个可与用户进行交互的程序，该程序读入上述文件并支持用户如下的操作请求 :
·列出所有年份中指定的某一天的所有访问者。
·列出某年某天的所有访问者。
·得出某个访问者在某年或某天的访问次数。
·列出某天或某年中前n个访问最频繁的访问者，n由用户指定。
·分别以IP地址、访问日期或访问年度为顺序将文件中的内容输出到标准输出流。
·列出所有年份中指定的某一天的所有访问者。
·列出某年某天的所有访问者。
·得出某个访问者在某年或某天的访问次数。
·列出某天或某年中前n个访问最频繁的访问者，n由用户指定。
·分别以IP地址、访问日期或访问年度为顺序将文件中的内容输出到标准输出流。
1.	采用面向对象程序设计，要运用类的封装、继承、多态等机制；(继承和多态怕是有毒吧)
2.	具备文件读写功能，程序中的数据要以文件方式保存；
3.	程序中要具备对STL容器的运用；（map(int,int)）
4.	程序中要求具备异常处理；(文件读取用一下异常处理)
5.	必须体现多文件结构的思想，类定义和类实现进行分离；
6.	程序要求做到界面友好，对于用户的输入操作要有明确的提示信息，并对输入的数据进行合法性和正确性的检查；
7.	做到工程名、类名、变量名、代码格式等合乎规范，代码中必须对所设计的类的功能或函数功能进行规范的注解。
8.	要求具备菜单功能，根据用户的输入，执行相应的操作。在菜单选项中，必须包含“关于”一项，
该菜单项用来显示课程设计的基本信息，包括程序名称、版本、完成时间、姓名、班级、学号等信息
*/
#include<iostream>
#include<conio.h>
#include"interface.h"
#include"holder.h"


using namespace std;

extern Holder holder;
extern Interface interface;
extern Fileread fileread;

void Interface::start() {
	system("cls");
	system("mode con cols=67 lines=34");
	system("color 06");
	cout << " ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n";
	cout << "★☆      Web站点用户访问信息管理系统                      ☆★\n";
	cout << "☆                                                           ☆\n";//先用反转的map来查询特定日期，将这些数据
	cout << "★☆  我告诉你这什么用都没有你信吗  1                       ☆★\n";//保存到一个新的map中，(该map需为反转回来的形式)
	cout << "☆                                                           ☆\n";//然后利用count()方法的到对应id的访问次数，再新建
	cout << "★☆        列出某年某天的所有访问者(Y)      2                ☆★\n";//一个map，键为id，值为访问次数
	cout << "☆                                                           ☆\n";//
	cout << "★☆       得出某个访问者的访问情况(Y)     3                 ☆★\n";//
	cout << "☆															     ☆\n";//
	cout << "★☆ 列出某天或某年中前n个访问最频繁的访问者，n由用户指定   4☆★\n";//
	cout << "☆		(输入两个值，分别为date和n)		                     ☆\n";//
	cout << "★☆ 以IP地址为顺序将文件中的内容输出到标准输出流(Y)      5  ☆★\n";//
	cout << "☆                                                           ☆\n";
	cout << "★☆   访问日期为顺序将文件中的内容输出到标准输出流(Y)    6    ☆★\n";
	cout << "☆															     ☆\n";
	cout << "★☆               测试文件读入map是否成功(Y)    7            ☆★\n";
	cout << "☆                                                           ☆\n";
	cout << "★☆        关于程序(Y)                  8              ☆★\n";
	cout << "☆                                                           ☆\n";
	cout << "★☆        退出程序(Y)                 9                ☆★\n";
	cout << " ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n";
	cout << "请输入数字进行操作：";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1':system("cls");
		system("mode con cols=67 lines=34");
		system("color 06");
		cout << "\n\n\n"<<endl;
		cout << "	へ　　　　　／|"<<endl;
		cout << "	/＼7　　∠＿/"<<endl;
		cout << "	/　│　　 ／　／"<<endl;
		cout << "	│　Z ＿,＜　／　　 /`ヽ"<<endl;
		cout << "	│　　　　　ヽ　　 /　　〉"<<endl;
		cout << "	Y　　　　　`　 /　　/"<<endl;
		cout << "	ｲ●　､　●　　⊂⊃〈　　/"<<endl;
		cout << "	()　 へ　　　　|　＼〈"<<endl;
		cout << "	>ｰ ､_　 ィ　 │ ／／"<<endl;
		cout << "	/ へ　　 /　ﾉ＜| ＼＼"<<endl;
		cout << "	ヽ_ﾉ　　(_／　 │／／"<<endl;
		cout << "	7　　　　　　　|／"<<endl;
		cout << "	＞―r￣￣`ｰ―＿"<<endl;

		_getch();
		interface.start();
		break;
	case '2':
		system("cls");
		system("mode con cols=67 lines=34");
		system("color 06");
		cout << "请输入要查询的date";
		int i;
		cin >> i;
		holder.show_value_to_key(i);
		_getch();
		interface.start();
		break;
	case '3':
		system("cls");
		system("mode con cols=67 lines=34");
		system("color 06");
		cout << "请输入要查询的id";
		int k;
		cin >> k;
		//i = _getch();
		holder.show_key(k );
		_getch();
		interface.start();
		break;
	case '4':
		system("cls");
		system("mode con cols=67 lines=34");
		system("color 06");
		cout << "请输入日期和n：" << endl;
		int r, n;
		cin >> r >> n;
		holder.show_data_sort( r,n);
		_getch();
		interface.start();
		break;
	case '5':holder.show_id(); 
		_getch();
		interface.start(); 
		break;
	case '6':system("cls");
		system("mode con cols=67 lines=34");
		system("color 06");
		holder.sort_date();
		//holder.show_date();
		_getch();
		interface.start();
		break;
	case '7':system("cls");
		system("mode con cols=67 lines=34");
		system("color 06");
		fileread.test();
		holder.test();
		_getch();
		start();
		break;
	case '8':	system("cls");
		system("mode con cols=67 lines=34");
		system("color 06");
		cout << "▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼\n";
		cout << "○Web站点用户访问信息管理程序   ○\n";
		cout << "△版本：1.0                     △\n";
		cout << "○当前版本发步时间:2019/6/9     ○\n";
		cout << "▼作者                          ▼\n";
		cout << "○ 姓名：王伟杰                 ○\n";
		cout << "○ 学号：8002118126             ○\n";
		cout << "○ 班级：软件工程1805班         ○\n";
		cout << "○                              ○\n";
		cout << "○                              ○\n";
		cout << "○                              ○\n";
		cout << "○ （话说要用继承有点太勉强了吧 ○\n";
		cout << "○  （所以用泛型也很勉强啊）    ○\n";
		cout << "○ (为什么我的全是map操作啊！！)○\n";
		cout << "○        好绝望啊              ○\n";
		cout << "△▲△▲△▲△▲△▲△▲△▲△▲△\n";
		_getch();
		start();
		break; 
	case '9':exit(0); break;
	default:start(); break;
	}

}