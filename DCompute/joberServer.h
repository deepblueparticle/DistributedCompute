/// \file jobServer.h Copyright (C).
/// \brief brief-description
///
///
/// \note:
/// \author: DI
/// \time: 2012/8/20 17:34
#pragma once

#ifndef _DCOMPUTE_JOBSERVER_H_
#define _DCOMPUTE_JOBSERVER_H_

#include <vector>

#include <cex/DeltaReflection.h>
#include <DCompute/config>
#include <DCompute/util.h>

namespace DCompute 
{
	class IReplyServer : public cex::Interface
	{
	public:

		virtual void create()=0;

		virtual void destory()=0;
	};

	class IJoberServer : public cex::Interface
	{
	public:
		virtual void create()=0;

		virtual bool start()=0;

		virtual bool stop()=0;
	};

	namespace Contract
	{
		class WorkerInfo;
	}

	class CRouterBase : public CThreadProxy
	{
	public:
		CRouterBase() : _context(0), _frontend(0), _backend(0) {}

		virtual ~CRouterBase() {}

		virtual void create()=0;

		virtual void destory()=0;

	protected:
		virtual unsigned int run()=0;

	protected:
		void* _context;
		void* _frontend;
		void* _backend;

	};

	class CWokerCounter
	{
	public:
		~CWokerCounter(){}

		std::vector<std::string> workers;

	private:
		CWokerCounter() {}

		static CWokerCounter* Instance();

		friend class Contract::WorkerInfo;
	};

}

#endif