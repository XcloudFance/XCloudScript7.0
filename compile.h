void compile(string code)
{
	string path=getfilepath()+"program.cpp";
	FILE *fs=fopen(path.data(),"w+");
	fprintf(fs,code.data());
	fclose(fs);
	string comp="g++ -O3 "+path;
	system(comp.data());
} 
