#include "stringbuilder.h"
class io{
	public:
		void WriteTexts(Stringbuilder filename,Stringbuilder content)
		{
			//�Զ��ر��ļ��� 
			FILE *_fs=fopen(filename.tostr(),"w+");
			fprintf(_fs,content.tostr());
			fclose(_fs);
		}
}; 
