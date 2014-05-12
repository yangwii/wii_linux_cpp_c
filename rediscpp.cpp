#include <iostream>
#include "hiredis/hiredis.h"
using namespace std;

int main()
{
	redisContext *c = redisConnect("127.0.0.1", 6379);
	redisReply *reply;
	reply = (redisReply*)redisCommand(c, "get name");
	cout<<reply->str<<endl;
	freeReplyObject(reply);
	return 0;
}
