/* 
	Copyright 2010 OpenRTMFP
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License received along this program for more
	details (or else see http://www.gnu.org/licenses/).

	This file is a part of Cumulus.
*/

#pragma once

#include "Cumulus.h"
#include "SendingUnit.h"
#include "Poco/Thread.h"
#include "Poco/AutoPtr.h"
#include "Poco/Event.h"
#include <list>

namespace Cumulus {

class SendingThread : private Poco::Runnable {
public:
	SendingThread(Poco::UInt32 id);
	~SendingThread();

	void			clear();
	void			push(Poco::AutoPtr<SendingUnit>& sending);
	Poco::UInt32	size();

private:
	void			run();

	Poco::FastMutex							_mutex;
	Poco::Event								_pushEvent;
	std::list<Poco::AutoPtr<SendingUnit> >	_sendings;
	bool									_haveToJoin;
	bool									_join;
	Poco::Thread							_thread;
};


} // namespace Cumulus
