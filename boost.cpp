#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
namespace po = boost::program_options;
struct emp{
        int id;
        std::string name;
        std::string dept;
        int salary;
};
struct emp* return_objects(std::string filename)
{
 std::fstream fin;
 fin.open(filename);
 struct emp *arr= new struct emp[5];
 std::vector<std::string> row;
 int i=0;
 std::string line;
 while(std::getline(fin,line))
      {
      std::vector<std::string>row;
      boost::algorithm::split(row,line,boost::is_any_of(","));
      arr[i].id=stoi(row[0]);
      arr[i].name=row[1];
      arr[i].dept=row[2];
      arr[i].salary=stoi(row[3]);
      i++;
       }
    fin.close();
    return arr;
}
bool compare(emp e,emp s)
{
        return(e.salary<s.salary);
}

int main(int argc,char *argv[])
{
  std::string filename;
  po::options_description desc("Allowed Options");
  desc.add_options()
        ("file",po::value<std::string>(),"file");
  po::variables_map vm;
  po::store(po::parse_command_line(argc,argv,desc),vm);
  if (vm.count("file")){
     filename=vm["file"].as<std::string>();
        }
  struct emp* arr=return_objects(filename);
  std::sort(arr,arr+5,compare);
  for(int i=0;i<5;i++){
          std::cout<<arr[i].id<<","<<arr[i].name<<","<<arr[i].dept<<","<<arr[i].salary<<std::endl;
  }
}
                                                                                                                            56,1          Bot
