#include "excel.h"

void main()
{
	char c;
	int choose;
	while (true)
	{
		std::cout << "┌─────────────────────────────────────────────────────┐" << endl;
		std::cout << "│                    简易电子表格                     │" << endl;
		std::cout << "├─────────────────────────────────────────────────────┤" << endl;
		std::cout << "│                  1---新建电子表格                   │" << endl;
		std::cout << "├─────────────────────────────────────────────────────┤" << endl;
		std::cout << "│                  2---打开电子表格                   │" << endl;
		std::cout << "├─────────────────────────────────────────────────────┤" << endl;
		std::cout << "│                  0---退出应用程序                   │" << endl;
		std::cout << "└─────────────────────────────────────────────────────┘" << endl;
		std::cout << "请选择:";
		std::cin >> c;
		if (c >= '0' && c <= '2')
		{
			choose = atoi(&c);
			switch (choose)
			{
			case 1:create(); system("cls"); break;
			case 2:open(); break;
			case 0:std::cout << "Good Bye!!!" << endl; exit(0); break;
			}
		}
		else
		{
			system("cls");
			std::cout << "#######请输入合法数据#######" << endl;
		}
	}
}

void open()
{
	std::cout << "打开" << endl;
}