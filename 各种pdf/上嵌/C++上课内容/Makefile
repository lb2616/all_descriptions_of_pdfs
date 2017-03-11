
obj := main.o company/company.o company/boss.o company/manager.o company/salesman.o company/salesmanager.o company/technician.o employee/employee.o tool/mysql_to_v.o tool/v_to_mysql.o tool/load_boss_passwd.o tool/save_boss_passwd.o

########################################################
all:$(obj)
	g++ $(obj) -o com -Wall -L /usr/lib/mysql -lmysqlclient -g

%.o:%.cpp
	g++ -c $< -o $@ -I ./include -Wall -L /usr/lib/mysql -lmysqlclient -g
	

clean:
	rm -rf `find -name "*.o"` com

