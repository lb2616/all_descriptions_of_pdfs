1. 如果你需要来回切换是否忽略空白的话，这种方法才是首选
int count = 0;
char c;
while (cin.get(c)) {  // Always reads whitespace chars.//ctrl+d==eof
        count++;}	
        cerr << count << endl;
}

2. 只能忽略空白
int count = 0;
char c;
cin >> noskipws;    // Stops all further whitespace skipping
while (cin >> c) {  // Reads whitespace chars now.
       count++;}
       cerr << count << endl;

