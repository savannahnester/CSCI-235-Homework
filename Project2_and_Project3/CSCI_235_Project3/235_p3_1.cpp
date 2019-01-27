/*
Savannah Nester
CSCI 235 Programming Assignment 3 Question 1
Imagine a robot sitting on the upper left corner of grid with r rows and c columns. The robot can only
move in two directions, right and down, but certain cells are \o limits" such that the robot cannot step
on them. Design an algorithm to nd a path for the robot from the top left to the bottom right.

PLEASE TAKE NOTICE: I wrote this in C++11 (I hope that's okay--> I use it at my internship and
I find some of it's features better suited for a problem like this)

*/

#include <iostream>
#include <vector>
#include <list>
#include<string>

using namespace std;

class Robot
{
	public:
	vector<vector<int> > grid;

	Robot(int rowSize, int colSize);
	void show_grid();
	void showOffLimit(int row, int col);
	bool isFree(int row, int col);
	list<string> findPath();
	list<string> findPath(int startRow, int startCol, int row, int col);
};
//constructor
Robot::Robot(int rowSize, int colSize)
{
	cout << "Creating a board X: " << rowSize << " Y: " << colSize << endl;
	for (int i = 0; i < rowSize; i++)
	{
		vector<int> aOneCol(colSize,0);
		grid.push_back(aOneCol);
	}
}
//this function builds and displays the grid (maze) the robot will be traveling through
void Robot::show_grid()
{
	int sizeRow = grid[0].size();
	int sizeCol = grid.size();

	cout << "Displaying a board of size X: " << sizeCol << " Y: " << sizeRow << std::endl;

	for (int i=sizeRow-1; i >= 0; i--)
	{
		for (int j=0; j < sizeCol; j++)
		{
			cout << grid[j][i];
		}
		cout << endl;
	}
}
//check if the space in the 2D vector is available for the robot to move through
bool Robot::isFree(int row, int col)
{
	if(row < 0 || row >= grid.size())
	{
		return false;
	}
	if(col <0 || col >= grid[0].size())
	{
		return false;
	}
	if (grid[row][col] != 0)
	{
		return false;
	}
	return true;
}
//off-limit sections of the grid where robot cannot move
//off limit = 1, free = 0
void Robot::showOffLimit(int row, int col)
{
	if(row > grid.size() || col > grid[0].size())
	{
		cout << "Error" << endl;
	}
	grid[row][col]=1;
}

list<string> Robot::findPath()
{
	int sizeRow_ = grid.size()-1;
	int sizeCol_ = grid[0].size()-1;
	cout << "Going from X: 0, Y: " << sizeCol_ << " to X: "<< sizeRow_ << " ,Y: 0" << endl;

	return findPath(0,sizeCol_,sizeRow_, 0);
}

//finds the different paths the robot can take to get to the bottom right corner of the grid
list<string> Robot::findPath(int startRow, int startCol, int row, int col)
{
	if ((row==startRow) && (col == startCol))
	{
		string aPath="";
		list<string> aPossiblePath;
		aPossiblePath.push_back(aPath);
		return aPossiblePath;
	}
	list<string> aPossiblePathCurrent;
	//if robot can move down, move there and add "D" for down to the list as part of it's path
	if (isFree(row, col+1))
	{
		list<string> aPossiblePath = findPath(startRow,startCol,row, col+1);
		for (string aOnePath : aPossiblePath)
		{
			aPossiblePathCurrent.push_back(aOnePath + "D");
		}
	}
	//if robot can move right, move there and add "R" for right to the list as part of it's path
	if (isFree(row-1,col))
	{
		list<string> aPossiblePath = findPath(startRow,startCol,row-1,col);
		for (string aOnePath : aPossiblePath)
		{
			aPossiblePathCurrent.push_back(aOnePath + "R");
		}
	}
	return aPossiblePathCurrent;
}
//main function for testing purposes
int main()
{
	//testing with a 3x5 grid
	Robot myRobot(3,5);
	//testing this location as off limit for the robot
	myRobot.showOffLimit(2,2);
	myRobot.show_grid();
	//find path and print the different paths the robot can take to get there
	//will be multiple paths since I only made one location off limit for the robot
	list<string> aPossiblePath = myRobot.findPath();
	for (auto aOnePath : aPossiblePath)
	{
		cout << "Path : " << aOnePath<< endl;
	}

	return 0;
}
