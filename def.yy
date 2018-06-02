%{
#include <stdio.h>
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;


static int label_count=0;
stack<string> labels;


struct str
	{
		string value;
		int type;
	};

//nagłówki metod
void make_threes(char name);
void make_assembler(str el1, str el2, string name, char sign);
string convert(int id);
bool Exist(string el);
void make_assembler_assign(str el1,str el2);
string GetInteger(str el, int RegNum);
string GetStoreCode(int type1,int type2,string result);
string GetFloat(str el, int RegNum);
void make_assembler_print(string tmp,bool flag);
void make_assembler_read(string tmp);
void makeCompareAssembler(string sign);
void makeElse();
void make_array_symbol(string id,int type,int size);
void make_array(string id, int flag);
void array_assign(string id, int flag);

int	ARRI = 10;
int	ARRF = 11;

static int helper = 0;
static int licznik=0;


template <typename T>
string tostring(T value);

template<typename T>
void push(T arg, int type);

struct symbolinfo{
		int size;
		int type;
		string id;
		string value;
		};

//struktury danych

vector<string> assembler;
stack<str> stos;
map<string,symbolinfo> symbole;


extern FILE *yyin,*yyout;
ofstream rpn_file,trojki_file,symbole_file;

extern "C" int yylex();
extern "C" int yyerror(const char *msg,...);
%}
%union
{char *text;
int	ival;float fval;};
%type <text> wyr
%token GT LT LE GE EQ NE
%token READ PRINT IF ELSE
%token INT FLOAT
%token FOR
%token <text> STRING
%token <text> ID
%token <ival> LC
%token <fval> LZ
%start multiline
%%
multiline
		:multiline line	{;}
		|line	{;}
		;

line
		:przypisanie ';'	{;}
		|deklaracja ';'		{;}
		|wypisanie ';'    {;}
		|wczytanie ';'    {;}
		|if_expr 				  {;}
		|for_expr					{;}
		|wyr	';'		{;}
		;


//------------------IF----------------------------------------------


if_expr
  :if_begin '{' multiline '}'
		{
			string etykieta=labels.top();
      assembler.push_back(etykieta+":");
      labels.pop();label_count++;
		}
  |if_begin '{' multiline '}' else_expr '{' multiline '}'
		{
			string etykieta=labels.top();
    	assembler.push_back(etykieta+":");
      labels.pop();label_count++;
		}
		;

if_begin
	:IF '(' cond_expr ')' {;}
	;

else_expr
  :ELSE  { makeElse();}
	;


//----------FOR------------------------------------------------------


for_expr
	:for_begin '{' multiline '}'
	{
		string label = labels.top();
	  labels.pop();
	  string label2 = labels.top();
	  labels.pop();
	  assembler.push_back("j " + label2);
	  assembler.push_back(label + ":");
	}
	;

for_begin
  : for_init for_inc cond_expr ')'	{;}
	;

for_init
  :FOR '(' przypisanie ';'
	{
		string label="FOR_L"+to_string(label_count);
		label_count++;
		string label2="FOR_L"+to_string(label_count);
		label_count++;

		labels.push(label2);
		labels.push(label);
		assembler.push_back("j " + label);
		assembler.push_back(label2 + ":");
  }
	;

for_inc
	:przypisanie ';'
	{
		string label=labels.top();
		labels.pop();
		assembler.push_back(label + ":");
 	}


//-----------porownania-----------------------------------------------------


cond_expr
	: wyr EQ wyr {makeCompareAssembler("bne");}
	| wyr NE wyr {makeCompareAssembler("beq");}
	| wyr LT wyr {makeCompareAssembler("bge");}
	| wyr GT wyr {makeCompareAssembler("ble");}
	| wyr LE wyr {makeCompareAssembler("bgt");}
	| wyr GE wyr {makeCompareAssembler("blt");}
	;



//--------------inne operacje--------------------------------------------------

wczytanie
	:READ'('ID')' {make_assembler_read($3);}
	;

wypisanie
	:PRINT '('ID')' {make_assembler_print($3,false);}
	|PRINT '('STRING')' {make_assembler_print($3,true);}
	;

deklaracja
	:INT ID
	{
	 	if(Exist($2)) cout << "juz istnieje\n";
		else
		{
			symbolinfo sInfo;
			sInfo.type=LC;
			sInfo.size=1;
			sInfo.id=$2;
			sInfo.value="0";
			symbole.insert(std::pair<string,symbolinfo>($2,sInfo));
		}
	}

	|FLOAT ID
	{
	 if(Exist($2)) cout << "Zmienna " << $2 << " juz istnieje\n";
	 else
		 {
		 	symbolinfo sInfo;
	 		sInfo.type=LZ;
			sInfo.size=1;
	 		sInfo.id=$2;
	 		sInfo.value="0";
			symbole.insert(std::pair<string,symbolinfo>($2,sInfo));
		}
	}

	|INT ID '[' LC ']'	{make_array_symbol($2,ARRI,$4);}

	|FLOAT ID '[' LC ']'	{make_array_symbol($2,ARRF,$4);}
	;

przypisanie
	:ID '=' wyr {push($1,ID); make_threes('=');};

	|ID '[' wyr ']' '=' wyr {
		int flag=0;

			auto it = symbole.find($1);
			if(it->second.type==ARRI)
				flag=1;

				array_assign($1,flag);
		}
	;

wyr
	:wyr '+' skladnik	{make_threes('+');}
	|wyr '-' skladnik	{make_threes('-');}
	|skladnik		{;}
	;
skladnik
	:skladnik '*' czynnik	{make_threes('*');}
	|skladnik '/' czynnik	{make_threes('/');}
	|czynnik		{;}
	;
czynnik
	:ID			{push($1,ID);}
	|LC			{push($1,LC);}
	|LZ			{push($1,LZ);}
	|'(' wyr ')'		{;}

	|ID tab_wyr
	{
		int flag=0;
			auto it = symbole.find($1);
			if(it->second.type==ARRI)
				flag=1;

		make_array($1,flag);
	}
	;

tab_wyr
	:'[' wyr ']'{;}
	;

%%
void make_array(string id, int flag)
{
	str var1 = stos.top();
	stos.pop();
	assembler.push_back("la $t4, " + tostring(id));

	if(var1.type == ID)
		assembler.push_back("lw $t5, " + tostring(var1.value));
	else
		assembler.push_back("li $t5, " + tostring(var1.value));

	assembler.push_back("mul $t5, $t5, 4");
	assembler.push_back("add $t4, $t4, $t5");
	string tempName="";

	if(flag==1)
	{
		assembler.push_back("lw $t0, ($t4)");
		helper++;
		tempName = "_tmp" + to_string(helper);
	}
	else
	{
		assembler.push_back("l.s $f0, ($t4)");
		licznik++;
		tempName = "_tmp" + to_string(licznik);
	}

	symbolinfo sInfo;
	sInfo.id = tempName;

	if(flag == 1)
		sInfo.type = LC;
	else
		sInfo.type = LZ;

	sInfo.size = 1;
	sInfo.value = "0";

	symbole.insert(std::pair<string,symbolinfo>(tempName,sInfo));
	push(tempName,ID);
	if(flag==1)
		assembler.push_back("sw $t0, " + tempName);
	else
		assembler.push_back("s.s $f0, " + tempName);
}

void array_assign(string id, int flag)
{
	assembler.push_back("la $t4, " + tostring(id));
	str variable1 = stos.top();
	stos.pop();
	string _asm1="";
	if(flag==1)
		_asm1 = GetInteger(variable1,0);
	else
		_asm1 = GetFloat(variable1,0);

	assembler.push_back(_asm1);

	str variable2 = stos.top();
	stos.pop();
	string _asm2 = GetInteger(variable2,5);
	assembler.push_back(_asm2);
	assembler.push_back("mul $t5, $t5, 4");
	assembler.push_back("add $t4, $t4, $t5");
	if(flag==1)
		assembler.push_back("sw $t0, ($t4)");
	else
		assembler.push_back("s.s $f0, ($t4)");
}

void make_array_symbol(string id,int type,int size)
{
		symbolinfo sinfo;
		sinfo.id=id;
		sinfo.type=type;
		sinfo.size=1;
		sinfo.value="0:"+to_string(size);
		symbole.insert(std::pair<string,symbolinfo>(sinfo.id,sinfo));
}

void makeElse()
{
	string etykieta=labels.top();
	string nowaEtykieta="ELSE_L"+to_string(label_count);

	assembler.push_back("j "+nowaEtykieta);
	assembler.push_back(etykieta+":");
	labels.pop();
	etykieta = "ELSE_L"+to_string(label_count);
	labels.push(etykieta);
}


void makeCompareAssembler(string sign){

  str variable2=stos.top();
  stos.pop();
  str variable1=stos.top();
  stos.pop();

  if(variable1.type==LZ || variable2.type==LZ)
		{
			cout << "Bledne typy do porownania\n";
			exit(-1);
		}

  string _asm1, _asm2, etykieta;

  _asm1=GetInteger(variable1,0);
  _asm2=GetInteger(variable2,1);
  etykieta = "IF_L"+to_string(label_count);

  labels.push(etykieta);
  assembler.push_back(_asm1);
  assembler.push_back(_asm2);
  assembler.push_back(sign +" $t0,$t1, "+etykieta);
  label_count++;
}

string convert(int id)
{
			if(id == LC || id == ARRI)
				return ".word";

			if(id == LZ | id == ARRF)
				return ".float";

			if(id == STRING)
				return ".asciiz";

	return ".unknown";
}

int GetType(str el)
{
	if(el.type == LC || el.type == LZ)
		return el.type;
	else if (el.type == ID)
	{
			auto it = symbole.find(el.value);

			if(it != symbole.end())
				return it->second.type;
	}
	else
	{
			cout << "Nie znaleziono symbolu.";
			exit(-1);
	}

		cout << "Nieznany typ.";
		exit(-1);

}

bool Exist(string el)
{
	auto it = symbole.find(el);

	if(it != symbole.end())
			return true;
	else
			return false;
}


void make_assembler_read(string tmp)
{
	string _asm1,_asm2,_asm3;

	map<string,symbolinfo>::iterator it;
	it=symbole.find(tmp);
	if(it!=symbole.end())
	{
		if(it->second.type == LC)
			{
				_asm1="li $v0, 5";
				_asm2="syscall";
				_asm3="sw $v0, " + tostring(tmp);
			}
		else if(it->second.type == LZ)
			{
				_asm1="li $v0, 6";
				_asm2="syscall";
				_asm3="s.s $f0, " + tostring(tmp);

			}
		}
		else
		{
			cout << "Nieznany typ zmiennej do wczytania";
			return;
		}

		assembler.push_back(_asm1);
		assembler.push_back(_asm2);
		assembler.push_back(_asm3);
}

void make_assembler_print(string tmp,bool flag){

string _asm1,_asm2,_asm3;

	if(flag){
		helper++;
		symbolinfo sinfo;
		sinfo.type=STRING;
		sinfo.size=1;
		sinfo.value=tmp;
		string nazwa="string"+to_string(helper);
		sinfo.id=nazwa;
		symbole.insert(std::pair<string,symbolinfo>(sinfo.id,sinfo));

		_asm1="li $v0, 4";
		_asm2="la $a0, "+nazwa;
		_asm3="syscall";
	}

else
{
	map<string,symbolinfo>::iterator it;
	it=symbole.find(tmp);
	if(it!=symbole.end())
	{
		if(it->second.type == LC)
			{
				_asm1="li $v0,1";
				_asm2="lw $a0 "+tmp;
				_asm3="syscall";
			}
		else if(it->second.type == LZ)
			{
				_asm1="li $v0,2";
				_asm2="lwc1 $f12 "+tmp;
				_asm3="syscall";
			}
		}
		else
		{
			cout << "Nieznany typ do wyswietlenia";
			return;
		}
}

	assembler.push_back(_asm1);
	assembler.push_back(_asm2);
	assembler.push_back(_asm3);
}

void make_assembler_assign(str el1,str el2)
{
	string _asm1,_asm2,_asm3,_asm4;
	int flaga=0;

	int type1=GetType(el1);
	int type2=GetType(el2);

	if(type1==LC && type2== LC){
			_asm1=GetInteger(el1,0);
	}
	else if(type1==LZ && type2==LZ){
			_asm1=GetFloat(el1,0);
	}
	else if(type2==LC && type1==LZ){
		cout << "Blad przypisania (int = float)" << endl;
		exit(-1);
	}

	if(type2==LZ && type1==LC){
		_asm1=GetInteger(el1,0);
		_asm2 = "mtc1 $t0 , $f0";
		_asm3 = "cvt.s.w $f0 , $f0";
		flaga=1;
	}

	assembler.push_back(_asm1);

	if(flaga)
	{
		assembler.push_back(_asm2);
		assembler.push_back(_asm3);
	}

	_asm4=GetStoreCode(type1,type2,el2.value);
	assembler.push_back(_asm4);
}


void make_threes(char name)
{
		str _temp2 = stos.top();
		stos.pop();
		str _temp1 = stos.top();
		stos.pop();


			if(name!='=')
			{
				helper++;
				int type1 = GetType(_temp1);
				int type2 = GetType(_temp2);

				string tmp_name = "_tmp"+to_string(helper);
				trojki_file << tmp_name << " = " << _temp1.value << name << _temp2.value << endl;
				push(tmp_name,ID);

				symbolinfo sinfo;
				sinfo.id=tmp_name;

				if(type1 == LZ || type2 == LZ)
					sinfo.type=LZ;
				else
					sinfo.type=LC;

				sinfo.size=1;
				sinfo.value="0";
				symbole.insert(std::pair<string,symbolinfo>(tmp_name,sinfo));
				make_assembler(_temp1,_temp2,tmp_name,name);
			}

			else
				make_assembler_assign(_temp1,_temp2);
}

string GetOperatorCode(char sign,int type1,int type2)
{
	string s;

	if(sign=='+')
		s="add";
	else if(sign=='-')
		s="sub";
	else if(sign=='*')
		s="mul";
	else if(sign=='/')
		s="div";


		if(type1 == LC && type2 == LC)
			s= s+" $t0, $t0,$t1";

		else
			s= s+".s $f0,$f0,$f1";

			return s;
}

string GetStoreCode(int type1,int type2,string result)
{
	string s;

		if(type1 == LC && type2 == LC)
			s="sw $t0,"+result;

		else
			s="s.s $f0,"+result;

			return s;
}

string GetFloat(str el, int RegNum)
{
		if(el.type==ID)
			return "l.s $f" + to_string(RegNum) + "," + el.value;

		symbolinfo sinfo;
		sinfo.id="_tmp_float"+to_string(licznik);
		licznik++;
		sinfo.type=LZ;
		sinfo.size=1;
		sinfo.value=el.value;
		symbole.insert(std::pair<string,symbolinfo>(sinfo.id,sinfo));

		return "l.s $f" + to_string(RegNum) + "," + sinfo.id;
}

string GetInteger(str el, int RegNum)
{
		if(el.type == ID)
			return "lw $t" + to_string(RegNum) + "," +el.value;
		else if(el.type == LC)
			return "li $t" + to_string(RegNum) + "," +el.value;
}

void make_assembler(str el1, str el2, string name, char sign)
{
	string _asm1,_asm2,_asm3,_asm4, _asm5,_asm_tmp1, _asm_tmp2;
	int type1, type2;
	int flaga = 0;

	type1 = GetType(el1);
	type2 = GetType(el2);

	if(type1 == LZ && type2 == LZ)
	{
		_asm1 = GetFloat(el1,0);
		_asm2 = GetFloat(el2,1);
	}

	else if (type1 == LC && type2 == LC)
	{
		_asm1=GetInteger(el1,0);
		_asm2=GetInteger(el2,1);
	}

	else
	{
		int rejestr;
		flaga=1;

		if (type1 == LZ)
		{
				rejestr = 1;
				_asm1 = GetFloat(el1,0);
				_asm2 = GetInteger(el2,rejestr);
		}

		else if(type2 == LZ)
		{
			rejestr = 0;
			_asm1 = GetInteger(el1,rejestr);
			_asm2 = GetFloat(el2,1);
		}

		_asm_tmp1 = "mtc1 $t" + to_string(rejestr) + ", " + "$f" + to_string(rejestr);
		_asm_tmp2 = "cvt.s.w $f" + to_string(rejestr) + ", " + "$f" + to_string(rejestr);
	}

	assembler.push_back(_asm1);

	if(flaga==1 && type2 == LZ)
	{
		assembler.push_back(_asm_tmp1);
		assembler.push_back(_asm_tmp2);
	}

	assembler.push_back(_asm2);

	if(flaga==1 && type1 == LZ)
	{
		assembler.push_back(_asm_tmp1);
		assembler.push_back(_asm_tmp2);
	}

	_asm3= GetOperatorCode(sign,type1,type2);
	_asm4= GetStoreCode(type1,type2,name);

	assembler.push_back(_asm3);
	assembler.push_back(_asm4);
}

template<typename T>
void push(T arg, int type)
{
	str x;
	x.value = tostring(arg);
	x.type = type;
	stos.push(x);

}

template <typename T>
string tostring(T value)
{
	stringstream sstream;
	sstream << value;
		return sstream.str();
}


int main(int argc, char *argv[])
{

	rpn_file.open("rpn.txt");
	trojki_file.open("trojki.txt");
	symbole_file.open("symbole.txt");


	if (argc>1)
	{
		yyin = fopen(argv[1], "rw");
			if (yyin==NULL)
			{
				printf("Błąd\n");
				return 0;
			}

	}

	yyparse();

		if (argc>1)
		{
			fclose(yyin);
		}

	yyout=fopen("kod.asm","w");
	fprintf(yyout,"%s",".data\n");

	for(auto sym:symbole)
	{
		fprintf(yyout,"\t%s\t:",sym.second.id.c_str());
		fprintf(yyout,"\t%s",convert(sym.second.type).c_str());
		fprintf(yyout,"\t%s\n",sym.second.value.c_str());
	}

	fprintf(yyout,"%s",".text\n\n");
	for(auto kod:assembler)
	{
		fprintf(yyout,"%s\n",kod.c_str());
	}

	for(auto sym:symbole)
	{
		symbole_file << sym.second.id << "\t";
		symbole_file << sym.second.type << "\t";
		symbole_file << sym.second.size << endl;
	}


	rpn_file.close();
	trojki_file.close();

	return 0;
}
