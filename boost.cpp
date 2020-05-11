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

// TODO: This can be done without raw pointers and heap memory allocation. Try to think about it once
// TODO: trailing return types
struct emp* return_objects(std::string filename)
{
    // TODO: Instead of calling open(), pass the file while constructing the object of std::fstream. Read about RAII
    //       You won't need to remember to call close() on file. It will automatically closed after the object goes out-of-scope
 std::fstream fin;
 fin.open(filename);
 // TODO: You didn't check whether file was opened or not??
 // TODO: Try not to use raw pointers. 
 // TODO: You did not delete these anywhere in the program, it will cause memory leak
 struct emp *arr= new struct emp[5];
 // TODO: Where is this row used?
 std::vector<std::string> row;
int i=0;
 std::string line;
while(std::getline(fin,line))
      {
      std::vector<std::string>row;
      boost::algorithm::split(row,line,boost::is_any_of(","));
      // TODO: Instead of separating assignments, You should try to create a constructor for emp and invoke it
      arr[i].id=stoi(row[0]);
      arr[i].name=row[1];
      arr[i].dept=row[2];
      arr[i].salary=stoi(row[3]);
      i++;         // TODO: Make a habit to prefer pre-increment over post-increment
       }
    fin.close();
    return arr;
}

// TODO: Don't create copy of e and s here. Use 'emp const &'
// TODO: You can also defined 'operator <' for emp struct
bool compare(emp e,emp s)
{
        return(e.salary<s.salary);
}

int main(int argc,char *argv[])
{
  std::string filename;
  // TODO : You should always add --help option. You know what option does the program provide. but the user will try to look up for help first
  po::options_description desc("Allowed Options");
  desc.add_options()
         // TODO: File option should be mandatory. 
        ("file",po::value<std::string>()->required(),"file");
  po::variables_map vm;
  po::store(po::parse_command_line(argc,argv,desc),vm);
  if (vm.count("file")){
     filename=vm["file"].as<std::string>();
        }
  // TODO: redesign return_objects function
  struct emp* arr=return_objects(filename);
  // TODO: Why 5? It should be on the basis of rows in file. size should not be hard-coded
  std::sort(arr,arr+5,compare);
  for(int i=0;i<5;i++){
          // TODO: Would have been easier if you defined 'operator <<' for the struct emp
          //   Inside emp struct
            // friend auto operator << (std::ostream & out, emp const & e) -> std::ostream& {
            //     out << e.id << ", " << e.name << ", " << e.dept << ", " << e.salary;
            //     return out;
            // }
           std::cout<<arr[i].id<<","<<arr[i].name<<","<<arr[i].dept<<","<<arr[i].salary<<std::endl;
  }
  return 0;
}

