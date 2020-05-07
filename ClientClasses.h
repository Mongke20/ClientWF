#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;
//�����, � ������� ���������� ������ ������ �� ������ ����� ��� �������� �� ��� �� ������ ����� ��� � ������ �����.
class MyFormData {
public:
	SOCKET TheSock;
};
MyFormData d1;

//����� ��� ��������, ��������� � �������� �������� �������
class MsgCl {
public:
	MsgCl() {
		code = -666;
		text = "-666";
	}
	MsgCl(int c, string t) {
		code = c;
		text = t;
	}
	//���� � ����� �������
	int code;
	//���� � ���������� �������
	string text;
	//����� ��� ������� �����
	string GenerateMsg() {
		string TheMsg = to_string(code) + "@" + text;
		return TheMsg;
	}
	//����� ��� �������� ������� �������.
	void Send() {
		//�������� �� ������� �����
		if (code != -666 && text != "-666") {
			string msg = GenerateMsg();
			int sizeM = msg.size() + 1;			
			int Result = send(d1.TheSock, (char*)& sizeM, sizeof(int), 0);
			if (Result == SOCKET_ERROR) {

			}
			Result = send(d1.TheSock, msg.c_str(), sizeM, 0);
		}
	}
};
MsgCl NewChat;
MsgCl GetChatsCl(-100, " ");
MsgCl Test(0,"");
map<int, int> Chats;
map<int, int> tempChats;
