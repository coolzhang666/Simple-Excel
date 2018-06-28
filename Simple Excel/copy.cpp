#include "excel.h"

void copy(Cell ***p, int _row, int _col)
{
	system("cls");
	draw(_row, _col, p);
	int row1, col1, row2, col2, row11, col11, row22, col22;
	double result = 0;
	string str;
	std::cout << "-----请输入块1信息-----" << endl;
	std::cout << "请输入行号1:";
	std::cin >> row1;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row1;
	}
	std::cout << "请输入列号1:";
	std::cin >> col1;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col1;
	}
	std::cout << "请输入行号2:";
	std::cin >> row2;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row2;
	}
	std::cout << "请输入列号2:";
	std::cin >> col2;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col2;
	}





	std::cout << "-----请输入块2信息-----" << endl;
	std::cout << "请输入行号1:";
	std::cin >> row11;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row11;
	}
	std::cout << "请输入列号1:";
	std::cin >> col11;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col11;
	}
	std::cout << "请输入行号2:";
	std::cin >> row22;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row22;
	}
	std::cout << "请输入列号2:";
	std::cin >> col22;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col22;
	}

	for (int i = row1 - 1, m = row11 - 1; i < row2; i++, m++)
	{
		for (int j = col1 - 1, n = col11 - 1; j < col2; j++, n++)
		{
			p[m][n]->setStatus(p[i][j]->getStatus());
			p[m][n]->setValue(p[i][j]->getValue());
		}
	}
	system("cls");
	draw(_row, _col, p);
}