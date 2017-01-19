
#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sstream>
#include <stdexcept>
#include <pthread.h>
#include <list>

using namespace std;

class Server: public Tcp {
public:
	Server(int port);
	void Start();
	static void* threadFunction(void* element);
	void receiveMessages(void* element);
	virtual ~Server();
private:

	struct ClientData
	{
		int client_socket;
		int client;
		unsigned int client_size;
		bool online;
		Server* server;
	};

	int port;
	int capacity;
	int num_of_connections;
	int server_socket;
	bool online;
	struct sockaddr_in server_details;
	list<ClientData*>* clients;
	pthread_mutex_t connection_locker;
	pthread_mutex_t list_locker;
};

#endif /* SERVER_SERVER_H_ */
