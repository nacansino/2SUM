#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool is_found(std::vector<long long int> &arr, long long int t){
  std::unordered_map<long long int, bool> my_map;
  for(auto x: arr){
    if(my_map.find(t-x) != my_map.end()) return true;
    my_map.insert(std::make_pair(x, true));
  }
  return false;
}

int main(){
//load text here
  //Variables for parsing the string
  std::string filename;
//  std::string filename = "tests/input_random_1_10.txt";
//  std::string filename = "tests/prob-2sum.txt";
  std::cin >> filename;
  filename = "tests/" + filename + ".txt";
  std::string s;  //for line parse
  //-----------------------------------
  std::vector<long long int> arr;
  long long int d;
  int ctr;
  //START
  std::ifstream inFile(filename, std::ios::in);
  if (!inFile) {
    std::cerr << "Unable to open file " << filename << std::endl;
    exit(1);   // call system to stop
  }
  //loop through the numbers one by one
  while (!inFile.eof()){
    //1: get line
    std::getline(inFile, s);
    //2: we expect nondelimited lines here so we directly convert them to int
    if(s.length() == 0) continue;

    //convert string line to integer, then add to array
    arr.push_back(std::stoll(s));
  }

  std::cout << "finished parsing lines" << std::endl;
  //loop through T=[-10000:10000] (inclusive)
  ctr = 0;
  for(long long int t=-10000; t<=10000; t++){
      if(is_found(arr, t)) {
        ctr++;
        continue;
      }
    }
  std::cout << ctr << std::endl;
}
