#include<cstdio>
#include<cstdlib>
#include <fstream> 
#include<cassert> 
class io{
	public:
		FILE *filer;
		void open(Stringbuilder filename,Stringbuilder Mode)
		{
			filer=fopen(filename.tostr(),Mode.tostr());
		}
		void close()
		{
			fclose(filer);
		}
		void write(Stringbuilder content)
		{
			fprintf(filer,"%s",content.tostr());
		}
		void WriteText(Stringbuilder filename,Stringbuilder content)
		{
			//�Զ��ر��ļ��� 
			FILE *_fs=fopen(filename.tostr(),"w+");
			fprintf(_fs,content.tostr());
			fclose(_fs);
		}
		Stringbuilder GetText(Stringbuilder filename)
		{
			ifstream infile; 
	  	  	infile.open(filename.tostr());   //���ļ����������ļ��������� 
	  	  	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 
	  	  	string re,tmp;
	  	  	while(getline(infile,tmp))re+=tmp+"\n";
	  	  	infile.close(); 
	  	  	return re;
		}
		inline bool fileexists(Stringbuilder filename)
		{
			 fstream _file;
		     _file.open(filename.tostr(), ios::in);
		     if(!_file)
		         return 0;
		     else
		        return 1;
		}
		void filecopy(Stringbuilder name1,Stringbuilder name2)
		{
			this->WriteText(name2,this->GetText(name1));
		}
}; 
