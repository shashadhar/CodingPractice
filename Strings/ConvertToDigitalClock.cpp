#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;



string convert_to_digital_time(int minutes)
{
  // complete this function

  string result = "";
  int hour = minutes / 60;
  int minutesLeft = minutes - (hour * 60);
  if (minutesLeft < 10)
  {
    result = to_string(hour) + ":" + "0" + to_string(minutesLeft);
  }
  else
  {
    result = to_string(hour) + ":" + to_string(minutesLeft);
  }
  return result;
}



int main()
{
  cout << convert_to_digital_time(125);
  
}
