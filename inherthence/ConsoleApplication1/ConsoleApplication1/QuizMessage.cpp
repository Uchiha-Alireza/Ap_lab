#include "QuizMessage.h"
#include <iostream>
#include <cstring>
#include <string>
#pragma warning (disable:4996)

QuizMessage::QuizMessage(int id, int date, const std::string& question, const char* options[], int count) :BaseMessage(id, date), question(question), optionCount(count) {
	this->options = new char* [optionCount];
	for (int i = 0 ; i < optionCount; i++) {
		this->options[i] = new char[std::strlen(options[i]) + 1];
		std::strcpy(this->options[i], options[i]);
	}
}
QuizMessage::~QuizMessage() {
	for (int i = 0; i < optionCount; i++) {
		delete[] options[i];
	}
	delete[] options;
}
void QuizMessage::print() const{
	BaseMessage::print();
	std::cout << "Quize Question:" << question << std::endl;
	for (int i = 0; i < optionCount; i++) {
		std::cout << "Option " << i + 1 << ": " << options[i] << std::endl;
	}
}