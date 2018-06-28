#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <regex>
#include <sstream>
#include <vector>

using namespace std;
#define MAX_ROW 26
#define MAX_COL 34

class Cell
{
private:
	int row, col;
	bool status;
	string value;
public:
	Cell(int row, int col, string value)
	{
		this->row = row;
		this->col = col;
		this->value = value;
		this->status = false;
	}

	int getRow()
	{
		return this->row;
	}

	void setRow(int row)
	{
		this->row = row;
	}

	int getCol()
	{
		return this->col;
	}

	void setCol(int col)
	{
		this->col = col;
	}

	string getValue()
	{
		return this->value;
	}

	void setValue(string value)
	{
		this->value = value;
	}

	bool getStatus()
	{
		return this->status;
	}

	void setStatus(bool status)
	{
		this->status = status;
	}
};

extern void create(Cell ***p, int _row, int _col);
extern void open();
extern void draw(int row, int col, Cell ***p);
extern void input(Cell ***p, int _row, int _col);
extern void save(Cell ***p, int _row, int _col);
extern void calculate(Cell ***p, int _row, int _col);
extern void sort(Cell ***p, int _row, int _col);
extern void copy(Cell ***p, int _row, int _col);
extern void formula(Cell ***p);
extern vector<string> readTxt(string file);