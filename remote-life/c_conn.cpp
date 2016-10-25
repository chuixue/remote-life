
#include "c_conn.h"

Conn::Conn()
{

}
Conn::~Conn()
{

}


int Conn::main() {
	std::string broker = "192.168.0.176:5672";
	std::string address = "amq.topic";
	std::string connectionOptions = "";
	//cout << "Hello";
	try {
		Connection connection(broker, connectionOptions);
		connection.open();
		Session session = connection.createSession();

		Receiver receiver = session.createReceiver(address);
		Sender sender = session.createSender(address);

		Message message;
		message.setContentObject("Hello nimeia!");
		message.getContentObject().setEncoding("utf8");
		sender.send(message);
		/*
		message = receiver.fetch(Duration::SECOND * 1);
		std::cout << message.getContent() << std::endl;
		session.acknowledge();
		*/
		Debug::Print("OK", true);
		connection.close();
		//system("pause");
		return 0;
	}
	catch (const std::exception& error) {
		Debug::Print(error.what(), true);
		//std::cerr << error.what() << std::endl;
		return 1;
	}
}
