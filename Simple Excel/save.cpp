#include "excel.h"

void save(Cell ***p)
{
	string filename;
	std::cout << "请输入文件名" << endl;
	std::cin >> filename;
	ifstream read;
	read.open(filename);
	if (!read)
	{
		string str;
		ofstream write;
		write.open(filename);
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++)
			{
				write << p[i][j]->getValue() << " ";
			}
			write << endl;
		}
		system("cls");
		std::cout << "保存成功" << endl;
		write.close();
		read.close();
	}
	else
	{
		char c;
		std::cin.get();
		std::cout << "文件已存在,是否覆盖?(Y/N)";
		std::cin >> c;
		if (c == 'y' || c == 'Y')
		{
			string str;
			ofstream write;
			write.open(filename);
			for (int i = 0; i < _row; i++) {
				for (int j = 0; j < _col; j++)
				{
					write << p[i][j]->getValue() << " ";
				}
				write << endl;
			}
			system("cls");
			std::cout << "保存成功" << endl;
			write.close();
			read.close();
		}
		else if (c == 'n' || c == 'N')
		{
			read.close();
		}
	}
}