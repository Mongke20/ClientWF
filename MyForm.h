#pragma once
#define WIN32_LEAN_AND_MEAN
#include "ClientClasses.h"
#include "TheChatWindow.h"
/*
#include <winsock2.h>
#include <ws2tcpip.h>
*/
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <thread>
#include <dos.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>




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







	private: System::Windows::Forms::Label^ ConnectionStatus;
	private: System::Windows::Forms::Label^ ConStatus;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ PasswordField;
	private: System::Windows::Forms::Label^ label2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->NickField = (gcnew System::Windows::Forms::TextBox());
			this->LabelNick = (gcnew System::Windows::Forms::Label());
			this->ToConnect = (gcnew System::Windows::Forms::Button());
			this->ConnectionStatus = (gcnew System::Windows::Forms::Label());
			this->ConStatus = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PasswordField = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// NickField
			// 
			this->NickField->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->NickField->Location = System::Drawing::Point(105, 22);
			this->NickField->Name = L"NickField";
			this->NickField->Size = System::Drawing::Size(100, 22);
			this->NickField->TabIndex = 0;
			// 
			// LabelNick
			// 
			this->LabelNick->AutoSize = true;
			this->LabelNick->Location = System::Drawing::Point(48, 25);
			this->LabelNick->Name = L"LabelNick";
			this->LabelNick->Size = System::Drawing::Size(51, 17);
			this->LabelNick->TabIndex = 1;
			this->LabelNick->Text = L"Логин:";
			// 
			// ToConnect
			// 
			this->ToConnect->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ToConnect->Location = System::Drawing::Point(80, 97);
			this->ToConnect->Name = L"ToConnect";
			this->ToConnect->Size = System::Drawing::Size(131, 34);
			this->ToConnect->TabIndex = 2;
			this->ToConnect->Text = L"Подключиться";
			this->ToConnect->UseVisualStyleBackColor = true;
			this->ToConnect->Click += gcnew System::EventHandler(this, &MyForm::ToConnect_Click);
			// 
			// ConnectionStatus
			// 
			this->ConnectionStatus->AutoSize = true;
			this->ConnectionStatus->Location = System::Drawing::Point(28, 175);
			this->ConnectionStatus->Name = L"ConnectionStatus";
			this->ConnectionStatus->Size = System::Drawing::Size(176, 17);
			this->ConnectionStatus->TabIndex = 10;
			this->ConnectionStatus->Text = L"Состояние подключения:";
			// 
			// ConStatus
			// 
			this->ConStatus->AutoSize = true;
			this->ConStatus->Location = System::Drawing::Point(210, 175);
			this->ConStatus->Name = L"ConStatus";
			this->ConStatus->Size = System::Drawing::Size(75, 17);
			this->ConStatus->TabIndex = 11;
			this->ConStatus->Text = L"Отключен";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 17);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Пароль:";
			// 
			// PasswordField
			// 
			this->PasswordField->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->PasswordField->Location = System::Drawing::Point(105, 60);
			this->PasswordField->Name = L"PasswordField";
			this->PasswordField->PasswordChar = '*';
			this->PasswordField->Size = System::Drawing::Size(100, 22);
			this->PasswordField->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 145);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 17);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Отключен";
			this->label2->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(313, 215);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->PasswordField);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ConStatus);
			this->Controls->Add(this->ConnectionStatus);
			this->Controls->Add(this->ToConnect);
			this->Controls->Add(this->LabelNick);
			this->Controls->Add(this->NickField);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Вход";
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
		//Используемый сокет
		SOCKET ConnectSocket = INVALID_SOCKET;
		int iResult;
		int recvbuflen = DEFAULT_BUFLEN;
		void EnterName(SOCKET ConSock) {
			std::string username = SystemToStl(NickField->Text);
			ourUser = username;
			username += "@";
			username += SystemToStl(PasswordField->Text);
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
		
		/*void receiver() {	
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
		}*/
		
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
			//46.17.104.142
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
			if (StatusStr != "Подключено\n") {
				label2->Visible = true;
				label2->Text = gcnew System::String(StatusStr.c_str());
				return;
			}
			//Проверка на уникальность сессии ника
			/*while (StatusStr == "Wrong name") {
				NickField->Text = gcnew System::String(StatusStr.c_str());
				EnterName(ConnectSocket);
				StatusStr = CheckStatus(ConnectSocket);
			}*/
			ConStatus->Text = "Подключен";
			
			d1.TheSock = ConnectSocket;
			TheChatWindow^ dlg1 = gcnew TheChatWindow();
			dlg1->ShowDialog();
			
			/*ThreadStart^ thrStart = gcnew ThreadStart(this, &MyForm::receiver);
			Thread^ t1 = gcnew Thread(thrStart);
			t1->IsBackground = true;
			t1->Start();
			timer1->Start();*/
			
		}
		
	private: System::Void ToConnect_Click(System::Object^ sender, System::EventArgs^ e) {
		label2->Visible = false;
		Hide();
		Chat();
		Show();
		//shutdown(ConnectSocket, SD_SEND);
		//closesocket(ConnectSocket);
		//WSACleanup();
		//ToConnect->Enabled = false;
		//NickField->Enabled = false;
	}	
			  
};
}
