#**郭宇嘉的Demo**<br>
---
##功能

判断某一年是否为闰年<br>

##如何实现

1.利用正则表达式判断是否输入的是数字<br>
>`if (new Regex("^[0-9]+$").IsMatch(textBox1.Text) || new Regex("^[-][0-9]+$").IsMatch(textBox1.Text))//利用正则表达式判断是否输入的是数字`<br>

2.判断是否为闰年
```
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                {
                    MessageBox.Show("输入的是闰年！");
                }
                else
                {
                    MessageBox.Show("输入的不是闰年！");
                }

```
-----
```
else
            {
                MessageBox.Show("输入的不是正常的年份！请重新输入！");
            }
```

##如何运行

1.下载Visual Studio 2017

2.打开文件"WindowsFormsApp5.sln"

3.点击启动按钮，即出现如下程序窗体：

![](https://raw.githubusercontent.com/hust-p/homework1/master/QQ%E5%9B%BE%E7%89%8720180813231633.png)

4.输入任意数字，点击判断按钮，即可判断是否为闰年。

