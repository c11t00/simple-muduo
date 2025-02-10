#include <vector>
#include <string.h>
#include <unistd.h>

#include "TestServer.h"
#include "EventLoop.h"
#include "ThreadPool.h"
#include "Thread.h"
#include "CurrentThread.h"
#include "AsyncLogging.h"
#include "Logging.h"
#include "Acceptor.h"
#include "InetAddress.h"
#include "SocketsOps.h"
#include "Timestamp.h"
#include "TcpServer.h"

using namespace muduo::net;

int main()
{
	muduo::Logger::setLogLevel(muduo::Logger::TRACE);
	daemon(1, 1);
	LOG_TRACE << "服务器 主线程 pid:" << getpid() << " tid:" << muduo::CurrentThread::tid();
	InetAddress listenAddr("127.0.0.1", 30120);
	EventLoop mainloop;
	TcpServer server(&mainloop, listenAddr, "测试服务器", TcpServer::kReusePort);
	server.setThreadNum(2);
	auto cb = [](const TcpConnectionPtr& conn, Buffer* buffer, muduo::Timestamp times)
	{
		LOG_TRACE << "收到来自 " << conn->getTcpInfoString() << "的消息 " << buffer->retrieveAllAsString();
	};
	server.setMessageCallback(cb);
	server.start();
	mainloop.loop();
    return 0;
}
