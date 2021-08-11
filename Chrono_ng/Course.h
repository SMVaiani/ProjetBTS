#pragma once

namespace Chrono_ng {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient; // Pour utiliser des requêtes Sql

	/// <summary>
	/// Description résumée de Course
	/// </summary>
	public ref class Course : public System::Windows::Forms::Form
	{
	private:
		Course(void)
		{
			InitializeComponent();

			/*######## Connexion ########*/
			String^ adressIP = "localhost";
			String^ utilisateur = "root";
			String^ motDePasse = "";
			String^ maBase = "chrono_ng";
			System::String^ requeteDeConnection = "server=" + adressIP + ";uid=" + utilisateur + ";password=" + motDePasse + ";database=" + maBase + ";";
			
			//String^ requeteDeConnection = "server=mysql-chrono.alwaysdata.net;uid=chrono;password='chrono';database=chrono_ng;"; // AlwaysData
			
			conn = gcnew MySqlConnection(requeteDeConnection);
			try
			{
				conn->Open();
			}
			catch (MySqlException^ ex)
			{
				MessageBox::Show(ex->Message + requeteDeConnection);
			}
			afficheTout();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Course()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  nom_course;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  lieu_course;
	private: System::Windows::Forms::TextBox^  distance_course;

	private: MySqlConnection^ conn; // Pour connexion à la base de donnée

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
		
	private: static Course^ CourseSingleton;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button_enregistrer;

	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Button^  button_modifier;
	private: System::Windows::Forms::Button^  button_recherche;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox_id;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DateTimePicker^  date_course;
	private: System::Windows::Forms::CheckBox^  checkBox_toutAfficher;
	private: System::Windows::Forms::Panel^  panel_entete;



	private: Bunifu::Framework::UI::BunifuElipse^  bunifuElipse1;
	private: System::Windows::Forms::Panel^  panel2;

	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nomD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  lieuD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  distanceD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dateD;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label_fermer;
	private: System::Windows::Forms::Label^  label_reduire;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: Bunifu::Framework::UI::BunifuDragControl^  bunifuDragControl1;



	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Course::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->nom_course = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lieu_course = (gcnew System::Windows::Forms::TextBox());
			this->distance_course = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_enregistrer = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_toutAfficher = (gcnew System::Windows::Forms::CheckBox());
			this->date_course = (gcnew System::Windows::Forms::DateTimePicker());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox_id = (gcnew System::Windows::Forms::TextBox());
			this->button_modifier = (gcnew System::Windows::Forms::Button());
			this->button_recherche = (gcnew System::Windows::Forms::Button());
			this->panel_entete = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label_reduire = (gcnew System::Windows::Forms::Label());
			this->label_fermer = (gcnew System::Windows::Forms::Label());
			this->bunifuElipse1 = (gcnew Bunifu::Framework::UI::BunifuElipse(this->components));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nomD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lieuD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->distanceD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bunifuDragControl1 = (gcnew Bunifu::Framework::UI::BunifuDragControl(this->components));
			this->groupBox1->SuspendLayout();
			this->panel_entete->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// nom_course
			// 
			this->nom_course->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nom_course->Location = System::Drawing::Point(126, 29);
			this->nom_course->Multiline = true;
			this->nom_course->Name = L"nom_course";
			this->nom_course->Size = System::Drawing::Size(185, 31);
			this->nom_course->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(7, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nom de la course:";
			// 
			// lieu_course
			// 
			this->lieu_course->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lieu_course->Location = System::Drawing::Point(126, 77);
			this->lieu_course->Multiline = true;
			this->lieu_course->Name = L"lieu_course";
			this->lieu_course->Size = System::Drawing::Size(185, 28);
			this->lieu_course->TabIndex = 1;
			// 
			// distance_course
			// 
			this->distance_course->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->distance_course->Location = System::Drawing::Point(126, 129);
			this->distance_course->Multiline = true;
			this->distance_course->Name = L"distance_course";
			this->distance_course->Size = System::Drawing::Size(34, 28);
			this->distance_course->TabIndex = 2;
			this->distance_course->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(7, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Lieu de la course:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(7, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Distance de la course:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(7, 194);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Date de la cousre:";
			// 
			// button_enregistrer
			// 
			this->button_enregistrer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_enregistrer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_enregistrer->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_enregistrer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_enregistrer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button_enregistrer->ForeColor = System::Drawing::SystemColors::Menu;
			this->button_enregistrer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_enregistrer.Image")));
			this->button_enregistrer->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button_enregistrer->Location = System::Drawing::Point(140, 241);
			this->button_enregistrer->Name = L"button_enregistrer";
			this->button_enregistrer->Size = System::Drawing::Size(103, 37);
			this->button_enregistrer->TabIndex = 7;
			this->button_enregistrer->Text = L"Enregistrer";
			this->button_enregistrer->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_enregistrer->UseVisualStyleBackColor = false;
			this->button_enregistrer->Click += gcnew System::EventHandler(this, &Course::button_enregistrer_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->groupBox1->Controls->Add(this->checkBox_toutAfficher);
			this->groupBox1->Controls->Add(this->date_course);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox_id);
			this->groupBox1->Controls->Add(this->button_modifier);
			this->groupBox1->Controls->Add(this->button_recherche);
			this->groupBox1->Controls->Add(this->button_enregistrer);
			this->groupBox1->Controls->Add(this->nom_course);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->lieu_course);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->distance_course);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->groupBox1->Location = System::Drawing::Point(21, 51);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(359, 317);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Créer une course";
			// 
			// checkBox_toutAfficher
			// 
			this->checkBox_toutAfficher->AutoSize = true;
			this->checkBox_toutAfficher->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBox_toutAfficher->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->checkBox_toutAfficher->Location = System::Drawing::Point(28, 286);
			this->checkBox_toutAfficher->Name = L"checkBox_toutAfficher";
			this->checkBox_toutAfficher->Size = System::Drawing::Size(93, 20);
			this->checkBox_toutAfficher->TabIndex = 15;
			this->checkBox_toutAfficher->TabStop = false;
			this->checkBox_toutAfficher->Text = L"Tout afficher";
			this->checkBox_toutAfficher->UseVisualStyleBackColor = true;
			// 
			// date_course
			// 
			this->date_course->CustomFormat = L"dd-MM-yyyy HH:mm:ss";
			this->date_course->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date_course->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->date_course->Location = System::Drawing::Point(126, 187);
			this->date_course->Name = L"date_course";
			this->date_course->Size = System::Drawing::Size(157, 21);
			this->date_course->TabIndex = 3;
			this->date_course->Value = System::DateTime(2019, 5, 30, 0, 0, 0, 0);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->label7->Location = System::Drawing::Point(166, 132);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 18);
			this->label7->TabIndex = 14;
			this->label7->Text = L"km";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->label6->Location = System::Drawing::Point(256, 285);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(22, 16);
			this->label6->TabIndex = 13;
			this->label6->Text = L"id:";
			// 
			// textBox_id
			// 
			this->textBox_id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_id->Location = System::Drawing::Point(283, 284);
			this->textBox_id->Name = L"textBox_id";
			this->textBox_id->Size = System::Drawing::Size(38, 26);
			this->textBox_id->TabIndex = 10;
			this->textBox_id->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button_modifier
			// 
			this->button_modifier->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_modifier->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_modifier->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_modifier->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_modifier->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_modifier->ForeColor = System::Drawing::SystemColors::Menu;
			this->button_modifier->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_modifier.Image")));
			this->button_modifier->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button_modifier->Location = System::Drawing::Point(249, 241);
			this->button_modifier->Name = L"button_modifier";
			this->button_modifier->Size = System::Drawing::Size(92, 37);
			this->button_modifier->TabIndex = 9;
			this->button_modifier->Text = L"Modifier";
			this->button_modifier->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_modifier->UseVisualStyleBackColor = false;
			this->button_modifier->Click += gcnew System::EventHandler(this, &Course::button_modifier_Click);
			// 
			// button_recherche
			// 
			this->button_recherche->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_recherche->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_recherche->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_recherche->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_recherche->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button_recherche->ForeColor = System::Drawing::SystemColors::Menu;
			this->button_recherche->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_recherche.Image")));
			this->button_recherche->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button_recherche->Location = System::Drawing::Point(24, 241);
			this->button_recherche->Name = L"button_recherche";
			this->button_recherche->Size = System::Drawing::Size(110, 37);
			this->button_recherche->TabIndex = 8;
			this->button_recherche->Text = L"Recherche";
			this->button_recherche->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_recherche->UseVisualStyleBackColor = false;
			this->button_recherche->Click += gcnew System::EventHandler(this, &Course::button_recherche_Click);
			// 
			// panel_entete
			// 
			this->panel_entete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->panel_entete->Controls->Add(this->pictureBox1);
			this->panel_entete->Controls->Add(this->label5);
			this->panel_entete->Controls->Add(this->label_reduire);
			this->panel_entete->Controls->Add(this->label_fermer);
			this->panel_entete->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_entete->Location = System::Drawing::Point(0, 0);
			this->panel_entete->Name = L"panel_entete";
			this->panel_entete->Size = System::Drawing::Size(971, 33);
			this->panel_entete->TabIndex = 12;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(32, 32);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::Info;
			this->label5->Location = System::Drawing::Point(41, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 22);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Course";
			// 
			// label_reduire
			// 
			this->label_reduire->AutoSize = true;
			this->label_reduire->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_reduire->Location = System::Drawing::Point(906, 2);
			this->label_reduire->Name = L"label_reduire";
			this->label_reduire->Size = System::Drawing::Size(21, 29);
			this->label_reduire->TabIndex = 1;
			this->label_reduire->Text = L"-";
			this->label_reduire->Click += gcnew System::EventHandler(this, &Course::label_reduire_Click);
			this->label_reduire->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Course::label_reduire_MouseDown);
			this->label_reduire->MouseLeave += gcnew System::EventHandler(this, &Course::label_reduire_MouseLeave);
			this->label_reduire->MouseHover += gcnew System::EventHandler(this, &Course::label_reduire_MouseHover);
			// 
			// label_fermer
			// 
			this->label_fermer->AutoSize = true;
			this->label_fermer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_fermer->Location = System::Drawing::Point(933, 4);
			this->label_fermer->Name = L"label_fermer";
			this->label_fermer->Size = System::Drawing::Size(26, 25);
			this->label_fermer->TabIndex = 0;
			this->label_fermer->Text = L"X";
			this->label_fermer->Click += gcnew System::EventHandler(this, &Course::label_fermer_Click);
			this->label_fermer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Course::label_fermer_MouseDown);
			this->label_fermer->MouseLeave += gcnew System::EventHandler(this, &Course::label_fermer_MouseLeave);
			this->label_fermer->MouseHover += gcnew System::EventHandler(this, &Course::label_fermer_MouseHover);
			// 
			// bunifuElipse1
			// 
			this->bunifuElipse1->ElipseRadius = 5;
			this->bunifuElipse1->TargetControl = this;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->panel2->Location = System::Drawing::Point(0, 32);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(400, 367);
			this->panel2->TabIndex = 13;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->panel3->Controls->Add(this->groupBox2);
			this->panel3->Location = System::Drawing::Point(397, 32);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(574, 370);
			this->panel3->TabIndex = 14;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->groupBox2->Location = System::Drawing::Point(19, 19);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(543, 317);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Résultat";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AccessibleDescription = L"";
			this->dataGridView1->AccessibleName = L"";
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::Info;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->id, this->nomD,
					this->lieuD, this->distanceD, this->dateD
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(19, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Size = System::Drawing::Size(508, 269);
			this->dataGridView1->TabIndex = 0;
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Width = 30;
			// 
			// nomD
			// 
			this->nomD->HeaderText = L"Nom";
			this->nomD->Name = L"nomD";
			this->nomD->ReadOnly = true;
			this->nomD->Width = 130;
			// 
			// lieuD
			// 
			this->lieuD->HeaderText = L"Lieu";
			this->lieuD->Name = L"lieuD";
			this->lieuD->ReadOnly = true;
			this->lieuD->Width = 110;
			// 
			// distanceD
			// 
			this->distanceD->HeaderText = L"Distance";
			this->distanceD->Name = L"distanceD";
			this->distanceD->ReadOnly = true;
			this->distanceD->Width = 65;
			// 
			// dateD
			// 
			this->dateD->HeaderText = L"Date";
			this->dateD->Name = L"dateD";
			this->dateD->ReadOnly = true;
			this->dateD->Width = 130;
			// 
			// bunifuDragControl1
			// 
			this->bunifuDragControl1->Fixed = true;
			this->bunifuDragControl1->Horizontal = true;
			this->bunifuDragControl1->TargetControl = this->panel_entete;
			this->bunifuDragControl1->Vertical = true;
			// 
			// Course
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(971, 394);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel_entete);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Course";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Course";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel_entete->ResumeLayout(false);
			this->panel_entete->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}

		public:
			static Course^ getCourseSingleton() // Garantir une instance unique
			{
				if (CourseSingleton == nullptr)
					CourseSingleton = gcnew Course();
				return CourseSingleton;
			}

			void enregistrer()
			{
				/*----------- Vérifier si l'entrée n'existe pas dans la table 'course' -------------*/
				String^ heure_depart = date_course->Text[11].ToString() + date_course->Text[12] + date_course->Text[13] + date_course->Text[14] + date_course->Text[15] + date_course->Text[16] + date_course->Text[17] + date_course->Text[18];
				String^ date_inverser = date_course->Text[6].ToString() + date_course->Text[7] + date_course->Text[8] + date_course->Text[9] + date_course->Text[5] + date_course->Text[3] + date_course->Text[4] + date_course->Text[2] + date_course->Text[0] + date_course->Text[1]; //  Inversersement de la date pour se conformer au format de MySql

				String^ requeteVerifDoublon = "SELECT nomURSE FROM course WHERE nomURSE='" + nom_course->Text + "' && lieuURSE='" + lieu_course->Text + "' && distanceURSE='" + distance_course->Text + "km' && dateURSE='" + date_inverser + "'";
				MySqlCommand^ commandVerifDoublon = gcnew MySqlCommand(requeteVerifDoublon, conn);
				MySqlDataReader^ readerVerifDoublon = commandVerifDoublon->ExecuteReader();
				bool ok = readerVerifDoublon->Read(); // True si existe sinon false si n'existe pas
				readerVerifDoublon->Close();

				/*----------- Insérer des données dans la table 'course' si << ok = false >> -------------*/
				if (!ok)
				{
					String^ requete = "INSERT INTO course (nomURSE,lieuURSE,distanceURSE,dateURSE,h_depart) VALUES ('" + nom_course->Text + "','" + lieu_course->Text + "','" + distance_course->Text + "km','" + date_inverser + "','" + heure_depart + "')";
					MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
					try
					{
						command->ExecuteNonQuery();
						//MessageBox::Show("Course enregistrer !");
						dataGridView1->Rows->Clear();
						afficheTout();
					}
					catch (Exception^ ex)
					{
						MessageBox::Show("Erreur d'écriture de donnée dans la base de donnée!\n" + ex->ToString());
					}
					nom_course->Text = "";		lieu_course->Text = "";		distance_course->Text = "";		date_course->Value = DateTime::Today;
				}
				else MessageBox::Show("Course déja créer !");
			}

			void afficheTout()
			{
				/*------- Affiche tout les données ---------*/
				String^ requeteAff = "SELECT * FROM course";
				MySqlCommand^ commandAff = gcnew MySqlCommand(requeteAff, conn); // Pour éxécuter une commande Sql
				MySqlDataReader^ reader = commandAff->ExecuteReader();  // Pour récupérer les données dans un dataredaer

				try
				{
					while (reader->Read())
					{
						String^ convert_date = reader->GetString(4); // Récupérer que la date en format 26/03/2019 sans l'heure '00:00:00'
						convert_date = convert_date[0].ToString() + convert_date[1] + convert_date[2] + convert_date[3] + convert_date[4] + convert_date[5] + convert_date[6] + convert_date[7] + convert_date[8] + convert_date[9];
						String^ aff_date_heure = convert_date + " " + reader->GetString(5); // Concaténation: 26/03/2019_10:00:10

						this->dataGridView1->Rows->Add(reader->GetString(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), aff_date_heure);
					}
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("Erreur de lecture!\n" + ex->ToString());
				}
				reader->Close();
			}

			void afficheCondition()
			{
				/*---------------- Affichage des données selon condition -----------------*/
				String^ date_inverser = date_course->Text[6].ToString() + date_course->Text[7] + date_course->Text[8] + date_course->Text[9] +
					date_course->Text[5] + date_course->Text[3] + date_course->Text[4] + date_course->Text[2] + date_course->Text[0] + date_course->Text[1]; //  Inversersement de la date pour se conformer au format de MySql

				String^ requeteAff = "SELECT * FROM course WHERE nomURSE='" + nom_course->Text + "' || lieuURSE='" + lieu_course->Text + "' || distanceURSE='" + distance_course->Text + "km' || dateURSE='" + date_inverser + "'";
				MySqlCommand^ commandAff = gcnew MySqlCommand(requeteAff, conn);
				MySqlDataReader^ reader = commandAff->ExecuteReader();

				try
				{
					while (reader->Read())
					{
						String^ convert_date = reader->GetString(4); // Récupérer que la date en format 26/03/2019 sans l'heure '00:00:00'
						convert_date = convert_date[0].ToString() + convert_date[1] + convert_date[2] + convert_date[3] + convert_date[4] + convert_date[5] + convert_date[6] + convert_date[7] + convert_date[8] + convert_date[9];
						String^ aff_date_heure = convert_date + " " + reader->GetString(5); // Concaténation: 26/03/2019_10:00:10

						this->dataGridView1->Rows->Add(reader->GetString(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), aff_date_heure);
					}
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("Erreur de lecture!\n" + ex->ToString());
				}

				reader->Close();	nom_course->Text = "";	lieu_course->Text = "";		distance_course->Text = "";		date_course->Value = DateTime::Today;
			}

			void afficheConditionComplet()
			{
				/*---------------- Affichage des données de plus de deux conditions -----------------*/
				String^ requeteAff = "SELECT * FROM course WHERE nomURSE='" + nom_course->Text + "' && lieuURSE='" + lieu_course->Text + "'";
				MySqlCommand^ commandAff = gcnew MySqlCommand(requeteAff, conn);
				MySqlDataReader^ reader = commandAff->ExecuteReader();

				try
				{
					while (reader->Read())
					{
						String^ convert_date = reader->GetString(4); // Récupérer que la date en format 26/03/2019 sans l'heure '00:00:00'
						convert_date = convert_date[0].ToString() + convert_date[1] + convert_date[2] + convert_date[3] + convert_date[4] + convert_date[5] + convert_date[6] + convert_date[7] + convert_date[8] + convert_date[9];
						String^ aff_date_heure = convert_date + " " + reader->GetString(5); // Concaténation: 26/03/2019_10:00:10

						this->dataGridView1->Rows->Add(reader->GetString(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), aff_date_heure);
					}
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("Erreur de lecture!\n" + ex->ToString());
				}

				reader->Close();	nom_course->Text = "";	lieu_course->Text = "";		distance_course->Text = "";		date_course->Value = DateTime::Today;
			}

			void modifierDonnees()
			{
				/*----------- Vérifier si l'entrée existe dans la table 'course' -------------*/
				String^ date_inverser = date_course->Text[6].ToString() + date_course->Text[7] + date_course->Text[8] + date_course->Text[9] +
					date_course->Text[5] + date_course->Text[3] + date_course->Text[4] + date_course->Text[2] + date_course->Text[0] + date_course->Text[1]; //  Inversersement de la date pour se conformer au format de MySql
				String^ requeteVerifID = "SELECT idURSE FROM course WHERE idURSE='" + textBox_id->Text + "'";
				MySqlCommand^ commandVerifID = gcnew MySqlCommand(requeteVerifID, conn);
				MySqlDataReader^ readerVerifID = commandVerifID->ExecuteReader();
				bool ok = readerVerifID->Read(); // <true> si existe, sinon <false> si n'existe pas
				readerVerifID->Close();

				if (ok == true)
				{
					/*----------- Modifier des données dans la table 'COURSE' -------------*/
					if (nom_course->Text != "" && lieu_course->Text != "" && distance_course->Text != "" && textBox_id->Text != "")
					{
						/*---- Modifier le NOM, LIEU, DISTANCE de la COURSE ----*/

						String^ requete = "UPDATE course SET nomURSE='" + nom_course->Text + "', lieuURSE='" + lieu_course->Text + "', distanceURSE='" + distance_course->Text + "km' WHERE idURSE='" + textBox_id->Text + "'";
						MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
						try
						{
							command->ExecuteNonQuery();
							MessageBox::Show("Course modifier !");
						}
						catch (Exception^ ex)
						{
							MessageBox::Show("Erreur d'écriture de donnée dans la base de donnée!\n" + ex->ToString());
						}
					}
					else if (nom_course->Text != "" && lieu_course->Text != "" && distance_course->Text == "" && textBox_id->Text != "")
					{
						/*---- Modifier le NOM,LIEU de la COURSE ----*/
						String^ requete = "UPDATE course SET nomURSE='" + nom_course->Text + "', lieuURSE='" + lieu_course->Text + "' WHERE idURSE='" + textBox_id->Text + "'";
						MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
						try
						{
							command->ExecuteNonQuery();
							MessageBox::Show("Course modifier !");
						}
						catch (Exception^ ex)
						{
							MessageBox::Show("Erreur d'écriture de donnée dans la base de donnée!\n" + ex->ToString());
						}
					}
					else if (nom_course->Text != "" && lieu_course->Text == "" && distance_course->Text == "" && textBox_id->Text != "")
					{
						/*---- Modifier le NOM de la COURSE ----*/
						String^ requete = "UPDATE course SET nomURSE='" + nom_course->Text + "' WHERE idURSE='" + textBox_id->Text + "'";
						MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
						try
						{
							command->ExecuteNonQuery();
							MessageBox::Show("Course modifier !");
						}
						catch (Exception^ ex)
						{
							MessageBox::Show("Erreur d'écriture de donnée dans la base de donnée!\n" + ex->ToString());
						}
					}

					else if (nom_course->Text == "" && lieu_course->Text != "" && distance_course->Text == "" && textBox_id->Text != "")
					{
						/*---- Modifier le LIEU de la COURSE ----*/
						String^ requete = "UPDATE course SET lieuURSE='" + lieu_course->Text + "' WHERE idURSE='" + textBox_id->Text + "'";
						MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
						try
						{
							command->ExecuteNonQuery();
							MessageBox::Show("Course modifier !");
						}
						catch (Exception^ ex)
						{
							MessageBox::Show("Erreur d'écriture de donnée dans la base de donnée!\n" + ex->ToString());
						}
					}

					else if (nom_course->Text == "" && lieu_course->Text == "" && distance_course->Text != "" && textBox_id->Text != "")
					{
						/*---- Modifier la DISTANCE de la COURSE ----*/
						String^ requete = "UPDATE course SET distanceURSE='" + distance_course->Text + "km' WHERE idURSE='" + textBox_id->Text + "'";
						MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
						try
						{
							command->ExecuteNonQuery();
							MessageBox::Show("Course modifier !");
						}
						catch (Exception^ ex)
						{
							MessageBox::Show("Erreur d'écriture de donnée dans la base de donnée!\n" + ex->ToString());
						}
					}

					else 
					{
						/*---- Modifier la DATE de la COURSE ----*/
						String^ heure_depart = date_course->Text[11].ToString() + date_course->Text[12] + date_course->Text[13] + date_course->Text[14] + date_course->Text[15] + date_course->Text[16] + date_course->Text[17] + date_course->Text[18];
						String^ date_inverser = date_course->Text[6].ToString() + date_course->Text[7] + date_course->Text[8] + date_course->Text[9] + date_course->Text[5] + date_course->Text[3] + date_course->Text[4] + date_course->Text[2] + date_course->Text[0] + date_course->Text[1]; //  Inversersement de la date pour se conformer au format de MySql
						
						String^ requete = "UPDATE course SET dateURSE='" + date_inverser + "',h_depart='" + heure_depart +  "' WHERE idURSE=" + textBox_id->Text + "";
						MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
						try
						{
							command->ExecuteNonQuery();
							MessageBox::Show("Course modifier !");
						}
						catch (Exception^ ex)
						{
							MessageBox::Show("Erreur d'écriture de donnée dans la base de donnée!\n" + ex->ToString());
						}
					}
				nom_course->Text = "";		lieu_course->Text = "";		distance_course->Text = "";	    date_course->Value = DateTime::Today;		textBox_id->Text = "";
				dataGridView1->Rows->Clear();
				afficheTout();
				}
				else MessageBox::Show("ID non connu !");
			}
				 
#pragma endregion
private: System::Void button_enregistrer_Click(System::Object^  sender, System::EventArgs^  e) {
	if (nom_course->Text != "" && lieu_course->Text != "" && distance_course->Text != "")
	{
		if (distance_course->Text->Length == 1 && distance_course->Text[0] >= '0' && distance_course->Text[0] <= '9')
			enregistrer();
		else if (distance_course->Text->Length == 2 && distance_course->Text[0] >= '1' && distance_course->Text[0] <= '9' && distance_course->Text[1] >= '0' && distance_course->Text[1] <= '9')
			enregistrer();
		else if (distance_course->Text->Length == 3 && distance_course->Text[0] >= '1' && distance_course->Text[0] <= '9' && distance_course->Text[1] >= '0' && distance_course->Text[1] <= '9' && distance_course->Text[2] >= '0' && distance_course->Text[2] <= '9')
			enregistrer();
		else MessageBox::Show("Distance invalide !");
	}
	else MessageBox::Show("Veuillez remplir tous les champs !");
}
		
private: System::Void button_recherche_Click(System::Object^  sender, System::EventArgs^  e) {
	dataGridView1->Rows->Clear();
	if (checkBox_toutAfficher->Checked == true)
	{
		afficheTout();
		checkBox_toutAfficher->Checked = false;
	}
	else if (nom_course->Text != "" && lieu_course->Text != "") afficheConditionComplet();
	else afficheCondition();
}

private: System::Void button_modifier_Click(System::Object^  sender, System::EventArgs^  e) {
	modifierDonnees();
}

/* ------- Design -------- */
/* Réduire */
private: System::Void label_reduire_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
private: System::Void label_reduire_MouseLeave(System::Object^  sender, System::EventArgs^  e) { // Raméne la couleur au bleu quand la souris quitte le composant
	label_reduire->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
		static_cast<System::Int32>(static_cast<System::Byte>(184)));
}
private: System::Void label_reduire_MouseHover(System::Object^  sender, System::EventArgs^  e) { // Quand le curseur est pointée sur le composant
	label_reduire->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
		static_cast<System::Int32>(static_cast<System::Byte>(244)));
}
private: System::Void label_reduire_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { // Quand la souris est enfoncée sur le composant
	label_reduire->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
		static_cast<System::Int32>(static_cast<System::Byte>(166)));
}

/* Fermer */
private: System::Void label_fermer_Click(System::Object^  sender, System::EventArgs^  e) {
	conn->Close(); // Fermeture de la connexion avec la base de donnée
	CourseSingleton = nullptr; // Pour pouvoir encore l'instancié (Singleton)
	this->Close(); // Fermer cette fenêtre uniquement
}
private: System::Void label_fermer_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	label_fermer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
		static_cast<System::Int32>(static_cast<System::Byte>(184)));
}
private: System::Void label_fermer_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	label_fermer->BackColor = Color::Red;
}
private: System::Void label_fermer_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	label_fermer->BackColor = Color::Salmon;
}
};
}
