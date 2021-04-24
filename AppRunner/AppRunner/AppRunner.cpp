#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

const int StoreSize = 4096;
#define CompleteVarStoreSize 4122;

char DataStore[4122] = "{DataStore}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {DataStoreEnd}";;
string AppPath = "";
string SharedStorages = "Z:\\;";

void InsertData(string outputFile, string data) {
	fstream file;
	fstream outFile;

	char* buffer = new char[1];
	string DataStoreBegin = "{ D a t a S t o r e }";
	string DataStoreEnd = "{ D a t a S t o r e E n d }";
	int begin = 0;
	int end = 0;

	file.open(AppPath, ios_base::in | ios_base::binary);
	if (file.is_open()) {
		//find Begin
		int correct = 0;
		while (correct <= 10 && !file.eof()) {
			file.read(buffer, 1);
			begin++;
			if (buffer[0] == DataStoreBegin[correct * 2])
			{
				correct++;
			}
			else
			{
				correct = 0;
			}
		}
		end = begin;
		//findBegin

		//findEnd
		correct = 0;
		while (correct <= 13 && !file.eof()) {
			file.read(buffer, 1);
			end++;
			if (buffer[0] == DataStoreEnd[correct * 2])
			{
				correct++;
			}
			else
			{
				correct = 0;
			}
		}
		end -= 14;
		//findEnd
		file.close();
	}

	file.open(AppPath, ios_base::in | ios_base::binary);
	outFile.open(outputFile, ios_base::out | ios_base::trunc | ios_base::binary);
	if (file.is_open() && outFile.is_open()) {
		for (int i = 0; i < begin; i++) {
			file.read(buffer, 1);
			outFile << buffer[0];
		}

		for (int i = 0; i < data.length(); i++) {

			if (i >= 4095)
				break;

			file.read(buffer, 1);
			outFile << data[i];
		}
		for (int i = data.length(); i < end - begin; i++) {
			file.read(buffer, 1);
			outFile << ' ';
		}
		while (!file.eof()) {
			file.read(buffer, 1);
			outFile << buffer[0];
		}
		file.close();
		outFile.close();
	}
}

string GetData() {
	string data = DataStore;
	data = data.substr(11, StoreSize);
	int lastChar = 0;
	for (int i = data.length() - 1; i > 0; i--)
	{
		if (data[i] != ' ')
		{
			lastChar = i;
			break;
		}
	}
	data = data.substr(0, lastChar);
	return data;
}

bool FileExists(string path) {
	ofstream file;
	file.open(path, ios_base::in);
	if (file.is_open()) {
		file.close();
		return true;
	}
	else {
		return false;
	}
}

bool InSharedStorages(string path) {
	string disk;
	disk = path[0] + path[1] + path[2];
	if (path.find(disk) >= 0) {
		return true;
	}
	return false;
}

void SaveData(string path, int argc, char* argv[]) {
	//prepare params
	string params = "remoteapplicationcmdline:s:";
	for (int i = 1; i < argc; i++) {
		if (FileExists(argv[i])) {
			string filePath = argv[i];
			if (InSharedStorages(argv[i])) {
				params = params + "\"" + filePath + "\" ";
			}
			else
			{

				filePath.replace(1, 1, "");
				params = params + "\"\\\\tsclient\\" + filePath + "\" ";
			}
		}
		else {
			params = params + argv[i] + " ";
		}
	}

	string data = GetData();
	fstream file;
	file.open(path, ios_base::out | ios_base::trunc);
	file << data << endl;
	if (argc > 1)
		file << params << endl;
	file.close();
}

string ReadFile(string path = "starter.rdp") {
	char* buffer = new char[1];
	string out = "";
	fstream file;
	file.open(path, ios_base::in);
	if (file.is_open()) {
		while (!file.eof()) {
			file.read(buffer, 1);
			out = out + buffer[0];
		}
		file.close();
	}
	return out;
}

int main(int argc, char* argv[])
{
	AppPath = argv[0];

	//commands execute
	if (argc == 2) {
		string arg = argv[1];
		if (arg == "--help") {
			cout << "Generate EXE:" << endl;
			cout << "       AppRunner.exe <path to rdp file> <output path for exe>" << endl;
			cout << "USAGE:" << endl;
			cout << "       Any other use will execute mstsc.exe with parameters." << endl;
			cout << endl;
			cout << "Addons:" << endl;
			cout << "If you put Resource Hacker \"rh.exe\" in this app directory and icon in output directory with the same name but.ico extension, app will set icon to new exe file." << endl;
			exit(0);
		}
	}

	//generate
	if (argc == 3) {
		string rdp = argv[1];
		string output = argv[2];
		if (rdp.find(".rdp") == rdp.length() - 4 && output.find(".exe") == output.length() - 4) {
			string rdpData = ReadFile(rdp);
			InsertData(output, rdpData);

			{	//set icon to exe file
				string rhPath;
				rhPath = AppPath.substr(0, AppPath.length() - 3) + "exe";
				string icoPath;
				icoPath = output.substr(0, output.length() - 3) + "ico";

				if (FileExists(rhPath) && FileExists(icoPath)) {
					system(("\"rh.exe\" -open \"" + output + "\" -save \"" + output + "\" -action addskip -res \"" + icoPath + "\" -mask ICONGROUP,MAINICON,0").c_str());
				}
			}

			cout << "created new runner" << endl;
			exit(0);
		}
	}

	SaveData("$starter.rdp", argc, argv);
	system("%windir%\\system32\\mstsc.exe $starter.rdp");
}