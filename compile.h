void compile(string code)
{
	string path=getfilepath()+"program.cpp";
	FILE *fs=fopen(path.data(),"w+");
	fprintf(fs,code.data());
	fclose(fs);
	string comp=getfilepath()+"mingw-XCS\\bin\\g++.exe -Ofast "+path+" -llua -lgmp";
	system(comp.data());
} 
