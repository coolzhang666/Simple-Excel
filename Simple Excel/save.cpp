#include "excel.h"

void save(Cell ***p)
{
	string filename;
	std::cout << "�������ļ���" << endl;
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
		std::cout << "����ɹ�" << endl;
		write.close();
		read.close();
	}
	else
	{
		char c;
		std::cin.get();
		std::cout << "�ļ��Ѵ���,�Ƿ񸲸�?(Y/N)";
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
			std::cout << "����ɹ�" << endl;
			write.close();
			read.close();
		}
		else if (c == 'n' || c == 'N')
		{
			read.close();
		}
	}
}