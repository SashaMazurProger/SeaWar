#include "Header.h"
#include "Player.cpp"


void BattleWithGamer()
{
	Player gamer1, gamer2;
	int vertical, horizontal;
	bool nick;
	bool keySaveMap;
	string nameGamer;
	cout << "\n>>>>>>>>>>>>>>>> ������ ����� <<<<<<<<<<<<<<<<";
	do
	{
		cout << "\n���� ���:";
		cin >> nameGamer;
	} while (nameGamer=="");
	gamer1.SetName(nameGamer);
	do
	{
		system("cls");
		cout << "\n>>>>>>>>>>>>>>>> ����� �����("<<gamer1.GetName()<<") <<<<<<<<<<<<<<<<";
		gamer1.SetShips();
		gamer1.ShowMyMap();
		cout << "\n����������?(1-���, 0-ͳ)";
		do
		{
			cout << "\n��� ����:";
			cin >> keySaveMap;
		} while (keySaveMap != 1 && keySaveMap != 0);
	} while (!keySaveMap);
	system("cls");
	cout << "\n>>>>>>>>>>>>>>>> ������ ����� <<<<<<<<<<<<<<<<";
	do
	{
		cout << "\n���� ���:";
		cin >> nameGamer;
	} while (nameGamer == "");
	gamer2.SetName(nameGamer);
	do
	{
		system("cls");
		cout << "\n>>>>>>>>>>>>>>>> ����� �����(" << gamer2.GetName() << ") <<<<<<<<<<<<<<<<";
		gamer2.SetShips();
		gamer2.ShowMyMap();
		cout << "\n����������?(1-���, 0-ͳ)";
		do
		{
			cout << "\n��� ����:";
			cin >> keySaveMap;
		} while (keySaveMap != 1 && keySaveMap != 0);
	} while (!keySaveMap);


	do
	{
		system("cls");
		cout << "\n\n>>>>>>>>>>>>>>>>>> "<<gamer1.GetName()<<" <<<<<<<<<<<<<<<<<<<";
		system("pause");
		do
		{
			cout << "\n��� ����\n";
			gamer1.ShowMyMap();
			cout << "\n���� ����������\n";
			gamer1.ShowEnemyMap();
			nick = false;
			do
			{
				do
				{
					cout << "\n������ ���������:";
					cin >> vertical;
					if (!AllowIndexes(vertical, 0))
						cout << "\n����������� ��������";
				} while (!AllowIndexes(vertical, 0));
				do
				{
					cout << "\n������ �����������:";
					cin >> horizontal;
					if (!AllowIndexes(0, horizontal))
						cout << "\n����������� ��������";
				} while (!AllowIndexes(0, horizontal));
			} while (!gamer1.IsPromiseCell(vertical, horizontal));
			if (gamer2.ShotMe(vertical, horizontal))
			{
				system("color A0");
				nick = true;
				gamer1.DeadEnemyMap(vertical, horizontal);
				cout << "\n����� ���������!!!"
					<< "\n��������� ��";
			}
			else
			{
				system("color C0");
				gamer1.MissEnemyMap(vertical, horizontal);
				cout << "\n������(";
			}
			system("pause");
			system("color F0");
			system("cls");
		} while (nick);
		system("cls");
		cout << "\n\n>>>>>>>>>>>>>>>>>> " << gamer2.GetName() << " <<<<<<<<<<<<<<<<<<<";
		system("pause");
		do
		{
			cout << "\n��� ����\n";
			gamer2.ShowMyMap();
			cout << "\n���� ����������\n";
			gamer2.ShowEnemyMap();
			nick = false;
			do
			{
				do
				{
					cout << "\n������ ���������:";
					cin >> vertical;
					if (!AllowIndexes(vertical, 0))
						cout << "\n����������� ��������";
				} while (!AllowIndexes(vertical, 0));
				do
				{
					cout << "\n������ �����������:";
					cin >> horizontal;
					if (!AllowIndexes(0, horizontal))
						cout << "\n����������� ��������";
				} while (!AllowIndexes(0, horizontal));
			} while (!gamer2.IsPromiseCell(vertical, horizontal));
			if (gamer1.ShotMe(vertical, horizontal))
			{
				system("color A0");
				nick = true;
				gamer2.DeadEnemyMap(vertical, horizontal);
				cout << "\n����� ���������!!!"
					<< "\n��������� ��";
			}
			else
			{
				system("color C0");
				gamer2.MissEnemyMap(vertical, horizontal);
				cout << "\n������(";
			}
			system("pause");
			system("color F0");
			system("cls");
		} while (nick);
		system("cls");
	} while (!gamer1.IsGameOver() && !gamer2.IsGameOver());
	if (gamer1.IsGameOver())
	{
		system("color A0");
		cout << "\n\n>>>>>>>>>>>>>>>>>> ������ 1 �����!!! <<<<<<<<<<<<<<<<<<<";
	}
	else
	{
		system("color C0");
		cout << "\n\n>>>>>>>>>>>>>>>>>>  ������ 2 �����!!! <<<<<<<<<<<<<<<<<<<";
	}
}

void BattleWithPC()
{
	Player gamer, pc;
	int vertical, horizontal;
	bool nick;
	bool keySaveMap;
	do
	{
		system("cls");
		cout << "\n>>>>>>>>>>>>>>>> ����� ������ ����� <<<<<<<<<<<<<<<<";
		gamer.SetShips();
		gamer.ShowMyMap();
		cout << "\n����������?(1-���, 0-ͳ)";
		do
		{
			cout << "\n��� ����:";
			cin >> keySaveMap;
		} while (keySaveMap != 1 && keySaveMap != 0);
	} while (!keySaveMap);
	system("cls");
	pc.SetShips();
	do
	{
		cout << "\n\n>>>>>>>>>>>>>>>>>> �� <<<<<<<<<<<<<<<<<<<";
		do
		{
			cout << "\n��� ����\n";
			gamer.ShowMyMap();
			cout << "\n���� ����������\n";
			gamer.ShowEnemyMap();
			nick = false;
			do
			{
				do
				{
					cout << "\n������ ���������:";
					cin >> vertical;
					if (!AllowIndexes(vertical, 0))
						cout << "\n����������� ��������";
				} while (!AllowIndexes(vertical, 0));
				do
				{
					cout << "\n������ �����������:";
					cin >> horizontal;
					if (!AllowIndexes(0, horizontal))
						cout << "\n����������� ��������";
				} while (!AllowIndexes(0, horizontal));
			} while (!gamer.IsPromiseCell(vertical, horizontal));
			if (pc.ShotMe(vertical, horizontal))
			{
				system("color A0");
				nick = true;
				gamer.DeadEnemyMap(vertical, horizontal);
				cout << "\n����� ���������!!!"
					<< "\n��������� ��";
			}
			else
			{
				system("color C0");
				gamer.MissEnemyMap(vertical, horizontal);
				cout << "\n������(";
			}
			system("pause");
			system("color F0");
			gamer.ShowMyMap();
			gamer.ShowEnemyMap();

		} while (nick);
		system("cls");
		cout << "\n\n>>>>>>>>>>>>>>>>>> PC <<<<<<<<<<<<<<<<<<<";
		do
		{
			nick = false;
			do
			{
				do
				{
					vertical = rand() % 10;
				} while (!AllowIndexes(vertical, 0));
				do
				{
					horizontal = rand() % 10;
				} while (!AllowIndexes(0, horizontal));
			} while (!pc.IsPromiseCell(vertical, horizontal));
			cout << "\n\n���������: " << vertical;
			cout << "\n�����������:" << horizontal;
			if (gamer.ShotMe(vertical, horizontal))
			{
				nick = true;
				pc.DeadEnemyMap(vertical, horizontal);
				cout << "\n����� ���������!!!";
			}
			else
			{
				pc.MissEnemyMap(vertical, horizontal);
				cout << "\n������(";
			}
		} while (nick);
		system("pause");
		system("cls");
	} while (!gamer.IsGameOver() && !pc.IsGameOver());
	if (pc.IsGameOver())
	{
		system("color A0");
		cout << "\n\n>>>>>>>>>>>>>>>>>> �� �������!!! <<<<<<<<<<<<<<<<<<<";
	}
	else
	{
		system("color C0");
		cout << "\n\n>>>>>>>>>>>>>>>>>> �� ��������!!! <<<<<<<<<<<<<<<<<<<";
	}
}

void main()
{
	system("color F0");
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int key;
	cout << "\n>>>>>>>>> ������� ���� <<<<<<<<<<<"
		<< "\n1 - ��� � ����'������"
		<< "\n2 - ��� �� ����"
		<< "\n3 - �����";
	do
	{
		cout << "\n��� ����:";
		cin >> key;
	} while (key < 1 || key>3);
	switch (key)
	{
	case 1:
		BattleWithPC();
		break;
	case 2:
		BattleWithGamer();
		break;
	case 3:
		break;
	}
	BattleWithGamer();
	system("pause");
}




