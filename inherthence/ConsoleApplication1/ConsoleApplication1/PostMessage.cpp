#include "PostMessage.h"
#include <iostream>

PostMessage::PostMessage(int _SenderID, int _SenderDate, const std::string& _content, const std::string _URL):BaseMessage(_SenderID,_SenderDate),content(_content),URL(_URL){}
void PostMessage::print()const {
    BaseMessage::print();
    std::cout << "Post content:"<<content<<std::endl;
    std::cout << "Image URL:" << URL << std::endl;

}
