#include <vector>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "EventLoop.h"
#include "ThreadPool.h"
#include "Thread.h"
#include "CurrentThread.h"
#include "AsyncLogging.h"
#include "Logging.h"
#include "Acceptor.h"
#include "InetAddress.h"
#include "SocketsOps.h"
#include "TcpClient.h"

using namespace muduo::net;

int main()
{
	muduo::Logger::setLogLevel(muduo::Logger::TRACE);
	LOG_TRACE << "客户端 主线程 pid:" << getpid() << " tid:" << muduo::CurrentThread::tid();
	InetAddress serverAddr("127.0.0.1", 30120);
	EventLoop mainloop;
	TcpClient client(&mainloop, serverAddr, "测试客户端");
	auto cb = [](const TcpConnectionPtr& conn)
	{
		LOG_TRACE << "消息发送成功!";
	};
	client.setWriteCompleteCallback(cb);
	client.connect();
	auto timecb = [&client]() {
		std::string tmp;
		std::cin >> tmp;
		client.connection()->send(tmp.data(), tmp.size());
	};
	mainloop.runEvery(5, timecb);

	mainloop.loop();
    return 0;
}
