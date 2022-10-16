using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_4_DB
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            
            InitializeComponent();
        }
        
        // private void CreateNewLabel(int column, int row, TextBox info)
        // {
        //     var newLabel = new Label();
        //     newLabel.Name = "Label" + Convert.ToString(column) + Convert.ToString(row);
        //     newLabel.Text = Convert.ToString(info.Text, CultureInfo.InvariantCulture);
        //     newLabel.AutoSize = true;
        //     
        //     this.Controls.Add(tableLayoutPanel1);
        //     tableLayoutPanel1.Controls.Add(newLabel, column, row);
        //
        // }
        
        private void label6_Click(object sender, EventArgs e)
        {
            throw new NotImplementedException();
        }
        
        private void button2_Click(object sender, EventArgs e)
        {
            throw new NotImplementedException();
            // var row = tableLayoutPanel1.Controls.Container.RowCount++;
            // tableLayoutPanel1.Controls.Container.RowCount = row;
            // CreateNewLabel(0, row, textBox4);
            // CreateNewLabel(1, row, textBox5);
            // CreateNewLabel(2, row, textBox1);
            // CreateNewLabel(3, row, textBox6);
            // CreateNewLabel(4, row, textBox7);
            // CreateNewLabel(5, row, textBox8);

        }
    }
}