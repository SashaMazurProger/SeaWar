#pragma once
#include "Header.h"
class Team
{
protected:
	int map[10][10];
	int statusShipMap[10][10];
	enum StatusShip
	{
		DeadShip=0,
		LiveShip=1,
		EmptyShip=2
	};
	enum StatusCell
	{
		IsDead = 0,
		IsLive = 1,
		Empty = 2,
		IsMiss = 3
	};
public:
	void SetDead(int vert, int horiz)
	{
		map[vert][horiz] = IsDead;
	}
	void SetMiss(int vert, int horiz)
	{
		map[vert][horiz] = IsMiss;
	}
	void SetEmptiesCells()
	{
		for (int a = 0; a < 10; ++a)
		{
			for (int b = 0; b < 10; ++b)
			{
				map[a][b] = Empty;
				statusShipMap[a][b] = EmptyShip;
			}
		}
	}
	bool IsEmpty(int vert, int horiz)
	{
		if (map[vert][horiz] == Empty)
			return true;
		else
			return false;
	}
	bool IsDeadCell(int vert, int horiz)
	{
		if (map[vert][horiz] == IsDead)
			return true;
		else
			return false;
	}


	bool IsDeadShip(int vert, int horiz,int oldVert=0,int oldHoriz=0)
	{
		
		if (vert - 1 > -1)
		{
			if (vert - 1 != oldVert)
			{
				if (IsDeadCell(vert - 1, horiz))
					return IsDeadShip(vert - 1, horiz, vert, horiz);
				else if (statusShipMap[vert - 1][horiz] == LiveShip)
					return false;
			}
		}
		if (horiz + 1 < 11)
		{
			if (horiz+1 != oldHoriz)
			{
				if (IsDeadCell(vert , horiz+1))
					return IsDeadShip(vert , horiz+1, vert, horiz);
				else if (statusShipMap[vert][horiz+1] == LiveShip)
					return false;
			}
		}
		if (vert + 1<11)
		{
			if (vert + 1 != oldVert)
			{
				if (IsDeadCell(vert + 1, horiz))
					return IsDeadShip(vert + 1, horiz, vert, horiz);
				else if (statusShipMap[vert + 1][horiz] == LiveShip)
					return false;
			}
		}
		if (horiz - 1 > -1)
		{
			if (horiz - 1 != oldHoriz)
			{
				if (IsDeadCell(vert , horiz-1))
					return IsDeadShip(vert , horiz-1, vert, horiz);
				else if (statusShipMap[vert][horiz-1] == LiveShip)
					return false;
			}
		}
		return true;
	}
	bool IsMissCell(int vert, int horiz)
	{
		if (map[vert][horiz] == IsMiss)
			return true;
		else
			return false;
	}
	void ShowMap()
	{
		cout << "\n\t\t\t   0  1  2  3  4  5  6  7  8  9 ";
		cout << "\n\t\t\t #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#";
		for (int i = 0; i < 10; ++i)
		{
			cout << "\n\t\t\t ¦" << setw(31) << "¦";
			cout << "\n\t\t\t" << i << "¦";
			for (int k = 0; k < 10; ++k)
			{
				if (map[i][k] == Empty)
					cout << " * ";
				else if (map[i][k] == IsDead)
					cout << " X ";
				else if (map[i][k] == IsMiss)
					cout << " o ";
				else if (map[i][k] == IsLive)
					cout << " $ ";
			}
			cout << "¦";
		}
		cout << "\n\t\t\t #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#";
	}
};