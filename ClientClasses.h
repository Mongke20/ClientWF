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
MsgCl toSend;
MsgCl NewChat;
MsgCl GetChatsCl(-100, " ");
MsgCl GetMessagesCl(-20, " ");
MsgCl getCl;
MsgCl Test(0,"");
vector<string> ChatListVector;
vector<vector<string>> OldMessageVector;
map<int, int> Chats;
map<int, int> tempChats;
vector<string> oneMessage;
