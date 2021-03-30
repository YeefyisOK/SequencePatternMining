//
//#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <vector>
//#include "EyeMovementTypeTime.h"
//using namespace std;
//
////名称:my_split(const std::string& src, const char& delim,
////		 std::vector<std::string>& vec)
////功能:用分隔符将源字符串分隔为多个子串并传出; n个分隔符, 分n+1个子串
////
////参数:
////	 src-传入参数, 源字符串;
////	 delim-传入参数, 分隔符;
////	 vec-传出参数, 子串的集合;
////
////返回值:
////	0-成功;
////	其它-失败;
// 
//int my_split(const string& src, const char& delim,
//	vector<string>& vec)
//{
//	int src_len = src.length();
//	int find_cursor = 0;
//	int read_cursor = 0;
//
//	if (src_len <= 0) return -1;
//
//	vec.clear();
//	while (read_cursor < src_len) {
//
//		find_cursor = src.find(delim, find_cursor);
//
//		//1.找不到分隔符
//		if (-1 == find_cursor) {
//			if (read_cursor <= 0) return -1;
//
//			//最后一个子串, src结尾没有分隔符
//			if (read_cursor < src_len) {
//				vec.push_back(src.substr(read_cursor, src_len - read_cursor));
//				return 0;
//			}
//		}
//		//2.有连续分隔符的情况
//		else if (find_cursor == read_cursor) {
//			//字符串开头为分隔符, 也按空子串处理, 如不需要可加上判断&&(read_cursor!=0)
//			vec.push_back(string(""));
//		}
//		//3.找到分隔符
//		else
//			vec.push_back(src.substr(read_cursor, find_cursor - read_cursor));
//
//		read_cursor = ++find_cursor;
//		if (read_cursor == src_len) {
//			//字符串以分隔符结尾, 如不需要末尾空子串, 直接return
//			vec.push_back(string(""));
//			return 0;
//		}
//	}//end while()
//	return 0;
//}
//
//int main()
//{
//	FILE *fp;
//	const string in_dir = "E:\\read-all\\";
//	const string out_dir = "E:\\out";
//	const string out_path = out_dir + "\\FourTypePercent10.csv";
//	
//	ofstream out_file(out_path, ofstream::out);
//	string line="Recording,fixationTime,saccadeTime,unclassifiedTime,eyesNotFoundTime,totalTime,fixationTimePercentage,saccadeTimePercentage,unclassifiedTimePercentage,eyesNotFoundTimePercentage ";
//	out_file << line << endl;
//	vector<string> names{
//		"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
//		"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
//		"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
//		"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
//		"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
//		"Project77_56-49 Recording35","Project77_56-49 Recording38",
//		"Project48-39 Recording19","Project48-39 Recording29","Project48-39 Recording34",
//		"Project48-39 Recording40","Project48-39 Recording45","Project48-39 Recording47",
//		"Project48-39 Recording49","Project48-39 Recording52","Project48-39 Recording55",
//		"Project48-39 Recording71",
//		"Project33-24 Recording16","Project33-24 Recording17","Project33-24 Recording36",
//		"Project33-24 Recording37","Project33-24 Recording39","Project33-24 Recording41",
//		"Project33-24 Recording57","Project33-24 Recording59","Project33-24 Recording65",
//		"Project33-24 Recording66","Project33-24 Recording67","Project33-24 Recording68",
//		"Project33-24 Recording72",
//		"Project22-1 Recording42","Project22-1 Recording48","Project22-1 Recording50",
//		"Project22-1 Recording51","Project22-1 Recording53","Project22-1 Recording54",
//		"Project22-1 Recording56","Project22-1 Recording58","Project22-1 Recording61",
//		"Project22-1 Recording62","Project22-1 Recording64","Project22-1 Recording69"
//	};
//	//vector<string> names{
//	//	"Project48-39 Recording29"
//	//};
//	string in_path;
//	for (int k = 0; k < names.size(); k++) {  
//		in_path = in_dir + names[k] + ".tsv";
//		cout << "第" << k << "个文件路径为：" << in_path << endl;
//		string date = "";
//		fp = fopen(in_path.c_str(), "r");//string to const char*
//		if (!fp)
//		{
//			cout << "OPEN ERROR!" << endl;
//			return 0;
//		}
//		int i = 0;
//		EyeMovementTypeTime eyeMovementTypeTime;
//		vector<string> AOIs{
//			"Diagram","OptionA","OptionB","OptionC","OptionD","Statement1","Statement2","Time","Else"
//		};//8 AOIs
//		vector<string> sequence;
//		
//		//char Sensor[10000], Validity_left[10000], Validity_right[10000], Mapped_eye_movement_type[10000];
//		//long long Recording_timestamp = 0, Computer_timestamp = 0;
//		//double Assisted_mapping_gaze_point_score = 0;
//		//int Mapped_eye_movement_type_index = 0;
//		//char data1[100],data2[100];
//		char original_data[20000];
//		//fscanf(fp, "%s", &data1);
//		fgets(original_data, sizeof(original_data), fp);
//		const char * split = "\t";
//		string last_eye_movement_type = "0";
//		int start_flag = 0;
//		//for (i = 0; i < 2478; i++)
//		long long recordingTime = 0;
//		long long lastLineRecordingTime = 0;//时刻记录最后一行的recordingTime，只有全读完了才知道是最后一行
//		int last_gaze_event_duration = 0;
//		while (fgets(original_data, sizeof(original_data), fp))//original_data != ""
//		{
//			i++;//recode current line
//			vector<string> line;
//			my_split(original_data, '\t', line);
//			if (line.size() == 0) {
//				break;
//			}
//			date = line[8];//3->8 Recording date
//			if (start_flag == 0) {
//				//读取第一行不计算duration
//				recordingTime = stoll(line[0]);
//				start_flag = 1;
//			}
//			else if (start_flag == 1) {
//				if (line[54] != last_eye_movement_type) {
//					int duration = stoll(line[0]) - recordingTime;
//					recordingTime = stoll(line[0]);
//					//cout << last_eye_movement_type << ":"<<duration << endl;
//					eyeMovementTypeTime.addTime(last_eye_movement_type, duration);//stoi(line[55])
//
//
//					//cout << line[54] << ":" << stoi(line[55]) << endl;
//					eyeMovementTypeTime.addTime(line[54], stoi(line[55]));//
//					start_flag = 2;
//				}
//			}
//			else if (start_flag == 2) {
//
//				if (line[54] != last_eye_movement_type) {
//					recordingTime = stoll(line[0]);
//					//cout << line[54] << ":" << stoi(line[55]) << endl;
//					eyeMovementTypeTime.addTime(line[54], stoi(line[55]));//
//				}
//			}
//			last_eye_movement_type = line[54];//每读一行修改一次
//			last_gaze_event_duration = stoi(line[55]);
//			lastLineRecordingTime = stoll(line[0]);
//			if (feof(fp))
//				break;
//		}
//		if (start_flag == 1) {//一直都是一个类型
//			//cout << last_eye_movement_type << ":" << lastLineRecordingTime + 8 - recordingTime << endl;
//			eyeMovementTypeTime.addTime(last_eye_movement_type, lastLineRecordingTime + 8 - recordingTime);
//		}
//		else if (start_flag == 2) {//有超过两个类型
//			//先把之前错的的减去
//			//cout <<"减去了：" <<last_eye_movement_type << ":" << last_gaze_event_duration << endl;
//			eyeMovementTypeTime.deleteTime(last_eye_movement_type, last_gaze_event_duration);
//			//再把后面的加上
//			//cout << last_eye_movement_type << ":" << lastLineRecordingTime + 8 - recordingTime << endl;
//			eyeMovementTypeTime.addTime(last_eye_movement_type, lastLineRecordingTime +8-recordingTime);//stoi(line[55])
//		
//		}
//		
//		//cout << "统计信息" << endl;
//		//cout << "fixationTime:" << eyeMovementTypeTime.fixationTime << endl;
//		//cout << "saccadeTime:" << eyeMovementTypeTime.saccadeTime << endl;
//		//cout << "unclassifiedTime:" << eyeMovementTypeTime.unclassifiedTime << endl;
//		//cout << "eyesNotFoundTime:" << eyeMovementTypeTime.eyesNotFoundTime << endl;;
//		vector<double> typePercent = eyeMovementTypeTime.getPercent();
//
//		stringstream sstream;
//		sstream << names[k]<< " " << date << "," << eyeMovementTypeTime.fixationTime << ","
//			<< eyeMovementTypeTime.saccadeTime << ","  
//			<< eyeMovementTypeTime.unclassifiedTime << ","
//			<< eyeMovementTypeTime.eyesNotFoundTime << ",";
//
//		sstream << typePercent[0] << "," << typePercent[1] << "," << typePercent[2] << ","
//			<< typePercent[3] << "," << typePercent[4];
//		out_file << sstream.str() << endl;
//
//	
//		fclose(fp);
//	}
//
//	out_file.close();
//
//	system("pause");
//
//}
