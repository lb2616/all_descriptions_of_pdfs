#include<mysql/mysql.h> //ENGIN = Innodb default charset = utf8; 这是不带原子事件的
#include<iostream>
#include<string>
using namespace std;
MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

int main(int argc, char **argv)
{
	const char *server = "localhost";
	const char *user = "root";
	const char *password = "123456";//密码
	const char *database = "mysql";
	conn = mysql_init(NULL);
	//连接数据库
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
	{
		cout << "connect error" <<endl;
		return 0;
	}
	
	//设置字符集
	mysql_set_character_set (conn,"utf8");
	if(mysql_query(conn,"select * from stu03"))
	{
		cout <<"query error" <<endl;
		return 0;
	}
	
	//获得结果集
	res = mysql_use_result(conn);
	cout << stu03 <<endl;
	//依次从结果集中获得每一行，并打印
	while((row = mysql_fetch_row(res))!=NULL)
	{
		cout <<row[0]<<"　"<<row[1] <<"　"<<row[2]<<endl;//行
	}
	
	//释放结果集
	mysql_free_result(res);
	
	//关闭数据库连接
	mysql_close(conn);
	return 0;
}

















