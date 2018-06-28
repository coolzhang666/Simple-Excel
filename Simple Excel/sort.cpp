#include "excel.h"

void sort_r(Cell ***p, int _row, int _col);
void sort_c(Cell ***p, int _row, int _col);
void sort_ru(Cell ***p, int _row, int _col);
void sort_rd(Cell ***p, int _row, int _col);
void sort_cu(Cell ***p, int _row, int _col);
void sort_cd(Cell ***p, int _row, int _col);

void sort(Cell ***p, int _row, int _col)
{
	system("cls");
	char c;
	int choose;
	while (true) {
		std::cout << "┌──────────────────────────┬──────────────────────────┐" << endl;
		std::cout << "│     1---按行排序         │      2---按列排序        │" << endl;
		std::cout << "├──────────────────────────┴──────────────────────────┤" << endl;
		std::cout << "│                      0---退出                       │" << endl;
		std::cout << "└─────────────────────────────────────────────────────┘" << endl;
		std::cout << "请选择:";
		std::cin >> c;
		if (c >= '0' || c <= '2')
		{
			choose = atoi(&c);
			switch (choose)
			{
			case 1:sort_r(p, _row, _col); break;
			case 2:sort_c(p, _row, _col); break;
			case 0:system("cls"); return; break;
			}
		}
		else
		{
			system("cls");
			std::cout << "#######请输入合法数据#######" << endl;
		}
	}
}

void sort_r(Cell ***p, int _row, int _col)
{
	system("cls");
	char c;
	int choose;
	while (true) {
		std::cout << "┌──────────────────────────┬──────────────────────────┐" << endl;
		std::cout << "│       1---升序           │        2---降序          │" << endl;
		std::cout << "├──────────────────────────┴──────────────────────────┤" << endl;
		std::cout << "│                      0---退出                       │" << endl;
		std::cout << "└─────────────────────────────────────────────────────┘" << endl;
		std::cout << "请选择:";
		std::cin >> c;
		if (c >= '0' || c <= '2')
		{
			choose = atoi(&c);
			switch (choose)
			{
			case 1:sort_ru(p, _row, _col); break;
			case 2:sort_rd(p, _row, _col); break;
			case 0:system("cls"); return; break;
			}
		}
		else
		{
			system("cls");
			std::cout << "#######请输入合法数据#######" << endl;
		}
	}
}

void sort_ru(Cell ***p, int _row, int _col)
{
	system("cls");
	draw(_row, _col, p);
	int row, i, j;
	string str, temp;
	std::cout << "请输入行号:";
	std::cin >> row;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row;
	}

	for (i = 0; i < _col; i++)
	{
		for (j = 0; j < _col - i - 1; j++)
		{
			if (p[row-1][j]->getStatus() == false)
			{
				continue;
			}
			double a = atof(p[row-1][j]->getValue().c_str());
			if (p[row - 1][j + 1]->getStatus() == false)
			{
				break;
			}
			double b = atof(p[row-1][j + 1]->getValue().c_str());
			if (a > b)
			{
				temp = p[row-1][j]->getValue();
				p[row-1][j]->setValue(p[row-1][j + 1]->getValue());
				p[row-1][j + 1]->setValue(temp);
			}
		}
	}
	system("cls");
	draw(_row, _col, p);
}

void sort_rd(Cell ***p, int _row, int _col)
{
	system("cls");
	draw(_row, _col, p);
	int row, i, j;
	string str, temp;
	std::cout << "请输入行号:";
	std::cin >> row;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row;
	}

	for (i = 0; i < _col; i++)
	{
		for (j = 0; j < _col - i - 1; j++)
		{
			if (p[row - 1][j]->getStatus() == false)
			{
				continue;
			}
			double a = atof(p[row - 1][j]->getValue().c_str());
			if (p[row - 1][j + 1]->getStatus() == false)
			{
				break;
			}
			double b = atof(p[row - 1][j + 1]->getValue().c_str());
			if (a < b)
			{
				temp = p[row - 1][j]->getValue();
				p[row - 1][j]->setValue(p[row - 1][j + 1]->getValue());
				p[row - 1][j + 1]->setValue(temp);
			}
		}
	}
	system("cls");
	draw(_row, _col, p);
}

void sort_c(Cell ***p, int _row, int _col)
{
	system("cls");
	char c;
	int choose;
	while (true) {
		std::cout << "┌──────────────────────────┬──────────────────────────┐" << endl;
		std::cout << "│       1---升序           │        2---降序          │" << endl;
		std::cout << "├──────────────────────────┴──────────────────────────┤" << endl;
		std::cout << "│                      0---退出                       │" << endl;
		std::cout << "└─────────────────────────────────────────────────────┘" << endl;
		std::cout << "请选择:";
		std::cin >> c;
		if (c >= '0' || c <= '2')
		{
			choose = atoi(&c);
			switch (choose)
			{
			case 1:sort_cu(p, _row, _col); break;
			case 2:sort_cd(p, _row, _col); break;
			case 0:system("cls"); return; break;
			}
		}
		else
		{
			system("cls");
			std::cout << "#######请输入合法数据#######" << endl;
		}
	}
}

void sort_cu(Cell ***p, int _row, int _col)
{
	system("cls");
	draw(_row, _col, p);
	int col, i, j;
	string str, temp;
	std::cout << "请输入列号:";
	std::cin >> col;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col;
	}

	for (i = 0; i < _row; i++)
	{
		for (j = 0; j < _row - i - 1; j++)
		{
			if (p[j][col - 1]->getStatus() == false)
			{
				continue;
			}
			double a = atof(p[j][col - 1]->getValue().c_str());
			if (p[j + 1][col - 1]->getStatus() == false)
			{
				break;
			}
			double b = atof(p[j + 1][col - 1]->getValue().c_str());
			if (a > b)
			{
				temp = p[j][col - 1]->getValue();
				p[j][col - 1]->setValue(p[j + 1][col - 1]->getValue());
				p[j + 1][col - 1]->setValue(temp);
			}
		}
	}
	system("cls");
	draw(_row, _col, p);
}

void sort_cd(Cell ***p, int _row, int _col)
{
	system("cls");
	draw(_row, _col, p);
	int col, i, j;
	string str, temp;
	std::cout << "请输入列号:";
	std::cin >> col;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col;
	}

	for (i = 0; i < _row; i++)
	{
		for (j = 0; j < _row - i - 1; j++)
		{
			if (p[j][col - 1]->getStatus() == false)
			{
				continue;
			}
			double a = atof(p[j][col - 1]->getValue().c_str());
			if (p[j + 1][col - 1]->getStatus() == false)
			{
				break;
			}
			double b = atof(p[j + 1][col - 1]->getValue().c_str());
			if (a < b)
			{
				temp = p[j][col - 1]->getValue();
				p[j][col - 1]->setValue(p[j + 1][col - 1]->getValue());
				p[j + 1][col - 1]->setValue(temp);
			}
		}
	}
	system("cls");
	draw(_row, _col, p);
}