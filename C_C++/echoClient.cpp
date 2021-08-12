#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <string>
#include <winsock2.h>

using namespace std;

void ShowErrorMessage(string message) //오류가 발생하면 메시지를 출력하고 종료
{
	cout << "[오류 발생]: " << message << '\n';
	system("pause");
	exit(1);
}

int main()
{
	WSADATA wsaData;
	SOCKET clientSocket;
	SOCKADDR_IN serverAddress;

	int serverPort = 9876; //포트번호가 서버와 같아야 요청이 가능
	char received[256]; //크기 설정
	string sent;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) //winsock 초기화
		ShowErrorMessage("WSAStartup()");

	clientSocket = socket(PF_INET, SOCK_STREAM, 0); //TCP 소켓 생성

	if (clientSocket == INVALID_SOCKET) //예외처리
		ShowErrorMessage("socket()");

	memset(&serverAddress, 0, sizeof(serverAddress)); //serverAddress 0으로 초기화
	serverAddress.sin_family = AF_INET; //IPv4
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); //문자열 ip를 네트워크 바이트 형식으로
	serverAddress.sin_port = htons(serverPort); //2바이트 정수 네트워크 바이트 형식으로
	if (connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("connect()");
	cout << "[현재 상태] connect()\n";

	while (1) {
		cout << "[메시지 전송]: ";
		getline(cin, sent);
		if (sent == "") continue;
		send(clientSocket, sent.c_str(), sent.length(), 0);
		int length = recv(clientSocket, received, sizeof(received), 0);
		received[length] = '\0';
		if (strcmp(received, "[exit]") == 0) {
			cout << "[서버 종료]\n";
			break;
		}
		cout << "[서버 메시지]: " << received << '\n';
	}

	closesocket(clientSocket);
	WSACleanup();
	system("pause");
	return 0;
}