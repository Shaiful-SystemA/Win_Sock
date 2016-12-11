//Server

#pragma comment(lib, "ws2_32.lib")
#include<WinSock2.h>
#include<iostream>


int main()
{

	//Winsocke Stratup

	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{

		MessageBoxA(NULL, "Winsocke startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);

	}


	SOCKADDR_IN addr; // Address that we will bind out listenig socket to
	int addrlen = sizeof(addr); // length of the address (required for accept call)
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Boradcase locally
	addr.sin_port = htons(1111); // port
	addr.sin_family = AF_INET; // IPv4 Socket


	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); // create socket to listen for new connection
	bind(sListen,(SOCKADDR*)&addr, sizeof(addr)); // Bind the addfress to the socket
	listen(sListen, SOMAXCONN); //Places sListen socker inn a state in whch it is lisening for an incoming connection

	SOCKET newConnection; // Socket to hold the clinet connection
	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen); // Accpet a new connection

	if (newConnection == 0) // If accepting the client connection failed 
	{

		std::cout << "Failed to accept the client's connectio" << std::endl;
		//char MOTD[256] = "Welcome " // create buffer with message of the day
		//	send(newConnection, MOTD, sizeof(MOTD), NULL); // Send MOTD buffer

	}
	else // If client connection properly accpeted 
	{

		//std:cout << "Client Connected" << std::endl;
		std::cout << "Client Connected" << std::endl;
		char MOTD[256] = "Welcome ";
		send(newConnection, MOTD, sizeof(MOTD), NULL); // Send MOTD buffer

	}
	system("pause");
	return 0;

}