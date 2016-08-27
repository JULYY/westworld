#ifndef STATE_H
#define STATE_H

template <typename entity_type>
class State
{
public:
	virtual ~State(){}

	//每一个状态分成三部分：进入；执行；退出

	//进入
	virtual void Enter(entity_type*) = 0;

	//执行
	virtual void Execute(entity_type*) = 0;

	//退出
	virtual void Exit(entity_type*) = 0;

};
#endif // !STATE_H
