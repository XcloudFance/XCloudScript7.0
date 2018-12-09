#include "stringbuilder.h"
class io{
	public:
		void WriteTexts(Stringbuilder filename,Stringbuilder content)
		{
			//自动关闭文件流 
			FILE *_fs=fopen(filename.tostr(),"w+");
			fprintf(_fs,content.tostr());
			fclose(_fs);
		}
}; 
