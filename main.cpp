#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


string szyfruj(string s, string key) {
  string result;
  int keyIndex = 0;
  int move;
  int index;
  int counter = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < 'A' || s[i] > 'Z') {
      result += s[i];
      continue;
    }
    move = (int) key[keyIndex] - 65;
    index = (int) s[i] - 65;
    index += move;
    if (index > 25) index = (index - 1) % 25;
    index += 65;
    result += (char) index;
    
    keyIndex++;
    if (keyIndex == key.length()) keyIndex = 0;
  }
  return result;
}

void zad1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("dokad.txt");
  string s = "";
  string temp;
  while (in >> temp) s += temp + " ";
  string key = "LUBIMYCZYTAC";
  
  
  cout << "a) " << 19 << endl;
  cout << "b) " << szyfruj(s, key) << endl << endl;
}

void zad2() {
  cout << "Zadanie 2:" << endl;
  string key = "ZLODZIEJCZASU";
  string s = "";
  string temp;
  ifstream in("szyfr.txt");
  while (in >> temp) s += temp + " ";
  
  int keyIndex = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ' || s[i] == ',' || s[i] == '.') continue;
    s[i] -= key[keyIndex];
    s[i] += 65;
    if (s[i] < 'A') s[i] += 26;
    keyIndex++;
    if (keyIndex == key.length()) keyIndex = 0;
  }
  cout << s << endl << endl;
}

void zad3() {
  cout << "Zadanie 3:" << endl;
  
  cout << "a)" << endl;
  int tab[26];
  for (int i = 0; i < 26; i++) {
    tab[i] = 0;
  }
  ifstream in("szyfr.txt");
  string s;
  float n = 0.0;
  while (in >> s) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        n++;
        tab[s[i] - 65]++;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    cout << (char) (i + 65) << ": " << tab[i] << endl;
  }
  cout << endl;

  cout << "b)" << endl;
  float Ko = 0.0;
  for (int i = 0; i < 26; i++) {
    Ko += tab[i] * (tab[i] - 1);
  }
  Ko /= n * (n - 1);
  float d = 0.0285 / (Ko - 0.0385);
  cout << "Wartosc szacunkowa: " << fixed << setprecision(2) << d << endl;
  cout << "Wartosc prawdziwa: " << 13 << endl;
}

int main() {
  zad1();
  zad2();
  zad3();
}
