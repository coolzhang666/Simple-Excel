#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <regex>
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

extern int _row, _col;
extern void create();
extern void open();
extern void draw(int row, int col, Cell ***p);
extern void input(Cell ***p);
extern void save(Cell ***p);
extern void calculate(Cell ***p);
extern void sort(Cell ***p);
extern void copy(Cell ***p);
extern void formula(Cell ***p);