#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include "hiredis/hiredis.h"
#include <assert.h>

int doTest()
{
	int i = 0;
	int timeout = 10000;
	struct timeval tv;
	tv.tv_sec = timeout / 1000;
	tv.tv_usec = timeout * 1000;

	redisContext* c = redisConnect("127.0.0.1", 6379);
	if(c->err)
	{
		printf("Failed to connect.\n");
		redisFree(c);
		return 1;
	}
	
	const char* command1 = "set stest1 value1";
	redisReply* r = (redisReply*)redisCommand(c, command1);
	if(NULL == r)
	{
		redisFree(c);
		return 1;
	}

	if(!(r->type == REDIS_REPLY_STATUS && strcasecmp(r->str, "OK") == 0))
	{
		printf("Failed to execute command[%s].\n", command1);
		freeReplyObject(r);
		redisFree(c);
		return 1;
	}

	freeReplyObject(r);
	printf("Success to execute command[%s].\n", command1);

	const char* command2 = "strlen stest1";
	r = (redisReply*)redisCommand(c, command2);
	if(r->type != REDIS_REPLY_INTEGER)
	{
		printf("Failed to execute command[%s].\n", command2);
		freeReplyObject(r);
		redisFree(c);
		return 1;
	}
	int length = r->integer;
	freeReplyObject(r);
	printf("The length of 'stest1' is %d.\n", length);
	printf("Success to execute command[%s].\n", command2);

	const char* command3 = "get stest1";
	r = (redisReply*)redisCommand(c, command3);
	if(r->type != REDIS_REPLY_STRING)
	{
		printf("Failed to execute command[%s].\n", command3);
		freeReplyObject(r);
		redisFree(c);
		return 1;
	}
	printf("The value of 'stest1' is %s.\n", r->str);
	freeReplyObject(r);
	printf("Success to execute command[%s].\n", command3);

	const char* command4 = "get stest2";
	r = (redisReply*)redisCommand(c, command4);
	if(r->type != REDIS_REPLY_NIL)
	{
		printf("Failed to execute command[%s].\n", command4);
		freeReplyObject(r);
		redisFree(c);
		return 1;
	}
	freeReplyObject(r);
	printf("Success to execute command[%s].\n", command4);

	const char* command5 = "mget stest1 stest2";
	r = (redisReply*)redisCommand(c, command5);
	if(r->type != REDIS_REPLY_ARRAY)
	{
		printf("Failed to execute command[%s].\n", command5);
		freeReplyObject(r);
		redisFree(c);
		assert(2 == r->elements);
		return 1;
	}
	for(i = 0; i < r->elements; i++)
	{
		redisReply* childReply = r->element[i];
		if(childReply->type == REDIS_REPLY_STRING)
		{
			printf("The value is %s.\n", childReply->str);
		}
	}
	freeReplyObject(r);
	printf("Success to execute command[%s].\n", command5);
	if (REDIS_OK != redisAppendCommand(c,command2))
	{
        redisFree(c);
        return;
    }
    redisReply* reply = NULL;
	     //对pipeline返回结果的处理方式，和前面代码的处理方式完全一直，这里就不再重复给出了。
    if (REDIS_OK != redisGetReply(c,(void**)&reply)) {
	    printf("Failed to execute command[%s] with Pipeline.\n",command2);
	    freeReplyObject(reply);
	    redisFree(c);
	}
	if(reply->type != REDIS_REPLY_INTEGER)
	{
	    freeReplyObject(reply);
		return 1;
	}
	freeReplyObject(reply);
	printf("The length of 'stest1' is %d.\n", reply->integer);
	printf("Succeed to execute command[%s] with Pipeline.\n",command2);
}

int main(int argv, char **argc)
{
	doTest();
	return 0;
}
