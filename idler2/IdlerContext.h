#ifndef IDLERCONTEXT_H
#define IDLERCONTEXT_H

#include "Common.h"

class IdlerContext
{
public:
	IdlerContext(ISteamClient008 *steam_client) : client(steam_client), pipe(0), user(0), running(false) {}; 
	virtual bool Begin() = 0;
	virtual void End() = 0;
	virtual void Think() = 0;
	virtual void HandleCallback(const CallbackMsg_t &callback) = 0;

	virtual bool IsRunning() { return running; };
	virtual HSteamPipe GetPipe() { return pipe; };

protected:
	ISteamClient008 *client;

	HSteamPipe pipe;
	HSteamUser user;

	bool running;
};


#endif //IDLERCONTEXT_H
