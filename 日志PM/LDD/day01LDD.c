�ؼ��֣��û��ռ� �ں˿ռ�  		�ں˳������ 		
					#include <linux/init.h>
					#include <linux/module.h>   
	�ں˳���������д��� module_param
	�ں˳�����ļ����� EXPORT_SYMBOL_GPL(���������߱�����)

һ.Ƕ��ʽlinux �豸���������������
��linux�豸�������򡷵�����  �о�����Ĵ���
��linux�ں������ʵ�֡�������
������һ��дMakefile��
�����⣺��ο���һ��linuxӲ���豸������
������ʾ��Ƕ��ʽlinuxϵͳ���������Ժ�Ҫ�������ʱ����ڿ���������Ӳ�����豸���������ϡ�����������������������Ҫ���в��ԣ����Ե�ǰ����Ҫ���ö���
	 ����������û��������Ҫ�����������Ӳ�����豸������
-------------------------------------------------------------------------------
����SecureCRTԶ�̵�¼linuxϵͳ�����ù��̣�
�򿪿�������-> Э�飺ssh2          
              ��������192.168.1.8
              �û�����tarena
->����->��������->����SecureCRT->ѡ��->�Ựѡ��->����->�նˣ�ANSI
                                                       ʹ����ɫ����ѡ��
->��ۣ������Լ�ϲ��������Courier New
	�ַ����룺UTF-8
	����
->���´�SecureCRT����

--------------------------------------------------------------------------------
1. �豸��������
   һ�������Ĺؼ��������ݣ�
   1. ��Ӳ���������������̽��з�װ
   2. �����ܹ����û��ṩ���ʲ���Ӳ���Ľӿڣ�������
      �����û����ú����ܹ�������Ӳ��

2. linuxϵͳ�������ռ䣨����״̬�����û��ռ���ں˿ռ�

   �û��ռ䣺
            �ֳ��û�̬
            ������������Ǹ����������Ӧ�ó��򣬸��ֿ⣬�������÷���
            �û��ռ����������е�ʱ��CPU�Ĺ���ģʽΪUSERģʽ��
            �û��ռ��������ܷ���Ӳ���豸�������ַ�����Ҫ����Ӳ�������ַ���뽫Ӳ������������ַӳ�䵽�û��ռ�������ַ�ϡ�
            �û��ռ���������ֱ�ӷ����ں˿ռ�Ĵ��룬��ַ������
	    �û��ռ�����������зǷ����ڴ���ʣ����ᵼ�²���ϵͳ��������Ӧ������ᱻ����ϵͳ�ɵ������磺*��int*��0=0��
       	    �û��ռ�����������̳����ͨ�û�
  	    �û��ռ�������ַ�ռ��СΪ3G��0x00000000-0xBFFFFFFF��


   �ں˿ռ䣺
            �ֳ��ں�̬
	    �ں˿ռ����������ں�Դ�루zImage��
	    �ں˴�������ʱ��CPU�Ĺ���ģʽΪSVCģʽ
	    �ں˿ռ����ͬ�����ܷ���Ӳ������������ַ�����뽫�����ַӳ�䵽�ں˿ռ������ַ��
   	    �ں˴���������зǷ����ڴ���ʣ�����ϵͳ��ֱ�ӱ������ºˣ�
	    �����磺*��int*��0=0�� 
	    �ں˿ռ�����������̳�Ĺ���Ա
	    �ں˿ռ�������ַ�ռ��СΪ1G��0xC0000000-0xFFFFFFFF��

3. linuxϵͳ�豸��������

   �ַ��豸����
	�ַ��豸����ʱ�����ֽ�����ʽ����
	���磺LED��������UART�ӿ��豸��BT��GPS��GPRS������������LCD���Դ棩
              ����������ͷ�����ִ�����

   ���豸����
	���豸����ʱ����һ�������ݿ���з��ʣ����ݿ����Ϊ512�ֽڣ�1KB�ֽ�
	���磺Ӳ�̣�U�̣�SD����TF����Nor��Nand��

   �����豸����
	�����豸��������ʱ��Ҫ���TCP/IPЭ��ջ������㣬������·�㣩���з���
	����һ����оƬ�����ṩ��������������Ҫ������ֲ
	
4. linux�ַ��豸���������������
  4.0 ��ȷ����ʲô����,���Ƕ����ں˳���
  4.1 ��ȷlinux�ں˳����̻������
      ���䣺Ӧ�ó����̿��
	vim helloworld.c
	#include<stdio.h> //��׼Cͷ�ļ�
	
	//main���������ں���
	int main(int argc, char *argv[])
	{
		//��׼C�⺯��
		printf("hello,world\n");

		//����ĳ���
		return 0;
	}


      �ں˳���ο����룺
	mkdir /opt/drivers/day01/1.0 -p
  	cd /opt/drivers/day01/1.0 
  	vim helloworld.c ��ӵ�һ���ں˳���

  	#include <linux/init.h>
  	#include <linux/module.h>

  	static int helloworld_init(void)
  	{
  		printk("hello,world\n");
  		return 0;
  	}

  	static void helloworld_exit(void)
  	{
  		printk("good bye world!\n");
  	}

  	module_init(helloworld_init);
  	module_exit(helloworld_exit);
  	MODULE_LICENSE("GPL");

  	˵����
  	1. �ں˳���ʹ�õ�ͷ�ļ�λ��linux�ں�Դ����(/opt/kernel)
  	2. �ں˳������ں�����Ҫʹ��module_init���������,����
    	   helloworld_init�������Ǵ��ں˳������ں���,��������
    	   ��װ����ʱ(insmod),�ں˻���ô˺�����
    	   �˺����ķ���ֵ����Ϊint��,ִ�гɹ�����0,ִ��ʧ�ܷ��ظ�ֵ
  	3. �ں˳���ĳ��ں�����Ҫʹ��module_exit���������,����
    	   helloworld_exit�������Ǵ��ں˳���ĳ��ں���,����ж��
    	   ����(rmmod)ʱ,�ں˻���ô˺���
  	4. �κ�һ���ں˳���Դ��(.c��β)�������MODULE_LICENSE("GPL")
    	   ��仰,���Ǹ����ں�,���ں˳���ͬ����ѭGPLЭ��,������������
  	5. �ں˴�ӡ����ʹ��printk,�˺������岻��C����,�������ں�Դ����
  	6. ���ۣ������ں˳���϶���Ҫ�����ں�Դ��
  
  4.2 �ں˳���ı���
      �عˣ�Ӧ�ó���ı���
	    gcc -o helloworld helloworld.c
	    ��дMakefile��make���뼴��

      �ں˳�����룺
      �ع�led_drv.c���벽��
      1. ��̬����
    	 �����ں˳����ں�Դ����
    	 �޸�Kconfig
    	 �޸�Makfile
    	 make menuconfig //ѡ��Ϊ*
    	 make zImage (led_drv.c������zImage����)

      2. ģ�黯����
         �����ں˳����ں�Դ����
    	 �޸�Kconfig
    	 �޸�Makfile
    	 make menuconfig //ѡ��ΪM
    	 make zImage 
    	 make modules //��led_drv.c->led_drv.ko
    	 insmod
    	 rmmod


  4.3 ģ�黯���뷽��2��
      ˼�����������ں˳��򿽱����ں�Դ����
      �����޸�Kconfig��Makefile
      ����make menuconfig 
      ����make zImage
      ֻ��һ��СС��Makeifle���ɸ㶨��
      ����һ�²ο����룺

      vim Makefile ����������ݣ�
      obj-m += helloworld.o  #����ģ�黯���룬helloworld.c->helloworld.ko
      #ִ������make all����make,ִ�ж�Ӧ������make -C ...
      all:
      	make -C /opt/kernel SUBDIRS=$(PWD) modules  
 ע�ͣ� #make -C /opt/kernel=cd /opt/kernel && make
        #SUBDIRS=/opt/drivers/day01/1.0,�����ں�Դ��,���ں�Դ��֮�⻹��һ��Ŀ¼��Ϊ��Ŀ¼
        #modules����1.0�����Ŀ¼�µ��ں˳������ģ�黯����
    clean��
    	make -C /opt/kernel SUBDIRS=$(PWD) clean
    	#����Ŀ¼1.0�ĳ������make clean����
    �����˳�
    make //����
    ls
      helloworld.ko //����ɹ�
    cp helloworld.ko /opt/rootfs/
    
    ��������ԣ�
    ����������,����uboot,���ں˼��ز���tftp,���ں���������nfs
    setenv bootcmd tftp 20008000 zImage \; bootm 20008000
    setenv bootargs root=/dev/nfs nfsroot=192.168.1.8:/opt/rootfs ...  
    savenv
    boot //����
    �����Ժ�
    insmod helloworld.ko //��װ�ں˳���,�ں�ִ����ں���helloworld_init  
    lsmod //�鿴�ں˳���İ�װ��Ϣ
    rmmod helloworld //ж���ں˳���,�ں�ִ�г��ں���helloworld_exit

 
4.2 linux�ں˳�����֮�����д���
    1. ����Ӧ�ó���������д���
  	vim helloworld.c
  	#include <stdio.h>   
  	int main(int argc, char *argv[])
  	{
  		int a;
  		int b;
  	
  		if (argc != 3) {
  	   	printf("�÷�: %s num1 num2\n", argv[0]);
  	   	return -1;
  		}
  	
  		//"100"->100    //�ַ���ת�����޷��ų�����
  		a = strtoul(argv[1], NULL, 0);
		b = strtoul(argv[2], NULL, 0);
	
		printf("a = %d, b = %d\n", a, b);
  		return 0;
  	} 
  	gcc -o helloworld helloworld.c 
  	./helloworld 100 200
  	������
  	argc = 3
  	argv[0] = "./helloworld"
  	argv[1] = "100"
  	argv[2] = "200" 	 
  	ȱ�㣺һ����������,������û���ٴδ����µĲ���



    2. �ں˳���������д���ʵ�ֹ���
       1. �ں˳���������д���ʱ�����ܲ������ں˳������������ȫ�ֱ���
       2. �������������ͱ����ǻ������������ͣ��ṹ�岻��
       3. ���Ҫ���ں˳����ĳ��ȫ�ֱ������ݲ�����
	  ��Ҫ�ں˳�����ʽ�Ľ��д������������������ĺ꣺
	  module_param��name��type��perm��
	  name�����ղ������ں�ȫ�ֱ�����
	  type���������������ͣ�
	       ������
		bool  invbool
		short  ushort
		int  uint
		long  ulong
		charp��=char*��
		�мǣ��ں˲�������������float��double��
		���磺2.3*3.2
		      23*32/100
		      ����������������û��ռ��Ӧ�ó���������
	  perm�������ķ���Ȩ�ޣ�rwx��
		���磺0664
		ע�⣺�������п�ִ��Ȩ�ޣ�x=1��  

��������д�ں˳���ʵ���ں˳���������д���
      ʵʩ���裺
      �����ִ�У�
      1. mkdir /opt/drivers/day01/2.0 -p
     	 cd /opt/drivers/day01/2.0
      2. vim helloworld.c ����������ݣ�
 
	 #include <linux/init.h>
	 #include <linux/module.h>

	 //����ȫ�ֱ���
 	 static int irq;
	 static char *pstring;

	 //��ʽ���д�������
	 module_param(irq, int, 0664);
	 module_param(pstring, charp, 0);

	 static int helloworld_init(void)
	 {
    	 	printk("%s: irq = %d, pstring = %s\n",
                    		 __func__, irq, pstring);
    	 	return 0;
	 }

	 static void helloworld_exit(void)
 	 {
    	 	printk("%s: irq = %d, pstring = %s\n",
                    	 	__func__, irq, pstring);
	 }

	 module_init(helloworld_init);
	 module_exit(helloworld_exit);
	 MODULE_LICENSE("GPL");

      3. vim Makefile �����������
      4. make
         helloworld.ko
      5. cp helloworld.ko /opt/rootfs/
  
 
   linuxϵͳ���Ժ꣺
   __FILE__
   __LINE__
   __FUNCITION__/
   __func__
   __DATE__
   __TIME__

      
      ARM��ִ��
      1. �����ݲ���
     	 insmod helloworld.ko
         lsmod
         rmmod helloworld



      2. ���ذ�װ�ں˳���ʱ���ݲ���
     	 insmod helloworld.ko irq=100 pstring=china
     	 lsmod
     	 rmmod helloworld 


      3.���ذ�װ�ں˳����Ժ󴫵ݲ���
	insmod helloworld.ko irq=100 pstring=china	                 
     	//��ȡ�ļ�irq������
     	cat /sys/module/helloworld/parameters/irq 
     	ls /sys/module/helloworld/parameters/pstring  //û�д��ļ� ��ΪȨ��Ϊ0
     	//���ļ�irq����д��һ��������
     	echo 20000 > /sys/module/helloworld/parameters/irq 
     	rmmod helloworld

 ���ۣ�
     1. �����������ʱ,Ȩ��Ϊ��0,��ô��/sys/...../parameters
        ������һ����������ͬ�����ļ�,�ļ����ݾ��Ǳ�����ֵ
     2. ͨ���޸��ļ������ݾͿ��Լ���޸ı�����ֵ
     3. ���Ȩ��Ϊ0,��ô��/sys/.../parameters�¾Ͳ���
        ����ͬ�����ļ�,��������Ĵ���ֻ���ڳ������ʱ����
     4. ע�⣺/sys/Ŀ¼�����е����ݶ����ں˴���,������
        �ڴ���,�������û���ں˳�������Ժ󴫵ݲ���������
        Ȩ�ޱ���һ�ɸ�0,Ŀ��Ϊ�˽�ʡ�ڴ���Դ��


4.3 linux�ں˳�����֮�ں˷��ŵ���
    ���䣺Ӧ�ó�����ļ�֮��ĵ���
    �ο����룺
    mkdir /opt/drivers/day01/3.0
    cd /opt/drivers/day01/3.0

    vim test.h //����
    #ifndef __TEST_H
    #define __TEST_H

    extern void test(void);

    #endif

    vim test.c //����
    #include <stdio.h>
    void test(void)
    {
	  printf("%s\n", __func__);
    }

    vim main.c //����
    #include <stdio.h>
    #include "test.h"

    int main(void)
    {
	  test();//����
	  return 0;
    }

    ���룺
        arm-linux-gcc -fpic -shared -o libtest.so test.c  //���ɶ�̬��
        arm-linux-gcc -o main main.c -L. -ltest
        mkdir /opt/rootfs/home/applib
        cp libtest.so /opt/rootfs/home/applib
        cp main /opt/rootfs/home/applib

    ��������ԣ�
        export LD_LIBRARY_PATH=/home/applib:$LD_LIBRARY_PATH    ��UC���ݣ�
        /home/applib/main

    �ں˳�����ļ��ĵ���ʵ�ֹ��̣�
    1. �ں˳�����ļ��ĵ���ʵ�ֹ��̺�Ӧ�ó�����ļ��ĵ���ʵ��
       ����һģһ��:������������,�ö���Ķ���,�õ��õĵ���
    2. ����Ҫ��ʽ�Ľ��з���(���������߱�����)�ĵ���
       �������ŵĺ꣺
       EXPORT_SYMBOL(���������߱�����);
       ����
       EXPORT_SYMBOL_GPL(���������߱�����);
       ǰ�ߵ����ı�������,���������ں˳����Ƿ���ӣ�MODULE_LICENSE("GPL")
       ���ܷ��ʵ��ã�
       ���ߵ����ı�������,ֻ�ܸ���Щ�����MODULE_LICENSE("GPL")���ں˳������


��������д�ں˳���,�����ں˵ķ��ŵ���֪ʶ��
	ʵʩ���裺
	�����ִ�У�
	mkdir /opt/drivers/day01/4.0 
	cd /opt/drivers/day01/4.0

	vim test.h �����������
	#ifndef __TEST_H
	#define __TEST_H

	//��������
	extern void test(void);

	#endif  
	�����˳�

	vim test.c �����������
	#include <linux/init.h>
	#include <linux/module.h>
	#include "test.h"

	//�������� 
	void test(void)
	{
		printk("%s\n",__func__);
	}

	//��ʽ�Ľ��е���
	EXPORT_SYMBOL(test);
	����
	EXPORT_SYMBOL_GPL(test);

	//�����ѭGPLЭ�����Ϣ
	MODULE_LICENSE("GPL");

	�����˳�

	vim helloworld.c �����������
	#include <linux/init.h>
	#include <linux/module.h>
	

	static int helloworld_init(void)
	{
		test(); //����
		printk("%s\n", __func__);
		return 0;
	}

	static void helloworld_exit(void)
	{
		test(); //����
		printk("%s\n", __func__);
	}

	module_init(helloworld_init);
	module_exit(helloworld_exit);

	MODULE_LICENSE("GPL");

	�����˳�

	�޸�Makefile,��Ӷ�test.c�ı���֧��
	obj-m += helloworld.o test.o
	����
	obj-m += helloworld.o
	obj-m += test.o

	make //��ʼ����
	test.ko helloworld.ko

	mkdir /opt/rootfs/home/drivers/ //��������Ŀ���ļ��Ĵ��Ŀ¼
	cp *.ko /opt/rootfs/home/drivers/


	��������ԣ�
	1.insmod /home/drivers/test.ko
	2.insmod /home/drivers/helloworld.ko
	3.rmmod helloworld
	4.rmmod test


����������EXPORT_SYMBOL_GPL���з��ŵ���,���ԱȲ���

# test: module license 'unspecified' taints kernel.


	���������䲻�����taints kernel
	EXPORT_SYMBOL_GPL(test);
	MODULE_LICENSE("GPL");




