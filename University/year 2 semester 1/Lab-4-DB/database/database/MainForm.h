#pragma once

namespace WindowsFormsTemplate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Configuration;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlconn = gcnew MySqlConnection();
		MySqlCommand^ sqlcom = gcnew MySqlCommand();
		DataTable^ table = gcnew DataTable();
		MySqlDataAdapter^ adpter = gcnew MySqlDataAdapter();
		MySqlDataReader^ rd;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ NameBox;
	private: System::Windows::Forms::TextBox^ GradeBox;
	private: System::Windows::Forms::TextBox^ YearBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ FormBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ GroupNameBox;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ IDBox;
	private: System::Windows::Forms::Label^ label7;




	private: System::Windows::Forms::PictureBox^ pictureBox1;

	public:
		MainForm(void)
		{
			InitializeComponent();
			StudentDB();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->NameBox = (gcnew System::Windows::Forms::TextBox());
			this->GradeBox = (gcnew System::Windows::Forms::TextBox());
			this->YearBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->FormBox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->GroupNameBox = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->IDBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(53, 191);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(155, 50);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(287, 191);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 50);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Изменить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(512, 191);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 50);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Сбросить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(11, 267);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1266, 559);
			this->panel1->TabIndex = 3;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(8, 10);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(1254, 542);
			this->dataGridView1->TabIndex = 12;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellClick);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(741, 191);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(156, 50);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Удалить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// NameBox
			// 
			this->NameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameBox->Location = System::Drawing::Point(167, 68);
			this->NameBox->Margin = System::Windows::Forms::Padding(4);
			this->NameBox->Name = L"NameBox";
			this->NameBox->Size = System::Drawing::Size(171, 29);
			this->NameBox->TabIndex = 2;
			// 
			// GradeBox
			// 
			this->GradeBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GradeBox->Location = System::Drawing::Point(536, 96);
			this->GradeBox->Margin = System::Windows::Forms::Padding(4);
			this->GradeBox->Name = L"GradeBox";
			this->GradeBox->Size = System::Drawing::Size(132, 29);
			this->GradeBox->TabIndex = 5;
			// 
			// YearBox
			// 
			this->YearBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->YearBox->Location = System::Drawing::Point(536, 33);
			this->YearBox->Margin = System::Windows::Forms::Padding(4);
			this->YearBox->MaxLength = 4;
			this->YearBox->Name = L"YearBox";
			this->YearBox->Size = System::Drawing::Size(132, 29);
			this->YearBox->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(7, 71);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"ФИО Студента";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(381, 102);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Средняя оценка";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(369, 39);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Год поступления";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(1, 118);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(150, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Форма обучения";
			// 
			// FormBox
			// 
			this->FormBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->FormBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBox->FormattingEnabled = true;
			this->FormBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Дневная", L"Вечерняя", L"Заочная" });
			this->FormBox->Location = System::Drawing::Point(167, 114);
			this->FormBox->Margin = System::Windows::Forms::Padding(4);
			this->FormBox->Name = L"FormBox";
			this->FormBox->Size = System::Drawing::Size(171, 32);
			this->FormBox->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(695, 39);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(154, 20);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Название группы";
			// 
			// GroupNameBox
			// 
			this->GroupNameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GroupNameBox->Location = System::Drawing::Point(872, 37);
			this->GroupNameBox->Margin = System::Windows::Forms::Padding(4);
			this->GroupNameBox->Name = L"GroupNameBox";
			this->GroupNameBox->Size = System::Drawing::Size(148, 29);
			this->GroupNameBox->TabIndex = 6;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(872, 90);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(148, 57);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Загрузить изображение";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(794, 107);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Фото";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(1028, 19);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(249, 222);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// IDBox
			// 
			this->IDBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->IDBox->Location = System::Drawing::Point(167, 21);
			this->IDBox->Margin = System::Windows::Forms::Padding(4);
			this->IDBox->Name = L"IDBox";
			this->IDBox->Size = System::Drawing::Size(171, 29);
			this->IDBox->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(33, 26);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(110, 20);
			this->label7->TabIndex = 10;
			this->label7->Text = L"ID студента";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1290, 826);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->IDBox);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->FormBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->GroupNameBox);
			this->Controls->Add(this->YearBox);
			this->Controls->Add(this->GradeBox);
			this->Controls->Add(this->NameBox);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Успеваемость студентов";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: static array<System::Byte>^ ImageToByte(Image^ img) {
		Type^ arr = array<System::Byte>::typeid;
		ImageConverter^ converter = gcnew ImageConverter();
		return (array<System::Byte>^)converter->ConvertTo(img, arr);
	}

	private: System::Void Reset() {
		IDBox->Text = "";
		NameBox->Text = "";
		GradeBox->Text = "";
		YearBox->Text = "";
		FormBox->Text = "";
		GroupNameBox->Text = "";
		pictureBox1->Image = nullptr;
	}

	private: System::Void StudentDB() {
		sqlconn->ConnectionString = "datasource=localhost; port=3306; username=root; password=password; database=students";
		sqlconn->Open();
		sqlcom->Connection = sqlconn;
		sqlcom->CommandText = "select s1.id, s1.Photo, s1.Name, s1.AverageGrade, s2.EnrollmentYear, s2.EducationForm, s2.GroupName from students1 s1 inner join students2 s2 on s2.id = s1.id";
		rd = sqlcom->ExecuteReader();
		table->Load(rd);
		rd->Close();
		sqlconn->Close();
		dataGridView1->DataSource = table;
		DataGridViewImageColumn^ pic1 = gcnew DataGridViewImageColumn();
		pic1 = (DataGridViewImageColumn^)dataGridView1->Columns[1];
		pic1->ImageLayout = DataGridViewImageCellLayout::Zoom;
	}
		
	private: System::Void refreshDB() {
		try {
			sqlconn->ConnectionString = "datasource=localhost; port=3306; username=root; password=password; database=students";
			sqlcom->Connection = sqlconn;

			MySqlDataAdapter^ sqladpter = gcnew MySqlDataAdapter("select s1.id, s1.Photo, s1.Name, s1.AverageGrade, s2.EnrollmentYear, s2.EducationForm, s2.GroupName from students1 s1 inner join students2 s2 on s2.id = s1.id", sqlconn);
			DataTable^ sqltable = gcnew DataTable();
			sqladpter->Fill(sqltable);
			dataGridView1->DataSource = sqltable;
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Filter = "Изображения| *.jpg; *.jpeg; *.png; *.gif; *.bmp";
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox1->Image = Image::FromFile(ofd->FileName);
		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Reset();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pictureBox1->Image == nullptr)
			pictureBox1->Image = pictureBox1->ErrorImage;
		if (GradeBox->Text == "")
			GradeBox->Text = "0";
		if (YearBox->Text == "")
			YearBox->Text = "0";
		sqlconn->ConnectionString = "datasource=localhost; port=3306; username=root; password=password; database=students";
		sqlconn->Open();
		sqlcom->Connection = sqlconn;
		try {		
			array<System::Byte>^ blobData = ImageToByte(pictureBox1->Image);
			sqlcom->CommandText = "insert into students1 (id, Name, AverageGrade, Photo) values (@id, @name, @grade, @photo);"
								  "insert into students2 (id, EnrollmentYear, EducationForm, GroupName) values (@id, @year, @form, @group)";
			sqlcom->Parameters->AddWithValue("@id", IDBox->Text);
			sqlcom->Parameters->AddWithValue("@name", NameBox->Text);
			sqlcom->Parameters->AddWithValue("@grade", GradeBox->Text);
			sqlcom->Parameters->AddWithValue("@photo", blobData);
			sqlcom->Parameters->AddWithValue("@year", YearBox->Text);
			sqlcom->Parameters->AddWithValue("@form", FormBox->Text);
			sqlcom->Parameters->AddWithValue("@group", GroupNameBox->Text);
			sqlcom->ExecuteNonQuery();
			sqlcom->Parameters->Clear();
			sqlconn->Close();
			StudentDB();
			refreshDB();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
			sqlcom->Parameters->Clear();
			sqlconn->Close();
		}
	}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		sqlconn->ConnectionString = "datasource=localhost; port=3306; username=root; password=password; database=students";
		sqlcom->Connection = sqlconn;
		
		sqlcom->CommandText = "delete from students1 where id = @id;"
							  "delete from students2 where id = @id", sqlconn;

		sqlcom->Parameters->AddWithValue("@id", IDBox->Text);

		Reset();

		sqlconn->Open();
		sqlcom->ExecuteNonQuery();
		sqlcom->Parameters->Clear();
		sqlconn->Close();
		refreshDB();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
		sqlcom->Parameters->Clear();
		sqlconn->Close();
	}
}
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	IDBox->Text = dataGridView1->CurrentRow->Cells[0]->Value->ToString();
	NameBox->Text = dataGridView1->CurrentRow->Cells[2]->Value->ToString();
	FormBox->Text = dataGridView1->CurrentRow->Cells[5]->Value->ToString();
	YearBox->Text = dataGridView1->CurrentRow->Cells[4]->Value->ToString();
	GradeBox->Text = dataGridView1->CurrentRow->Cells[3]->Value->ToString();
	GroupNameBox->Text = dataGridView1->CurrentRow->Cells[6]->Value->ToString();
	MemoryStream^ ms = gcnew MemoryStream((array<System::Byte>^)dataGridView1->CurrentRow->Cells[1]->Value);
	pictureBox1->Image = Image::FromStream(ms);
	GradeBox->Text = GradeBox->Text->Replace(",", ".");
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		sqlconn->ConnectionString = "datasource=localhost; port=3306; username=root; password=password; database=students";
		sqlcom->Connection = sqlconn;
		sqlcom->Parameters->Clear();

		sqlcom->CommandText = "update students1 set Photo = @photo, Name = @name, AverageGrade = @grade where id = @id;"
							  "update students2 set EnrollmentYear = @year, EducationForm = @form, GroupName = @group where id = @id", sqlconn;

		array<System::Byte>^ blobDatanew = ImageToByte(pictureBox1->Image);
		sqlcom->Parameters->AddWithValue("@photo", blobDatanew);
		sqlcom->Parameters->AddWithValue("@name", NameBox->Text);
		sqlcom->Parameters->AddWithValue("@grade", GradeBox->Text);
		sqlcom->Parameters->AddWithValue("@id", IDBox->Text);
		sqlcom->Parameters->AddWithValue("@year", YearBox->Text);
		sqlcom->Parameters->AddWithValue("@form", FormBox->Text);
		sqlcom->Parameters->AddWithValue("@group", GroupNameBox->Text);

		sqlconn->Open();
		sqlcom->ExecuteNonQuery();
		sqlconn->Close();
		StudentDB();
		refreshDB();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
		sqlconn->Close();
	}
}
};
}
