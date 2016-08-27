#ifndef STATE_H
#define STATE_H

template <typename entity_type>
class State
{
public:
	virtual ~State(){}

	//ÿһ��״̬�ֳ������֣����룻ִ�У��˳�

	//����
	virtual void Enter(entity_type*) = 0;

	//ִ��
	virtual void Execute(entity_type*) = 0;

	//�˳�
	virtual void Exit(entity_type*) = 0;

};
#endif // !STATE_H
