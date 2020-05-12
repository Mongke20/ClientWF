#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;
//Класс, в который помещаются нужные данные из первой формы для передачи их или во вторую форму или в другой класс.
class MyFormData {
public:
	SOCKET TheSock;
};
MyFormData d1;

//Класс для хранения, генерации и отправки запросов серверу
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
	//Поле с кодом запроса
	int code;
	//Поле с сообщением запроса
	string text;
	//Метод для склейки полей
	string GenerateMsg() {
		string TheMsg = to_string(code) + "@" + text;
		return TheMsg;
	}
	//Метод для отправки запроса серверу.
	void Send() {
		//проверка на пустоту полей
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
MsgCl Test(0,"Все в порядке");
vector<string> ChatListVector;
vector<vector<string>> OldMessageVector;
map<int, int> Chats;
map<int, int> tempChats;
vector<string> oneMessage;
MsgCl toExit(-40, " ");