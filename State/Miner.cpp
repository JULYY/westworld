#include "stdafx.h"
#include "Miner.h"
#include "MinerOwnedStates.h"


Miner::Miner(int id) :BaseGameEntity(id),
						m_location(shack),
						m_iGoldCarried(0),
						m_iMoneyInBank(0),
						m_iThirst(0),
						m_iFatigue(0)
						
	{
	m_pStateMachine = new StateMachine<Miner>(this);
	m_pStateMachine->SetCurrentState(GoHomeAndSleepTilRested::Instance());
	//m_pStateMachine->SetGlobalState()
	}

//void Miner::ChangeState(State<Miner>* p_NewState)
//{
//	assert(m_pCurrentState&&p_NewState);
//
//	m_pCurrentState->Exit(this);
//	m_pCurrentState = p_NewState;
//	m_pCurrentState->Enter(this);
//}

void Miner::AddToGoldCarried(const int val)
{
	m_iGoldCarried += val;
	if (m_iGoldCarried<0)
	{
		m_iGoldCarried = 0;
	}
}

void Miner::AddToWealth(const int val)
{
	m_iMoneyInBank += val;
	if (m_iMoneyInBank < 0)
	{
		m_iMoneyInBank = 0;
	}

}

bool Miner::Thirsty()const
{
	if (m_iThirst>=ThirstLevel)
	{
		return true;
	}
	return false;
}

void Miner::Update()
{
	m_iThirst += 1;
	m_pStateMachine->CurrentState()->Execute(this);
}

bool Miner::Fatigued()const
{
	if (m_iThirst>TirednessThreshord)
	{
		return true;
	}
	return false;
}