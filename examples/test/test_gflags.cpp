/*
 * Demo of gflags
 * Build: g++ test-gflags.cc -o test-gfalgs -lgflags
 * // ERROR: illegal value '-1' specified for uint64 flag 'u64'
 * ./test-gflags.out --b=false --i32=-1 --i64=1 --u64=-1 --d=10.01 -s="string
 * value"
 * // ERROR: failed validation of new value '11' for flag 'i32'
 * ./test-gflags.out --b=false --i32=11 --i64=1 --u64=1 --d=10.01 -s="string
 * value"
 * ./test-gflags.out --b=false --i32=1 --i64=1 --u64=1 --d=10.01 extraa extrab
 * extrac
 *
 * Refer to gflags.h for more detail help message of structs and function.
 */

#include <gflags/gflags.h>
#include <iostream>
#include <string>
#include <vector>

// move these declare statements to header file. Other source files
// which included the header could use these flags too.
DECLARE_bool(b);
DECLARE_int32(i32);
DECLARE_int64(i64);
DECLARE_uint64(u64);
DECLARE_double(d);
DECLARE_string(s);

DEFINE_bool(b, true, "bool value");
DEFINE_int32(i32, 10, "int32 value");
DEFINE_int64(i64, 10, "int64 value");
DEFINE_uint64(u64, 10, "uint64 value");
DEFINE_double(d, 10.0, "double value");
DEFINE_string(s, "english,french,german",
              "comma-separated list of languages to offer in the 'lang' menu");

static bool ValidateInt(const char* flagname, int value) {
  if (value < 10) return true;
  return false;
}

int main(int argc, char* argv[]) {
  for (int i = 0; i < argc; i++) {
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  }

  // Demo of google::RegisterFlagValidator()
  if (!google::RegisterFlagValidator(&FLAGS_i32, &ValidateInt)) {
    std::cout << "RegisterFlagValidator fail" << std::endl;
  }

  // Demo of google::ParseCommandLineFlags()
  // calling google::ParseCommandLineFlags(&argc, &argv, true), argvs will be
  // reserved.
  google::ParseCommandLineFlags(&argc, &argv, true);

  // Demo of using flags and their value
  std::cout << "FLAGS_b = " << FLAGS_b << std::endl;
  std::cout << "FLAGS_i32 = " << FLAGS_i32 << std::endl;
  std::cout << "FLAGS_i64 = " << FLAGS_i64 << std::endl;
  std::cout << "FLAGS_u64 = " << FLAGS_u64 << std::endl;
  std::cout << "FLAGS_d = " << FLAGS_d << std::endl;
  std::cout << "FLAGS_s = " << FLAGS_s << std::endl;

  // output reserved argvs
  for (int i = 0; i < argc; i++) {
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  }

  google::CommandLineFlagInfo info;
  std::string buf;
  // Demo of google::GetCommandLineOption()
  google::GetCommandLineOption("s", &buf);

  // Demo of google::GetCommandLineFlagInfo()
  if (google::GetCommandLineFlagInfo("s", &info) && info.is_default) {
    std::cout << "s is not set, using default value " << info.default_value
              << std::endl;
  } else {
    std::cout << "s is set to " << buf << std::endl;
  }

  // Demo of google::SetCommandLineOption()
  google::SetCommandLineOption("s", "new string value");
  google::GetCommandLineOption("s", &buf);
  if (google::GetCommandLineFlagInfo("s", &info) && info.is_default) {
    std::cout << "s is not set, using default value " << info.default_value
              << std::endl;
  } else {
    std::cout << "s is set to " << buf << std::endl;
  }

  std::cout << "Show all flags" << std::endl;
  std::vector<google::CommandLineFlagInfo> bufs;
  // Demo of google::GetAllFlags()
  google::GetAllFlags(&bufs);
  for (std::vector<google::CommandLineFlagInfo>::iterator ite = bufs.begin();
       ite != bufs.end(); ite++) {
    std::cout << ite->name << "=" << ite->current_value
              << ", default: " << ite->default_value << std::endl;
  }
  return 0;
}
