文件说明:
=========
supervivi-64M/128M   - 	开发板的BIOS,可以通过JTAG小板配合H-JTAG烧写到NOR 
			FLASH中运行，也可以烧写NAND FLASH运行,它也可以完
			全适用于micro2440
			64M尾缀的适合K9F1208型号的nand flash
			128M尾缀的适合2K页的大容量nand flash
nboot_N35.bin	     -	适用于NEC3.5"LCD的bootloader，有源代码，带启动条，
			使用supervivi可以下载烧写bmp格式的图片作为开机Logo，
			nboot可以加载启动画面，你可以看到其他尾缀的nboot文
			件，它们是通过修改源代码头文件定义而分别编译出来的，
			说明如下，修改说明和编译见用户手册：
			* X35 表示支持Sony 3.5"LCD显示屏 
			 * N35 表示支持NEC3.5"LCD显示屏 
		    	 * T35 表示支持统宝3.5"LCD显示屏
		     	 * A70 表示支持群创7"LCD显示屏
		    	 * L80 表示支持Sharp 8"LCD显示屏(或者兼容型号)
		     	 * VGA1024x768 表示支持NEC3.5"LCD
		    
NK_N35.bin	     -	适用于NEC3.5"LCD的WindowsCE烧写文件映象，你还可以看
			到其他尾缀的NK文件，它们是通过修改BSP中头文件定义而
			分别编译出来的。
			说明如下，修改说明和编译见用户手册
			* X35 表示支持Sony 3.5"LCD显示屏 
		     	* N35 表示支持NEC3.5"LCD显示屏 
		   	* T35 表示支持统宝3.5"LCD显示屏
		     	* A70 表示支持群创7"LCD显示屏
		     	* L80 表示支持Sharp 8"LCD显示屏(或者兼容型号)
		     	* VGA1024x768 表示支持NEC3.5"LCD

NK_N35.nb0	     -	适用于NEC3.5"LCD的运行时映象，可以借助supervivi的Download & Run
			功能通过USB下载到0x30200000运行你还可以看到其他尾缀的
			nb0文件，它们是通过修改BSP中头文件定义而分别编译出来的。
			和上面的bin文件同时产生。
			说明如下，修改说明和编译见用户手册
			* X35 表示支持Sony 3.5"LCD显示屏 
			* N35 表示支持NEC3.5"LCD显示屏 
			* T35 表示支持统宝3.5"LCD显示屏
			* A70 表示支持群创7"LCD显示屏
			* L80 表示支持Sharp 8"LCD显示屏(或者兼容型号)
			* VGA1024x768 表示支持NEC3.5"LCD

简易烧写步骤：
=============
请根据文件的名字使用各个文件
1. 设置开发板的S2开关为NOR FLASH启动，开机进入bios菜单模式
2. 选“n"下载nboot_A70.bin或者nboot_N35.bin等，根据实际的屏型号。
3. 选"l"下载bootlogo.bmp,该步是下载开机画面
4. 选"w"下载nk_A70.bin或者nk.N35.bin等，根据实际的屏型号
5. 烧写完毕，设置开发板的S2开关为nand flash模式，复位或者重新开机即可启动系统

说明: 
1. 第3步也可以使用"v"命令下载supervivi，只是supervivi没有开机画面和启动条，但启动速度比nboot要快2-3秒。
2. nboot提供了源代码，使用ADS编译，nboot实现了开机画面和进度条。


