#include "excel.h"

void rows(Cell ***p);
void cols(Cell ***p);
bool isNum(string str);
void sum_r(Cell ***p);
void average_r(Cell ***p);
void max_r(Cell ***p);
void min_r(Cell ***p);
void sum_c(Cell ***p);
void average_c(Cell ***p);
void max_c(Cell ***p);
void min_c(Cell ***p);
void block(Cell ***p);
void sum_b(Cell ***p);
void average_b(Cell ***p);
void max_b(Cell ***p);
void min_b(Cell ***p);

void calculate(Cell ***p)
{
	system("cls");
	int choose;
	char c;
	while (true) 
	{
		std::cout << "┌──────────────────────────┬──────────────────────────┐" << endl;
		std::cout << "│      1---按行统计        │      2---按列统计        │" << endl;
		std::cout << "├──────────────────────────┼──────────────────────────┤" << endl;
		std::cout << "│      3---按块统计        │      0---退出            │" << endl;
		std::cout << "└──────────────────────────┴──────────────────────────┘" << endl;
		std::cout << "请选择:" << endl;
		std::cin >> c;
		if (c >= '0' && c <= '3')
		{
			choose = atoi(&c);
			switch (choose)
			{
			case 1:rows(p); break;
			case 2:cols(p); break;
			case 3:block(p); break;
			case 0:system("cls"); return; break;
			}
		}
		else
		{
			system("cls");
			std::cout << "请输入合法数据" << endl;
		}
	}
}


void rows(Cell ***p)
{
	system("cls");
	int choose;
	char c;
	while (true)
	{
		std::cout << "┌──────────────────────────┬──────────────────────────┐" << endl;
		std::cout << "│       1---合计           │      2---求平均值        │" << endl;
		std::cout << "├──────────────────────────┼──────────────────────────┤" << endl;
		std::cout << "│       3---求最大值       │      4---求最小值        │" << endl;
		std::cout << "├──────────────────────────┴──────────────────────────┤" << endl;
		std::cout << "│                      0---退出                       │" << endl;
		std::cout << "└─────────────────────────────────────────────────────┘" << endl;
		std::cout << "请选择:";
		std::cin >> c;
		if (c >= '0' && c <= '4')
		{
			choose = atoi(&c);
			switch (choose)
			{
			case 1:sum_r(p); break;
			case 2:average_r(p); break;
			case 3:max_r(p); break;
			case 4:system("cls"); min_r(p); break;
			case 0:return; break;
			}
		}
		else
		{
			system("cls");
			std::cout << "请输入合法数据" << endl;
		}
	}
}

void sum_r(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int row;
	double result = 0;
	string str;
	std::cout << "请输入行号:";
	std::cin >> row;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row;
	}

	for (int i = 0; i < _col; i++)
	{
		string s = p[row-1][i]->getValue();
		if (isNum(s))
		{
			result += atof(s.c_str());
		}
		else
		{
			system("cls");
			std::cout << "#######不能对字符串数据进行求和#######" << endl;
			return;
		}
	}
	system("cls");
	std::cout << "第" << row << "行求和结果为:" << result << endl;
}

void average_r(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int row, flag = 0;
	double result = 0;
	string str;
	std::cout << "请输入行号:";
	std::cin >> row;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row;
	}
	for (int i = 0; i < _col; i++)
	{
		string s = p[row - 1][i]->getValue();
		if (isNum(s))
		{
			if (p[row - 1][i]->getStatus() == true)
			{
				flag++;
			}
			result += atof(s.c_str());
		}
		else
		{
			system("cls");
			std::cout << "#######不能对字符串数据进行求和#######" << endl;
			return;
		}
	}
	system("cls");
	std::cout << "第" << row << "行求平均结果为:" << result/flag << endl;
}

void max_r(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int row, flag = 0;
	double result = 0;
	string str;
	std::cout << "请输入行号:";
	std::cin >> row;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row;
	}
	result = atof(p[row - 1][0]->getValue().c_str());
	for (int i = 0; i < _col; i++)
	{
		string s = p[row - 1][i]->getValue();
		if (isNum(s))
		{
			if (p[row - 1][i]->getStatus() == true)
			{
				double a = atof(s.c_str());
				if (a > result)
				{
					result = a;
				}
			}
		}
		else
		{
			system("cls");
			std::cout << "#######不能对字符串数据进行求和#######" << endl;
			return;
		}
	}
	system("cls");
	std::cout << "第" << row << "行最大值为:" << result << endl;
}

void min_r(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int row, flag = 0;
	double result = 0;
	string str;
	std::cout << "请输入行号:";
	std::cin >> row;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> row;
	}
	result = atof(p[row - 1][0]->getValue().c_str());
	for (int i = 0; i < _col; i++)
	{
		string s = p[row - 1][i]->getValue();
		if (isNum(s))
		{
			if (p[row - 1][i]->getStatus() == true)
			{
				double a = atof(s.c_str());
				if (a < result)
				{
					result = a;
				}
			}
		}
		else
		{
			system("cls");
			std::cout << "#######不能对字符串数据进行求和#######" << endl;
			return;
		}
	}
	system("cls");
	std::cout << "第" << row << "行最小值为:" << result << endl;
}


void cols(Cell ***p)
{
	system("cls");
	int choose;
	char c;
	while (true)
	{
		std::cout << "┌──────────────────────────┬──────────────────────────┐" << endl;
		std::cout << "│       1---合计           │      2---求平均值        │" << endl;
		std::cout << "├──────────────────────────┼──────────────────────────┤" << endl;
		std::cout << "│       3---求最大值       │      4---求最小值        │" << endl;
		std::cout << "├──────────────────────────┴──────────────────────────┤" << endl;
		std::cout << "│                      0---退出                       │" << endl;
		std::cout << "└─────────────────────────────────────────────────────┘" << endl;
		std::cout << "请选择:";
		std::cin >> c;
		if (c >= '0' && c <= '4')
		{
			choose = atoi(&c);
			switch (choose)
			{
			case 1:sum_c(p); break;
			case 2:average_c(p); break;
			case 3:max_c(p); break;
			case 4:system("cls"); min_c(p); break;
			case 0:return; break;
			}
		}
		else
		{
			system("cls");
			std::cout << "请输入合法数据" << endl;
		}
	}
}

void sum_c(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int col;
	double result = 0;
	string str;
	std::cout << "请输入列号:";
	std::cin >> col;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col;
	}

	for (int i = 0; i < _row; i++)
	{
		string s = p[i][col - 1]->getValue();
		if (isNum(s))
		{
			result += atof(s.c_str());
		}
		else
		{
			system("cls");
			std::cout << "#######不能对字符串数据进行求和#######" << endl;
			return;
		}
	}
	system("cls");
	std::cout << "第" << col << "行求和结果为:" << result << endl;
}

void average_c(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int col, flag = 0;
	double result = 0;
	string str;
	std::cout << "请输入列号:";
	std::cin >> col;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col;
	}
	for (int i = 0; i < _row; i++)
	{
		string s = p[i][col - 1]->getValue();
		if (isNum(s))
		{
			if (p[i][col - 1]->getStatus() == true)
			{
				flag++;
			}
			result += atof(s.c_str());
		}
		else
		{
			system("cls");
			std::cout << "#######不能对字符串数据进行求和#######" << endl;
			return;
		}
	}
	system("cls");
	std::cout << "第" << col << "列求平均结果为:" << result / flag << endl;
}

void max_c(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int col, flag = 0;
	double result = 0;
	string str;
	std::cout << "请输入列号:";
	std::cin >> col;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col;
	}
	result = atof(p[0][col - 1]->getValue().c_str());
	for (int i = 0; i < _row; i++)
	{
		string s = p[i][col - 1]->getValue();
		if (isNum(s))
		{
			if (p[i][col - 1]->getStatus() == true)
			{
				double a = atof(s.c_str());
				if (a > result)
				{
					result = a;
				}
			}
		}
		else
		{
			system("cls");
			std::cout << "#######不能对字符串数据进行求和#######" << endl;
			return;
		}
	}
	system("cls");
	std::cout << "第" << col << "列最大值为:" << result << endl;
}

void min_c(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int col, flag = 0;
	double result = 0;
	string str;
	std::cout << "请输入列号:";
	std::cin >> col;
	while (cin.fail())
	{
		cin.clear();
		cin >> str;
		std::cout << "#######请输入正确的数据#######" << endl;
		std::cin >> col;
	}
	result = atof(p[0][col - 1]->getValue().c_str());
	for (int i = 0; i < _row; i++)
	{
		string s = p[i][col - 1]->getValue();
		if (isNum(s))
		{
			if (p[i][col - 1]->getStatus() == true)
			{
				double a = atof(s.c_str());
				if (a < result)
				{
					result = a;
				}
			}
		}
		else
		{
			system("cls");
			std::cout << "#######不能对字符串数据进行求和#######" << endl;
			return;
		}
	}
	system("cls");
	std::cout << "第" << col << "列最小值为:" << result << endl;
}


void block(Cell ***p)
{
	system("cls");
	int choose;
	char c;
	while (true)
	{
		std::cout << "┌──────────────────────────┬──────────────────────────┐" << endl;
		std::cout << "│       1---合计           │      2---求平均值        │" << endl;
		std::cout << "├──────────────────────────┼──────────────────────────┤" << endl;
		std::cout << "│       3---求最大值       │      4---求最小值        │" << endl;
		std::cout << "├──────────────────────────┴──────────────────────────┤" << endl;
		std::cout << "│                      0---退出                       │" << endl;
		std::cout << "└─────────────────────────────────────────────────────┘" << endl;
		std::cin.get();
		std::cout << "请选择:";
		std::cin >> c;
		if (c >= '0' && c <= '4')
		{
			choose = atoi(&c);
			switch (choose)
			{
			case 1:sum_b(p); break;
			case 2:average_b(p); break;
			case 3:max_b(p); break;
			case 4:min_b(p); break;
			case 0:system("cls"); return; break;
			}
		}
		else
		{
			system("cls");
			std::cout << "请输入合法数据" << endl;
		}
	}
}

void sum_b(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int row1, col1, row2, col2;
	double result = 0;
	string str;
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

	for (int i = row1 - 1; i < row2; i++)
	{
		for (int j = col1 - 1; j < col2; j++)
		{
			string s = p[i][j]->getValue();
			if (isNum(s))
			{
				result += atof(s.c_str());
			}
			else
			{
				system("cls");
				std::cout << "#######不能对字符串数据进行求和#######" << endl;
				return;
			}
		}
	}
	system("cls");
	std::cout << "求和结果为:" << result << endl;
}

void average_b(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int row1, col1, row2, col2, flag = 0;
	double result = 0;
	string str;
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

	for (int i = row1 - 1; i < row2; i++)
	{
		for (int j = col1 - 1; j < col2; j++)
		{
			string s = p[i][j]->getValue();
			if (p[i][j]->getStatus() == true)
			{
				flag++;
			}
			if (isNum(s))
			{
				result += atof(s.c_str());
			}
			else
			{
				system("cls");
				std::cout << "#######不能对字符串数据进行求和#######" << endl;
				return;
			}
		}
	}
	system("cls");
	std::cout << "求平均结果为:" << result/flag << endl;
}

void max_b(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int row1, col1, row2, col2;
	double result = 0;
	string str;
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
	result = atof(p[row1 - 1][col1 - 1]->getValue().c_str());
	for (int i = row1 - 1; i < row2; i++)
	{
		for (int j = col1 - 1; j < col2; j++)
		{
			string s = p[i][j]->getValue();
			if (isNum(s))
			{
				double a = atof(s.c_str());
				if (a > result)
				{
					result = a;
				}
			}
			else
			{
				system("cls");
				std::cout << "#######不能对字符串数据进行求和#######" << endl;
				return;
			}
		}
	}
	system("cls");
	std::cout << "最大值为:" << result << endl;
}

void min_b(Cell ***p)
{
	system("cls");
	draw(_row, _col, p);
	int row1, col1, row2, col2;
	double result = 0;
	string str;
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
	result = atof(p[row1 - 1][col1 - 1]->getValue().c_str());
	for (int i = row1 - 1; i < row2; i++)
	{
		for (int j = col1 - 1; j < col2; j++)
		{
			string s = p[i][j]->getValue();
			if (isNum(s))
			{
				double a = atof(s.c_str());
				if (a < result)
				{
					result = a;
				}
			}
			else
			{
				system("cls");
				std::cout << "#######不能对字符串数据进行求和#######" << endl;
				return;
			}
		}
	}
	system("cls");
	std::cout << "最小值为:" << result << endl;
}

bool isNum(string str)
{
	std::string pattern{ "^(\\-|\\+)?\\d+(\\.\\d+)?$" };
	std::regex regex(pattern);
	bool result = std::regex_match(str, regex);
	return result;
}