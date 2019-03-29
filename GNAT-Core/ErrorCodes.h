#pragma once

// Startup
#define STARTUP_SUCCESSFUL 0
#define WINSOCK_STARTUP_FAIL -1
#define SOCKET_CREATION_FAIL -2
#define BINDING_SOCKET_FAIL -3
#define GETTING_PORT_FAILED -4

// Client
#define FAILED_TO_CONNECT_TO_SERVER -5
#define NOT_CONNECTED_TO_SERVER -6
#define CONNECTION_ESTABLISHED 0

// Sending Messages
#define FAILED_TO_SEND_MESSAGE -7

// Receiving Messages
#define NO_MESSAGE_TO_RECEIVE 0
#define UNEXPECTED_MESSAGE -8
#define EXEPTION_DURING_MSG_RECEIVE -9

#define UNEXPECTED_PROGRAM_STATE -99

typedef int Error_Code;