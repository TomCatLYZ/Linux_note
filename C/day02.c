关键字：vi  gcc 少量C知识

vi 是Linux系统下里用来记录文字信息的工具

vi只能在终端窗口里使用(不能使用鼠标)

vi的功能被分成三组，任何时候只能使用其中的一组
vi提供三种工作模式，每种工作模式对应一组功能
任何时候只能处于一种工作模式下

* vi三种工作模式 ： 正常模式  插入模式  命令模式
正常模式下可以执行 简单命令
插入模式下可以修改 文字内容
命令模式下可以执行 复杂命令

每当启动vi的时候一定处于正常模式下

*不同工作模式间转换:正常模式下输入 i 可以进入插入模式(在光标当前位置插入)
			      输入 a 在光标所在位置后插入
			      输入 o(小写o) 在光标所在行下插入一个空行
			      输入 O(大写O) 在光标所在行上插入一个空行
		    正常模式下输入 ：可以进入命令模式
		    任何模式  输入Esc可以进入正常模式

启动vi 	命令如下
	vi  文件路径   /*vi day02.txt   vi ADC.c */

* 两种方法退出vi
	1.在命令模式下输入 q! (不存盘退出)
	2.在命令模式下输入 wq 或 x (存盘并退出)

*在命令模式下输入 w 可以只保存修改而不退出vi
	     输入 w newfile 存成新文件

*在正常模式下移动光标
	k 向上
	j 向下
	h 向左
	l 向右
*
(复制)在正常模式下输入 nyy 命令可以把光标所在行开始的连续n行*复制*到剪贴板
	(如果n是1可以省略)
(粘帖)在正常模式下输入 np 命令可以把剪贴板上的内容在光标所在行下面粘帖n次
	(如果n是1也可以省略)
(剪切)在正常模式下输入 ndd 命令可以把光标所在行开始的连续n行*剪切*到剪贴板
	(如果n是1可以省略)

*在正常模式下 yw  拷贝词
	     yy  拷贝行（或Y）
	     dd  剪切行
	     p   当前行下粘帖

*
在正常模式下 x 删除一个字符
	    dw 删除当前词
	    3dw 删除三个词  /* 一堆符号 算一个词 */

*
在正常模式下 ～ 改变光标所在位的字符大小写
	     u   就是undo的意思
	    1G  光标停在指定行
			(1G:停在第一行 3G:停在第三行 数字超过行数 则停在文件尾 单按G也会到达文件尾)

	    /串  从当前行往下查找
	    ?串  从当前行往上查找
	    n    继续查找

*在命令模式下输入 set nu 命令可以让vi显示每行的行号
		  set nonu  取消显示行号

gVim 是Windows里的vi

*********************************************************************
.c文件 叫做C语言源文件  
.h文件 叫做头文件

C语言中每个计算步骤最后都必须使用；结束，使用；结束的计算步骤叫一条语句
main函数  主函数
函数结束时可以用一个数字表示它的工作结果，这个数字叫做函数的返回值
主函数应该有一个返回值，如果返回值是0 ，表示程序希望计算机认为它正常结束了。如果不是0 表示程序希望计算机认为它遇到问题了

C语言里预先保留里几十个英文单词，这些单词叫做关键字
每个关键字都有特定的用途，不能随便使用
所有关键字都是用小写英文字母构成
return 就是一个关键字，它的主要用途是结束函数的执行，辅助用途是指定返回值的数值
void 返回值类型的函数，单单使用 return； 用于结束这个函数

计算机里根据数字在某个方面的区别把数字分成几组，每组叫做一个数据类型
每个数据类型都有名字
整数是一种数据类型，它的名字是int 
这个类型里包含几乎所有不带小数点的数字

程序里的所有数字都必须有类型
程序中所有不带小数点的数字默认都是整数类型

如果函数有返回值就必须把返回值的类型名称写在 函数名称 前  
	/*void main()    int main()*/

C语言程序编码规范
1.一行里最多包含一条语句
2.被同一对大括号包含的语句最左边一列应该上下对齐
3.在合适的地方使用空格和空行提高程序的可读性

C语言程序中通常包含预处理指令
预处理指令以#做开头，不是以;做结尾
#include是一个预处理指令，它可以把一个头文件的内容包含到当前文件中
这个预处理指令中需要使用相对路径表示头文件的位置
把相对路径包含在<>里表示以系统中预先规定好的一组目录作为起点依次查找头文件 
     /*这个相对路径和终端中的不一样，其实这个相对路径的概念没卵用，也可能有用 待查 -> 已查有用*/
把相对路径包含在""里表示首先以当前文件所在目录作为起点查找，然后再以系统中预先规定好的目录作为起点查找

注释：单行注释以//做开头，一直到行尾为止
      多行注释以/*做开头，以*/做结尾 

C语言中大量采用名称区分不同内容 这些名称叫做标识符
标识符最好都采用英文单词
*标识符的书写规则
1.第一个字符应该可以是英文字母或下划线
2.后面的每个字符可以是英文字母，下划线或阿拉伯数字
3.大小写不同的标识符是不同的标识符(大小写敏感)
4.关键字不能作为标识符使用
5.标识符长度没有限制，但是计算机只会截取前面一部分使用
6.标识符应该采用驼峰方式或下划线方式书写

**********************************************************************

*编译器负责把编写好的程序翻译成计算机能认识的格式
gcc是Linux系统里C语言的编译器
MinGW是Windows里的gcc

*Linux系统里c语言程序基本开发步骤
1.使用vi编写源文件
2.使用gcc把所有源文件翻译成计算机认识的格式（编译） /*gcc 文件名.c */
3.使用./a.out作为命令执行得到的文件

*gcc编译器工作过程
1.处理所有预处理指令
2.把第一步的处理结果翻译成计算机认识的格式（编译）
3.把第二步的结果合并成执行文件（链接）

*gcc选项介绍
	-E  只处理预处理指令
	-c  只完成预处理和编译   处理结果是以.o作为扩展名的目标文件
	-o  自定义得到的结果文件的名称  /*gcc 名称.c -o 要改的名称*/
		  更改a.out的名称   gcc ADC.c -o ASD 
*	-Wall 编译器检测到可能的错误时并生成警告消息 
			/* gcc -Wall 文件名.c  */
	-S  产生汇编文件

-std=c89 或 -std=c99
		这个选项决定采用哪个版本的规范进行编译
		默认采用c89规范编译
		/* gcc -std=c99 文件名.c */

**********************************************************************

c语言里预先提供一组工具，这组工具叫做标准函数
每个标准函数可以解决一个常见问题
程序中可以编写函数调用语句来使用某个标准函数

printf标准函数可以把程序中的数字显示在终端窗口里
为了使用这个标准函数需要包含stdio.h头文件
可以把双引号里面的数字转移到双引号后面，这个时候双引号里面必须使用占位符表示数字应该出现的位置
不同类型的数字应该和不同占位符配合使用
	整数类型数字应该和%d占位符配合使用
双引号后面的数字可以是一个计算公式的结果

程序中所有数字都必须记录在内存里
内存由大量字节构成，每个字节可以单独记录一个数字
每个字节有一个编号，不同字节的编号不同。这个编号叫做字节的地址
所有字节的地址从0开始向上依次递增

内存中几个相邻字节可以合并在一起用来记录一个数字
可以把内存中用来记录一个数字的所有字节统称为存储区（为讲课方便发明的）
一个存储区记录的数字类型必须相同
存储区也有地址，它的地址是它所包含的字节中地址最小字节的地址

程序中可以使用变量代表存储区，
	对变量的操作就是对存储区的操作
变量必须先声明然后才能使用
可以在一条语句里声明多个同类型的变量

赋值语句可以向变量里放一个数字
赋值语句里使用赋值操作符(=)
赋值操作符左边的内容必须可以代表一个存储区，这种内容叫做左值
	  右边的内容必须可以代表数字
	  可以把右边的数字记录到左边的存储区里

可以在声明变量的时候立刻对变量进行赋值，这叫做变量的初始化
C语言里所有变量都应该初始化

可以在程序中直接把变量当作数字使用，这个时候计算机会首先获得数字然后再进行计算

变量名称既可以代表存储区也可以代表存储区里的数字，由环境决定代表什么

预习：变量 数据类型 scanf sizeof 二进制
作业：编写长方形面积 用变量长 7 宽3 

