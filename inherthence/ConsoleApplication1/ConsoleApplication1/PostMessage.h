#pragma once
#include "BaseMessage.h"
#include <string>

class PostMessage : public BaseMessage {
private:
    std::string content;
    std::string URL;

public:
    PostMessage(int _SenderID, int _SenderDate,const std::string& _content,const std::string _URL);


    void print()const override;
};
