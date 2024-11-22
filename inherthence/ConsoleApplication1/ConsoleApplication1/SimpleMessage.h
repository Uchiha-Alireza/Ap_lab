#pragma once
#include "BaseMessage.h"
#include <string>
class SimpleMessage:public BaseMessage{
private:
	std::string Message;
public:
	SimpleMessage(int,int,const std::string);
	void print()const override;

};