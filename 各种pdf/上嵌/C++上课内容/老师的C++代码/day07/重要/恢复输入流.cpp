cin.clear();	// 重置 cin 输入状态
cin.sync();	// 清除 cin 缓冲区未读取信息
#include <limits>
cin.ignore( numeric_limits<streamsize>::max(), '\n' );
ctrl+d 停止输入
