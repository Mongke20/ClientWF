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

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ ChatListBox;
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ListBox^ UserList;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TheChatWindow::typeid));
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->usersInChat = (gcnew System::Windows::Forms::TextBox());
			this->oldMessages = (gcnew System::Windows::Forms::TextBox());
			this->newMessage = (gcnew System::Windows::Forms::TextBox());
			this->sendMessage = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->UserList = (gcnew System::Windows::Forms::ListBox());
			this->ChatListBox = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ChatUsers = (gcnew System::Windows::Forms::TextBox());
			this->infoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->usersOnline = (gcnew System::Windows::Forms::Button());
			this->oldChats = (gcnew System::Windows::Forms::Button());
			this->newChat = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabPage2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->exitButton);
			this->tabPage2->Controls->Add(this->usersInChat);
			this->tabPage2->Controls->Add(this->oldMessages);
			this->tabPage2->Controls->Add(this->newMessage);
			this->tabPage2->Controls->Add(this->sendMessage);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(712, 403);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Chat";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(539, 329);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::Color::Salmon;
			this->exitButton->Location = System::Drawing::Point(596, 264);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(105, 50);
			this->exitButton->TabIndex = 4;
			this->exitButton->Text = L"Выйти из чата";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &TheChatWindow::ExitButton_Click);
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
			this->sendMessage->BackColor = System::Drawing::Color::LightGreen;
			this->sendMessage->Location = System::Drawing::Point(596, 327);
			this->sendMessage->Name = L"sendMessage";
			this->sendMessage->Size = System::Drawing::Size(106, 65);
			this->sendMessage->TabIndex = 2;
			this->sendMessage->Text = L"Отправить";
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
			this->tabControl1->Size = System::Drawing::Size(720, 432);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->UserList);
			this->tabPage1->Controls->Add(this->ChatListBox);
			this->tabPage1->Controls->Add(this->label2);
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
			// UserList
			// 
			this->UserList->ColumnWidth = 50;
			this->UserList->ForeColor = System::Drawing::Color::Black;
			this->UserList->FormattingEnabled = true;
			this->UserList->ItemHeight = 16;
			this->UserList->Location = System::Drawing::Point(160, 201);
			this->UserList->MultiColumn = true;
			this->UserList->Name = L"UserList";
			this->UserList->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
			this->UserList->Size = System::Drawing::Size(268, 180);
			this->UserList->TabIndex = 11;
			// 
			// ChatListBox
			// 
			this->ChatListBox->FormattingEnabled = true;
			this->ChatListBox->ItemHeight = 16;
			this->ChatListBox->Location = System::Drawing::Point(160, 6);
			this->ChatListBox->Name = L"ChatListBox";
			this->ChatListBox->Size = System::Drawing::Size(552, 180);
			this->ChatListBox->TabIndex = 10;
			this->ChatListBox->DoubleClick += gcnew System::EventHandler(this, &TheChatWindow::ChatListBox_DoubleClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 378);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"label2";
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
			this->ChatUsers->Location = System::Drawing::Point(428, 201);
			this->ChatUsers->Multiline = true;
			this->ChatUsers->Name = L"ChatUsers";
			this->ChatUsers->Size = System::Drawing::Size(281, 180);
			this->ChatUsers->TabIndex = 5;
			// 
			// infoTextBox
			// 
			this->infoTextBox->Enabled = false;
			this->infoTextBox->Location = System::Drawing::Point(160, 6);
			this->infoTextBox->Multiline = true;
			this->infoTextBox->Name = L"infoTextBox";
			this->infoTextBox->ReadOnly = true;
			this->infoTextBox->Size = System::Drawing::Size(549, 375);
			this->infoTextBox->TabIndex = 4;
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(11, 318);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(124, 47);
			this->exit->TabIndex = 3;
			this->exit->Text = L"Выход";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &TheChatWindow::Exit_Click);
			// 
			// usersOnline
			// 
			this->usersOnline->Location = System::Drawing::Point(11, 223);
			this->usersOnline->Name = L"usersOnline";
			this->usersOnline->Size = System::Drawing::Size(124, 53);
			this->usersOnline->TabIndex = 2;
			this->usersOnline->Text = L"Список\nпользователей";
			this->usersOnline->UseVisualStyleBackColor = true;
			this->usersOnline->Click += gcnew System::EventHandler(this, &TheChatWindow::UsersOnline_Click);
			// 
			// oldChats
			// 
			this->oldChats->Location = System::Drawing::Point(11, 131);
			this->oldChats->Name = L"oldChats";
			this->oldChats->Size = System::Drawing::Size(124, 48);
			this->oldChats->TabIndex = 1;
			this->oldChats->Text = L"Список чатов";
			this->oldChats->UseVisualStyleBackColor = true;
			this->oldChats->Click += gcnew System::EventHandler(this, &TheChatWindow::OldChats_Click);
			// 
			// newChat
			// 
			this->newChat->Location = System::Drawing::Point(11, 38);
			this->newChat->Name = L"newChat";
			this->newChat->Size = System::Drawing::Size(124, 50);
			this->newChat->TabIndex = 0;
			this->newChat->Text = L"Новый чат";
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
			this->ClientSize = System::Drawing::Size(720, 432);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
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
		// Код = -10 : создать новый чат						//
		// Код = -20 : Получить последние 10 сообщений в чате	//
		// Код = -30 : выход из чата							//
		// Код = -40 : Выход из приложения						//
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
	//Количество пользователей онлайн
		int UsersCount = 0;
	//! Строка, в которую записывается текст только что полученного сообщения
	String^ ToChange;
	/*! Строка, в которой хранится текст последнего полученного и обработанного сообщения.
	В таймере она сравнивается со строкой ToChange, и если она изменилась, это значит, что полученно новое сообщение
	*/
	String^ CompWith;
	//! Счетчик секунд для паузы перед закрытием формы
	int closeCounter = 0;
	//! Переменная для хранения кода открытого чата
	int chatID = 0;
	//! Вспомогательная переменная для получения чатов и сообщений
	int getCounter = 0;
	//! Переменная для отладки
	int CurID = 0;
	bool TimeDo = false;

	//!Функция для перевода строки System::String в std::string
	string SystemToStl(String^ s) {
		using namespace Runtime::InteropServices;
		const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		string str = string(ptr);
		Marshal::FreeHGlobal(IntPtr((void*)ptr));
		return str;
	}

	/*! \brief Функция для получения списка чатов
	Формирует запрос и отправляет его на сервер. После того, как в другом потоке сообщения от сервера получены, обработаны
	и вставленны в вектор, эта функция заполняет ListBox по одному чату в каждый пункт. Затем и вектор, и экземпляр класса
	для пересылки запросов очищаются.
	*/
	void GetChats() {
		ChatListBox->Items->Clear();
		getCl.code = -100;
		getCl.text = " ";
		getCl.Send();
		while (getCounter !=-1) {
			label2->Text = "Что-то есть " + Convert::ToString(getCounter);
		};
		
		for (auto i : ChatListVector) {
			ChatListBox->Items->Add(gcnew System::String(i.c_str()));
		}
		ChatListVector.clear();
		getCounter = 0;
		getCl.text = " ";
	}

	/*! Переносит список пользователей в чате (строка, полученная в первом аргументе) во вкладку с чатом.
	Второй аргумент нужен для обрезки непечатных символов в конце строки, если это необходимо
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

	/*! \brief Функция для получения списка пользователей
	Формирует запрос и отправляет его на сервер. После того, как в другом потоке сообщения от сервера получены, обработаны
	и вставленны в вектор, эта функция заполняет ListBox по одному пользователю в каждый пункт. Затем и вектор, и экземпляр
	класса для пересылки запросов очищаются.
	*/
	void GetUsers() {
		UserList->Items->Clear();
		getCl.code = -1000;
		getCl.text = " ";
		getCl.Send();
		while (getCounter != -1) {
			label2->Text = "Что-то есть " + Convert::ToString(getCounter);
		};
		for (auto user : userListVector) {
			if (UserList->Items->Count == UsersCount) UserList->Items->Add("|______|");
			UserList->Items->Add(gcnew System::String(user.c_str()));
		}
		userListVector.clear();
		getCounter = 0;
		getCl.text = " ";
		UserList->SelectionMode = SelectionMode::None;
	}

	/*! \brief Функция для получения не более, чем 40 сообщений в открытый чат
	Формирует запрос и отправляет его на сервер. После того, как в другом потоке сообщения от сервера получены, обработаны
	и вставленны в вектор, эта функция переносит их из вектора в textBox. Затем и вектор, и экземпляр класса для пересылки
	запросов очищаются.
	*/
	void GetMessages(string ChatIDStr) {
		oldMessages->Text = " ";
		getCl.code = -20;
		getCl.text = ChatIDStr;
		getCl.Send();
		while (getCounter != -1) {
			label2->Text = "Что-то есть " + Convert::ToString(getCounter);
		};
		for (auto msg : OldMessageVector) {
			oldMessages->Text += formatStr(msg);
		}
		OldMessageVector.clear();
		getCounter = 0;
		getCl.text = " ";
	}

	//! Функция для получения сообщения. Разбивает строку на поля по служебному символу "@". Возвращает вектор строк
	vector<string> GetMessage(string text) {
		vector<string> result;
		try {
			int position = 0;
			int oldpoz = position;
			//Первая часть - это отправитель
			while (position < text.length() && text[position] != '@') {
				position++;
			}
			string PersonFrom = text.substr(oldpoz, position - oldpoz);
			result.push_back(PersonFrom);
			position++;
			oldpoz = position;
			//Вторая часть - это дата
			while (position < text.length() && text[position] != '@') {
				position++;
			}
			string DateFrom = text.substr(oldpoz, position - oldpoz);
			result.push_back(DateFrom);
			position++;
			//Третья часть - это время вместе с самим сообщением
			string timeMessage = text.substr(position);
			result.push_back(timeMessage);
		}
		catch (exception e) {
			Test.text = e.what();
			system("pause");
		}
		return result;
	}

	/*! Функция для отладки. Выводит текущее время.
	Нужна для отслеживания времени, которое требуется программе для выполнения тех или иных действий, в том числе
	взаимодействия с сервером
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

	//!Приводит сообщение (вектор) к форматированному виду (строка)
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

	/*! \brief Функция для получения всех сообщений от сервера и их идентификации
	В бесконечном цикле получает сообщения от сервера при помощи сокетов. Разбивает их на код и текст. В зависимости
	от кода, размещает текст полученных сообщений в соответствующих векторах. Меняет переменную getCounter, чтобы сообщить
	функциям в другом потоке, что все сообщения по данному запросу полученны.
	Из-за работы в режиме нескольких потоков недопустимо обращаться в этой функции к элементам формы,
	так как они были созданы в базовом потоке.
	*/
	void receiver() {
		try {
			Test.code++;
			int iResult = 0;
			do {
				int msgS = 0;
				recv(d1.TheSock, (char*)& msgS, sizeof(int), 0);
				char* msg = new char[msgS + 2]; //! Переменная для получения очередного сообщения от сервера
				iResult = recv(d1.TheSock, msg, msgS, 0);
				msg[msgS] = '\n';
				msg[msgS + 1] = '\0';
				string msgStr = msg; //! Переменная типа string для дальнейшей работы с сообщением
				delete[]msg;
				if (iResult > 0) {
					int position = 0; //! Позиция в строке при разбиении ее на код и текст
					while (position < msgStr.length() && msgStr[position] != '@') {
						position++;
					}
					int code = stoi(msgStr.substr(0, position)); //! Код полученного сообщения
					CurID = code;
					string text = msgStr.substr(position + 1); //! Текст полученного сообщения
					//! Получение ответа на создание нового чата
					if (code == -10) {
						chatID = stoi(text);
						NewChat.code = code;
						NewChat.text = text;
					}
					//! Получение списка доступных чатов
					else if (code == -100) {						
						if (getCounter == 0) {
							getCounter = stoi(text);
							tempChats = Chats;
							Chats.clear();
							if (getCounter == 0) getCounter--;
						}
						else {
							position = 0; //! Позиция в строке при разбиении ее на код чата и список пользователей
							while (position < text.length() && text[position] != '@') {
								position++;
							}
							string ChatIDStr = text.substr(0, position++); //! Код чата
							string TheChatUsers = text.substr(position); //! Список пользователей в чате
							Chats[stoi(ChatIDStr)] = tempChats[stoi(ChatIDStr)];
							//! Форматированная строка с информацией о чате для записи её в listBox
							string newChat = ChatIDStr + '(' + to_string(tempChats[stoi(ChatIDStr)]) + ") " + TheChatUsers + "\r\n";
							getCl.text += newChat;
							ChatListVector.push_back(newChat);
							if (getCounter == 1) getCounter = -1;
							else getCounter--;
						}
					}
					//! Получение списка пользователей
					else if (code == -1000) {
						int prevPos = 0; //! Предыдущая позиция символа в строке для выделения подстроки
						while (text[prevPos] != '@') prevPos++;

						int n = stoi(text.substr(0, prevPos)); //! Количество пользователей онлайн
						UsersCount = n;
						prevPos++;
						for (int i = prevPos; i < text.length(); i++) {
							if (text[i] == ',') {
								userListVector.push_back(text.substr(prevPos, i - prevPos));
								prevPos = i + 1;
							}
						}
						userListVector.push_back(text.substr(prevPos, text.length() - prevPos));
						getCounter = -1;
					}
					//! Получение не более, чем 40 сообщений в открытый чат
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
					//! Получение сообщений, отправленных кем-то прямо сейчас, по одному, в какой-либо чат.
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
			Test.text += " - ресивер";
			return;
		}
	}
	
	//! Функция отправки сообщения в чат
	void TheSender() {
		try {
			std::string str; //Строка, в которую записывается сообщение из textBox
			str = SystemToStl(newMessage->Text);
			toSend.code = chatID;
			toSend.text = str;
			toSend.Send();
		}
		catch (...) {
			Test.text = "Ошибка в sender";
			return;
		}
	}

	/*! \brief Функция при нажатии на кнопку "Новый чат"
	Скрывает список чатов, появляется поле для ввода пользователей, которые должны быть в новом чате.
	Когда пользователь введет список ников через запятую, отправляет запрос на сервер. Затем ждет, когда объект класса,
	использующийся для создания нового чата, изменится. В поле text вместо списка пользователей появится код созданного
	чата. В случае успешного создания переключается на вторую вкладку формы (с чатом). Вызывает функцию для записи списка
	пользователей в соответствующее поле. Очищает поле с историей сообщений.
	Возвращает textBox ChatUsers к состоянию до нажатия кнопки
	*/
	private: System::Void NewChat_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ChatUsers->Enabled == false) {
			ChatUsers->Enabled = true;
		}
		else {
			if (ChatUsers->Text->Length == 0 || ChatUsers->Text == "Введите пользователей") {
				ChatUsers->Text = "Введите пользователей";
			}
			else {
				newMessage->Text = "";
				NewChat.code = -10;
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
			//Возвращение к состоянию до нажатия кнопки
			ChatUsers->Text = "";
			ChatUsers->Enabled = false;
		}
	}

/*! События при загрузке формы
В заголовок окна записывается ник текущего пользователя. Запускается поток для постоянного приема сообщений от сервера.
Запускается таймер для получения новых сообщений. Для второго таймера выставляется интервал ожидания, который будет нужен
при закрытии формы.
*/
private: System::Void TheChatWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	Text = gcnew System::String(ourUser.c_str());
	//Начало потока, где идет постоянный прием.
	ThreadStart^ thrStart = gcnew ThreadStart(this, &TheChatWindow::receiver);
	Thread^ t1 = gcnew Thread(thrStart);
	t1->IsBackground = true;
	t1->Start();
	//Запуск таймера
	timer1->Start();
	timer2->Interval = 1000;
}

//! Таймер для отображения сообщений в текущем чате и отладки.
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	label1->Text = "Таймер работает";
	//label3->Text = Convert::ToString(chatID);
	label2->Text =  "Test.code = " + Convert::ToString(Test.code) + " Test.text = " + gcnew System::String(Test.text.c_str())
		+ " CurID = "  + CurID;
	if (CompWith != ToChange) {		
		oldMessages->Text += formatStr(oneMessage);
		CompWith = ToChange;
		label1->Text = "До захода";
		if (TimeDo) {
			label1->Text = "Зашел";
			GetChats();
			TimeDo = false;
		}
	}
	
}

//! При нажатии на кнопку отправить сообщение во 2 вкладке вызывается функция отправки
private: System::Void SendMessage_Click(System::Object^ sender, System::EventArgs^ e) {
	TheSender();
}

//! При нажатии на кнопку список чатов вызывается функция получения чатов
private: System::Void OldChats_Click(System::Object^ sender, System::EventArgs^ e) {
	GetChats();
}


/*! При двойном клике на чат в списке чатов вторая вкладка открывается с этим чатом и отправляется запрос
на получение истории сообщений в этот чат
*/
	private: System::Void ChatListBox_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		newMessage->Text = "";
		if (ChatListBox->SelectedIndex >= 0) {
			//Переключение на вторую вкладку
			tabControl1->SelectedIndex = 1;
			//! Строка из пункта списка чатов для разбиения на код чата и список пользователей
			string chatString = SystemToStl(ChatListBox->SelectedItem->ToString());
			int position = 0; //! Позиция в строке при разбиении её на части при помощи substr
			while (chatString[position] != '(') {
				position++;
			}
			chatID = stoi(chatString.substr(0, position));
			label3->Text = Convert::ToString(chatID);
			while (chatString[position] != ')') {
				position++;
			}
			string TheChatUsers = chatString.substr(position + 1);
			//Перенос списка пользователей во вкладку с чатом
			CUWithLines(gcnew System::String(TheChatUsers.c_str()), 3);
			//Отправить запрос на получение сообщений для этого чата
			GetMessages(to_string(chatID));
		}
}
//! Закрытие формы кнопкой "выход". Отправляет серверу запрос на выход и ждет секунду, чтобы успеть выйти
private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e) {	
	toExit.Send();
	timer2->Start();
	//this->Close();
}
//! Закрытие формы. Отправляет серверу запрос на выход и ждет секунду, чтобы успеть выйти
private: System::Void TheChatWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {	
	toExit.Send();
	timer2->Start();
}
//! Выход из чата. Отправляет запрос серверу на выход из чата. Переходит на первую вкладку. Очищает историю сообщений чата
private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedIndex = 0;
	MsgCl toExitChat(-30,to_string(chatID)); //! Экземпляр класса для отправки запроса на выход из чата
	toExitChat.Send();
	oldMessages->Text = "";
	newMessage->Text = "";
	GetChats();
}

//! Таймер для ожидания перед выходом. Нужен, чтобы все необходимые операции успели завершиться.
private: System::Void Timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (closeCounter == 1) {
		closeCounter = 0;		
		this->Close();
	}
	else closeCounter++;
}

/*! Получение списка пользователей.
При нажатии на кнопку вызывает соответствующую функцию. Сначала выводятся те пользователи, которые сейчас онлайн,
потом все остальные. Внутри группы пользователи сортируются в алфавитном порядке
*/
private: System::Void UsersOnline_Click(System::Object^ sender, System::EventArgs^ e) {
	GetUsers();
}

};
}
