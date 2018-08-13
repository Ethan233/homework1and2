using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;//用到了正则表达式 

namespace WindowsFormsApp5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //Form1关闭事件

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (MessageBox.Show("是否关闭程序？", "标题栏", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                e.Cancel = false;//确定关闭
            }
            else
            {
                e.Cancel = true;//不关闭
            }
        }

        //Button1的点击事件

        private void 判断_Click(object sender, EventArgs e)
        {

            if (new Regex("^[0-9]+$").IsMatch(textBox1.Text) || new Regex("^[-][0-9]+$").IsMatch(textBox1.Text))//利用正则表达式判断是否输入的是数字 
            {
                int year = int.Parse(textBox1.Text);//将textBox1的文本转化为整形
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                {
                    MessageBox.Show("输入的是闰年！");
                }
                else
                {
                    MessageBox.Show("输入的不是闰年！");
                }
            }
            else
            {
                MessageBox.Show("输入的不是正常的年份！请重新输入！");
            }

        }
    }
}
