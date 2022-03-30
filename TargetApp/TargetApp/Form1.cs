using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TargetApp
{
    public partial class Form1 : Form
    {
        private int aimVariable = 1337;

        public Form1()
        {
            InitializeComponent();
        }

        private void writeBtn_Click(object sender, EventArgs e)
        {
            try
            {
                aimVariable = Convert.ToInt32(textBox1.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void readBtn_Click(object sender, EventArgs e)
        {
            textBox2.Text = Convert.ToString(aimVariable);
        }
    }
}
