
#include <iostream>


#define  NAME_OF(AnyName)	(#AnyName)

class EventReceiver {

public:


};


class EventDispatcher {
public:


};

/*
���ڼ�¼ ��Щ�¼�����Щ������
*/
class EventManager {

private:


};

template<class EvtClsName>
class BaseEvent {
public:
	virtual std::string getEventName() { return NAME_OF(EvtClsName); }
};


struct EvtTest : public BaseEvent<EvtTest> {
	EvtTest(int _num, std::string _str) :num(_num), str(_str) {}
	int num;
	std::string str;
	


};

