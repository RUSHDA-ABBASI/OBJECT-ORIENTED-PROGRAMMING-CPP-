#include<iostream>
#include<fstream>

using namespace std;

class Logger{
	private:
		static Logger* ptr;
		ofstream file;
		Logger(const string& filename = "log.txt"){
			file.open(filename.c_str(), ios::app);
			if(!file.is_open()){
				cerr<<"File not accessible.\n";
			}
		}
		Logger(const Logger&) = delete;
		Logger& operator = (const Logger&) = delete;
		
	public:
		static Logger* getInstance(const string& filename = "log.txt"){
			if(!ptr){
				ptr = new Logger (filename);
			}
			return ptr;
		}
		void LogMsg(const string& msg){
			if(file.is_open()){
				file<<msg<<endl;
			}
		}
		~Logger(){
			file.close();
		}
};
Logger* Logger::ptr = NULL;

int main(){
	//Logger log
	Logger* obj = Logger::getInstance("section_b.txt");
	obj -> LogMsg("Online Class!");
	obj -> LogMsg("Section B");
	
	return 0;
}