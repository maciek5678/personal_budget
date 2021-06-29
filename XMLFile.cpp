#include <iostream>
#include "XMLFile.h"
bool XMLFile::doesFileExist ()
{
    return xml.Load( FILE_NAME);
}
int XMLFile::getLastID()
{
    return lastID;
}
