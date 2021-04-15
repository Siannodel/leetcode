#include <iostream>

using namespace std;
//封装性是对类外的操作来说的，在类内操作本类的一个对象时，
//可以通过该对象访问其私有成员，这种设计也是挺合理的，因为
//类是自己设计的，当然自己也就知道类的内部结构，所以没有必
//要对自己也进行类的“封装”。另有一种说法是：“同种类之间是友元关系”。


class CMString
{
public:
    CMString(char *pData = NULL)
    {
        m_pData = pData;
    }
    CMString &operator=(const CMString &str)
    {
        if (this != &str)
        {
            CMString strTemp(str);
            char *pTemp = strTemp.m_pData;
            strTemp.m_pData = m_pData;
            m_pData = pTemp;
        }
        return *this;
    }

    void printCTest(const CMString& str)
    {
        cout << str.m_pData << endl; //通过对象访问私有成员变量
    }
    
private: 
    char *m_pData;
};

int main()
{
    char *p = "hello";
    CMString s1(p);
    CMString s2;
    s2 = s1;
    s1.printCTest(s2);
}