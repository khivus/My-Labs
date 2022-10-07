#pragma once
#include "treeDLL.h"

namespace WindowsFormsTemplate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int multiplier = 1;
	double doter = 25;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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

	protected:
	private: System::Windows::Forms::Button^ InsertBTN;
	private: System::Windows::Forms::NumericUpDown^ Insertnumeric;
	private: System::Windows::Forms::Button^ OutputBTN;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ SumBTN;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ delBTN;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ destroyBTN;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->InsertBTN = (gcnew System::Windows::Forms::Button());
			this->Insertnumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->OutputBTN = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SumBTN = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->delBTN = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->destroyBTN = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Insertnumeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// InsertBTN
			// 
			this->InsertBTN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InsertBTN->Location = System::Drawing::Point(12, 12);
			this->InsertBTN->Name = L"InsertBTN";
			this->InsertBTN->Size = System::Drawing::Size(113, 34);
			this->InsertBTN->TabIndex = 1;
			this->InsertBTN->Text = L"Add element";
			this->InsertBTN->UseVisualStyleBackColor = true;
			this->InsertBTN->Click += gcnew System::EventHandler(this, &MainForm::InsertBTN_Click);
			// 
			// Insertnumeric
			// 
			this->Insertnumeric->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Insertnumeric->Location = System::Drawing::Point(146, 17);
			this->Insertnumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999, 0, 0, 0 });
			this->Insertnumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Insertnumeric->Name = L"Insertnumeric";
			this->Insertnumeric->Size = System::Drawing::Size(53, 26);
			this->Insertnumeric->TabIndex = 2;
			this->Insertnumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// OutputBTN
			// 
			this->OutputBTN->Enabled = false;
			this->OutputBTN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OutputBTN->Location = System::Drawing::Point(12, 64);
			this->OutputBTN->Name = L"OutputBTN";
			this->OutputBTN->Size = System::Drawing::Size(113, 49);
			this->OutputBTN->TabIndex = 4;
			this->OutputBTN->Text = L"Preorder output\r\n";
			this->OutputBTN->UseVisualStyleBackColor = true;
			this->OutputBTN->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(146, 64);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(162, 65);
			this->textBox1->TabIndex = 5;
			// 
			// SumBTN
			// 
			this->SumBTN->Enabled = false;
			this->SumBTN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SumBTN->Location = System::Drawing::Point(12, 143);
			this->SumBTN->Name = L"SumBTN";
			this->SumBTN->Size = System::Drawing::Size(112, 49);
			this->SumBTN->TabIndex = 6;
			this->SumBTN->Text = L"Sum of elements";
			this->SumBTN->UseVisualStyleBackColor = true;
			this->SumBTN->Click += gcnew System::EventHandler(this, &MainForm::SumBTN_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(146, 143);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(90, 32);
			this->textBox2->TabIndex = 5;
			// 
			// delBTN
			// 
			this->delBTN->Enabled = false;
			this->delBTN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->delBTN->Location = System::Drawing::Point(12, 213);
			this->delBTN->Name = L"delBTN";
			this->delBTN->Size = System::Drawing::Size(111, 48);
			this->delBTN->TabIndex = 7;
			this->delBTN->Text = L"Delete element";
			this->delBTN->UseVisualStyleBackColor = true;
			this->delBTN->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Enabled = false;
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown1->Location = System::Drawing::Point(146, 225);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(53, 26);
			this->numericUpDown1->TabIndex = 8;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// destroyBTN
			// 
			this->destroyBTN->Enabled = false;
			this->destroyBTN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->destroyBTN->Location = System::Drawing::Point(10, 286);
			this->destroyBTN->Name = L"destroyBTN";
			this->destroyBTN->Size = System::Drawing::Size(113, 38);
			this->destroyBTN->TabIndex = 9;
			this->destroyBTN->Text = L"Destroy tree";
			this->destroyBTN->UseVisualStyleBackColor = true;
			this->destroyBTN->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(853, 538);
			this->Controls->Add(this->destroyBTN);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->delBTN);
			this->Controls->Add(this->SumBTN);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->OutputBTN);
			this->Controls->Add(this->Insertnumeric);
			this->Controls->Add(this->InsertBTN);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BinaryTree";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Insertnumeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:Treenode* root = 0;

	private: int sumBT(Treenode* root) {
		if (root != 0) {
			return (root->number + sumBT(root->left) + sumBT(root->right));
		}
	}

	private: Treenode* dtree(Treenode* tree, int key) {
		Treenode* p, * p2;
		if (!tree) return tree;
		if (tree->number == key) {
			if (tree->left == 0 && tree->right == 0) {
				delete tree;
				tree = 0;
				return 0;
			}
			else if (tree->left == 0) {
				p = tree->right;
				p->parent = tree->parent;
				p->x = tree->x;
				p->y = tree->y;
				p->lvl = tree->lvl;
				delete tree;
				return p;
			}
			else if (tree->right == 0) {
				p = tree->left;
				p->parent = tree->parent;
				p->x = tree->x;
				p->y = tree->y;
				p->lvl = tree->lvl;
				delete tree;
				return p;
			}
			else {
				p2 = tree->right;
				p = tree->right;
				while (p->left)
				{
					p = p->left;
				}
				tree->number = p->number;
				tree->lvl = p->lvl;
				if (p->parent->left != tree->left)
				{
					p->parent->left = 0;
					dtree(p, p->number);
				}
				else
				{
					tree->right = dtree(tree->right, tree->right->number);
				}
				return tree;
			}
		}
		if (tree->number < key)tree->right = dtree(tree->right, key);
		else tree->left = dtree(tree->left, key);
		return tree;
	}

	private: Treenode* find_all(Treenode* tree, int x) {
		if (tree != 0) {
			tree->left = find_all(tree->left, x);
			tree->right = find_all(tree->right, x);
			if (tree->number == x) {
				tree = dtree(tree, x);
			}
			return tree;
		}
	}

	private: System::Void treeprint(Treenode* tree) {
		if (tree) {
			Graphics^ g = Graphics::FromHwnd(this->Handle);
			System::Drawing::Font^ font_1 = gcnew Drawing::Font("Arial", 20);
			Pen^ arrow = gcnew Pen(Color::Black, 2);
			arrow->CustomEndCap = gcnew System::Drawing::Drawing2D::AdjustableArrowCap(4, 5, true);
			treeprint(tree->left);

			g->DrawEllipse(Pens::Black, tree->x, tree->y, 50, 50);
			if (tree->number < 10) {
				g->DrawString(Convert::ToString(tree->number), font_1, Brushes::Black, tree->x + 11, tree->y + 8);
			}
			else if (tree->number < 100) {
				g->DrawString(Convert::ToString(tree->number), font_1, Brushes::Black, tree->x + 5, tree->y + 8);
			}
			else {
				g->DrawString(Convert::ToString(tree->number), font_1, Brushes::Black, tree->x - 3, tree->y + 8);
			}
			if (tree->left != 0) {
				g->DrawLine(arrow, tree->x + 3, tree->y + 33, tree->left->x + 22, tree->y + 50);
			}
			if (tree->right != 0) {
				g->DrawLine(arrow, tree->x + 43, tree->y + 33, tree->right->x + 25, tree->y + 50);
			}
			treeprint(tree->right);
		}
	}

	private: System::Void refresh(Treenode* tree, int max, int lvl) {
		if (tree) {
			if (tree->parent) {
				tree->lvl = lvl;
				if (tree->parent->left == tree) {
					tree->y = tree->parent->y + 50;
					tree->x = tree->parent->x - doter * Math::Pow(2, max - 1);
				}
				else {
					tree->y = tree->parent->y + 50;
					tree->x = tree->parent->x + doter * Math::Pow(2, max - 1);
				}
			}
			refresh(tree->left, max - 1, lvl + 1);
			refresh(tree->right, max - 1, lvl + 1);
		}
	}

	private: System::Void printPreorder(Treenode* root) {
		if (root) {
			textBox1->AppendText(Convert::ToString(root->number) + " ");
			printPreorder(root->left);
			printPreorder(root->right);
		}
	}

	private: System::Void InsertBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		int max;
		max = find_maxlvl(root, 0);
		root = addnode(root, Convert::ToInt32(Insertnumeric->Value), 1000, 50, 0, 1);
		multiplier = max;
		Graphics^ g = Graphics::FromHwnd(this->Handle);
		g->Clear(Color::White);
		refresh(root, multiplier, 1);
		treeprint(root);
		destroyBTN->Enabled = 1;
		OutputBTN->Enabled = 1;
		SumBTN->Enabled = 1;
		delBTN->Enabled = 1;
		numericUpDown1->Enabled = 1;
		textBox1->Text = "";
		textBox2->Text = "";
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "";
		printPreorder(root);
	}

	private: System::Void SumBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		int sum = sumBT(root);
		textBox2->Text = Convert::ToString(sum);
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		root = find_all(root, Convert::ToInt32(numericUpDown1->Value));
		Graphics^ g = Graphics::FromHwnd(this->Handle);
		g->Clear(Color::White);
		int max = find_maxlvl(root, 0);
		multiplier = max;
		refresh(root, multiplier, 1);
		treeprint(root);
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (root) {
			destroy_tree(root);
			root = 0;
			Graphics^ g = Graphics::FromHwnd(this->Handle);
			g->Clear(Color::White);
		}
		destroyBTN->Enabled = 0;
		OutputBTN->Enabled = 0;
		SumBTN->Enabled = 0;
		delBTN->Enabled = 0;
		numericUpDown1->Enabled = 0;
		textBox1->Text = "";
		textBox2->Text = "";
	}

	private: System::Void MainForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		destroy_tree(root);
		root = 0;
		Graphics^ g = Graphics::FromHwnd(this->Handle);
		g->Clear(Color::White);
	}
};
}
