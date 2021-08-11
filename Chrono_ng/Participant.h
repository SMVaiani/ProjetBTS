#pragma once

namespace Chrono_ng {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace MySql::Data::MySqlClient; // Pour pouvoir utiliser des requêtes Sql

	/// <summary>
	/// Description résumée de Participant
	/// </summary>
	public ref class Participant : public System::Windows::Forms::Form
	{
	private:
		Participant(void)
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
			String^ date = DateTime::Now.Today.ToString("d");
			String^ dateInverser = date[6].ToString() + date[7] + date[8] + date[9] + date[5] + date[3] + date[4] + date[2] + date[0] + date[1];
			String^ requete = "SELECT nomURSE FROM course WHERE dateURSE>'" + dateInverser + "' ORDER BY dateURSE LIMIT 0,5"; // Récupérer les courses qui ne sont pas encore passée
			MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
			MySqlDataReader^ reader = command->ExecuteReader();
			try
			{
				while (reader->Read())
				{
					this->course_choix->Items->AddRange(gcnew cli::array< System::Object^  >(1) { reader->GetString(0) });
				}
			}
			catch (Exception^ ex)
			{

			}
			reader->Close();

		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Participant()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  nom_coureur;
	private: System::Windows::Forms::TextBox^  prenom_coureur;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::CheckBox^  masculin;
	private: System::Windows::Forms::CheckBox^  feminin;
	private: System::Windows::Forms::Button^  button_envoyer;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: MySqlConnection^ conn;

	private: static Participant^ ParticipantSingleton;
	private: System::Windows::Forms::DateTimePicker^  date_naissance;
	private: System::Windows::Forms::Button^  button_consulter;

	private: System::Windows::Forms::DataGridView^  dataGridView1;

	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::CheckBox^  checkBox_toutAfficher;
	private: System::Windows::Forms::ComboBox^  course_choix;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nomD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  prenomD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  date_de_naissanceD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  sexeD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseD;
	private: Bunifu::Framework::UI::BunifuElipse^  bunifuElipse1;
	private: System::Windows::Forms::Panel^  panel_entete;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label_reduire;

	private: System::Windows::Forms::Label^  label_fermer;
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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Participant::typeid));
			this->nom_coureur = (gcnew System::Windows::Forms::TextBox());
			this->prenom_coureur = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->masculin = (gcnew System::Windows::Forms::CheckBox());
			this->feminin = (gcnew System::Windows::Forms::CheckBox());
			this->button_envoyer = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->course_choix = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox_toutAfficher = (gcnew System::Windows::Forms::CheckBox());
			this->button_consulter = (gcnew System::Windows::Forms::Button());
			this->date_naissance = (gcnew System::Windows::Forms::DateTimePicker());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nomD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->prenomD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_de_naissanceD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->sexeD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CourseD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->bunifuElipse1 = (gcnew Bunifu::Framework::UI::BunifuElipse(this->components));
			this->panel_entete = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label_reduire = (gcnew System::Windows::Forms::Label());
			this->label_fermer = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bunifuDragControl1 = (gcnew Bunifu::Framework::UI::BunifuDragControl(this->components));
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->panel_entete->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// nom_coureur
			// 
			this->nom_coureur->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nom_coureur->Location = System::Drawing::Point(23, 40);
			this->nom_coureur->Multiline = true;
			this->nom_coureur->Name = L"nom_coureur";
			this->nom_coureur->Size = System::Drawing::Size(178, 37);
			this->nom_coureur->TabIndex = 0;
			// 
			// prenom_coureur
			// 
			this->prenom_coureur->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->prenom_coureur->Location = System::Drawing::Point(218, 40);
			this->prenom_coureur->Multiline = true;
			this->prenom_coureur->Name = L"prenom_coureur";
			this->prenom_coureur->Size = System::Drawing::Size(178, 37);
			this->prenom_coureur->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(67, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Nom du coureur:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(256, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Prénom du coureur:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(442, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Date de naissance:";
			// 
			// masculin
			// 
			this->masculin->AutoSize = true;
			this->masculin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->masculin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->masculin->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->masculin->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->masculin->Location = System::Drawing::Point(623, 60);
			this->masculin->Name = L"masculin";
			this->masculin->Size = System::Drawing::Size(79, 21);
			this->masculin->TabIndex = 4;
			this->masculin->Text = L"Masculin";
			this->masculin->UseVisualStyleBackColor = true;
			// 
			// feminin
			// 
			this->feminin->AutoSize = true;
			this->feminin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->feminin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->feminin->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->feminin->ForeColor = System::Drawing::Color::PaleVioletRed;
			this->feminin->Location = System::Drawing::Point(623, 33);
			this->feminin->Name = L"feminin";
			this->feminin->Size = System::Drawing::Size(73, 21);
			this->feminin->TabIndex = 3;
			this->feminin->Text = L"Féminin";
			this->feminin->UseVisualStyleBackColor = true;
			// 
			// button_envoyer
			// 
			this->button_envoyer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_envoyer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_envoyer->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_envoyer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_envoyer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_envoyer->ForeColor = System::Drawing::SystemColors::Menu;
			this->button_envoyer->Location = System::Drawing::Point(866, 13);
			this->button_envoyer->Name = L"button_envoyer";
			this->button_envoyer->Size = System::Drawing::Size(90, 32);
			this->button_envoyer->TabIndex = 5;
			this->button_envoyer->Text = L"S\'inscrire";
			this->button_envoyer->UseVisualStyleBackColor = false;
			this->button_envoyer->Click += gcnew System::EventHandler(this, &Participant::button_envoyer_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->course_choix);
			this->groupBox1->Controls->Add(this->prenom_coureur);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->checkBox_toutAfficher);
			this->groupBox1->Controls->Add(this->button_envoyer);
			this->groupBox1->Controls->Add(this->nom_coureur);
			this->groupBox1->Controls->Add(this->button_consulter);
			this->groupBox1->Controls->Add(this->date_naissance);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->feminin);
			this->groupBox1->Controls->Add(this->masculin);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->groupBox1->Location = System::Drawing::Point(92, 38);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1000, 121);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Inscription";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(756, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Course:";
			// 
			// course_choix
			// 
			this->course_choix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course_choix->FormattingEnabled = true;
			this->course_choix->Location = System::Drawing::Point(723, 47);
			this->course_choix->Name = L"course_choix";
			this->course_choix->Size = System::Drawing::Size(121, 26);
			this->course_choix->TabIndex = 9;
			this->course_choix->TabStop = false;
			// 
			// checkBox_toutAfficher
			// 
			this->checkBox_toutAfficher->AutoSize = true;
			this->checkBox_toutAfficher->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->checkBox_toutAfficher->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBox_toutAfficher->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->checkBox_toutAfficher->Location = System::Drawing::Point(866, 95);
			this->checkBox_toutAfficher->Name = L"checkBox_toutAfficher";
			this->checkBox_toutAfficher->Size = System::Drawing::Size(93, 20);
			this->checkBox_toutAfficher->TabIndex = 8;
			this->checkBox_toutAfficher->Text = L"Tout afficher";
			this->checkBox_toutAfficher->UseVisualStyleBackColor = false;
			// 
			// button_consulter
			// 
			this->button_consulter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_consulter->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_consulter->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->button_consulter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_consulter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_consulter->ForeColor = System::Drawing::SystemColors::Menu;
			this->button_consulter->Location = System::Drawing::Point(866, 57);
			this->button_consulter->Name = L"button_consulter";
			this->button_consulter->Size = System::Drawing::Size(90, 32);
			this->button_consulter->TabIndex = 6;
			this->button_consulter->Text = L"Consulter";
			this->button_consulter->UseVisualStyleBackColor = false;
			this->button_consulter->Click += gcnew System::EventHandler(this, &Participant::button_consulter_Click);
			// 
			// date_naissance
			// 
			this->date_naissance->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->date_naissance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date_naissance->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->date_naissance->Location = System::Drawing::Point(413, 45);
			this->date_naissance->Name = L"date_naissance";
			this->date_naissance->Size = System::Drawing::Size(173, 21);
			this->date_naissance->TabIndex = 2;
			this->date_naissance->Tag = L"";
			this->date_naissance->Value = System::DateTime(2019, 5, 31, 0, 0, 0, 0);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::Info;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id, this->nomD,
					this->prenomD, this->date_de_naissanceD, this->sexeD, this->CourseD
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(37, 39);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(674, 357);
			this->dataGridView1->TabIndex = 14;
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Participant::dataGridView1_CellValueChanged);
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Width = 50;
			// 
			// nomD
			// 
			this->nomD->HeaderText = L"Nom";
			this->nomD->Name = L"nomD";
			this->nomD->Width = 150;
			// 
			// prenomD
			// 
			this->prenomD->HeaderText = L"Prénom";
			this->prenomD->Name = L"prenomD";
			this->prenomD->Width = 150;
			// 
			// date_de_naissanceD
			// 
			this->date_de_naissanceD->HeaderText = L"Date de Naissance";
			this->date_de_naissanceD->Name = L"date_de_naissanceD";
			this->date_de_naissanceD->Width = 80;
			// 
			// sexeD
			// 
			this->sexeD->HeaderText = L"Sexe";
			this->sexeD->Name = L"sexeD";
			this->sexeD->Width = 50;
			// 
			// CourseD
			// 
			this->CourseD->HeaderText = L"Course";
			this->CourseD->Name = L"CourseD";
			this->CourseD->ReadOnly = true;
			this->CourseD->Width = 150;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->groupBox2->Location = System::Drawing::Point(234, 15);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(755, 431);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Résultat";
			// 
			// bunifuElipse1
			// 
			this->bunifuElipse1->ElipseRadius = 5;
			this->bunifuElipse1->TargetControl = this;
			// 
			// panel_entete
			// 
			this->panel_entete->BackColor = System::Drawing::Color::Red;
			this->panel_entete->Controls->Add(this->pictureBox1);
			this->panel_entete->Controls->Add(this->label5);
			this->panel_entete->Controls->Add(this->label_reduire);
			this->panel_entete->Controls->Add(this->label_fermer);
			this->panel_entete->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_entete->Location = System::Drawing::Point(0, 0);
			this->panel_entete->Name = L"panel_entete";
			this->panel_entete->Size = System::Drawing::Size(1209, 38);
			this->panel_entete->TabIndex = 16;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(32, 32);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::Info;
			this->label5->Location = System::Drawing::Point(41, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(112, 25);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Participant";
			// 
			// label_reduire
			// 
			this->label_reduire->AutoSize = true;
			this->label_reduire->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_reduire->Location = System::Drawing::Point(1138, 1);
			this->label_reduire->Name = L"label_reduire";
			this->label_reduire->Size = System::Drawing::Size(27, 37);
			this->label_reduire->TabIndex = 1;
			this->label_reduire->Text = L"-";
			this->label_reduire->Click += gcnew System::EventHandler(this, &Participant::label_reduire_Click);
			this->label_reduire->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Participant::label_reduire_MouseDown);
			this->label_reduire->MouseLeave += gcnew System::EventHandler(this, &Participant::label_reduire_MouseLeave);
			this->label_reduire->MouseHover += gcnew System::EventHandler(this, &Participant::label_reduire_MouseHover);
			// 
			// label_fermer
			// 
			this->label_fermer->AutoSize = true;
			this->label_fermer->BackColor = System::Drawing::Color::Red;
			this->label_fermer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_fermer->Location = System::Drawing::Point(1171, 4);
			this->label_fermer->Name = L"label_fermer";
			this->label_fermer->Size = System::Drawing::Size(30, 29);
			this->label_fermer->TabIndex = 0;
			this->label_fermer->Text = L"X";
			this->label_fermer->Click += gcnew System::EventHandler(this, &Participant::label_fermer_Click);
			this->label_fermer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Participant::label_fermer_MouseDown);
			this->label_fermer->MouseLeave += gcnew System::EventHandler(this, &Participant::label_fermer_MouseLeave);
			this->label_fermer->MouseHover += gcnew System::EventHandler(this, &Participant::label_fermer_MouseHover);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Location = System::Drawing::Point(0, 36);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1209, 187);
			this->panel1->TabIndex = 17;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 214);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1209, 473);
			this->panel2->TabIndex = 18;
			// 
			// bunifuDragControl1
			// 
			this->bunifuDragControl1->Fixed = true;
			this->bunifuDragControl1->Horizontal = true;
			this->bunifuDragControl1->TargetControl = this->panel_entete;
			this->bunifuDragControl1->Vertical = true;
			// 
			// Participant
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1209, 687);
			this->Controls->Add(this->panel_entete);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Participant";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Participant";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->panel_entete->ResumeLayout(false);
			this->panel_entete->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		public:
		static Participant^ getParticipantSingleton()
		{
			if (ParticipantSingleton == nullptr)
				ParticipantSingleton = gcnew Participant();
			return ParticipantSingleton;
		}

		int affecteCategorie(int annee, Char sexe_coureur) // Attribution des catégories de chaque coureur
		{
			int attributCategorie = 0;
			if (annee >= 2013)
				if (sexe_coureur == 'M' || sexe_coureur == 'F')
					attributCategorie = 1;		// Baby Athlé

			if (annee >= 2010 && annee <= 2012)
				if (sexe_coureur == 'M' || sexe_coureur == 'F')
					attributCategorie = 2;		// 	École d'Athlétisme 

			if (annee >= 2008 && annee <= 2009)
				if (sexe_coureur == 'M' || sexe_coureur == 'F')
					attributCategorie = 3;		// Poussin

			if (annee >= 2006 && annee <= 2007)
				if (sexe_coureur == 'M' || sexe_coureur == 'F')
					attributCategorie = 4;		// Benjamin

			if (annee >= 2004 && annee <= 2005)
				if (sexe_coureur == 'M' || sexe_coureur == 'F')
					attributCategorie = 5;		// Minime

			if (annee >= 2002 && annee <= 2003)
				if (sexe_coureur == 'M' || sexe_coureur == 'F')
					attributCategorie = 6;		// Cadet

			if (annee >= 2000 && annee <= 2001 && sexe_coureur == 'M')
				attributCategorie = 7;		// Junior Homme

			if (annee >= 2000 && annee <= 2001 && sexe_coureur == 'F')
				attributCategorie = 8;		// Junior Femme

			if (annee >= 1997 && annee <= 1999 && sexe_coureur == 'M')
				attributCategorie = 9;		// Espoir Homme

			if (annee >= 1997 && annee <= 1999 && sexe_coureur == 'F')
				attributCategorie = 10;		// Espoir Femme

			if (annee >= 1980 && annee <= 1996 && sexe_coureur == 'M')
				attributCategorie = 11;		// Senior Homme

			if (annee >= 1980 && annee <= 1996 && sexe_coureur == 'F')
				attributCategorie = 12;		// Senior Femme

			if (annee >= 1970 && annee <= 1979 && sexe_coureur == 'M')
				attributCategorie = 13;		// Master 1 Homme

			if (annee >= 1970 && annee <= 1979 && sexe_coureur == 'F')
				attributCategorie = 14;		// Master 1 Femme

			if (annee >= 1960 && annee <= 1969 && sexe_coureur == 'M')
				attributCategorie = 15;		// Master 2 Homme

			if (annee >= 1960 && annee <= 1969 && sexe_coureur == 'F')
				attributCategorie = 16;		// Master 2 Femme

			if (annee >= 1950 && annee <= 1959)
				if (sexe_coureur == 'M' || sexe_coureur == 'F')
					attributCategorie = 17;		// 	Master 3
			
			if (annee >= 1940 && annee <= 1949)
				if (sexe_coureur == 'M' || sexe_coureur == 'F')
					attributCategorie = 18;		// 	Master 4 

			if (annee <= 1939)
				if (sexe_coureur == 'M' || sexe_coureur == 'F')
					attributCategorie = 19;		// 	Master 5 

			return attributCategorie;
		}

		void envoyer()
		{
			/*----------- Vérifier si l'entrée n'existe pas dans la table 'coureur' -------------*/
			String^ requeteIDURSE = "SELECT idURSE FROM course WHERE nomURSE='" + course_choix->Text + "'";
			MySqlCommand^ commandIDURSE = gcnew MySqlCommand(requeteIDURSE, conn);
			MySqlDataReader^ readerIDURSE = commandIDURSE->ExecuteReader();
			readerIDURSE->Read();
			int idURSE = readerIDURSE->GetInt16(0);
			readerIDURSE->Close();

			String^ requeteVerifDoublon = "SELECT nomREUR FROM coureur WHERE nomREUR='" + nom_coureur->Text + "' && prenomREUR='" + prenom_coureur->Text + "' && idURSE=" + idURSE;
			MySqlCommand^ commandVerifDoublon = gcnew MySqlCommand(requeteVerifDoublon, conn);
			MySqlDataReader^ readerVerifDoublon = commandVerifDoublon->ExecuteReader();
			bool ok = readerVerifDoublon->Read(); // True si existe, sinon false si n'existe pas
			readerVerifDoublon->Close();

			/*----------- Insérer des données dans la table 'coureur' -------------*/
			if (!ok)
			{
				String^ date_inverser = date_naissance->Text[6].ToString() + date_naissance->Text[7] + date_naissance->Text[8] + date_naissance->Text[9] +
					date_naissance->Text[5] + date_naissance->Text[3] + date_naissance->Text[4] + date_naissance->Text[2] + date_naissance->Text[0] + date_naissance->Text[1]; //  Inversersement de la date pour se conformer au format de MySql

				Char sexe_coureur;
				if (masculin->Checked == true)
					sexe_coureur = 'M';
				else
					sexe_coureur = 'F';

				/*-------------------- Catégorie ------------------*/
				String^ a = date_naissance->Text[6].ToString() + date_naissance->Text[7] + date_naissance->Text[8] + date_naissance->Text[9];
				int annee = Convert::ToInt32(a);
				int categorie;
				categorie = affecteCategorie(annee, sexe_coureur); // Appel de la méthode "affecteCategorie" pour attribué la catégorie du coureur


				String^ requete = "INSERT INTO coureur (nomREUR,prenomREUR,date_naissance,sexeREUR,idURSE,idGORIE) VALUES ('" + nom_coureur->Text + "','" + prenom_coureur->Text + "','" + date_inverser + "','" + sexe_coureur + "'," + idURSE + "," + categorie + ")";
				MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
				try
				{
					command->ExecuteNonQuery();
					//MessageBox::Show("Inscription réussie !");
					dataGridView1->Rows->Clear();
					afficheTout();
					nom_coureur->Text = "";		prenom_coureur->Text = "";		masculin->Checked = false;	feminin->Checked = false;		date_naissance->Value = DateTime::Today;	course_choix->Text = "";
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("Erreur d'écriture de donnée dans la base de donnée!");
				}

			}
			else MessageBox::Show("Coureur déja inscrit !");
		}

		void afficheTout()
		{
			/*------- Affiche tout les données ---------*/
			String^ requeteAff = "SELECT idREUR, nomREUR, prenomREUR, date_naissance, sexeREUR, nomURSE FROM (coureur INNER JOIN course ON coureur.idURSE=course.idURSE)";
			MySqlCommand^ commandAffiche = gcnew MySqlCommand(requeteAff, conn);
			MySqlDataReader^ reader = commandAffiche->ExecuteReader();

			try
			{
				while (reader->Read())
				{
					String^ convert = reader->GetString(3); // Récupérer que la date en format 26/03/2019 sans l'heures
					convert = convert[0].ToString() + convert[1] + convert[2] + convert[3] + convert[4] + convert[5] + convert[6] + convert[7] + convert[8] + convert[9];

					this->dataGridView1->Rows->Add(reader->GetString(0), reader->GetString(1), reader->GetString(2), convert, reader->GetString(4), reader->GetString(5));
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Erreur de lecture!");
			}
			reader->Close();
		}

		void afficheNomPrenom()
		{
			String^ requeteAff = "SELECT idREUR, nomREUR, prenomREUR, date_naissance, sexeREUR, nomURSE FROM (coureur INNER JOIN course ON coureur.idURSE=course.idURSE) WHERE nomREUR='" + nom_coureur->Text + "' && prenomREUR='" + prenom_coureur->Text + "'";
			MySqlCommand^ commandAff = gcnew MySqlCommand(requeteAff, conn);
			MySqlDataReader^ reader = commandAff->ExecuteReader();

			try
			{
				while (reader->Read())
				{
					String^ convert = reader->GetString(3); // Récupérer que la date en format 26/03/2019
					convert = convert[0].ToString() + convert[1] + convert[2] + convert[3] + convert[4] + convert[5] + convert[6] + convert[7] + convert[8] + convert[9];

					this->dataGridView1->Rows->Add(reader->GetString(0), reader->GetString(1), reader->GetString(2), convert, reader->GetString(4), reader->GetString(5));
				}
				nom_coureur->Text = "";		prenom_coureur->Text = "";		masculin->Checked = false;	feminin->Checked = false;	date_naissance->Value = DateTime::Today;	course_choix->Text = "";
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Erreur de lecture!");
			}
			reader->Close();
		}

		void afficheCondition()
		{
			/*---------------- Affichage des données selon condition -----------------*/
			String^ date_inverser = date_naissance->Text[6].ToString() + date_naissance->Text[7] + date_naissance->Text[8] + date_naissance->Text[9] +
				    date_naissance->Text[5] + date_naissance->Text[3] + date_naissance->Text[4] + date_naissance->Text[2] + date_naissance->Text[0] + date_naissance->Text[1]; //  Inversersement de la date pour se conformer au format de MySql
			String^ sexe_coureur;
			if (masculin->Checked == true) sexe_coureur = "M";
			else if (feminin->Checked == true) sexe_coureur = "F";

			String^ requeteAff = "SELECT idREUR, nomREUR, prenomREUR, date_naissance, sexeREUR, nomURSE FROM (coureur INNER JOIN course ON coureur.idURSE=course.idURSE) WHERE nomREUR='" + nom_coureur->Text + "' || prenomREUR='" + prenom_coureur->Text + "' || date_naissance='" + date_inverser + "' || sexeREUR='" + sexe_coureur + "' || nomURSE='" + course_choix->Text + "'";
			MySqlCommand^ commandAff = gcnew MySqlCommand(requeteAff, conn);
			MySqlDataReader^ reader = commandAff->ExecuteReader();

			try
			{
				while (reader->Read())
				{
					String^ convert = reader->GetString(3); // Récupérer que la date en format 26/03/2019
					convert = convert[0].ToString() + convert[1] + convert[2] + convert[3] + convert[4] + convert[5] + convert[6] + convert[7] + convert[8] + convert[9];

					this->dataGridView1->Rows->Add(reader->GetString(0), reader->GetString(1), reader->GetString(2), convert, reader->GetString(4), reader->GetString(5));
				}
				nom_coureur->Text = "";		prenom_coureur->Text = "";			masculin->Checked = false;	feminin->Checked = false;		date_naissance->Value = DateTime::Today;	course_choix->Text = "";
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Erreur de lecture!");
			}
			reader->Close();
		}

		void modifierDonnees()
		{
			
			/*----------- Modifier des données dans la table 'COUREUR' -------------*/
			//int reussi = 0;
			//int erreur = 0;
			for (int i(0); i < dataGridView1->RowCount; i++)	// RowsCount: Le nombre de lignes du dataGridView
			{
				String^ dateNaissance = dataGridView1->Rows[i]->Cells[3]->Value->ToString();
				String^ date_inverser = dateNaissance[6].ToString() + dateNaissance[7] + dateNaissance[8] + dateNaissance[9] + dateNaissance[5] + dateNaissance[3] + dateNaissance[4] + dateNaissance[2] + dateNaissance[0] + dateNaissance[1]; //  Inversersement de la date pour se conformer au format de MySql


				String^ sexeDuCoureur = dataGridView1->Rows[i]->Cells[4]->Value->ToString();
				Char sexe_coureur = sexeDuCoureur[0];

				/*-------------------- Catégorie ------------------*/
				String^ a = dateNaissance[6].ToString() + dateNaissance[7] + dateNaissance[8] + dateNaissance[9];
				int annee = Convert::ToInt32(a);
				int categorie = 0;
				categorie = affecteCategorie(annee, sexe_coureur); // Appel de la méthode "affecteCategorie" pour attribué la catégorie du coureur																																																								/*-------------------- Catégorie ------------------*/

				if (categorie != 0)
				{
					String^ requete = "UPDATE coureur SET nomREUR='" + dataGridView1->Rows[i]->Cells[1]->Value->ToString() + "', prenomREUR='" + dataGridView1->Rows[i]->Cells[2]->Value->ToString() + "', date_naissance='" + date_inverser + "', sexeREUR='" + dataGridView1->Rows[i]->Cells[4]->Value->ToString() + "', idGORIE='" + categorie + "' WHERE idREUR='" + dataGridView1->Rows[i]->Cells[0]->Value + "'";

					MySqlCommand^ command = gcnew MySqlCommand(requete, conn);
					try
					{
						command->ExecuteNonQuery();
						//if (reussi < 1) // Affiche une fois le message
						//{
							//MessageBox::Show("Modification pris en compte !");
							//reussi++;
						//}
					}
					catch (Exception^ ex)
					{
						MessageBox::Show("Erreur d'écriture de donnée dans la base de donnée!");
					}
				}
				else
				{
					MessageBox::Show("Sexe non reconnu !");
					dataGridView1->Rows->Clear();
					afficheTout();
				}
			}
		}

#pragma endregion
private: System::Void button_envoyer_Click(System::Object^  sender, System::EventArgs^  e) {
	if (nom_coureur->Text != "" && prenom_coureur->Text != "" && course_choix->Text != "")
	{
		if (masculin->Checked == true || feminin->Checked == true) envoyer();
		else MessageBox::Show("Indiquer le sexe !");
	}
	else MessageBox::Show("Veuillez remplir tous les champs !");
}

private: System::Void button_consulter_Click(System::Object^  sender, System::EventArgs^  e) {
	dataGridView1->Rows->Clear();
	if (checkBox_toutAfficher->Checked == true)
	{
		afficheTout();
		checkBox_toutAfficher->Checked = false;
	}
	else if (nom_coureur->Text != "" && prenom_coureur->Text != "") afficheNomPrenom();
	else afficheCondition();
}

private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	modifierDonnees();
}

/* ------- Design -------- */
/* Réduire */
private: System::Void label_reduire_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
private: System::Void label_reduire_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	label_reduire->BackColor = Color::Red;
}
private: System::Void label_reduire_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	label_reduire->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
		static_cast<System::Int32>(static_cast<System::Byte>(244)));
}
private: System::Void label_reduire_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	label_reduire->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
		static_cast<System::Int32>(static_cast<System::Byte>(166)));
}

/* Fermer */
private: System::Void label_fermer_Click(System::Object^  sender, System::EventArgs^  e) {
	conn->Close(); // Fermeture de la connexion avec la base de donnée
	ParticipantSingleton = nullptr;	// Pour pouvoir encore l'instancié (Singleton)
	this->Close(); // Fermer cette fenêtre uniquement
}
private: System::Void label_fermer_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	label_fermer->BackColor = Color::Red;
}
private: System::Void label_fermer_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	label_fermer->BackColor = Color::Yellow;
}
private: System::Void label_fermer_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	label_fermer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
		static_cast<System::Int32>(static_cast<System::Byte>(128)));
}
};
}
