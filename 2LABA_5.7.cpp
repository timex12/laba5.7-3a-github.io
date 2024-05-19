#include<list>
#include<fstream>
#include <iostream>
#include<string>
using namespace std;

bool punctuation_marks(char ch)
{
    string punctuation = " .,:;!?-()";
    return punctuation.find(ch) != string::npos;
}

int main()
{
    string line;
    list<string> words;
    int n;
    cout << "enter the size of line: ";
    cin >> n;

    ifstream infile("file.txt");
    if (!infile.is_open())
    {
        cout << "error" << endl;
    }

    while (getline(infile, line))
    {
        string word;
        for (int i = 0; i < line.size(); i++)
        {
            char ch = line[i];
            if (punctuation_marks(ch))
            {
                if (!word.empty() && word.size() == n)
                {
                    words.push_back(word);
                }
                word.clear();
            }
            else 
            {
                word += ch;
            }
        }
        if (!word.empty() && word.size() == n)
        {
            words.push_back(word);
        }
    }

    infile.close();

    ofstream outfile("file.txt");
    if (!outfile.is_open())
    {
        cout << "error2" << endl;
    }

    // Записываем слова в файл
    for (list<string>::iterator p = words.begin(); p != words.end(); ++p)
    {
        outfile << *p << "\n";
    }

    outfile.close();

    return 0;
}
