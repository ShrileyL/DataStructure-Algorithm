//
//  when to use virtual function
//
//  Created by KevinLiu on 17/1/6.
//  Copyright © 2017年 KevinLiu. All rights reserved.
//

// thispointer.com


#include <iostream>

class MessageCoverter
{
public:
	std::string convert(std::string msg)
	{
		msg = "[START]" + msg + "[END]";
		return msg;
	}
};

class MessageSender
{
	MessageCoverter * mMsgCoverterPtr;
public:
	MessageSender() :mMsgCoverterPtr(NULL){}
	void sendMessage(std::string msg)
	{
		if(mMsgCoverterPtr)
			msg = mMsgCoverterPtr->convert(msg);
		std::cout<<"Message Sent :: "<<msg<<std::endl;
	}
	void setMsgCoverterPtr(MessageCoverter * msgCoverterPtr) {
		mMsgCoverterPtr = msgCoverterPtr;
	}
};


int main(int argc, char const *argv[])
{
	MessageSender msgSenderObj;

	MessageCoverter * msgConverterPtr = new MessageCoverter();
	msgSenderObj.setMsgCoverterPtr(msgConverterPtr);

	msgSenderObj.sendMessage("Hello World");
	delete msgConverterPtr;
	return 0;
}