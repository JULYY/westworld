#ifndef MINER_H
#define MINER_H

#include <string>
#include <cassert>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "State.h"

//
const int ConfortLevel = 5;

//����ڽ���
const int MaxNuggets = 3;

//��󼢿�ֵ
const int ThirstLevel = 5;

//���ƣ��ֵ
const int TirednessThreshord = 5;


class Miner :public BaseGameEntity
{
public:

	Miner(int id);

	//ִ��״̬��Ǩ��
	void Update();

	//�˳���ǰ״̬Exit()�������״̬�Ϸ��ԣ�ִ�н���״̬����Enter()
	void ChangeState(State<Miner>* new_state);

	location_type Location()const { return m_location; }
	void ChangeLocation(const location_type loc) { m_location = loc; }

	int GoldCarried()const{ return m_iGoldCarried; }
	void SetGoldCarried(const int val){ m_iGoldCarried = val; }
	void AddToGoldCarried(const int val);
	bool PocketsFull()const{ return m_iGoldCarried >= MaxNuggets; }

	int Wealth()const{ return m_iGoldCarried; }
	void SetWealth(const int val){ m_iMoneyInBank = val; }
	void AddToWealth(const int val);

	bool Fatigued()const;
	void DecreaseFatigue(){ m_iFatigue -= 1; }
	void IncreaseFatugue(){ m_iFatigue += 1; }

	bool Thirsty()const;
	void BuyAndDrinkAWhiskey(){ m_iThirst = 0; m_iMoneyInBank -= 2; }

private:
	//��ǰ״̬
	State<Miner>* m_pCurrentState;

	//��ǰλ��
	location_type m_location;
	
		int m_iGoldCarried;
		int m_iMoneyInBank;
		int m_iThirst;
		int m_iFatigue;;

};
#endif
