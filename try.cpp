#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  fstream f;
  f.open("sample.ild", fstream::in);

  vector<string> sintax;
  string line;

  while(getline(f, line)) {
    sintax.clear(); 
    sintax.push_back(line);
    for(int i = 0; i < sintax.size(); i++)
      cout << sintax[i] << " ";
    cout << " fine linea" << endl;
  }
}
