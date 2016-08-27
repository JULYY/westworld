#include "stdafx.h"
#include "MinerOwnedStates.h"
#include "State.h"
#include "Miner.h"
#include "ConsoleUtils.h"
#include "EntityNames.h"
#include <iostream>
using namespace std;


//-----------methods for EnterMinerAndDigForNugget
EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "Walking to the goldmine";
	pMiner->ChangeLocation(goldmine);

}

void EnterMineAndDigForNugget::Execute(Miner* pMiner)
{
	pMiner->AddToGoldCarried(1);
	pMiner->IncreaseFatugue();

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "Picking up a nugget";
	if (pMiner->PocketsFull())
	{
		pMiner->ChangeState(VisitBankAndDepositGold::Instance());
	}
	if (pMiner->Thirsty())
	{
		pMiner->ChangeState(QuenchThirst::Instance());
	}
}


void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "I'm leaving the goldmine with pockets full of sweet gold";
}

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* pMiner)
{
	if (pMiner->Location()!=bank)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "Going to the bank.Yes sir";
		pMiner->ChangeLocation(bank);
	}
}

void VisitBankAndDepositGold::Execute(Miner* pMiner)
{
	pMiner->AddToWealth(pMiner->GoldCarried());
	pMiner->SetGoldCarried(0);
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "Depositing gold. total saving now:" << pMiner->Wealth();

	if (pMiner->Wealth()>ConfortLevel)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "WooHoo! Rich enough for now.Back home!";
		pMiner->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else
	{
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}

}

void VisitBankAndDepositGold::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "Leaving the bank";
}

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner)
{
	if (pMiner->Location() != shack)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "Walking home!";
		pMiner->ChangeLocation(shack);
	}
}

void GoHomeAndSleepTilRested::Execute(Miner* pMiner)
{
	
	

	if (!pMiner->Fatigued())
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "what a God darn fantastic nap! Time to find more gold!";
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		pMiner->DecreaseFatigue();
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "zzz....!";
	}

}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "Leaving the house!";
}

QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Miner* pMiner)
{
	if (pMiner->Location()!=saloon)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "thirst,go to the saloon ";
		pMiner->ChangeLocation(saloon);
	}
}

void QuenchThirst::Execute(Miner* pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkAWhiskey();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "That's might fine sipping liquer ";
		pMiner->ChangeLocation(saloon);
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "ERROR ";
	}
}

void QuenchThirst::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "Leaving the saloon,feeling good! ";
}