#include "BaseMessage.h"
#include <iostream>

BaseMessage::BaseMessage(int _SenderId,int _SenderDate):SenderID(_SenderId),SenderDate(_SenderDate){}
/*int BaseMessage::GetSenderID()const {
	return SenderID;
}
*/
/*void BaseMessage::SetSenderID(int _SenderID) {
	SenderID = _SenderID;
}
*/
void BaseMessage::PrintDate() const {
    int day = SenderDate % 100;
    int month = (SenderDate / 100) % 100;
    int year = SenderDate / 10000;
    std::cout << year << "/" << month << "/" << day;
}
void BaseMessage::print() const{
    std::cout <<"Sender ID :" << SenderID<<std::endl;
    PrintDate();
}
