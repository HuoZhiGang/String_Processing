```
#include<string>
#include <windows.h>
#include <fstream>
#include <vector>
#include<iostream>
#include <string>
using namespace std;


vector<string> Data;
// 处理
void StroedData()
{
	int index = 0;
	const char* fileName = "d:\\data.txt";
	ifstream read(fileName,ifstream::in);
	string temp;
	while (!read.eof() && getline(read,temp) )
	{
		Data.push_back(temp);
		Data[index].replace(Data[index].find("#"),3,",");
		Data[index].replace(Data[index].find("#"),3,",");
		Data[index].replace(Data[index].find("#"),3,",");
		Data[index].replace(Data[index].find("#"),3,",");
		Data[index].replace(Data[index].find("#"),3,",");
		Data[index].replace(Data[index].find("#"),3,",");
		Data[index].erase(Data[index].find("T"));
		Data[index].insert(Data[index].begin(),'0');		
		Data[index].insert(Data[index].begin(),'0');		
		Data[index].insert(Data[index].begin(),'0');		
		Data[index].insert(Data[index].begin(),'1');
		Data[index].insert(Data[index].end(), '\n');
		cout << Data[index];
		index++;
	}
	printf("共存储： %d 组数据\n", index);
	read.close();

}

// 输出到文件
void Write()
{
	int index = 0;
	const char* fileName = "d:\\out.txt";
	ofstream w(fileName, ofstream::out);
	while (index != Data.size() - 1)
	{
		w.write(Data[index].c_str(),Data[index].length());
		index++;
	}
	w.close();
}

void Go()
{
	cout << "使用说明：" <<endl;
	cout <<'\n';
	cout << "\t1.将要处理的txt文本放到D盘根目录并命名为data.txt，"<<endl;
	cout <<'\n';
	cout << "\t2.等待几秒处理完成后，在D盘根目录下生成文件out.txt"<<endl;
	cout <<'\n';
	cout << "注：每执行一次都会覆盖生成的out.txt，如要使用，请拷贝别处以防丢失。"<<endl;
	cout <<'\n';
	cout <<'\n';
	cout << "继续请按回车键..."<<endl;
	getchar();
	cout << "正在处理，请稍后."<<endl;
	Sleep(1000);
	StroedData();
	Sleep(1000);
	Write();
	Sleep(1000);
	cout << "处理完成，请到D盘根目录查看生成的文件，按回车键结束程序." << endl;
	getchar();
}
int main()
{
	Go();
	return 0;
}
```
