#include "thrift-tl.h"

#ifdef _WIN32
#include <Windows.h>
#endif

namespace apache {
namespace thrift {
bool istarts_with(const char* a, const char* b) {
  if (a == nullptr || b == nullptr)
    return false;
  auto len_a = strlen(a);
  auto len_b = strlen(b);
  if (len_b > len_a)
    return false;
  for (size_t i = 0; i <= len_b; i++) {
    if (a[i] != b[i])
      return false;
  }
  return true;
}
bool iends_with(const char* a, const char* b) {
  if (a == nullptr || b == nullptr)
    return false;
  auto len_a = strlen(a);
  auto len_b = strlen(b);
  if (len_b > len_a)
    return false;
  for (size_t i = 1; i <= len_b; i++) {
    if (a[len_a - i] != b[len_b - i])
      return false;
  }
  return true;
}
void split_string(const std::string& s, std::vector<std::string>& v, const std::string& c) {
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while (std::string::npos != pos2) {
    v.push_back(s.substr(pos1, pos2 - pos1));
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if (pos1 != s.length())
    v.push_back(s.substr(pos1));
}
std::string utf16_to_utf8(std::vector<uint16_t> const& data) {
  if (data.empty())
    return "";
  int size_needed
      = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)data.data(), data.size(), NULL, 0, NULL, NULL);
  std::string strTo(size_needed, 0);
  WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)data.data(), data.size(), &strTo[0], size_needed,
                      NULL, NULL);
  return strTo;
}
} // namespace thrift
} // namespace apache
