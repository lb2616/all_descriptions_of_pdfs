    #include<iostream>  
    using namespace std;  
      
    class CExample  
    {  
    private:  
        int m_nTest;  
      
    public:  
        CExample(int x) : m_nTest(x)      //带参数构造函数  
        {   
            cout << "constructor with argument"<<endl;  
        }  
      
        // 拷贝构造函数，参数中的const不是严格必须的，但引用符号是必须的  
        CExample(const CExample & ex)     //拷贝构造函数  
        {  
            m_nTest = ex.m_nTest;  
            cout << "copy constructor"<<endl;  
        }  
      
        CExample& operator = (const CExample &ex)   //赋值函数(赋值运算符重载)  
        {     
            cout << "assignment operator"<<endl;  
            m_nTest = ex.m_nTest;  
            return *this;  
        }  
      
        void myTestFunc(CExample ex)  
        {  
        }  
    };  
      
    int main(void)  
    {  
        CExample aaa(2);  
        CExample bbb(3);  
        bbb = aaa;  
        CExample ccc = aaa;  
        bbb.myTestFunc(aaa);  
      
        return 0;     
    }  
