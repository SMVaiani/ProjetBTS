#pragma once
#include "Course.h"
#include "Participant.h"

namespace Chrono_ng {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_course;
	protected:
	private: System::Windows::Forms::Button^  button_participant;

	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Panel^  panel2;

	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label_fermer;
	private: System::Windows::Forms::Label^  label_reduire;
	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;









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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button_course = (gcnew System::Windows::Forms::Button());
			this->button_participant = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label_fermer = (gcnew System::Windows::Forms::Label());
			this->label_reduire = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_course
			// 
			this->button_course->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button_course->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_course->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_course->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_course->Location = System::Drawing::Point(200, 33);
			this->button_course->Name = L"button_course";
			this->button_course->Size = System::Drawing::Size(100, 47);
			this->button_course->TabIndex = 0;
			this->button_course->Text = L"COURSE";
			this->button_course->UseVisualStyleBackColor = false;
			this->button_course->Click += gcnew System::EventHandler(this, &MyForm::button_course_Click);
			this->button_course->MouseLeave += gcnew System::EventHandler(this, &MyForm::button_course_MouseLeave);
			this->button_course->MouseHover += gcnew System::EventHandler(this, &MyForm::button_course_MouseHover);
			// 
			// button_participant
			// 
			this->button_participant->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button_participant->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_participant->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_participant->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_participant->Location = System::Drawing::Point(401, 33);
			this->button_participant->Name = L"button_participant";
			this->button_participant->Size = System::Drawing::Size(100, 47);
			this->button_participant->TabIndex = 1;
			this->button_participant->Text = L"PARTICIPANT";
			this->button_participant->UseVisualStyleBackColor = false;
			this->button_participant->Click += gcnew System::EventHandler(this, &MyForm::button_participant_Click);
			this->button_participant->MouseLeave += gcnew System::EventHandler(this, &MyForm::button_participant_MouseLeave);
			this->button_participant->MouseHover += gcnew System::EventHandler(this, &MyForm::button_participant_MouseHover);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Aqua;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(277, 5);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Saisir/Modifier/Consulter";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::LightSlateGray;
			this->panel2->Controls->Add(this->button_course);
			this->panel2->Controls->Add(this->button_participant);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(0, 218);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(694, 108);
			this->panel2->TabIndex = 7;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(126)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->panel3->Location = System::Drawing::Point(0, 35);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(200, 185);
			this->panel3->TabIndex = 3;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(126)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->panel4->Location = System::Drawing::Point(501, 35);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(193, 185);
			this->panel4->TabIndex = 4;
			// 
			// label_fermer
			// 
			this->label_fermer->AutoSize = true;
			this->label_fermer->BackColor = System::Drawing::Color::Ivory;
			this->label_fermer->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_fermer->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_fermer->Location = System::Drawing::Point(669, 0);
			this->label_fermer->Name = L"label_fermer";
			this->label_fermer->Size = System::Drawing::Size(23, 24);
			this->label_fermer->TabIndex = 1;
			this->label_fermer->Text = L"X";
			this->label_fermer->Click += gcnew System::EventHandler(this, &MyForm::label_fermer_Click);
			this->label_fermer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::label_fermer_MouseDown);
			this->label_fermer->MouseLeave += gcnew System::EventHandler(this, &MyForm::label_fermer_MouseLeave);
			this->label_fermer->MouseHover += gcnew System::EventHandler(this, &MyForm::label_fermer_MouseHover);
			// 
			// label_reduire
			// 
			this->label_reduire->AutoSize = true;
			this->label_reduire->BackColor = System::Drawing::Color::Ivory;
			this->label_reduire->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_reduire->Font = (gcnew System::Drawing::Font(L"Century Gothic", 17.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_reduire->Location = System::Drawing::Point(643, 0);
			this->label_reduire->Name = L"label_reduire";
			this->label_reduire->Size = System::Drawing::Size(20, 27);
			this->label_reduire->TabIndex = 2;
			this->label_reduire->Text = L"-";
			this->label_reduire->Click += gcnew System::EventHandler(this, &MyForm::label_reduire_Click);
			this->label_reduire->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::label_reduire_MouseDown);
			this->label_reduire->MouseLeave += gcnew System::EventHandler(this, &MyForm::label_reduire_MouseLeave);
			this->label_reduire->MouseHover += gcnew System::EventHandler(this, &MyForm::label_reduire_MouseHover);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(694, 232);
			this->panel1->TabIndex = 6;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(200, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(301, 212);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Ivory;
			this->panel6->Controls->Add(this->label1);
			this->panel6->Controls->Add(this->label_fermer);
			this->panel6->Controls->Add(this->label_reduire);
			this->panel6->Location = System::Drawing::Point(0, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(694, 36);
			this->panel6->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Ivory;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(117, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(444, 23);
			this->label1->TabIndex = 6;
			this->label1->Text = L"GESTION DES COURSES - MENU PRINCIPAL";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(694, 326);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Accueil";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_course_Click(System::Object^  sender, System::EventArgs^  e) {
		Course^ course = Course::getCourseSingleton();
		course->Show();
	}

	private: System::Void button_participant_Click(System::Object^  sender, System::EventArgs^  e) {
		Participant^ participant = Participant::getParticipantSingleton();
		participant->Show();
	}


/* -- Design -- */
private: System::Void label_reduire_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
private: System::Void label_fermer_Click(System::Object^  sender, System::EventArgs^  e) {
	Environment::Exit(0);
}
private: System::Void label_reduire_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	label_reduire->BackColor = Color::Ivory;
}
private: System::Void label_reduire_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	label_reduire->BackColor = Color::Teal;
}
private: System::Void label_reduire_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	label_reduire->BackColor = Color::DarkCyan;
}
private: System::Void label_fermer_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	label_fermer->BackColor = Color::Ivory;
}
private: System::Void label_fermer_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	label_fermer->BackColor = Color::Red;
}
private: System::Void label_fermer_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	label_fermer->BackColor = Color::Salmon;
}
private: System::Void button_course_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	button_course->BackColor = System::Drawing::SystemColors::InactiveCaption;
}
private: System::Void button_course_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	button_course->BackColor = System::Drawing::SystemColors::ButtonFace;
}
private: System::Void button_participant_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	button_participant->BackColor = System::Drawing::SystemColors::InactiveCaption;
}
private: System::Void button_participant_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	button_participant->BackColor = System::Drawing::SystemColors::ButtonFace;
}
};
}
