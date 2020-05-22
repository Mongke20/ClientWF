#pragma once

/*!
\file
\brief Заголовочный файл с начальной формой программы

Данный файл содержит в себе описание стартовой формы чата, необходимой для ввода имени польователя и пароля
и подключения к серверу.
*/

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

/**
namespace ClientWinForms
@brief Пространство имен ClientWinForms
*/
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
	private: System::Windows::Forms::ToolTip^ toolTip1;
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
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
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
			this->ConnectionStatus->Location = System::Drawing::Point(29, 180);
			this->ConnectionStatus->Name = L"ConnectionStatus";
			this->ConnectionStatus->Size = System::Drawing::Size(176, 17);
			this->ConnectionStatus->TabIndex = 10;
			this->ConnectionStatus->Text = L"Состояние подключения:";
			// 
			// ConStatus
			// 
			this->ConStatus->AutoSize = true;
			this->ConStatus->Location = System::Drawing::Point(211, 180);
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
		//!Функция для перевода строки System::String в std::string
		string SystemToStl(String^ s){
			using namespace Runtime::InteropServices;
			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			string str = string(ptr);
			Marshal::FreeHGlobal(IntPtr((void*)ptr));
			return str;
		}

		SOCKET ConnectSocket = INVALID_SOCKET; //!< Переменная для хранения используемого сокета
		int iResult;
		int recvbuflen = DEFAULT_BUFLEN;

		/*! \brief Функция для отправки ника и пароля, введенных пользователем, на сервер для проверки

		Перед отправкой они соединяются в одну строку с использованием служебного символа "@"
		*/
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

		/*! \brief Функция проверки статуса, т.е. ответа сервера.

		"Подключено" - при успешном подключении
		"Неправильный пароль!" - если пароль введен неправильно
		"Такой пользователь уже подключен!" - если такой пользователь уже онлайн с другого устройства
		*/
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
		
		/*! \brief Функция для запуска чата.

		Запускает все необходимое для работы с сокетами. Подключается к серверу. Отправляет для проверки имя пользователя
		и пароль. В случае успешного подключения открывает новое окно. В случае провала выводит информационное сообщение
		и завершается
		*/
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
			//! StatusStr - Переменная для хранения ответа сервера на попытку подключения
			std::string StatusStr = CheckStatus(ConnectSocket);
			if (StatusStr != "Подключено\n") {
				label2->Visible = true;
				label2->Text = gcnew System::String(StatusStr.c_str());
				return;
			}
			
			ConStatus->Text = "Подключен";
			
			d1.TheSock = ConnectSocket;
			TheChatWindow^ dlg1 = gcnew TheChatWindow();
			dlg1->ShowDialog();			
		}
	
	//!При нажатиии кнопки "Подключиться" скрывает эту форму, вызывает функцию Chat(), а после ее завершения снова показывает форму
	private: System::Void ToConnect_Click(System::Object^ sender, System::EventArgs^ e) {
		bool correctFields = true;
		for (int i = 0; i < NickField->Text->Length; i++) {
			if ((NickField->Text[i] >= '0' && NickField->Text[i] <= '9') || (NickField->Text[i] >= 'a' && NickField->Text[i] <= 'z') ||
				(NickField->Text[i] >= 'A' && NickField->Text[i] <= 'Z')) continue;
			else {
				correctFields = false;
				break;
			}
		}
		if (correctFields) {
			for (int i = 0; i < PasswordField->Text->Length; i++)
				if ((PasswordField->Text[i] >= '0' && PasswordField->Text[i] <= '9') || (PasswordField->Text[i] >= 'a' && PasswordField->Text[i] <= 'z') ||
					(PasswordField->Text[i] >= 'A' && PasswordField->Text[i] <= 'Z')) continue;
				else {
					correctFields = false;
					break;
				}
		}
		if (!correctFields) {
			label2->Visible = true;
			label2->Text = "  Логин и пароль должны\nсодержать только A-Z/a-z и 0-9 символы";
		}
		else {
			label2->Visible = false;
			Hide();
			Chat();
			Show();
		}
		//shutdown(ConnectSocket, SD_SEND);
		//closesocket(ConnectSocket);
		//WSACleanup();
		//ToConnect->Enabled = false;
		//NickField->Enabled = false;
	}	
			  
};
}
