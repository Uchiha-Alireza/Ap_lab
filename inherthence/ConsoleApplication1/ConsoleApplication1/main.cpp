#include "SimpleMessage.h"
#include "QuizMessage.h"
#include "PostMessage.h" 
#include <iostream>
int main() {
	int mcount = 3;
	BaseMessage** all = new BaseMessage*[mcount];
	all[0] = new SimpleMessage(65656886, 52, "Simple Message!");
	all[1] = new PostMessage(556565656, 989, "Post Message!","ddsjkjkskkdsk");
	const char* quizOptions[] = { "1","2","3","4" };
	all[2] = new QuizMessage(10135,103,"hjhjkjkkjk",quizOptions,3);
	std::cout << "all messages:"<<std::endl;
	for (int i = 0; i < mcount; i++) {
		all[i]->print();
		std::cout << "§***********\n";
	}
	for (int i = 0; i < mcount; i++) {
		delete all[i];
	}
	delete[] all;
	return 0;
}