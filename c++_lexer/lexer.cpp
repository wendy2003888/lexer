#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>


using namespace std;
const int N=50;

int line,keys,opts,cmps,rels,seps;
char keywords[][10] = {"do","while","if","else","then","int","double","float","const","return","main"};
char operators[][2] = {"+","-","*","/","%","&","|","^","~","!","="};
char cmp_operators[][3] = {"<","<=",">",">=","==","!="};
char rel_operators[][3] = {"&&","||"};
char sep_operators[][3] = {",",";","(",")","{","}"};
char type[][N]={"arithmetic operator","compare operator","relation operator","separate operator"};


void initial()	//初始化行号和关键字个数
{
	line=1;
	keys=11;
	opts=11;
	cmps=6;
	rels=2;
	seps=6;
}

char remove_blank(char ch)	//移去空格，缩进，并计算行号
{
	while(ch == ' ' || ch == '\t')
	{
		ch = getchar();
	}
	if(ch == '\n')
	{
		line++;
		ch = getchar();
	}
	return ch;

}
char number(char ch)	//分析数字
{
    string num;
    while(isdigit(ch))
    {
        num += ch;
        ch = getchar();
    }
    cout<<"Line:"<<line<<"\t"<<"<number, "<<num<<" >"<<endl;
    return ch;
}

bool check_key(string s)	//检查是否是关键字
{
	int flag=0;
	for(int i=0;i<keys;i++)
	{
		if(s.compare(keywords[i]) == 0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}

char word(char ch)	//分析单词
{
	string word;
	while(isalpha(ch))
	{
		word += ch;
		ch = getchar();
	}
	if(check_key(word))
	{
		cout<<"Line:"<<line<<"\t"<<"<KEYWORD, "<<word<<" >"<<endl;
	}
	else
	{
		cout<<"Line:"<<line<<"\t"<<"<ID, "<<word<<" >"<<endl;
	}
	return ch;
}

bool judge(string s,int i)	//判断是否是运算符等
{
	if(i==0)
	{
		for(int i=0;i<opts;i++)
		{
			if(s.compare(operators[i])==0)
				return true;
		}
	}
	else if(i==1)
	{
		for(int i=0;i<cmps;i++)
		{
			if(s.compare(cmp_operators[i])==0)
				return true;
		}
	}
	else if(i==2)
	{
		for(int i=0;i<rels;i++)
		{
			if(s.compare(rel_operators[i])==0)
				return true;
		}

	}
	else if(i==3)
	{
		for(int i=0;i<seps;i++)
		{
			if(s.compare(sep_operators[i])==0)
				return true;
		}

	}
	return false;
}

char others(char ch)	//分析单词和数字以外的字符
{
	string others;
	others += ch;
	ch = getchar();
	if(others[0] == '<' || others[0] == '>' || others[0] == '=' || others[0] == '!')
	{
		if(ch == '=')
		{
			others += ch;
			ch = getchar();
		}
	}
	else if( others[0] == '&' && ch == '&')
	{
		others += ch;
		ch = getchar();
	}
	else if( others[0] == '|' && ch == '|')
	{
		others += ch;
		ch = getchar();
	}

	for(int i=0;i<4;i++)
	{
		if(judge(others,i))
		{
			cout<<"Line:"<<line<<"\t"<<"<"<<type[i]<<", "<<others<<" >"<<endl;
			return ch;
		}

	}
	cout<<"Line:"<<line<<"\t"<<"<others, "<<others<<" >"<<endl;
	return ch;

}



void lexer()
{
	char ch;
	ch = getchar();
	while(ch!=EOF)
	{
		
        if(isdigit(ch))
        {
            ch = number(ch);
        }
        else if(isalpha(ch))
        {
            ch = word(ch);
        }
        else if(isspace(ch))
        {
            ch = remove_blank(ch);
        }
        else
        {
        	ch = others(ch);
        }

	}

}
int main()
{
	freopen("in.txt","r",stdin);	//读入文件
	freopen("out.txt","w",stdout);	//写入文件
	initial();
	lexer();
	return 0;
}