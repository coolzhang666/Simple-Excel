#include "excel.h"

void create1();

void main()
{
	char c;
	int choose;
	while (true)
	{
		std::cout << "��������������������������������������������������������������������������������������������������������������" << endl;
		std::cout << "��                    ���׵��ӱ��                     ��" << endl;
		std::cout << "��������������������������������������������������������������������������������������������������������������" << endl;
		std::cout << "��                  1---�½����ӱ��                   ��" << endl;
		std::cout << "��������������������������������������������������������������������������������������������������������������" << endl;
		std::cout << "��                  2---�򿪵��ӱ��                   ��" << endl;
		std::cout << "��������������������������������������������������������������������������������������������������������������" << endl;
		std::cout << "��                  0---�˳�Ӧ�ó���                   ��" << endl;
		std::cout << "��������������������������������������������������������������������������������������������������������������" << endl;
		std::cout << "��ѡ��:";
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
			std::cout << "#######������Ϸ�����#######" << endl;
		}
	}
}

void open()
{
	string filename;
	std::cout << "�������ļ���" << endl;
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
		std::cout << "�ļ�������" << endl;
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
	std::cout << "����������������:";
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
	std::cout << "�����ɹ�" << endl;
	create(array, _row, _col);
	free(array);
}