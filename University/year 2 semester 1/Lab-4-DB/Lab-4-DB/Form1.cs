using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
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

        private void label6_Click(object sender, EventArgs e)
        {
            throw new System.NotImplementedException();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            tableLayoutPanel1.Controls.Container.RowCount = tableLayoutPanel1.Controls.Container.RowCount++;
            Label newLabel = new Label();
            newLabel.Name = "Label1" + Convert.ToString(tableLayoutPanel1.Controls.Container.RowCount);
            newLabel.Text = Convert.ToString(numericUpDown3.Value);
            newLabel.AutoSize = true;
            
            this.Controls.Add(tableLayoutPanel1);
            tableLayoutPanel1.Controls.Add(newLabel, 1, tableLayoutPanel1.Controls.Container.RowCount);

        }
    }
}