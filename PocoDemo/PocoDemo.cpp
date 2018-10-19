// ConsolePocoDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

#include "Poco\Timer.h"
#include "Poco\Thread.h"

#include "Poco/ThreadPool.h"
#include "Poco/Runnable.h"

using Poco::Timer;
using Poco::Thread;
using Poco::TimerCallback;
using namespace std;

//----------------------------------------------------------------------------
//Include
//�� C / C++ | General | Additional Include Directories �����������ӣ�
//$(POCO_ROOT)\include
//----------------------------------------------------------------------------
//�� Linker | General | Additional Library Directories �����������ӣ�
//$(POCO_ROOT)\build\$(Platform)\$(Configuration)\
//----------------------------------------------------------------------------
//�� Linker | Input | Additional Dependencies �������棬��� Debug configuration�����ӣ�
//PocoEncodingsd.lib
//PocoFoundationd.lib
//PocoJSONd.lib
//PocoNetd.lib
//PocoUtild.lib
//PocoXMLd.lib
//��� Release configuration�����ӣ�
//PocoEncodings.lib
//PocoFoundation.lib
//PocoJSON.lib
//PocoNet.lib
//PocoUtil.lib
//PocoXML.lib
//----------------------------------------------------------------------------
//�� Post - Build Event �����������ӿ��� DLL �ļ���Ŀ���ļ��е�����
//copy "$(POCO_ROOT)\build\$(Platform)\bin\$(Configuration)\*.*" $(TargetDir)


//POCO c++ ʹ������:��ʱ��
class TimerExample
{
public:
	void onTimer(Poco::Timer &timer)
	{
		cout << "func:" << __FUNCTION__ << endl;
	}
};

//poco Ĭ���̳߳�
class HelloRunnable : public Poco::Runnable
{
	virtual void run()
	{
		cout << "Hello,bingzhe" << std::endl;
	}
};

int main(int argc, char** argv)
{
	//1.��ʱ��
	//TimerExample te;
	//Timer timer(100, 1000);// fire after 2000ms, repeat every 1000ms  
	//timer.start(TimerCallback<TimerExample>(te, &TimerExample::onTimer));
	//Thread::sleep(10000);
	//timer.stop();

	//2.Ĭ���̳߳�
	HelloRunnable runnable;
	Poco::ThreadPool::defaultPool().start(runnable);
	Poco::ThreadPool::defaultPool().joinAll();

	//3.test----------------------------------------
	//test
	getchar();
	return 0;
}



