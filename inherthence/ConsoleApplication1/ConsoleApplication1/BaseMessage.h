#pragma once
class BaseMessage {
private:
	int SenderID;
	int SenderDate;
protected:
	void PrintDate()const;

public:
	BaseMessage(int,int);
	virtual ~BaseMessage() = default;
	virtual void print()const;
	/*int GetSenderID()const;
	void SetSenderID(int);
	*/
};