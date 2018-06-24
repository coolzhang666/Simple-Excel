#include "excel.h"
int _row, _col;

void create() {
	system("cls");
	int row, col;
	Cell ***array;
	std::cout << "请输入行数和列数:";
	std::cin >> row >> col;
	_row = row;
	_col = col;
	array = (Cell ***)malloc(sizeof(Cell**)*row);
	for (int i = 0; i < row; i++)
	{
		array[i] = (Cell **)malloc(sizeof(Cell*)*col);
		for (int j = 0; j < col; j++)
		{
			array[i][j] = new Cell(i, j, 0);
		}
	}
	system("cls");
	std::cout << "创建成功" << endl;
	char c;
	int choose;
	while (true) {
		std::cout << "┌──────────────────────────┬──────────────────────────┐" << endl;
		std::cout << "│     1---编辑电子表格     │      2---统计计算        │" << endl;
		std::cout << "├──────────────────────────┼──────────────────────────┤" << endl;
		std::cout << "│     3---排序             │      4---数据复制        │" << endl;
		std::cout << "├──────────────────────────┼──────────────────────────┤" << endl;
		std::cout << "│     5---公式输入         │      6---保存表格        │" << endl;
		std::cout << "├──────────────────────────┴──────────────────────────┤" << endl;
		std::cout << "│                  0---关闭电子表格                   │" << endl;
		std::cout << "└─────────────────────────────────────────────────────┘" << endl;
		std::cout << "请选择:";
		std::cin >> c;
		if (c >= '0' || c <= '6')
		{
			choose = atoi(&c);
			switch (choose)
			{
			case 1:input(array); break;
			case 2:break;
			case 3:break;
			case 4:break;
			case 5:break;
			case 6:save(array); break;
			case 0:free(array); return; break;
			}
		}
		else
		{
			system("cls");
			std::cout << "#######请输入合法数据#######" << endl;
		}
	}
}

void draw(int row, int col, Cell ***p)
{
	for (int i = 0; i < col; i++) {
		std::cout << setw(6) << i+1;
	}
	std::cout << endl;

	std::cout << "  ┌";
	for (int i = 0; i < col-1; i++) {
		std::cout << "─────┬";
	}
	std::cout << "─────┐" << endl;

	for (int i = 0; i < row; i++)
	{
		std::cout << setw(2) << i+1 << "│";
		for (int j = 0; j < col; j++)
		{
			if (p[i][j]->getStatus() == false)
			{
				std::cout << "     │";
			}
			else
			{
				//std::cout << "     │";
				std::cout << setw(5) <<  p[i][j]->getValue() << "│";
			}
		}
		std::cout << endl;

		if (i == row - 1)
		{
			continue;
		}
		std::cout << "  ├";
		for (int k = 0; k < col-1; k++) {
			std::cout << "─────┼";
		}
		std::cout << "─────┤" << endl;
	}

	std::cout << "  └";
	for (int i = 0; i < col - 1; i++) {
		std::cout << "─────┴";
	}
	std::cout << "─────┘" << endl;
}

void input(Cell ***p)
{
	system("cls");\
	draw(_row, _col, p);
	while (true) {
		string err;
		int row, col, value;
		std::cout << "请依次输入行号,列号和数据(输入0 0 0以退出编辑):";
		std::cout << "行号";
		std::cin >> row;
		while (cin.fail())
		{
			cin.clear();
			cin >> err;
			std::cout << "#######请输入正确的数据#######" << endl;
			system("cls");
			continue;
		}
		std::cout << "列号";
		std::cin >> col;
		while (cin.fail())
		{
			cin.clear();
			cin >> err;
			std::cout << "#######请输入正确的数据#######" << endl;
			system("cls");
			continue;
		}
		std::cout << "数据";
		std::cin >> value;
		while (cin.fail())
		{
			cin.clear();
			cin >> err;
			std::cout << "#######请输入正确的数据#######" << endl;
			system("cls");
			continue;
		}
		if (row == 0 && col == 0 && value == 0)
		{
			break;
		}
		else if (row <= 0 || row > MAX_ROW || col <= 0 || col > MAX_COL)
		{
			system("cls");
			std::cout << "#######请输入正确的数据#######" << endl;
			draw(_row, _col, p);
			continue;
		}
		p[row - 1][col - 1]->setValue(value);
		p[row - 1][col - 1]->setStatus(true);
		system("cls");
		draw(_row, _col, p);
	}
	system("cls");
}