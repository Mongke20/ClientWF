#pragma once
#define WIN32_LEAN_AND_MEAN
#include "ClientClasses.h"
#include "MyForm.h"
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




	private: System::Windows::Forms::ListBox^ ChatListBox;
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Timer^ timer2;

	private: System::Windows::Forms::ListBox^ UserList;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Label^ label1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TheChatWindow::typeid));
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->usersInChat = (gcnew System::Windows::Forms::TextBox());
			this->oldMessages = (gcnew System::Windows::Forms::TextBox());
			this->newMessage = (gcnew System::Windows::Forms::TextBox());
			this->sendMessage = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->UserList = (gcnew System::Windows::Forms::ListBox());
			this->ChatListBox = (gcnew System::Windows::Forms::ListBox());
			this->ChatUsers = (gcnew System::Windows::Forms::TextBox());
			this->infoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->usersOnline = (gcnew System::Windows::Forms::Button());
			this->oldChats = (gcnew System::Windows::Forms::Button());
			this->newChat = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tabPage2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->exitButton);
			this->tabPage2->Controls->Add(this->usersInChat);
			this->tabPage2->Controls->Add(this->oldMessages);
			this->tabPage2->Controls->Add(this->newMessage);
			this->tabPage2->Controls->Add(this->sendMessage);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(712, 390);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Chat";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::Color::Salmon;
			this->exitButton->Location = System::Drawing::Point(596, 264);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(105, 50);
			this->exitButton->TabIndex = 4;
			this->exitButton->Text = L"����� �� ����";
			this->toolTip1->SetToolTip(this->exitButton, L"�������� ������� ���");
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &TheChatWindow::ExitButton_Click);
			// 
			// usersInChat
			// 
			this->usersInChat->Enabled = false;
			this->usersInChat->Location = System::Drawing::Point(596, 6);
			this->usersInChat->Multiline = true;
			this->usersInChat->Name = L"usersInChat";
			this->usersInChat->ReadOnly = true;
			this->usersInChat->Size = System::Drawing::Size(105, 300);
			this->usersInChat->TabIndex = 3;
			this->toolTip1->SetToolTip(this->usersInChat, L"������ ������������� � ���� ����");
			// 
			// oldMessages
			// 
			this->oldMessages->Enabled = false;
			this->oldMessages->Location = System::Drawing::Point(10, 6);
			this->oldMessages->Multiline = true;
			this->oldMessages->Name = L"oldMessages";
			this->oldMessages->ReadOnly = true;
			this->oldMessages->Size = System::Drawing::Size(575, 300);
			this->oldMessages->TabIndex = 1;
			this->toolTip1->SetToolTip(this->oldMessages, L"������� ��������� ����� ����");
			// 
			// newMessage
			// 
			this->newMessage->Location = System::Drawing::Point(10, 317);
			this->newMessage->Multiline = true;
			this->newMessage->Name = L"newMessage";
			this->newMessage->Size = System::Drawing::Size(575, 67);
			this->newMessage->TabIndex = 0;
			this->toolTip1->SetToolTip(this->newMessage, L"���� ��� ����� ���������");
			// 
			// sendMessage
			// 
			this->sendMessage->BackColor = System::Drawing::Color::LightGreen;
			this->sendMessage->Location = System::Drawing::Point(596, 319);
			this->sendMessage->Name = L"sendMessage";
			this->sendMessage->Size = System::Drawing::Size(106, 65);
			this->sendMessage->TabIndex = 2;
			this->sendMessage->Text = L"���������";
			this->sendMessage->UseVisualStyleBackColor = false;
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
			this->tabControl1->Size = System::Drawing::Size(720, 419);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &TheChatWindow::tabControl1_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->UserList);
			this->tabPage1->Controls->Add(this->ChatListBox);
			this->tabPage1->Controls->Add(this->ChatUsers);
			this->tabPage1->Controls->Add(this->infoTextBox);
			this->tabPage1->Controls->Add(this->exit);
			this->tabPage1->Controls->Add(this->usersOnline);
			this->tabPage1->Controls->Add(this->oldChats);
			this->tabPage1->Controls->Add(this->newChat);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(712, 390);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Menu";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Enabled = false;
			this->label1->Location = System::Drawing::Point(499, 258);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 12;
			this->label1->Text = L"label1";
			this->label1->Visible = false;
			// 
			// UserList
			// 
			this->UserList->ColumnWidth = 55;
			this->UserList->ForeColor = System::Drawing::Color::Black;
			this->UserList->FormattingEnabled = true;
			this->UserList->ItemHeight = 16;
			this->UserList->Location = System::Drawing::Point(160, 201);
			this->UserList->MultiColumn = true;
			this->UserList->Name = L"UserList";
			this->UserList->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
			this->UserList->Size = System::Drawing::Size(275, 180);
			this->UserList->TabIndex = 11;
			this->toolTip1->SetToolTip(this->UserList, L"������ ������������� ����");
			// 
			// ChatListBox
			// 
			this->ChatListBox->FormattingEnabled = true;
			this->ChatListBox->ItemHeight = 16;
			this->ChatListBox->Location = System::Drawing::Point(160, 6);
			this->ChatListBox->Name = L"ChatListBox";
			this->ChatListBox->Size = System::Drawing::Size(550, 180);
			this->ChatListBox->TabIndex = 10;
			this->toolTip1->SetToolTip(this->ChatListBox, L"������ ����� �����");
			this->ChatListBox->DoubleClick += gcnew System::EventHandler(this, &TheChatWindow::ChatListBox_DoubleClick);
			// 
			// ChatUsers
			// 
			this->ChatUsers->AcceptsTab = true;
			this->ChatUsers->Location = System::Drawing::Point(435, 201);
			this->ChatUsers->Multiline = true;
			this->ChatUsers->Name = L"ChatUsers";
			this->ChatUsers->Size = System::Drawing::Size(275, 180);
			this->ChatUsers->TabIndex = 5;
			this->toolTip1->SetToolTip(this->ChatUsers, L"���� ��� ����� �������������");
			this->ChatUsers->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TheChatWindow::ChatUsers_MouseClick);
			// 
			// infoTextBox
			// 
			this->infoTextBox->Enabled = false;
			this->infoTextBox->Location = System::Drawing::Point(160, 6);
			this->infoTextBox->Multiline = true;
			this->infoTextBox->Name = L"infoTextBox";
			this->infoTextBox->ReadOnly = true;
			this->infoTextBox->Size = System::Drawing::Size(550, 375);
			this->infoTextBox->TabIndex = 4;
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(11, 318);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(124, 47);
			this->exit->TabIndex = 3;
			this->exit->Text = L"�����";
			this->toolTip1->SetToolTip(this->exit, L"����� �� ��������");
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &TheChatWindow::Exit_Click);
			// 
			// usersOnline
			// 
			this->usersOnline->Location = System::Drawing::Point(11, 223);
			this->usersOnline->Name = L"usersOnline";
			this->usersOnline->Size = System::Drawing::Size(124, 53);
			this->usersOnline->TabIndex = 2;
			this->usersOnline->Text = L"������\n�������������";
			this->toolTip1->SetToolTip(this->usersOnline, L"�������� ������ �������������. ������ ������������ - ������");
			this->usersOnline->UseVisualStyleBackColor = true;
			this->usersOnline->Click += gcnew System::EventHandler(this, &TheChatWindow::UsersOnline_Click);
			// 
			// oldChats
			// 
			this->oldChats->Location = System::Drawing::Point(11, 131);
			this->oldChats->Name = L"oldChats";
			this->oldChats->Size = System::Drawing::Size(124, 48);
			this->oldChats->TabIndex = 1;
			this->oldChats->Text = L"������ �����";
			this->toolTip1->SetToolTip(this->oldChats, L"�������� ������ ��������� �����");
			this->oldChats->UseVisualStyleBackColor = true;
			this->oldChats->Click += gcnew System::EventHandler(this, &TheChatWindow::OldChats_Click);
			// 
			// newChat
			// 
			this->newChat->Location = System::Drawing::Point(11, 38);
			this->newChat->Name = L"newChat";
			this->newChat->Size = System::Drawing::Size(124, 50);
			this->newChat->TabIndex = 0;
			this->newChat->Text = L"����� ���";
			this->toolTip1->SetToolTip(this->newChat, L"������� ����� ���");
			this->newChat->UseVisualStyleBackColor = true;
			this->newChat->Click += gcnew System::EventHandler(this, &TheChatWindow::NewChat_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &TheChatWindow::Timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &TheChatWindow::Timer2_Tick);
			// 
			// TheChatWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 423);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(742, 470);
			this->MinimumSize = System::Drawing::Size(742, 470);
			this->Name = L"TheChatWindow";
			this->Text = L"TheChatWindow";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TheChatWindow::TheChatWindow_FormClosing);
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
		// ��� = -30 : ����� �� ����							//
		// ��� = -40 : ����� �� ����������						//
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
	//���������� ������������� ������
		int UsersCount = 0;
	//! ������, � ������� ������������ ����� ������ ��� ����������� ���������
	String^ ToChange;
	/*! ������, � ������� �������� ����� ���������� ����������� � ������������� ���������.
	� ������� ��� ������������ �� ������� ToChange, � ���� ��� ����������, ��� ������, ��� ��������� ����� ���������
	*/
	String^ CompWith;
	//! ������� ������ ��� ����� ����� ��������� �����
	int closeCounter = 0;
	//! ���������� ��� �������� ���� ��������� ����
	int chatID = 0;
	//! ��������������� ���������� ��� ��������� ����� � ���������
	int getCounter = 0;
	//! ���������� ��� �������
	int CurID = 0;
	bool TimeDo = false;
	//! ����������-���� ��� ������� ���� ����� ������������� ������ ���� �� ��������������� ���������
	bool clearChatUsers = false;
	//! ���������� ��� �������� ��������������� ��������� ��� �������� ������ ����
	System::String ^ newChatMsg = gcnew System::String(newChatMsgStr.c_str());

	//!������� ��� �������� ������ System::String � std::string
	string SystemToStl(String^ s) {
		using namespace Runtime::InteropServices;
		const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		string str = string(ptr);
		Marshal::FreeHGlobal(IntPtr((void*)ptr));
		return str;
	}

	/*! \brief ������� ��� ��������� ������ �����

	��������� ������ � ���������� ��� �� ������. ����� ����, ��� � ������ ������ ��������� �� ������� ��������, ����������
	� ���������� � ������, ��� ������� ��������� ListBox �� ������ ���� � ������ �����. ����� � ������, � ��������� ������
	��� ��������� �������� ���������.
	*/
	void GetChats() {
		ChatListBox->Items->Clear();
		getCl.code = -100;
		getCl.text = " ";
		getCl.Send();
		while (getCounter !=-1) {
			label1->Text = "���-�� ���� " + Convert::ToString(getCounter);
		};
		
		for (auto i : ChatListVector) {
			ChatListBox->Items->Add(gcnew System::String(i.c_str()));
		}
		ChatListVector.clear();
		getCounter = 0;
		getCl.text = " ";
	}

	/*! \brief ������� ������ ������������� � ����������� ����
	
	\param froms - ������ �� ������� �������������
	\param cut - ����� �����, ���������� ���������� �������� � ����� ������ (��������, 0)

	��������� ������ ������������� � ���� �� ������� � �����.
	*/
	void CUWithLines(String^ froms, int cut) {
		usersInChat->Text = "";
		for (int i = 0; i < froms->Length - cut; i++) {
			if (froms[i] == ',') {
				usersInChat->Text += "\r\n";
			}
			else usersInChat->Text += froms[i];
		}
	}

	/*! \brief ������� ��� ��������� ������ �������������

	��������� ������ � ���������� ��� �� ������. ����� ����, ��� � ������ ������ ��������� �� ������� ��������, ����������
	� ���������� � ������, ��� ������� ��������� ListBox �� ������ ������������ � ������ �����. ����� � ������, � ���������
	������ ��� ��������� �������� ���������.
	*/
	void GetUsers() {
		UserList->Items->Clear();
		getCl.code = -1000;
		getCl.text = " ";
		getCl.Send();
		while (getCounter != -1) {
			label1->Text = "���-�� ���� " + Convert::ToString(getCounter);
		};
		for (auto user : userListVector) {
			if (UserList->Items->Count == UsersCount) UserList->Items->Add("|______|");
			UserList->Items->Add(gcnew System::String(user.c_str()));
		}
		getCounter = 0;
		getCl.text = " ";
		UserList->SelectionMode = SelectionMode::None;
	}

	/*! \brief ������� ��� ��������� �� �����, ��� 40 ��������� � �������� ���

	\param ChatIDStr - ������ � ����� ����

	��������� ������ � ���������� ��� �� ������. ����� ����, ��� � ������ ������ ��������� �� ������� ��������, ����������
	� ���������� � ������, ��� ������� ��������� �� �� ������� � textBox. ����� � ������, � ��������� ������ ��� ���������
	�������� ���������.
	*/
	void GetMessages(string ChatIDStr) {
		oldMessages->Text = " ";
		getCl.code = -20;
		getCl.text = ChatIDStr;
		getCl.Send();
		while (getCounter != -1) {
			label1->Text = "���-�� ���� " + Convert::ToString(getCounter);
		};
		for (auto msg : OldMessageVector) {
			oldMessages->Text += formatStr(msg);
		}
		OldMessageVector.clear();
		getCounter = 0;
		getCl.text = " ";
	}

	/*! \brief ������� ��� ��������� ���������.

	\param text - ������-���������, ���������� �� �������
	\return ������ �����
	
	��������� ������ �� ���� �� ���������� ������� "@". ���������� ������ �����
	- ������ ����� - ��� �����������
	- ������ ����� - ��� ����
	- ������ ����� - ��� ����� ������ � ����� ����������
	*/
	vector<string> GetMessage(string text) {
		vector<string> result;
		try {
			int position = 0;
			int oldpoz = position;
			while (position < text.length() && text[position] != '@') {
				position++;
			}
			string PersonFrom = text.substr(oldpoz, position - oldpoz);
			result.push_back(PersonFrom);
			position++;
			oldpoz = position;
			while (position < text.length() && text[position] != '@') {
				position++;
			}
			string DateFrom = text.substr(oldpoz, position - oldpoz);
			result.push_back(DateFrom);
			position++;
			string timeMessage = text.substr(position);
			result.push_back(timeMessage);
		}
		catch (exception e) {
			Test.text = e.what();
			system("pause");
		}
		return result;
	}

	/*! \brief ������� ��� �������. ������� ������� �����.

	����� ��� ������������ �������, ������� ��������� ��������� ��� ���������� ��� ��� ���� ��������, � ��� �����
	�������������� � ��������
	*/
	void ShowTime() {
		seconds = time(NULL);
		timeinfo = localtime(&seconds);
		char st[50];
		char* format = "%A, %B %d, %Y %I:%M:%S";
		strftime(st, 80, format, timeinfo);
		string str = st;
		newMessage->Text += gcnew System::String(str.c_str()) + "\r\n";
	}

	/*! �������� ��������� (������) � ���������������� ���� (������)

	\param v - ������ �� �����, ���� ���������
	\return ������ � ������ ������� (� ������������� ����� ������� ���������)
	*/
	String^ formatStr(vector<string> v) {
		String^ result;
		result += gcnew System::String(v[0].c_str());
		result += ":\t";
		result += gcnew System::String(v[1].c_str());
		result += ":\t";
		result += gcnew System::String(v[2].c_str());
		result += "\r\n";
		return result;
	}
	

	/*! \brief ������� ��� �������� ������������ ������� �� ����� ���

	\param froms ������ �� ������� ������������� ��� ������ ����
	\return ������ �����, ������ ������������� �� �������, ������� �� ����������

	���������, ���������� �� ��������� ������������, � ���� ���, ����� ������ ��� �� ���, ��� �� ����������,
	� �������������� ����������.
	*/
	vector<string> checkChat(String^ froms) {
		int pos = 0;
		int prevPos = 0;
		vector<string> wrongUsers;
		string temp;
		while (pos < froms->Length) {
			while (pos < froms->Length && froms[pos] != ',') {
				pos++;
			}
			while (froms[prevPos] == ' ') {
				prevPos++;
			}
			temp = SystemToStl(froms->Substring(prevPos, pos - prevPos));
			auto result = find(userListVector.begin(), userListVector.end(), temp);
			if (result == userListVector.end()) {
				wrongUsers.push_back(temp);
			}
			pos++;
			prevPos = pos;
		}
		return wrongUsers;
	}


	/*! \brief ������� ��� ��������� ���� ��������� �� ������� � �� �������������

	� ����������� ����� �������� ��������� �� ������� ��� ������ �������. ��������� �� �� ��� � �����. � �����������
	�� ����, ��������� ����� ���������� ��������� � ��������������� ��������. ������ ���������� getCounter, ����� ��������
	�������� � ������ ������, ��� ��� ��������� �� ������� ������� ���������.
	��-�� ������ � ������ ���������� ������� ����������� ���������� � ���� ������� � ��������� �����,
	��� ��� ��� ���� ������� � ������� ������.
	*/
	void receiver() {
		try {
			Test.code++;
			int iResult = 0;
			do {
				int msgS = 0;
				recv(d1.TheSock, (char*)& msgS, sizeof(int), 0);
				char* msg = new char[msgS + 2]; //! msg - ���������� ��� ��������� ���������� ��������� �� �������
				iResult = recv(d1.TheSock, msg, msgS, 0);
				msg[msgS] = '\n';
				msg[msgS + 1] = '\0';
				string msgStr = msg; //! msgStr - ���������� ���� string ��� ���������� ������ � ����������
				delete[]msg;
				if (iResult > 0) {
					int position = 0; //! position - ������� � ������ ��� ��������� �� �� ��� � �����
					while (position < msgStr.length() && msgStr[position] != '@') {
						position++;
					}
					int code = stoi(msgStr.substr(0, position)); //! code - ��� ����������� ���������
					CurID = code;
					string text = msgStr.substr(position + 1); //! text - ����� ����������� ���������
					// ��������� ������ �� �������� ������ ����
					if (code == -10) {
						chatID = stoi(text);
						NewChat.code = code;
						NewChat.text = text;
					}
					// ��������� ������ ��������� �����
					else if (code == -100) {						
						if (getCounter == 0) {
							getCounter = stoi(text);
							tempChats = Chats;
							Chats.clear();
							if (getCounter == 0) getCounter--;
						}
						else {
							position = 0;
							while (position < text.length() && text[position] != '@') {
								position++;
							}
							string ChatIDStr = text.substr(0, position++); //! ChatIDStr - ��� ����
							string TheChatUsers = text.substr(position); //! TheChatUsers - ������ ������������� � ����
							Chats[stoi(ChatIDStr)] = tempChats[stoi(ChatIDStr)];
							//! newChat - ��������������� ������ � ����������� � ���� ��� ������ � � listBox
							string newChat = ChatIDStr + '(' + to_string(tempChats[stoi(ChatIDStr)]) + ") " + TheChatUsers + "\r\n";
							getCl.text += newChat;
							ChatListVector.push_back(newChat);
							if (getCounter == 1) getCounter = -1;
							else getCounter--;
						}
					}
					// ��������� ������ �������������
					else if (code == -1000) {
						userListVector.clear();
						int prevPos = 0; //! prevPos - ���������� ������� ������� � ������ ��� ��������� ���������
						while (text[prevPos] != '@') prevPos++;

						int n = stoi(text.substr(0, prevPos)); //! n - ���������� ������������� ������
						UsersCount = n;
						prevPos++;
						for (int i = prevPos; i < text.length(); i++) {
							if (text[i] == ',') {
								userListVector.push_back(text.substr(prevPos, i - prevPos));
								prevPos = i + 1;
							}
						}
						userListVector.push_back(text.substr(prevPos, text.length() - prevPos - 1));
						getCounter = -1;
					}
					// ��������� �� �����, ��� 40 ��������� � �������� ���
					else if (code == -20) {
						if (getCounter == 0) {
							getCounter = stoi(text);
							if (getCounter == 0) getCounter--;
						}
						else {							
							OldMessageVector.push_back(GetMessage(text));
							if (getCounter == 1) getCounter = -1;
							else getCounter--;
						}
					}
					// ��������� ���������, ������������ ���-�� ����� ������, �� ������, � �����-���� ���.
					else if (code > 0) {
						Chats[code]++;
						ToChange = gcnew System::String(text.c_str());
						if (code == chatID) {
							Chats[code] = 0;
							oneMessage = GetMessage(text);								
						}							
						else TimeDo = true;
					}
				}
				else if (iResult == 0) {
				}
				else {
				}

			} while (iResult > 0);
		}
		catch (exception e) {
			Test.text = e.what();
			Test.text += " - �������";
			return;
		}
	}
	
	//! ������� �������� ��������� � ���
	void TheSender() {
		try {
			std::string str; //! str - ������, � ������� ������������ ��������� �� textBox
			str = SystemToStl(newMessage->Text);
			toSend.code = chatID;
			toSend.text = str;
			toSend.Send();
		}
		catch (...) {
			Test.text = "������ � sender";
			return;
		}
	}

	/*! \brief ������� ��� ������� �� ������ "����� ���"

	�������� ������ �����, ���������� ���� ��� ����� �������������, ������� ������ ���� � ����� ����.
	����� ������������ ������ ������ ����� ����� �������, ���������� ������ �� ������. ����� ����, ����� ������ ������,
	�������������� ��� �������� ������ ����, ���������. � ���� text ������ ������ ������������� �������� ��� ����������
	����. � ������ ��������� �������� ������������� �� ������ ������� ����� (� �����). �������� ������� ��� ������ ������
	������������� � ��������������� ����. ������� ���� � �������� ���������.
	���������� textBox ChatUsers � ��������� �� ������� ������
	*/
	private: System::Void NewChat_Click(System::Object^ sender, System::EventArgs^ e) {
		GetUsers();
		if (ChatUsers->Text->Length == 0 || ChatUsers->Text == newChatMsg) {
			ChatUsers->Text = newChatMsg;
			clearChatUsers = true;
		}
		else {
			newMessage->Text = "";
			NewChat.code = -10;
			vector<string> wrongUsers = checkChat(ChatUsers->Text);
			if (wrongUsers.size() > 0) {
				clearChatUsers = true;
				ChatUsers->Text = "������! ��� ������������ �� ����������:";
				ChatUsers->Text += "\r\n";
				for (auto user : wrongUsers) {
					ChatUsers->Text = ChatUsers->Text + gcnew System::String(user.c_str()) + "\r\n";
				}
				return;
			}
			NewChat.text = SystemToStl(ChatUsers->Text);
			NewChat.Send();
			while (NewChat.text == SystemToStl(ChatUsers->Text)) {
				label1->Text = ChatUsers->Text;
			}
			if (NewChat.text[0] >= '0' && NewChat.text[0] <= '9') {
				tabControl1->SelectedIndex = 1;
				chatID = stoi(NewChat.text);
				CUWithLines(ChatUsers->Text, 0);
				oldMessages->Text = "";
				//usersInChat->Text = ChatUsers->Text;
				//MsgCl GetStory(-20,id);
			}
			else {
				ChatUsers->Text = gcnew System::String(NewChat.text.c_str());
			}
		}
	}

/*! \brief ������� ��� �������� �����

� ��������� ���� ������������ ��� �������� ������������. � ���� ��� �������� ������ ���� ������������ ��������������
���������. ������������ ���� ��� ��� ������� �� �����. ����������� ����� ��� ����������� ������ ��������� �� �������.
����������� ������ ��� ��������� ����� ���������. ��� ������� ������� ������������ �������� ��������, ������� ����� �����
��� �������� �����.
*/
private: System::Void TheChatWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	Text = gcnew System::String(ourUser.c_str());
	clearChatUsers = true;
	ChatUsers->Text = newChatMsg;
	//������ ������, ��� ���� ���������� �����.
	ThreadStart^ thrStart = gcnew ThreadStart(this, &TheChatWindow::receiver);
	Thread^ t1 = gcnew Thread(thrStart);
	t1->IsBackground = true;
	t1->Start();
	//������ �������
	timer1->Start();
	timer2->Interval = 1000;
}

//! ������ ��� ����������� ��������� � ������� ���� � �������.
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {	
	if (CompWith != ToChange) {		
		oldMessages->Text += formatStr(oneMessage);
		CompWith = ToChange;
		if (TimeDo) {
			GetChats();
			TimeDo = false;
		}
	}
	
}

//! ��� ������� �� ������ ��������� ��������� �� 2 ������� ���������� ������� ��������
private: System::Void SendMessage_Click(System::Object^ sender, System::EventArgs^ e) {
	TheSender();
	newMessage->Text = "";
}

//! ��� ������� �� ������ ������ ����� ���������� ������� ��������� �����
private: System::Void OldChats_Click(System::Object^ sender, System::EventArgs^ e) {
	GetChats();
}

/*!  \brief ����� ���� �� ������

��� ������� ����� �� ��� � ������ ����� ������ ������� ����������� � ���� ����� � ������������ ������
�� ��������� ������� ��������� � ���� ���
*/
	private: System::Void ChatListBox_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		newMessage->Text = "";
		if (ChatListBox->SelectedIndex >= 0) {
			//������������ �� ������ �������
			tabControl1->SelectedIndex = 1;
			//! chatString - ������ �� ������ ������ ����� ��� ��������� �� ��� ���� � ������ �������������
			string chatString = SystemToStl(ChatListBox->SelectedItem->ToString());
			int position = 0; // ������� � ������ ��� ��������� � �� ����� ��� ������ substr
			while (chatString[position] != '(') {
				position++;
			}
			chatID = stoi(chatString.substr(0, position));
			while (chatString[position] != ')') {
				position++;
			}
			string TheChatUsers = chatString.substr(position + 1);
			//������� ������ ������������� �� ������� � �����
			CUWithLines(gcnew System::String(TheChatUsers.c_str()), 3);
			//��������� ������ �� ��������� ��������� ��� ����� ����
			GetMessages(to_string(chatID));
		}
}
//! �������� ����� ������� "�����". ���������� ������� ������ �� ����� � ���� �������, ����� ������ �����
private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e) {	
	toExit.Send();
	timer2->Start();
	//this->Close();
}
//! �������� �����. ���������� ������� ������ �� ����� � ���� �������, ����� ������ �����
private: System::Void TheChatWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {	
	toExit.Send();
	timer2->Start();
}
//! ����� �� ����. ���������� ������ ������� �� ����� �� ����. ��������� �� ������ �������. ������� ������� ��������� ����
private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedIndex = 0;
	MsgCl toExitChat(-30,to_string(chatID)); //! toExitChat - ��������� ������ ��� �������� ������� �� ����� �� ����
	toExitChat.Send();
	oldMessages->Text = "";
	newMessage->Text = "";
	GetChats();
}

//! ������ ��� �������� ����� �������. �����, ����� ��� ����������� �������� ������ �����������.
private: System::Void Timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (closeCounter == 1) {
		closeCounter = 0;		
		this->Close();
	}
	else closeCounter++;
}

/*! \brief ��������� ������ �������������.

��� ������� �� ������ �������� ��������������� �������. ������� ��������� �� ������������, ������� ������ ������,
����� ��� ���������. ������ ������ ������������ ����������� � ���������� �������
*/
private: System::Void UsersOnline_Click(System::Object^ sender, System::EventArgs^ e) {
	GetUsers();
}

//! ������� ���� ��� �������� ������ ���� �� �����, ���� ����� ���� ������������� �������
private: System::Void ChatUsers_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (clearChatUsers) ChatUsers->Text = "";
	clearChatUsers = false;
}

//! �������� ��� �������� � ������� ����
private: System::Void tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (tabControl1->SelectedIndex == 0) {
		ChatUsers->Text = newChatMsg;
		clearChatUsers = true;
	}
}
};
}
