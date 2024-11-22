#pragma once
#include "BaseMessage.h"
#include <string>

class QuizMessage : public BaseMessage {
private:
    std::string question;
    char** options;
    int optionCount;
public:
    QuizMessage(int id, int date, const std::string& question, const char* options[], int count);
    void print()const override;
    ~QuizMessage();
};