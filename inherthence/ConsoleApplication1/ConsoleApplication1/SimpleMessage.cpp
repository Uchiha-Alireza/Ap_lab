#include "SimpleMessage.h"
#include "BaseMessage.h" 
#include <iostream>
SimpleMessage::SimpleMessage(int _SenderID,int _SenderDate,const std::string _message): BaseMessage(_SenderID, _SenderDate),Message(_message) {}

void SimpleMessage::print() const{
    BaseMessage::print();
    std::cout << "Message: " << Message << std::endl;
}
