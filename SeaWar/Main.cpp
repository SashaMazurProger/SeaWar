#include "Header.h"
#include "Player.cpp"


void BattleWithGamer()
{
	Player gamer1, gamer2;
	int vertical, horizontal;
	bool nick;
	bool keySaveMap;
	string nameGamer;
	cout << "\n>>>>>>>>>>>>>>>> ПЕРШИЙ ІГРОК <<<<<<<<<<<<<<<<";
	do
	{
		cout << "\nВаше імя:";
		cin >> nameGamer;
	} while (nameGamer=="");
	gamer1.SetName(nameGamer);
	do
	{
		system("cls");
		cout << "\n>>>>>>>>>>>>>>>> КАРТА ФЛОТУ("<<gamer1.GetName()<<") <<<<<<<<<<<<<<<<";
		gamer1.SetShips();
		gamer1.ShowMyMap();
		cout << "\nПродовжити?(1-Так, 0-Ні)";
		do
		{
			cout << "\nВаш вибір:";
			cin >> keySaveMap;
		} while (keySaveMap != 1 && keySaveMap != 0);
	} while (!keySaveMap);
	system("cls");
	cout << "\n>>>>>>>>>>>>>>>> ДРУГИЙ ІГРОК <<<<<<<<<<<<<<<<";
	do
	{
		cout << "\nВаше імя:";
		cin >> nameGamer;
	} while (nameGamer == "");
	gamer2.SetName(nameGamer);
	do
	{
		system("cls");
		cout << "\n>>>>>>>>>>>>>>>> КАРТА ФЛОТУ(" << gamer2.GetName() << ") <<<<<<<<<<<<<<<<";
		gamer2.SetShips();
		gamer2.ShowMyMap();
		cout << "\nПродовжити?(1-Так, 0-Ні)";
		do
		{
			cout << "\nВаш вибір:";
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
			cout << "\nВАШ ФЛОТ\n";
			gamer1.ShowMyMap();
			cout << "\nФЛОТ ПРОТИВНИКА\n";
			gamer1.ShowEnemyMap();
			nick = false;
			do
			{
				do
				{
					cout << "\nВкажіть вертикаль:";
					cin >> vertical;
					if (!AllowIndexes(vertical, 0))
						cout << "\nНедопустиме значення";
				} while (!AllowIndexes(vertical, 0));
				do
				{
					cout << "\nВкажіть горизонталь:";
					cin >> horizontal;
					if (!AllowIndexes(0, horizontal))
						cout << "\nНедопустиме значення";
				} while (!AllowIndexes(0, horizontal));
			} while (!gamer1.IsPromiseCell(vertical, horizontal));
			if (gamer2.ShotMe(vertical, horizontal))
			{
				system("color A0");
				nick = true;
				gamer1.DeadEnemyMap(vertical, horizontal);
				cout << "\nПряме попадання!!!"
					<< "\nСпробуйте ще";
			}
			else
			{
				system("color C0");
				gamer1.MissEnemyMap(vertical, horizontal);
				cout << "\nПромах(";
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
			cout << "\nВАШ ФЛОТ\n";
			gamer2.ShowMyMap();
			cout << "\nФЛОТ ПРОТИВНИКА\n";
			gamer2.ShowEnemyMap();
			nick = false;
			do
			{
				do
				{
					cout << "\nВкажіть вертикаль:";
					cin >> vertical;
					if (!AllowIndexes(vertical, 0))
						cout << "\nНедопустиме значення";
				} while (!AllowIndexes(vertical, 0));
				do
				{
					cout << "\nВкажіть горизонталь:";
					cin >> horizontal;
					if (!AllowIndexes(0, horizontal))
						cout << "\nНедопустиме значення";
				} while (!AllowIndexes(0, horizontal));
			} while (!gamer2.IsPromiseCell(vertical, horizontal));
			if (gamer1.ShotMe(vertical, horizontal))
			{
				system("color A0");
				nick = true;
				gamer2.DeadEnemyMap(vertical, horizontal);
				cout << "\nПряме попадання!!!"
					<< "\nСпробуйте ще";
			}
			else
			{
				system("color C0");
				gamer2.MissEnemyMap(vertical, horizontal);
				cout << "\nПромах(";
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
		cout << "\n\n>>>>>>>>>>>>>>>>>> ВИГРАВ 1 ІГРОК!!! <<<<<<<<<<<<<<<<<<<";
	}
	else
	{
		system("color C0");
		cout << "\n\n>>>>>>>>>>>>>>>>>>  ВИГРАВ 2 ІГРОК!!! <<<<<<<<<<<<<<<<<<<";
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
		cout << "\n>>>>>>>>>>>>>>>> КАРТА ВАШОГО ФЛОТУ <<<<<<<<<<<<<<<<";
		gamer.SetShips();
		gamer.ShowMyMap();
		cout << "\nПродовжити?(1-Так, 0-Ні)";
		do
		{
			cout << "\nВаш вибір:";
			cin >> keySaveMap;
		} while (keySaveMap != 1 && keySaveMap != 0);
	} while (!keySaveMap);
	system("cls");
	pc.SetShips();
	do
	{
		cout << "\n\n>>>>>>>>>>>>>>>>>> ВИ <<<<<<<<<<<<<<<<<<<";
		do
		{
			cout << "\nВАШ ФЛОТ\n";
			gamer.ShowMyMap();
			cout << "\nФЛОТ ПРОТИВНИКА\n";
			gamer.ShowEnemyMap();
			nick = false;
			do
			{
				do
				{
					cout << "\nВкажіть вертикаль:";
					cin >> vertical;
					if (!AllowIndexes(vertical, 0))
						cout << "\nНедопустиме значення";
				} while (!AllowIndexes(vertical, 0));
				do
				{
					cout << "\nВкажіть горизонталь:";
					cin >> horizontal;
					if (!AllowIndexes(0, horizontal))
						cout << "\nНедопустиме значення";
				} while (!AllowIndexes(0, horizontal));
			} while (!gamer.IsPromiseCell(vertical, horizontal));
			if (pc.ShotMe(vertical, horizontal))
			{
				system("color A0");
				nick = true;
				gamer.DeadEnemyMap(vertical, horizontal);
				cout << "\nПряме попадання!!!"
					<< "\nСпробуйте ще";
			}
			else
			{
				system("color C0");
				gamer.MissEnemyMap(vertical, horizontal);
				cout << "\nПромах(";
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
			cout << "\n\nВертикаль: " << vertical;
			cout << "\nГоризонталь:" << horizontal;
			if (gamer.ShotMe(vertical, horizontal))
			{
				nick = true;
				pc.DeadEnemyMap(vertical, horizontal);
				cout << "\nПряме попадання!!!";
			}
			else
			{
				pc.MissEnemyMap(vertical, horizontal);
				cout << "\nПромах(";
			}
		} while (nick);
		system("pause");
		system("cls");
	} while (!gamer.IsGameOver() && !pc.IsGameOver());
	if (pc.IsGameOver())
	{
		system("color A0");
		cout << "\n\n>>>>>>>>>>>>>>>>>> ВИ ВИГРАЛИ!!! <<<<<<<<<<<<<<<<<<<";
	}
	else
	{
		system("color C0");
		cout << "\n\n>>>>>>>>>>>>>>>>>> ВИ ПРОГРАЛИ!!! <<<<<<<<<<<<<<<<<<<";
	}
}

void main()
{
	system("color F0");
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int key;
	cout << "\n>>>>>>>>> Головне меню <<<<<<<<<<<"
		<< "\n1 - Гра з комп'ютером"
		<< "\n2 - Гра на двох"
		<< "\n3 - Вихід";
	do
	{
		cout << "\nВаш вибір:";
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




