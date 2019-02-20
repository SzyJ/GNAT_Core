#pragma once
#include "pch.h"
#include "ErrorCodes.h"

namespace GNAT {
	class Client {
	private:
		Error_Code errorFlag = STARTUP_SUCCESSFUL;

		const static int PLAYER_COUNT = 4;

		// map of: ID, Value 
		std::map<byte, char> playerStates;

		const static std::string SERVER_ADDRESS;
		
		const static USHORT SERVER_PORT;
		const static int MESSAGE_BUFFER_SIZE = 1024;
		char messageBuffer[MESSAGE_BUFFER_SIZE];

		SOCKADDR_IN serverAddress;

		SOCKET clientSocket;

		std::thread sendUpdates;
		std::thread recvUpdates;

		byte thisID;
		char const* thisVal;

		bool threadsListening = false;

		bool sendToServer(const char* message, const int messageLen, const char* onErrorMsg = nullptr);
		int listenForServerMessage(const int maxRetryCount);

		char checkForUserInput();

		bool userInputLoop();
		bool stateUpdateLoop();

	public:
		Client();
		~Client();
		
		bool sendJoinRequest();
		bool startListen();
		bool stopListen();

		const int getErrorCode() const;
	};
}