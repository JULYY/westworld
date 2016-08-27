#ifndef MINEROWNEDSTAATES_H
#define MINEROWNEDSTAATES_H

#include "State.h"

class Miner;


//都是由基类状态继承
//使用singleton单例模式
//挖金子状态
class EnterMineAndDigForNugget :public State<Miner>
{
private:
	//构造函数
	EnterMineAndDigForNugget(){}

	//拷贝函数
	EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);

	EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);

public:
	static EnterMineAndDigForNugget* Instance();

	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);


};

//去银行存钱状态
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
