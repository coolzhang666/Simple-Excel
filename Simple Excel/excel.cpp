#include <iostream>
using namespace std;
#define MAX_ROW 50
#define MAX_COL 50

extern void create();
void open();

void main()
{
	int choose;
	std::cout << "┌─────────────────────────────────────────────────────┐" << endl;
	std::cout << "│                    简易电子表格                     │" << endl;
	std::cout << "├─────────────────────────────────────────────────────┤" << endl;
	std::cout << "│                  1---新建电子表格                   │" << endl;
	std::cout << "├─────────────────────────────────────────────────────┤" << endl;
	std::cout << "│                  2---打开电子表格                   │" << endl;
	std::cout << "├─────────────────────────────────────────────────────┤" << endl;
	std::cout << "│                  0---退出应用程序                   │" << endl;
	std::cout << "└─────────────────────────────────────────────────────┘" << endl;
	while (true)
	{
		std::cout << "请选择:";
		std::cin >> choose;
		switch (choose)
		{
		case 1:create(); break;
		case 2:open(); break;
		case 0:std::cout << "Good Bye!!!" << endl; exit(0); break;
		default: std::cout << "请输入合法数据!" << endl;
		}
	}
}

void open()
{
	std::cout << "打开" << endl;
}