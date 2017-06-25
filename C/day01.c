关键字：终端(terminal)  路径  命令 选项

软件分为 系统软件 和 应用软件
系统软件 主要用实现对硬件的管理
应用软件 用来满足使用者的各种需要

Windows  Unix  Linux

通过 终端(terminal) 使用Linux系统
终端 不能使用鼠标 只能使用键盘
在终端窗口里通过命令控制计算机

常见命令
	* clear 清除终端窗口里所有文字信息

操作系统中用来管理文件的部分叫 文件系统
文件系统采用 分组方式 管理文件，每个分组里可以包含任意数量的文件
一个分组里文件还可以再次分组
文件系统中的一个文件分组叫做文件夹或目录
如果目录A包含目录B，它们之前存在父子关系。目录A叫做父目录，目录B叫子目录

Linux文件系统中有一个大分组，这个分组包含所以文件
这个分组叫做根目录，可以在终端窗口里采用 / 代表根目录

*
路径 表示文件或文件夹的位置
     从某个文件夹开始到某个文件或文件夹为止中间的路线
路径又分为 绝对路径 和 相对路径，区别在于它们的起点不同。
	绝对路径的起点必须是根目录，必须以 / 开头
	相对路径的起点可以是任何目录
	相对路径里使用..表示向上走一步，用.表示原地踏步
	相对路径里不需要包含起点位置

                    /
      abc          def           xyz
   vbn   pqr       iop        asd   jkl

/xyz/asd     asd的绝对路径      
../../xyz/asd    以vbn为起点,以asd为终点 相对路径 

终端窗口里可以设置当前目录，这个目录作为相对路径的起点使用，当前目录的位置可以改变。

*命令 选项 [参数]

* pwd命令可以用来查看当前目录的位置

* cd命令可以改变当前目录的位置
	使用方法  cd 目录路径 /*是路径 不是目录名 子父目录直接用目录名*/

* ls命令可以查看一个目录里的内容
	使用方法  ls 目录路径
	如果省略路径就能查看当前目录里的内容(不包含隐藏文件)

	*使用-a选项可以查看目录里的所有内容(包含隐藏文件)    /* ls -a */
	*使用-l选项可以查看每个项目的详细信息   /* ls -l */
	*这两个选项可以合并成-al,既能看见所以内容又能看见详细信息

* touch命令可以用来创建新的文件
	使用方法  touch 文件路径
	如果文件已经存在就把文件的最后修改时间改成执行touch命令的时间

* rm命令可以删除文件
	使用方法  rm 文件路径
	
	*rm命令也可以用来删除目录，这个时候要加-r选项 /* rm -r */

* mkdir命令可以用来创建目录
	使用方法  mkdir 目录路径
	目录本身必须不存在，但父目录必须存在

	*使用-p选项可以把路径中所有不存在的目录都创建出来

* cat命令可以用来查看文件内容
	使用方法  cat 文件路径  (查看文件内容 文件)

预习 vi的使用  c语言

作业 假设要开发一个叫做BankATM的系统，这个系统分成客户端（client）和服务器端（server）两部分。要求创建一组目录把这个系统的所有文件和其他文件隔离开，两个部分的文件之间也要隔离开
  答案  mkdir BankATM
	mkdir BankATM/client
	mkdir BankATM/server


