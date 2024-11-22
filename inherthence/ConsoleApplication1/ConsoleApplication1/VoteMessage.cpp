/*#include "VoteMessage.h"
#include <iostream>

VoteMessage::VoteMessage(int senderId, std::string title, const std::string options[], int count, int senderDate): BaseMessage(senderId, senderDate),voteTitle(title),optionCount(count) {
    for (int i = 0; i < optionCount && i < MAX_OPTIONS; ++i) {
        voteOptions[i] = options[i];
    }
}

void VoteMessage::display() {
    std::cout << "Vote from User " << GetSenderID() << " on ";
    PrintDate();
    std::cout << ": " << voteTitle << std::endl;
    for (int i = 0; i < optionCount; ++i) {
        std::cout << i + 1 << ". " << voteOptions[i] << std::endl;
    }
}
*/