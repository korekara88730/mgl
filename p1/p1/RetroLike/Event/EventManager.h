
#include <iostream>


#define  NAME_OF(AnyName)	(#AnyName)

class EventReceiver {

public:


};


class EventDispatcher {
public:


};

/*
用于记录 哪些事件有哪些监听者
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

