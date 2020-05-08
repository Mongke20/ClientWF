#pragma once
#define WIN32_LEAN_AND_MEAN
#include "ClientClasses.h"
//#include "MyForm.h"
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <thread>
#include <dos.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
namespace ClientWinForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// ������ ��� TheChatWindow
	/// </summary>
	public ref class TheChatWindow : public System::Windows::Forms::Form
	{
	public:
		TheChatWindow(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~TheChatWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabPage^ tabPage2;
	protected:
	private: System::Windows::Forms::TextBox^ usersInChat;
	private: System::Windows::Forms::TextBox^ oldMessages;
	private: System::Windows::Forms::TextBox^ newMessage;
	private: System::Windows::Forms::Button^ sendMessage;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TextBox^ infoTextBox;
	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::Button^ usersOnline;
	private: System::Windows::Forms::Button^ oldChats;
	private: System::Windows::Forms::Button^ newChat;
	private: System::Windows::Forms::TextBox^ ChatUsers;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::TextBox^ UserList;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ ChatListBox;


	private: System::ComponentModel::IContainer^ components;

	protected:

















	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->usersInChat = (gcnew System::Windows::Forms::TextBox());
			this->oldMessages = (gcnew System::Windows::Forms::TextBox());
			this->newMessage = (gcnew System::Windows::Forms::TextBox());
			this->sendMessage = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->ChatListBox = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->UserList = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ChatUsers = (gcnew System::Windows::Forms::TextBox());
			this->infoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->usersOnline = (gcnew System::Windows::Forms::Button());
			this->oldChats = (gcnew System::Windows::Forms::Button());
			this->newChat = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabPage2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->usersInChat);
			this->tabPage2->Controls->Add(this->oldMessages);
			this->tabPage2->Controls->Add(this->newMessage);
			this->tabPage2->Controls->Add(this->sendMessage);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(712, 403);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Chat1";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// usersInChat
			// 
			this->usersInChat->Enabled = false;
			this->usersInChat->Location = System::Drawing::Point(596, 14);
			this->usersInChat->Multiline = true;
			this->usersInChat->Name = L"usersInChat";
			this->usersInChat->ReadOnly = true;
			this->usersInChat->Size = System::Drawing::Size(105, 300);
			this->usersInChat->TabIndex = 3;
			// 
			// oldMessages
			// 
			this->oldMessages->Enabled = false;
			this->oldMessages->Location = System::Drawing::Point(10, 15);
			this->oldMessages->Multiline = true;
			this->oldMessages->Name = L"oldMessages";
			this->oldMessages->ReadOnly = true;
			this->oldMessages->Size = System::Drawing::Size(575, 300);
			this->oldMessages->TabIndex = 1;
			// 
			// newMessage
			// 
			this->newMessage->Location = System::Drawing::Point(10, 326);
			this->newMessage->Multiline = true;
			this->newMessage->Name = L"newMessage";
			this->newMessage->Size = System::Drawing::Size(575, 67);
			this->newMessage->TabIndex = 0;
			// 
			// sendMessage
			// 
			this->sendMessage->Location = System::Drawing::Point(596, 327);
			this->sendMessage->Name = L"sendMessage";
			this->sendMessage->Size = System::Drawing::Size(106, 65);
			this->sendMessage->TabIndex = 2;
			this->sendMessage->Text = L"���������";
			this->sendMessage->UseVisualStyleBackColor = true;
			this->sendMessage->Click += gcnew System::EventHandler(this, &TheChatWindow::SendMessage_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(720, 432);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->ChatListBox);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->UserList);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->ChatUsers);
			this->tabPage1->Controls->Add(this->infoTextBox);
			this->tabPage1->Controls->Add(this->exit);
			this->tabPage1->Controls->Add(this->usersOnline);
			this->tabPage1->Controls->Add(this->oldChats);
			this->tabPage1->Controls->Add(this->newChat);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(712, 403);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Menu";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// ChatListBox
			// 
			this->ChatListBox->FormattingEnabled = true;
			this->ChatListBox->ItemHeight = 16;
			this->ChatListBox->Location = System::Drawing::Point(160, 6);
			this->ChatListBox->Name = L"ChatListBox";
			this->ChatListBox->Size = System::Drawing::Size(544, 228);
			this->ChatListBox->TabIndex = 10;
			this->ChatListBox->DoubleClick += gcnew System::EventHandler(this, &TheChatWindow::ChatListBox_DoubleClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(581, 195);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"label2";
			// 
			// UserList
			// 
			this->UserList->Location = System::Drawing::Point(160, 230);
			this->UserList->Multiline = true;
			this->UserList->Name = L"UserList";
			this->UserList->Size = System::Drawing::Size(544, 164);
			this->UserList->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(502, 240);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			// 
			// ChatUsers
			// 
			this->ChatUsers->AcceptsTab = true;
			this->ChatUsers->Enabled = false;
			this->ChatUsers->Location = System::Drawing::Point(298, 85);
			this->ChatUsers->Multiline = true;
			this->ChatUsers->Name = L"ChatUsers";
			this->ChatUsers->Size = System::Drawing::Size(262, 139);
			this->ChatUsers->TabIndex = 5;
			// 
			// infoTextBox
			// 
			this->infoTextBox->Enabled = false;
			this->infoTextBox->Location = System::Drawing::Point(160, 6);
			this->infoTextBox->Multiline = true;
			this->infoTextBox->Name = L"infoTextBox";
			this->infoTextBox->ReadOnly = true;
			this->infoTextBox->Size = System::Drawing::Size(544, 389);
			this->infoTextBox->TabIndex = 4;
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(25, 325);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(110, 40);
			this->exit->TabIndex = 3;
			this->exit->Text = L"�����";
			this->exit->UseVisualStyleBackColor = true;
			// 
			// usersOnline
			// 
			this->usersOnline->Location = System::Drawing::Point(25, 230);
			this->usersOnline->Name = L"usersOnline";
			this->usersOnline->Size = System::Drawing::Size(110, 40);
			this->usersOnline->TabIndex = 2;
			this->usersOnline->Text = L"������";
			this->usersOnline->UseVisualStyleBackColor = true;
			// 
			// oldChats
			// 
			this->oldChats->Location = System::Drawing::Point(25, 135);
			this->oldChats->Name = L"oldChats";
			this->oldChats->Size = System::Drawing::Size(110, 40);
			this->oldChats->TabIndex = 1;
			this->oldChats->Text = L"������ �����";
			this->oldChats->UseVisualStyleBackColor = true;
			this->oldChats->Click += gcnew System::EventHandler(this, &TheChatWindow::OldChats_Click);
			// 
			// newChat
			// 
			this->newChat->Location = System::Drawing::Point(25, 40);
			this->newChat->Name = L"newChat";
			this->newChat->Size = System::Drawing::Size(110, 40);
			this->newChat->TabIndex = 0;
			this->newChat->Text = L"����� ���";
			this->newChat->UseVisualStyleBackColor = true;
			this->newChat->Click += gcnew System::EventHandler(this, &TheChatWindow::NewChat_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &TheChatWindow::Timer1_Tick);
			// 
			// TheChatWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(720, 432);
			this->Controls->Add(this->tabControl1);
			this->Name = L"TheChatWindow";
			this->Text = L"TheChatWindow";
			this->Load += gcnew System::EventHandler(this, &TheChatWindow::TheChatWindow_Load);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//////////////////////////////////////////////////////////
		//														//
		//														//
		// ��� = -10 : ������� ����� ���						//
		// ��� = -20 : �������� ��������� 10 ��������� � ����	//
		//														//
		//														//
		// ��� = -100: ���������� ������ �����					//
		//														//
		//														//
		//														//
		//														//
		//														//
		// ��� = -1000 ���������� ������������� ������			//
		//														//
		//														//
		//														//
		//														//
		//////////////////////////////////////////////////////////
	
	String^ ToChange;
	String^ CompWith;
	//���� ��������� ����
	int chatSend;
	//��������������� ���������� ��� ��������� �����
	int GetChatsCounter = 0;
	//��������������� ���������� ��� ��������� ���������
	int GetMessagesCounter = 0;
	//���������� �������
	int Entries = 0;
	//������� �������������� ��������� ������ � �������
	string SystemToStl(String^ s) {
		using namespace Runtime::InteropServices;
		const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		return string(ptr);
	}
	//������� ��������� �����
	void GetChats() {
		ChatListBox->Items->Clear();
		GetChatsCl.code = -100;
		GetChatsCl.text = " ";
		GetChatsCl.Send();
		while (GetChatsCounter!=-1) {
			label2->Text = "���-�� ���� " + Convert::ToString(GetChatsCounter);
		};		
		for (auto i : ChatListVector) {
			ChatListBox->Items->Add(gcnew System::String(i.c_str()));
		}
		ChatListVector.clear();
		GetChatsCounter = 0;
		GetChatsCl.text = " ";
	}

	//������� ��������� �����
	void GetMessages(string chatID) {
		oldMessages->Text = "";
		GetMessagesCl.code = -20;
		GetMessagesCl.text = chatID;
		GetMessagesCl.Send();
		while (GetMessagesCounter != -1) {
			label2->Text = "���-�� ���� " + Convert::ToString(GetMessagesCounter);
		};
		//���� �������� ����� ����! ����� ��� �������� ������ �����, ����� ��� �� �������.
		for (auto msg : OldMessageVector) {
			oldMessages->Text += "\r\n";
			oldMessages->Text += gcnew System::String(msg[0].c_str());
			oldMessages->Text += ":\t";
			oldMessages->Text += gcnew System::String(msg[1].c_str());
			oldMessages->Text += ":\t";
			oldMessages->Text += gcnew System::String(msg[2].c_str());
		}
		OldMessageVector.clear();
		GetMessagesCounter = 0;
		GetMessagesCl.text = " ";
	}

	//��������� ������ �������������(������� �����) �� 1 ������� �� ������� � �����.
	void CUWithLines(String^ froms) {
		usersInChat->Text = "";
		for (int i = 0; i < froms->Length; i++) {
			if (froms[i] == ',') {
				usersInChat->Text += "\r\n";
			}
			else usersInChat->Text += froms[i];
		}

	}
	//������� ��� ���������� ��������� ���������. � ������������� ������� �������� ������������ �� ������ ������� ��� ������, �� ��� ������
	// ��� ������ �� � ���� �������
	string GetMessage() {
		int msgS = 0;
		recv(d1.TheSock, (char*)& msgS, sizeof(int), 0);
		char* msg = new char[msgS + 2];
		int iResult = recv(d1.TheSock, msg, msgS, 0);
		msg[msgS] = '\n';
		msg[msgS + 1] = '\0';
		string msgStr = msg;
		return msgStr;
	}
	//����������. �� � ��� ������ �� ������������ �������� �����!!!
	void receiver() {
		try {
			int iResult = 0;
			do {
				int msgS = 0;
				recv(d1.TheSock, (char*)& msgS, sizeof(int), 0);				
				char* msg = new char[msgS + 2];
				iResult = recv(d1.TheSock, msg, msgS, 0);
				msg[msgS] = '\n';
				msg[msgS + 1] = '\0';
				string msgStr = msg;
				if (iResult > 0) {
					Entries++;
					int position = 0;
					while (position < msgStr.length() && msgStr[position] != '@') {
						position++;
					}
					int code = stoi(msgStr.substr(0, position));
					string text = msgStr.substr(position + 1);
					//����� �������� ����� �� �������� ������ ����
					if (code == -10) {
						NewChat.code = code;
						NewChat.text = text;
					}
					//��������� ������ ��������� �����
					else if (code == -100) {						
						if (GetChatsCounter == 0) {
							GetChatsCounter = stoi(text);
							tempChats = Chats;
							Chats.clear();
							if (GetChatsCounter == 0) GetChatsCounter--;
						}
						else {
							Test.code++;
							position = 0;
							while (position < text.length() && text[position] != '@') {
								position++;
							}
							string ChatID = text.substr(0, position++);
							string TheChatUsers = text.substr(position);
							Chats[stoi(ChatID)] = tempChats[stoi(ChatID)];
							string newChat = ChatID + '(' + to_string(tempChats[stoi(ChatID)]) + ") " + TheChatUsers + "\r\n";
							GetChatsCl.text += newChat;
							ChatListVector.push_back(newChat);
							if (GetChatsCounter == 1) GetChatsCounter = -1;
							else GetChatsCounter--;
						}
					}
					//��������� ���� ��������� � ������ ��� �������� ���
					else if (code == -20) {
						if (GetMessagesCounter == 0) {
							GetMessagesCounter = stoi(text);
							if (GetMessagesCounter == 0) GetMessagesCounter--;
						}
						else {
							vector<string> oneMessage;
							//������ ����� (�� @) - ��� ��� ����. �� ��� �� ����� �����
							position = 0;
							while (position < text.length() && text[position] != '@') {
								position++;
							}
							position++;
							int oldpoz = position;
							//������ ����� - ��� �����������
							while (position < text.length() && text[position] != '@') {
								position++;
							}
							string PersonFrom = text.substr(oldpoz, position - oldpoz);
							oneMessage.push_back(PersonFrom);
							position++;
							oldpoz = position;
							//������ ����� - ��� ����
							while (position < text.length() && text[position] != '@') {
								position++;
							}
							string DateFrom = text.substr(oldpoz, position - oldpoz);
							oneMessage.push_back(DateFrom);
							position++;
							//��������� ����� - ��� ����� ������ � ����� ����������
							string timeMessage = text.substr(position);
							oneMessage.push_back(timeMessage);
							OldMessageVector.push_back(oneMessage);
							if (GetMessagesCounter == 1) GetMessagesCounter = -1;
							else GetMessagesCounter--;
						}
					}
					//��������� ������� ��������� � �����-���� ���. ���� ��������
					else if (code > 0) {
						int ChatsSize = Chats.size();
						if (Chats.count(code) == 0) {
							//������� ������ �� ��������� ������ �����
						}
						else {
							Chats[code] = 0;
							if (code == chatSend) {
								oldMessages->Text += "\r\n";
								position = 0;
								while (position < text.length() && text[position] != '@') {
									position++;
								}								
								string PersonFrom = text.substr(0, position++);
								int oldpoz = position;
								while (position < text.length() && text[position] != '@') {
									position++;
								}
								string DateFrom = text.substr(position, position-oldpoz);
							}
						}
					}
				}
				else if (iResult == 0) {
				}
				else {
				}
			} while (iResult > 0);
		}
		catch (exception e) {

			return;
		}
	}
	//������� �������� ���������
	void TheSender() {
		try {
			std::string str;
			// ���� ��������� � ���������� ��� �� ��� ����������, ��������� � �����-�������
			str = SystemToStl(newMessage->Text);
			MsgCl toSend(chatSend, str);
			toSend.Send();
		}
		catch (...) {
			return;
		}
	}
	// ��� ����� (��� ���������� ����) �� ������ ����� ���
	private: System::Void NewChat_Click(System::Object^ sender, System::EventArgs^ e) {
		//�������� ������ �����, ���������� ���� ��� ����� �������������
		if (ChatUsers->Enabled == false) {
			ChatUsers->Enabled = true;
			ChatListBox->Enabled = false;
			ChatUsers->Visible = true;
			ChatListBox->Visible = false;
		}
		//���� ��� ������ �����, ��������� �������
		else {
			if (ChatUsers->Text->Length == 0 || ChatUsers->Text == "������� �������������") {
				ChatUsers->Text = "������� �������������";
			}
			else {
				NewChat.code = -10;
				NewChat.text = SystemToStl(ChatUsers->Text);
				NewChat.Send();
				while (NewChat.text == SystemToStl(ChatUsers->Text)) {
					label1->Text = ChatUsers->Text;
				}
				if (NewChat.text[0] >= '0' && NewChat.text[0] <= '9') {
					tabControl1->SelectedIndex = 1;
					chatSend = stoi(NewChat.text);
					CUWithLines(ChatUsers->Text);
					//usersInChat->Text = ChatUsers->Text;
					//MsgCl GetStory(-20,id);
				}
				else {
					ChatUsers->Text = gcnew System::String(NewChat.text.c_str());

				}
			}
			//����������� � ��������� �� ������� ������
			ChatUsers->Text = "";
			ChatUsers->Enabled = false;
			ChatListBox->Enabled = true;
			ChatUsers->Visible = false;
			ChatListBox->Visible = true;
		}
	}

//������� ��� �������� �����
private: System::Void TheChatWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	/*MsgCl getChats(-100, "");
	MsgCl getUsers(-1000, "");
	getChats.Send();
	getUsers.Send();*/
	//������ ������, ��� ���� ���������� �����.
	ThreadStart^ thrStart = gcnew ThreadStart(this, &TheChatWindow::receiver);
	Thread^ t1 = gcnew Thread(thrStart);
	t1->IsBackground = true;
	t1->Start();
	//������ �������
	timer1->Start();
}

//������. ���� �����������, ������������� ��� �������. ������ �����, ����� ��� ����������� ��������� � ������� ����.(��� ���� ������)
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	label2->Text = Convert::ToString(GetChatsCounter) +  " " + Convert::ToString(Test.code) + " " + Convert::ToString(Entries);
	if (CompWith != ToChange) {
		oldMessages->Text += ToChange + "\r\n";
		CompWith = ToChange;
	}
	
}

//��� ������� �� ������ ��������� ��������� �� 2 �������
private: System::Void SendMessage_Click(System::Object^ sender, System::EventArgs^ e) {
	TheSender();
}

//��� ������� �� ������ ������ �����
private: System::Void OldChats_Click(System::Object^ sender, System::EventArgs^ e) {
	GetChats();
}


//��� ������� ����� �� ���
	private: System::Void ChatListBox_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		if (ChatListBox->SelectedIndex >= 0) {
			//������������ �� ������ �������
			tabControl1->SelectedIndex = 1;
			//��������� ������ �� ��� ���� � ������ �������������
			string chatString = SystemToStl(ChatListBox->SelectedItem->ToString());
			int position = 0;
			while (chatString[position] != '(') {
				position++;
			}
			string ChatID = chatString.substr(0, position);
			while (chatString[position] != ')') {
				position++;
			}
			string TheChatUsers = chatString.substr(position + 1);
			//������� ������ ������������� �� ������� � �����
			CUWithLines(gcnew System::String(TheChatUsers.c_str()));
			oldMessages->Text = ChatListBox->SelectedItem->ToString();
			//��������� ������ �� ��������� ��������� ��� ����� ����
			GetMessages(ChatID);
		}
}
};
}
