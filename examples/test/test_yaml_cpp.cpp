//
// Created by steve on 9/17/22.
//

#include <iostream>
#include <yaml-cpp/yaml.h>
#include <fstream>

using namespace std;

int main(int argc,char** argv)
{
  YAML::Node config;
  try{
    config = YAML::LoadFile("/home/steve/code/mycode/iiplib/examples/test/config.yaml");
  } catch(YAML::BadFile &e) {
    std::cout<<"read error!"<<std::endl;
    return -1;
  }

  cout << "Node type " << config.Type() << endl;
  cout << "skills type " << config["skills"].Type() << endl;

  //可以用string类型作为下表，读取参数
  string age = "age";
  cout << "age when string is label:" << config[age].as<int>() << endl;

  cout << "name:" << config["name"].as<string>() << endl;
  cout << "sex:" << config["sex"].as<string>() << endl;
  cout << "age:" << config["age"].as<int>() << endl;

  //读取不存在的node值，报YAML::TypedBadConversion异常
  try{
    string label = config["label"].as<string>();
  }catch(YAML::TypedBadConversion<string> &e){
    std::cout<<"label node is NULL"<<std::endl;
  }//TypedBadConversion是模板类，读取什么类型的参数就传入什么类型

  cout << "skills c++:" << config["skills"]["c++"].as<int>() << endl;
  cout << "skills java:" << config["skills"]["java"].as<int>() << endl;
  cout << "skills android:" << config["skills"]["android"].as<int>() << endl;
  cout << "skills python:" << config["skills"]["python"].as<int>() << endl;

  for(YAML::const_iterator it= config["skills"].begin(); it != config["skills"].end();++it)
  {
    cout << it->first.as<string>() << ":" << it->second.as<int>() << endl;
  }

  YAML::Node test1 = YAML::Load("[1,2,3,4]");
  cout << " Type: " << test1.Type() << endl;

  YAML::Node test2 = YAML::Load("1");
  cout << " Type: " << test2.Type() << endl;

  YAML::Node test3 = YAML::Load("{'id':1,'degree':'senior'}");
  cout << " Type: " << test3.Type() << endl;

  ofstream fout("./testconfig.yaml"); //保存config为yaml文件

  config["score"] = 99;//添加新元素

  fout << config;

  fout.close();

  return 0;
}