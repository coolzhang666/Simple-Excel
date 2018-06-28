#include "excel.h"

void create1();

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
			case 1:create1(); system("cls"); break;
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
	string filename;
	std::cout << "请输入文件名" << endl;
	std::cin >> filename;
	vector<string> data;
	data = readTxt(filename);
	if (data.size() > 0)
	{
		int _row = atoi(data[0].c_str());
		int _col = atoi(data[1].c_str());
		Cell ***array = (Cell ***)malloc(sizeof(Cell**)*_row);
		for (int i = 0; i < _row; i++)
		{
			array[i] = (Cell **)malloc(sizeof(Cell*)*_col);
			for (int j = 0; j < _col; j++)
			{
				array[i][j] = new Cell(i, j, "0");
			}
		}
		int m = 2;
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _col; j++)
			{
				array[i][j]->setValue(data[m]);
				array[i][j]->setStatus(true);
				m++;
			}
		}
		create(array, _row, _col);
		free(array);
	}
}

vector<string> readTxt(string file)
{
	vector<string> res;
	ifstream infile;
	infile.open(file.data());
	if (!infile)
	{
		system("cls");
		std::cout << "文件不存在" << endl;
	}
	else
	{
		string s;
		char *pch;
		while (getline(infile, s))
		{
			string word = s;
			string result;
			stringstream input(word);
			while (input >> result)
				res.push_back(result);
		}
		infile.close();
	}
	return res;
}

void create1()
{
	system("cls");
	int row, col;
	Cell ***array;
	std::cout << "请输入行数和列数:";
	std::cin >> row >> col;
	int _row = row;
	int _col = col;
	array = (Cell ***)malloc(sizeof(Cell**)*row);
	for (int i = 0; i < row; i++)
	{
		array[i] = (Cell **)malloc(sizeof(Cell*)*col);
		for (int j = 0; j < col; j++)
		{
			array[i][j] = new Cell(i, j, "0");
		}
	}
	system("cls");
	std::cout << "创建成功" << endl;
	create(array, _row, _col);
	free(array);
}