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
	/// Сводка для TheChatWindow
	/// </summary>
	public ref class TheChatWindow : public System::Windows::Forms::Form
	{
	public:
		TheChatWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	protected:

















	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->sendMessage->Text = L"Отправить";
			this->sendMessage->UseVisualStyleBackColor = true;
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(426, 227);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			this->label1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TheChatWindow::Label1_MouseClick);
			// 
			// ChatUsers
			// 
			this->ChatUsers->AcceptsTab = true;
			this->ChatUsers->Location = System::Drawing::Point(199, 6);
			this->ChatUsers->Multiline = true;
			this->ChatUsers->Name = L"ChatUsers";
			this->ChatUsers->Size = System::Drawing::Size(208, 88);
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
			this->exit->Text = L"Выход";
			this->exit->UseVisualStyleBackColor = true;
			// 
			// usersOnline
			// 
			this->usersOnline->Location = System::Drawing::Point(25, 230);
			this->usersOnline->Name = L"usersOnline";
			this->usersOnline->Size = System::Drawing::Size(110, 40);
			this->usersOnline->TabIndex = 2;
			this->usersOnline->Text = L"Онлайн";
			this->usersOnline->UseVisualStyleBackColor = true;
			// 
			// oldChats
			// 
			this->oldChats->Location = System::Drawing::Point(25, 135);
			this->oldChats->Name = L"oldChats";
			this->oldChats->Size = System::Drawing::Size(110, 40);
			this->oldChats->TabIndex = 1;
			this->oldChats->Text = L"Список чатов";
			this->oldChats->UseVisualStyleBackColor = true;
			// 
			// newChat
			// 
			this->newChat->Location = System::Drawing::Point(25, 40);
			this->newChat->Name = L"newChat";
			this->newChat->Size = System::Drawing::Size(110, 40);
			this->newChat->TabIndex = 0;
			this->newChat->Text = L"Новый чат";
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
		// Код = -10 : создать новый чат						//
		// Код = -20 : Получить последние 10 сообщений в чате	//
		//														//
		//														//
		// Код = -100: Отобразить список чатов					//
		//														//
		//														//
		//														//
		//														//
		//														//
		// Код = -1000 Отобразить пользователей онлайн			//
		//														//
		//														//
		//														//
		//														//
		//////////////////////////////////////////////////////////
	String^ ToChange;
	String^ CompWith;
	int chatSend;
	string SystemToStl(String^ s) {
		using namespace Runtime::InteropServices;
		const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		return string(ptr);
	}
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
	void receiver() {
		try {
			int msg_size;
			int name_size;
			int iResult = 0;
			do {
				// Получение имени отправителя
				recv(d1.TheSock, (char*)& name_size, sizeof(int), 0);
				char* name = new char[name_size + 2];
				iResult = recv(d1.TheSock, name, name_size, 0);
				name[name_size] = '\n';
				name[name_size + 1] = '\0';
				// Получение сообщения
				recv(d1.TheSock, (char*)& msg_size, sizeof(int), 0);
				char* answer = new char[msg_size + 2];
				iResult = recv(d1.TheSock, answer, msg_size, 0);
				answer[msg_size] = '\n';
				answer[msg_size + 1] = '\0';
				if (iResult > 0) {
					std::string Got_Msg = answer;
					std::string Got_Nm = name;
					Got_Msg = "from " + Got_Nm + " msg " + Got_Msg;
					ToChange = gcnew System::String(Got_Msg.c_str());

				}
				else if (iResult == 0) {
				}
				else {
					//ConStatus->Text = "Error";
				}
				delete[] answer;
			} while (iResult > 0);
		}
		catch (...) {
			//ConStatus->Text = "Server unable";
			return;
		}
	}
	void TheSender() {
		try {
			std::string str;
			// Ввод сообщения и разделение его на ник получателя, сообщение и слова-маркеры
			str = SystemToStl(newMessage->Text);
			MsgCl(chatSend, str);
		}
		catch (...) {
			return;
		}
	}
	private: System::Void NewChat_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ChatUsers->Text->Length == 0 || ChatUsers->Text=="Введите пользователей") {
			ChatUsers->Text = "Введите пользователей";
		}
		else {
			MsgCl NewChat(-10, SystemToStl(ChatUsers->Text));
			NewChat.Send();
			string id = GetMessage();
			if (id[0] >= '0' && id[0] <= '9') {
				tabControl1->SelectedIndex = 1;
				chatSend = stoi(id);
				usersInChat->Text = ChatUsers->Text;
				//MsgCl GetStory(-20,id);
				
			}
			else ChatUsers->Text = gcnew System::String(id.c_str());
		}
	}
private: System::Void Label1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	label1->Text = "clicked";
}
private: System::Void TheChatWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	/*MsgCl getChats(-100, "");
	MsgCl getUsers(-1000, "");
	getChats.Send();
	getUsers.Send();*/
	/*ThreadStart^ thrStart = gcnew ThreadStart(this, &TheChatWindow::receiver);
	Thread^ t1 = gcnew Thread(thrStart);
	t1->IsBackground = true;
	t1->Start();*/
}
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (CompWith != ToChange) {
		oldMessages->Text += ToChange + "\r\n";
		CompWith = ToChange;
	}
	
}
};
}
