#pragma once
#include "Team.cpp"
#include "Header.h"
#include "AllowIndexes.h"
class MyTeam :public Team
{
private:
	//увесь флот гравц€; 
	int singleShips;
	int doubleShips;
	int tripleShips;
	int foursShips;

	int countIsLive;   //загальна к-сть "живих"
	int countIsWounded;   //к-сть п≥дбитих
	int countIsDead;   //к-сть затонулих

	enum TypeShips
	{
		TypeSingle = 1,
		TypeDouble = 2,
		TypeTriple = 3,
		TypeFours = 4
	};
	enum CountShips
	{
		CountSingle = 4,
		CountDouble = 3,
		CountTriple = 2,
		CountFours = 1
	};
	//enum StatusShip
	//{
	//	Cilyy,
	//	Wounded,
	//	Dead
	//};

	enum StatusCell
	{
		IsDead = 0,
		IsLive = 1,
		Empty = 2,
		IsMiss = 3
	};
public:
	void SetShips()
	{
		SetEmptiesCells();
		SearchPosition(TypeFours, CountFours);
		SearchPosition(TypeTriple, CountTriple);
		SearchPosition(TypeDouble, CountDouble);
		SearchPosition(TypeSingle, CountSingle);
	}
	bool IsLiveCell(int vert, int horiz)
	{
		if (map[vert][horiz] == IsLive)
			return true;
		else
			return false;
	}
	void SearchPosition(TypeShips typeShip, CountShips countShips)
	{
		int direction;
		bool result;
		for (int count = 0, vertical, horizontal; count < countShips; ++count)
		{
			result = false;
			do
			{
				do
				{
					vertical = rand() % 10;
					horizontal = rand() % 10;
				} while (!IsEmpty(vertical, horizontal) || !IsEmptySide(vertical, horizontal));

				int vertEnd, horizEnd;

				for (bool keyUp = true, keyDown = true, keyLeft = true, keyRight = true;
					result == false;)
				{
					direction = rand() % 4;
					switch (direction)
					{
					case 0:    // напр€мок вверх
						if (keyUp)
						{
							vertEnd = vertical - (typeShip - 1);
							horizEnd = horizontal;
							if (IsEmptySide(vertEnd, horizEnd) && AllowIndexes(vertEnd, horizEnd))
							{
								for (int v = vertical, h = horizontal; v >= vertEnd; --v)
									map[v][h] = IsLive;
								result = true;
							}
							else
							{
								keyUp = false;
							}
						}
						break;
					case 1:    // напр€мок вниз
						if (keyDown)
						{
							vertEnd = vertical + (typeShip - 1);
							horizEnd = horizontal;
							if (IsEmptySide(vertEnd, horizEnd) && AllowIndexes(vertEnd, horizEnd))
							{
								for (int v = vertical, h = horizontal; v <= vertEnd; ++v)
									map[v][h] = IsLive;
								result = true;
							}
							else
							{
								keyDown = false;
							}
						}
						break;
					case 2:    // напр€мок вл≥во
						if (keyLeft)
						{
							vertEnd = vertical;
							horizEnd = horizontal - (typeShip - 1);
							if (IsEmptySide(vertEnd, horizEnd) && AllowIndexes(vertEnd, horizEnd))
							{
								for (int v = vertical, h = horizontal; h >= horizEnd; --h)
									map[v][h] = IsLive;
								result = true;
							}
							else
							{
								keyLeft = false;
							}
						}
						break;
					case 3:    // напр€мок вправо
						if (keyRight)
						{
							vertEnd = vertical;
							horizEnd = horizontal + (typeShip - 1);
							if (IsEmptySide(vertEnd, horizEnd) && AllowIndexes(vertEnd, horizEnd))
							{
								for (int v = vertical, h = horizontal; h <= horizEnd; ++h)
									map[v][h] = IsLive;
								result = true;
							}
							else
							{
								keyRight = false;
							}
						}
						break;
					}
				}
			} while (!result);
		}
	}
	bool IsEmptySide(int vert, int horiz)
	{
		if (vert - 1 > -1 && horiz - 1 > -1)
		{
			if (!IsEmpty(vert - 1, horiz - 1))
				return false;
		}
		if (vert - 1 > -1)
		{
			if (!IsEmpty(vert - 1, horiz))
				return false;
		}
		if (vert - 1 > -1 && horiz + 1 < 11)
		{
			if (!IsEmpty(vert - 1, horiz + 1))
				return false;
		}
		if (horiz + 1 < 11)
		{
			if (!IsEmpty(vert, horiz + 1))
				return false;
		}
		if (vert + 1 < 11 && horiz + 1<11)
		{
			if (!IsEmpty(vert + 1, horiz + 1))
				return false;
		}
		if (vert + 1<11)
		{
			if (!IsEmpty(vert + 1, horiz))
				return false;
		}
		if (vert + 1 < 11 && horiz - 1 > -1)
		{
			if (!IsEmpty(vert + 1, horiz - 1))
				return false;
		}
		if (horiz - 1 > -1)
		{
			if (!IsEmpty(vert, horiz - 1))
				return false;
		}
		return true;
	}
	bool IsDeadTeam()
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int k = 0; k < 10; ++k)
			{
				if (map[i][k] == IsLive)
					return false;
			}
		}
		return true;
	}
};

class TeamEnemy :public Team
{
public:
	
};
class Player
{
private:
	string name;
	MyTeam myTeam;
	TeamEnemy teamEnemy;
public:
	Player()
	{
	}
	void SetName(string n)
	{
		name = n;
	}
	string GetName()
	{
		return name;
	}
	void SetShips()
	{
		myTeam.SetShips();
		teamEnemy.SetEmptiesCells();
	}
	void ShowMyMap()
	{
		myTeam.ShowMap();
	}
	void ShowEnemyMap()
	{
		teamEnemy.ShowMap();
	}
	bool ShotMe(int vert, int horiz)
	{
		if (myTeam.IsLiveCell(vert, horiz))
		{
			myTeam.SetDead(vert, horiz);
			return true;
		}
		else
		{
			myTeam.SetMiss(vert, horiz);
			return false;
		}
	}
	bool IsGameOver()
	{
		if (myTeam.IsDeadTeam())
			return true;
		else
			return false;
	}
	bool IsPromiseCell(int vert, int horiz)
	{
		if (!teamEnemy.IsDeadCell(vert, horiz) && !teamEnemy.IsMissCell(vert, horiz))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void DeadEnemyMap(int vert, int horiz)
	{
		teamEnemy.SetDead(vert, horiz);
	}
	void MissEnemyMap(int vert, int horiz)
	{
		teamEnemy.SetMiss(vert, horiz);
	}
};