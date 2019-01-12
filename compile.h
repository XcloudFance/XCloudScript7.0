void compile(string code)
{
	string choosecompile="-Ofast";
	string inc="-I"+getfilepath()+"mingw-XCS\\include\"";
	string lib="-L"+getfilepath()+"mingw-XCS\\lib\"";

	cout<<lib<<endl;
	string path=getfilepath()+"program.cpp";
	string path2=getfilepath()+"program.exe";
	FILE *fs=fopen(path.data(),"w+");
	fprintf(fs,code.data());
	fclose(fs);
	string comp=getfilepath()+"mingw-XCS\\bin\\g++.exe \""+path+"\" -o \""+path2+"\"  "+choosecompile+" "+inc+" "+lib+" -lgmp -llua";
	system(comp.data());
} 
