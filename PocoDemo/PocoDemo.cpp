// ConsolePocoDemo.cpp : 定义控制台应用程序的入口点。
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
//在 C / C++ | General | Additional Include Directories 设置里面增加：
//$(POCO_ROOT)\include
//----------------------------------------------------------------------------
//在 Linker | General | Additional Library Directories 设置里面增加：
//$(POCO_ROOT)\build\$(Platform)\$(Configuration)\
//----------------------------------------------------------------------------
//在 Linker | Input | Additional Dependencies 设置里面，针对 Debug configuration，增加：
//PocoEncodingsd.lib
//PocoFoundationd.lib
//PocoJSONd.lib
//PocoNetd.lib
//PocoUtild.lib
//PocoXMLd.lib
//针对 Release configuration，增加：
//PocoEncodings.lib
//PocoFoundation.lib
//PocoJSON.lib
//PocoNet.lib
//PocoUtil.lib
//PocoXML.lib
//----------------------------------------------------------------------------
//在 Post - Build Event 设置里面增加拷贝 DLL 文件到目标文件夹的命令
//copy "$(POCO_ROOT)\build\$(Platform)\bin\$(Configuration)\*.*" $(TargetDir)


//POCO c++ 使用例子:定时器
class TimerExample
{
public:
	void onTimer(Poco::Timer &timer)
	{
		cout << "func:" << __FUNCTION__ << endl;
	}
};

//poco 默认线程池
class HelloRunnable : public Poco::Runnable
{
	virtual void run()
	{
		cout << "Hello,bingzhe" << std::endl;
	}
};

int main(int argc, char** argv)
{
	//1.定时器
	//TimerExample te;
	//Timer timer(100, 1000);// fire after 2000ms, repeat every 1000ms  
	//timer.start(TimerCallback<TimerExample>(te, &TimerExample::onTimer));
	//Thread::sleep(10000);
	//timer.stop();

	//2.默认线程池
	HelloRunnable runnable;
	Poco::ThreadPool::defaultPool().start(runnable);
	Poco::ThreadPool::defaultPool().joinAll();

	//3.test----------------------------------------
	//test
	getchar();
	return 0;
}



