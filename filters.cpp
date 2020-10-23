#include <iostream>
#include <string>
#include <array>
#include <cstdlib>

using namespace std;

class Filter
{
protected:
  string _name;

public:
  Filter(){}
  Filter(const std::string& name) : _name(name) {}
  virtual ~Filter() {};

  virtual string apply(const string& input) = 0;

  string get_name() { return _name; }
};



class Capitalize : public Filter{

public:
  Capitalize(){_name = "Capitalize";}
  ~Capitalize(){}

  string apply(const string& in){
    string newStr = "";
    char currentChar;

    for(int i=0;i<in.length();i++){

      currentChar = in[i];

      //make sure its a lower case letter before trying to Capitalize
      if(currentChar >= 97 && currentChar <= 122){
        currentChar -= ' ';
      }

      newStr += currentChar;

    }
    return newStr;
  }
};
class CapitalizeFirstLetter : public Filter{
public:
  CapitalizeFirstLetter(){_name = "Capitalize First Letter";}
  ~CapitalizeFirstLetter(){}

  string apply(const string& in){
    string newStr = "";
    char currentChar;
    bool alreadyCap=false;
    for(int i=0;i<in.length();i++){

      currentChar = in[i];

      //make sure its a lower case letter before trying to Capitalize
      if(currentChar >= 97 && currentChar <= 122 && !alreadyCap){
        currentChar -= ' ';
        alreadyCap = true;
      }

      newStr += currentChar;

    }
    return newStr;
  }

};
class CapitalizeFirstLetterOfEveryWord : public Filter{
public:
  CapitalizeFirstLetterOfEveryWord(){_name = "Capitalize First Letter Of Every Word";}
  ~CapitalizeFirstLetterOfEveryWord(){}

  string apply(const string& in){
    string newStr = "";
    char currentChar;
    char prevChar;

    for(int i=0;i<in.length();i++){

      currentChar = in[i];
      prevChar = 0; //temp
      if(i>0){
        prevChar = in[i-1];
      }

      if(prevChar == 32 | i==0){
        //make sure its a lower case letter before trying to Capitalize
        if(currentChar >= 97 && currentChar <= 122){
          currentChar -= ' ';
        }
      }

      newStr += currentChar;

    }
    return newStr;
  }
};
class Obenglobish : public Filter{

public:
  Obenglobish(){_name = "Obenglobish";}
  ~Obenglobish(){};

  string apply(const string& input){

    string newStr = "";
    char currentChar;

    for(int i=0; i < input.length(); i++){

      currentChar = input[i];

      if(currentChar == 65 || currentChar == 69 || currentChar == 73
         || currentChar == 79 || currentChar == 85 || currentChar == 97 ||
         currentChar == 101 || currentChar == 105 || currentChar == 111 ||
         currentChar == 117){
           newStr = newStr + "ob" + currentChar;
         }else{
           newStr = newStr + currentChar;
         }

    }
    return newStr;
  }

};
class ReverseString : public Filter{

public:
  ReverseString(){_name = "Reverse String";}
  ~ReverseString(){};

  string apply(const string& input){
    string newStr = "";
    for(int i=input.length()-1;i>=0;i--){
      newStr = newStr + input[i];
    }
    return newStr;
  }

};
class ToSmall : public Filter{

public:
  ToSmall(){_name = "To Lower";}
  ~ToSmall(){}

  string apply(const string& in){
    string newStr = "";
    char currentChar;

    for(int i=0;i<in.length();i++){

      currentChar = in[i];

      //make sure its a upper case letter before trying to get lower case
      if(currentChar >= 65 && currentChar <= 90){
        currentChar += ' ';
      }

      newStr += currentChar;

    }
    return newStr;
  }

};
class Randomize : public Filter{

public:
  Randomize(){_name = "Randomize";}
  ~Randomize(){};

  string apply(const string& in){

    string newStr = "";

    for(int i=0;i<in.length();i+=2){
      newStr += in[i];
    }
    for(int i=1;i<in.length();i+=2){
      newStr += in[i];
    }
    return newStr;
  }

};

/////////////////////////////////////////////////////

int main(){

    const int num_filters = 7;
    Filter* filters[num_filters];

    filters[0] = new Capitalize();
    filters[1] = new CapitalizeFirstLetter();
    filters[2] = new CapitalizeFirstLetterOfEveryWord();
    filters[3] = new Obenglobish();
    filters[4] = new ReverseString();
    filters[5] = new ToSmall();
    filters[6] = new Randomize();

    string input;
    cout << "Enter string: ";  getline(cin, input);

    cout << "Input string: " << input << endl;
    for (int i=0; i<num_filters; ++i) {
    cout << "Filter name:  " << filters[i]->get_name() << endl;
    cout << "Output:       " << filters[i]->apply(input) << endl;
    }

    for (int i=0; i<num_filters; ++i) delete filters[i];

    return 0;
}
