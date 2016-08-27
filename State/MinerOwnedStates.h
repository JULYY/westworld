#ifndef MINEROWNEDSTAATES_H
#define MINEROWNEDSTAATES_H

#include "State.h"

class Miner;


//�����ɻ���״̬�̳�
//ʹ��singleton����ģʽ
//�ڽ���״̬
class EnterMineAndDigForNugget :public State<Miner>
{
private:
	//���캯��
	EnterMineAndDigForNugget(){}

	//��������
	EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);

	EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);

public:
	static EnterMineAndDigForNugget* Instance();

	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);


};

//ȥ���д�Ǯ״̬
class VisitBankAndDepositGold :public State<Miner>
{
private:
	VisitBankAndDepositGold(){}

	VisitBankAndDepositGold(const VisitBankAndDepositGold&);
	VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);
public:
	static VisitBankAndDepositGold* Instance();

	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);
	
	virtual void Exit(Miner* pMiner);

};

class GoHomeAndSleepTilRested:public State<Miner>
{
private:
	GoHomeAndSleepTilRested(){}
	GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
	GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);

public:
	static GoHomeAndSleepTilRested* Instance();

	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);


};

class QuenchThirst :public State<Miner>
{
private:
	QuenchThirst(){}
	QuenchThirst(const QuenchThirst&);
	QuenchThirst& operator=(const QuenchThirst&);

public:
	static QuenchThirst* Instance();

	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);


};

#endif
