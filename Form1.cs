using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace атомный_распад
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            WindowState = FormWindowState.Maximized;
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            string file = @"уран.exe";
            Process.Start(file);
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            string file = @"плутоний.exe";
            Process.Start(file);
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            string file = @"цезий.exe";
            Process.Start(file);
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            string file = @"стронций.exe";
            Process.Start(file);
        }

        private void Button5_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
