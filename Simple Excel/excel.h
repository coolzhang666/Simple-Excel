#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#define MAX_ROW 26
#define MAX_COL 34

class Cell
{
private:
	int row, col, value;
	bool status;

public:
	Cell(int row, int col, int value)
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

	int getValue()
	{
		return this->value;
	}

	void setValue(int value)
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
extern Cell ***array;
extern void create();
extern void open();
extern void draw(int row, int col, Cell ***p);
extern void input(Cell ***p);
extern void save(Cell ***p);