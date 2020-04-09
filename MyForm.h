#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <thread>
#include <string>
#include <dos.h>
#include <cstdlib>
#include <ctime>



// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
namespace ClientWinForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Threading;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ NickField;
	protected:
	private: System::Windows::Forms::Label^ LabelNick;
	private: System::Windows::Forms::Button^ ToConnect;
	private: System::Windows::Forms::TextBox^ SendMessage;
	private: System::Windows::Forms::TextBox^ GetMessage;
	private: System::Windows::Forms::Button^ ButtonSendMessage;
	private: System::Windows::Forms::Label^ LabelSendMessageStatus;
	private: System::Windows::Forms::Label^ LabelSendMessage;
	private: System::Windows::Forms::Label^ LabelGetMessage;
	private: System::Windows::Forms::Label^ LabelGetMessageStatus;
	private: System::Windows::Forms::Label^ ConnectionStatus;
	private: System::Windows::Forms::Label^ ConStatus;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

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
			this->NickField = (gcnew System::Windows::Forms::TextBox());
			this->LabelNick = (gcnew System::Windows::Forms::Label());
			this->ToConnect = (gcnew System::Windows::Forms::Button());
			this->SendMessage = (gcnew System::Windows::Forms::TextBox());
			this->GetMessage = (gcnew System::Windows::Forms::TextBox());
			this->ButtonSendMessage = (gcnew System::Windows::Forms::Button());
			this->LabelSendMessageStatus = (gcnew System::Windows::Forms::Label());
			this->LabelSendMessage = (gcnew System::Windows::Forms::Label());
			this->LabelGetMessage = (gcnew System::Windows::Forms::Label());
			this->LabelGetMessageStatus = (gcnew System::Windows::Forms::Label());
			this->ConnectionStatus = (gcnew System::Windows::Forms::Label());
			this->ConStatus = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// NickField
			// 
			this->NickField->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->NickField->Location = System::Drawing::Point(144, 32);
			this->NickField->Name = L"NickField";
			this->NickField->Size = System::Drawing::Size(100, 22);
			this->NickField->TabIndex = 0;
			// 
			// LabelNick
			// 
			this->LabelNick->AutoSize = true;
			this->LabelNick->Location = System::Drawing::Point(44, 35);
			this->LabelNick->Name = L"LabelNick";
			this->LabelNick->Size = System::Drawing::Size(94, 17);
			this->LabelNick->TabIndex = 1;
			this->LabelNick->Text = L"Введите ник:";
			// 
			// ToConnect
			// 
			this->ToConnect->Location = System::Drawing::Point(250, 28);
			this->ToConnect->Name = L"ToConnect";
			this->ToConnect->Size = System::Drawing::Size(134, 31);
			this->ToConnect->TabIndex = 2;
			this->ToConnect->Text = L"Подключиться";
			this->ToConnect->UseVisualStyleBackColor = true;
			this->ToConnect->Click += gcnew System::EventHandler(this, &MyForm::ToConnect_Click);
			// 
			// SendMessage
			// 
			this->SendMessage->Location = System::Drawing::Point(27, 143);
			this->SendMessage->Multiline = true;
			this->SendMessage->Name = L"SendMessage";
			this->SendMessage->Size = System::Drawing::Size(278, 91);
			this->SendMessage->TabIndex = 3;
			// 
			// GetMessage
			// 
			this->GetMessage->Location = System::Drawing::Point(524, 125);
			this->GetMessage->Multiline = true;
			this->GetMessage->Name = L"GetMessage";
			this->GetMessage->Size = System::Drawing::Size(326, 129);
			this->GetMessage->TabIndex = 4;
			// 
			// ButtonSendMessage
			// 
			this->ButtonSendMessage->Location = System::Drawing::Point(311, 168);
			this->ButtonSendMessage->Name = L"ButtonSendMessage";
			this->ButtonSendMessage->Size = System::Drawing::Size(118, 31);
			this->ButtonSendMessage->TabIndex = 5;
			this->ButtonSendMessage->Text = L"Отправить";
			this->ButtonSendMessage->UseVisualStyleBackColor = true;
			this->ButtonSendMessage->Click += gcnew System::EventHandler(this, &MyForm::ButtonSendMessage_Click);
			// 
			// LabelSendMessageStatus
			// 
			this->LabelSendMessageStatus->AutoSize = true;
			this->LabelSendMessageStatus->Location = System::Drawing::Point(117, 237);
			this->LabelSendMessageStatus->Name = L"LabelSendMessageStatus";
			this->LabelSendMessageStatus->Size = System::Drawing::Size(53, 17);
			this->LabelSendMessageStatus->TabIndex = 6;
			this->LabelSendMessageStatus->Text = L"Статус";
			// 
			// LabelSendMessage
			// 
			this->LabelSendMessage->AutoSize = true;
			this->LabelSendMessage->Location = System::Drawing::Point(78, 123);
			this->LabelSendMessage->Name = L"LabelSendMessage";
			this->LabelSendMessage->Size = System::Drawing::Size(145, 17);
			this->LabelSendMessage->TabIndex = 7;
			this->LabelSendMessage->Text = L"Введите сообщение:";
			// 
			// LabelGetMessage
			// 
			this->LabelGetMessage->AutoSize = true;
			this->LabelGetMessage->Location = System::Drawing::Point(605, 105);
			this->LabelGetMessage->Name = L"LabelGetMessage";
			this->LabelGetMessage->Size = System::Drawing::Size(173, 17);
			this->LabelGetMessage->TabIndex = 8;
			this->LabelGetMessage->Text = L"Полученные сообщения:";
			// 
			// LabelGetMessageStatus
			// 
			this->LabelGetMessageStatus->AutoSize = true;
			this->LabelGetMessageStatus->Location = System::Drawing::Point(668, 257);
			this->LabelGetMessageStatus->Name = L"LabelGetMessageStatus";
			this->LabelGetMessageStatus->Size = System::Drawing::Size(53, 17);
			this->LabelGetMessageStatus->TabIndex = 9;
			this->LabelGetMessageStatus->Text = L"Статус";
			// 
			// ConnectionStatus
			// 
			this->ConnectionStatus->AutoSize = true;
			this->ConnectionStatus->Location = System::Drawing::Point(12, 366);
			this->ConnectionStatus->Name = L"ConnectionStatus";
			this->ConnectionStatus->Size = System::Drawing::Size(176, 17);
			this->ConnectionStatus->TabIndex = 10;
			this->ConnectionStatus->Text = L"Состояние подключения:";
			// 
			// ConStatus
			// 
			this->ConStatus->AutoSize = true;
			this->ConStatus->Location = System::Drawing::Point(194, 366);
			this->ConStatus->Name = L"ConStatus";
			this->ConStatus->Size = System::Drawing::Size(75, 17);
			this->ConStatus->TabIndex = 11;
			this->ConStatus->Text = L"Отключен";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::Timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(893, 392);
			this->Controls->Add(this->ConStatus);
			this->Controls->Add(this->ConnectionStatus);
			this->Controls->Add(this->LabelGetMessageStatus);
			this->Controls->Add(this->LabelGetMessage);
			this->Controls->Add(this->LabelSendMessage);
			this->Controls->Add(this->LabelSendMessageStatus);
			this->Controls->Add(this->ButtonSendMessage);
			this->Controls->Add(this->GetMessage);
			this->Controls->Add(this->SendMessage);
			this->Controls->Add(this->ToConnect);
			this->Controls->Add(this->LabelNick);
			this->Controls->Add(this->NickField);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Функция для перевода строки этой штуки в нормальную строку
		string SystemToStl(String^ s){
			using namespace Runtime::InteropServices;
			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			return string(ptr);
		}
		//Cтроки для обновления текстбокса с полученными сообщениями
		String^ ToChange;
		String^ CompWith;
		//Используемый сокет
		SOCKET ConnectSocket = INVALID_SOCKET;
		int iResult;
		int recvbuflen = DEFAULT_BUFLEN;
		void EnterName(SOCKET ConSock) {
			std::string username = SystemToStl(NickField->Text);
			int name_size = username.size() + 1;
			// Отправка имени серверу
			iResult = send(ConSock, (char*)& name_size, sizeof(int), 0);
			if (iResult == SOCKET_ERROR) {
				NickField->Text = "Ошибка";
				NickField->ForeColor = Color::Red;
				closesocket(ConSock);
				WSACleanup();
				return;
			}
			iResult = send(ConSock, username.c_str(), name_size, 0);
			return;
		}

		//Функция проверки статуса
		std::string CheckStatus(SOCKET ConSock) {
			int StatusSize;
			iResult = recv(ConSock, (char*)& StatusSize, sizeof(int), 0);
			char* Status = new char[StatusSize + 1];
			Status[StatusSize] = '\0';
			iResult = recv(ConSock, Status, StatusSize, 0);
			std::string StatusStr = Status;
			delete[]Status;
			return StatusStr;
		}
		void receiver() {	
			try {
				int msg_size;
				int name_size;
				int iResult = 0;
				do {
					// Получение имени отправителя
					recv(ConnectSocket, (char*)& name_size, sizeof(int), 0);
					char* name = new char[name_size + 2];
					iResult = recv(ConnectSocket, name, name_size, 0);
					name[name_size] = '\n';
					name[name_size + 1] = '\0';
					// Получение сообщения
					recv(ConnectSocket, (char*)& msg_size, sizeof(int), 0);
					char* answer = new char[msg_size + 2];
					iResult = recv(ConnectSocket, answer, msg_size, 0);
					answer[msg_size] = '\n';
					answer[msg_size + 1] = '\0';
					if (iResult > 0) {
						std::string Got_Msg = answer;
						std::string Got_Nm = name;
						Got_Msg = "from " + Got_Nm + " msg " + Got_Msg;
						ToChange = gcnew System::String(Got_Msg.c_str());

					}
					else if (iResult == 0)
						ConStatus->Text = "Отключен";
					else ConStatus->Text = "Error";
						delete[] answer;
				} while (iResult > 0);
			}
			catch (...) {
				ConStatus->Text = "Server unable" ;
				return;
			}
		}
		void TheSender() {
			try {
				std::string str;
				int target_size;
				int msg_size;
				std::string mark0, mark1, target_name, msg;
				// Ввод сообщения и разделение его на ник получателя, сообщение и слова-маркеры
				str = SystemToStl(SendMessage->Text);
				std::stringstream ss(str);
				ss >> mark0;
				ss >> target_name;
				ss >> mark1;
				//Для пропуска одного смвола после слова msg (ПРОБЕЛА)
				ss.ignore(1);
				std::getline(ss, msg);
				while (mark0 != "to" || mark1 != "msg") {					
					SendMessage->Text = "Формат ввода для отправки сообщений: \n to NAME msg MESSAGE";
					str = SystemToStl(SendMessage->Text);
					std::stringstream ss(str);
					ss >> mark0;
					ss >> target_name;
					ss >> mark1;
					ss.ignore(1);
					std::getline(ss, msg);
				}
				target_name;
				msg;
				target_size = target_name.size() + 1;
				msg_size = msg.size() + 1;
				send(ConnectSocket, (char*)& target_size, sizeof(int), 0);
				send(ConnectSocket, target_name.c_str(), target_size, 0);
				send(ConnectSocket, (char*)& msg_size, sizeof(int), 0);
				iResult = send(ConnectSocket, msg.c_str(), msg_size, 0);

				if (iResult > 0) {
					LabelSendMessageStatus->Text = "Сообщение отправлено";
				}
				else if (iResult == 0)
					LabelSendMessageStatus->Text = "Connection closed\n";
				else
					LabelSendMessageStatus->Text = "send failed with error: %d\n";

			}
			catch (...) {
				LabelSendMessageStatus->Text = "Server unable";
				ConStatus->Text = "Отключен";
				return;
			}
		}
		void Chat() {
			SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
			SetConsoleOutputCP(1251);
			setlocale(LC_ALL, "Russian");
			WSADATA wsaData;
			struct addrinfo* result = NULL,
				* ptr = NULL,
				hints;
			char recvbuf[DEFAULT_BUFLEN];
			iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
			ZeroMemory(&hints, sizeof(hints));
			hints.ai_family = AF_UNSPEC;
			hints.ai_socktype = SOCK_STREAM;
			hints.ai_protocol = IPPROTO_TCP;
			// Resolve the server address and port
			//185.255.135.230
			//192.168.0.11
			iResult = getaddrinfo("192.168.0.11", DEFAULT_PORT, &hints, &result);
			if (iResult != 0) {
				NickField->ForeColor = Color::Red;
				NickField->Text = "ERROR";				
				WSACleanup();
				return;
			}

			// Attempt to connect to an address until one succeeds
			for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
				// Create a SOCKET for connecting to server
				ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
					ptr->ai_protocol);
				if (ConnectSocket == INVALID_SOCKET) {
					printf("socket failed with error: %ld\n", WSAGetLastError());
					WSACleanup();
					return;
				}

				// Connect to server.
				iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
				if (iResult == SOCKET_ERROR) {
					closesocket(ConnectSocket);
					ConnectSocket = INVALID_SOCKET;
					continue;
				}
				break;
			}
			freeaddrinfo(result);

			if (ConnectSocket == INVALID_SOCKET) {
				printf("Unable to connect to server!\n");
				WSACleanup();
				return;
			}


			//идентификация клиента
			EnterName(ConnectSocket);
			std::string StatusStr = CheckStatus(ConnectSocket);			
			//Проверка на уникальность сессии ника
			while (StatusStr == "Wrong name") {
				NickField->Text = gcnew System::String(StatusStr.c_str());
				EnterName(ConnectSocket);
				StatusStr = CheckStatus(ConnectSocket);
			}
			ConStatus->Text = "Подключен";
			int msg_size;
			iResult = recv(ConnectSocket, (char*)& msg_size, sizeof(int), 0);
			char* welcome = new char[msg_size + 1];
			iResult = recv(ConnectSocket, welcome, msg_size, 0);
			welcome[msg_size] = '\0';
			string WeclomeMsg = welcome;
			if (iResult > 0) {
				GetMessage->Text = gcnew System::String(WeclomeMsg.c_str()) + "\r\n";
			}
			ThreadStart^ thrStart = gcnew ThreadStart(this, &MyForm::receiver);
			Thread^ t1 = gcnew Thread(thrStart);
			t1->IsBackground = true;
			t1->Start();
			timer1->Start();
			/*
			MyClass^ mcl = gcnew MyClass;
			mcl->ConnectSocket = ConnectSocket;
			ThreadStart^ thrStart = gcnew ThreadStart(mcl,&MyClass::receiver);
			Thread^ t1 = gcnew Thread(thrStart);
			t1->IsBackground = true;
			t1->Start();*/
			/*
			MyClass^ mcl = gcnew MyClass;
			mcl->ConnectSocket = ConnectSocket;
			Thread^ t = gcnew Thread(gcnew ThreadStart(mcl, &MyClass::receiver));
			t->Start();*/
			/*
			// Отдельный тред с получением сообщений

			//CreateThread(NULL, NULL, &receiver, NULL, NULL, NULL);


			//Thread^ myThread = gcnew Thread((this->receiver));
			/myThread->Start();
			receiver();



			// shutdown the connection since no more data will be sent
			iResult = shutdown(ConnectSocket, SD_SEND);
			if (iResult == SOCKET_ERROR) {
				closesocket(ConnectSocket);
				WSACleanup();
				return;
			}

			// cleanup
			closesocket(ConnectSocket);
			WSACleanup();
			*/
		}
	private: System::Void ToConnect_Click(System::Object^ sender, System::EventArgs^ e) {
		Chat();
		ToConnect->Enabled = false;
		NickField->Enabled = false;
	}
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (CompWith != ToChange) {
		GetMessage->Text += ToChange + "\r\n";
		CompWith = ToChange;
	}
}
private: System::Void ButtonSendMessage_Click(System::Object^ sender, System::EventArgs^ e) {
	TheSender();
}
};
}
