//// mysql.cpp : 定义控制台应用程序的入口点。
////
//
#include "stdafx.h"

int main() {
	return 0;
}

//
//#include "Poco/Exception.h"
//#include "Poco/Data/Session.h"
//#include "Poco/Data/Common.h"
//#include "Poco/Data/BLOB.h"
//#include "Poco/Data/StatementImpl.h"
//#include "Poco/Data/SessionPool.h"
//#include "Poco/Data/PooledSessionImpl.h"
//#include "Poco/Data/MySQL/Connector.h"
//#include "Poco/Data/MySQL/MySQLException.h"
//#include "Poco/Data/SQLite/Connector.h"
//#include "Poco/Data/SQLite/SQLiteException.h"
//#include "Poco/Data/ODBC/Connector.h"
//#include "Poco/Data/ODBC/ODBCException.h"
//#include <iostream>
//#include "Poco/Data/Common.h"
//#include "Poco/Data/SessionPool.h"
//#include "Poco/Thread.h"
//
//int main()
//{
//	try
//	{
//		Poco::Data::MySQL::Connector::registerConnector();
//		Poco::Data::SessionPool pool("MySQL", "user=root;password=;db=calserver;compress=true;auto-reconnect=true", 1, 4, 5);
//
//		Poco::Data::Session sess(pool.get());
//		if (sess.isConnected())
//		{
//			int count = 0;
//
//			sess << "SELECT COUNT(*) FROM termstate", Poco::Data::into(count), Poco::Data::now;
//			std::cout << "the sum is : " << count << "recorder" << std::endl;
//
//		}
//		else
//		{
//			std::cout << "*** Connected to DB"
//				<< "failed" << std::endl;
//		}
//
//		Poco::Data::MySQL::Connector::unregisterConnector();
//	}
//	catch (Poco::Exception &ex)
//	{
//		std::cerr << ex.displayText() << std::endl;
//	}
//	return 0;
//}
//
//
