// State.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "Locations.h"
#include "Miner.h"
#include "ConsoleUtils.h"
#include "EntityNames.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Miner miner(ent_Miner_Bob);

	for (int i = 0; i < 20;i++)
	{
		miner.Update();

		Sleep(800);
	}

	PressAnyKeyToContinue();

	return 0;
}

