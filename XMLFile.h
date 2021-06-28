#ifndef XMLFILE_H
#define XMLFILE_H
#include <iostream>
#include "Markup.h"
using namespace std;
class XMLFile
{

protected:
    const string FILE_NAME;
    int lastID;
    CMarkup xml;
public:
    XMLFile(string FileName)
        :FILE_NAME( FileName)
    {}
    bool doesFileExist ();
    int getLastID();

};


#endif
