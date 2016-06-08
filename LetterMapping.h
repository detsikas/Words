//
//  LetterMapping.h
//  LSITest
//
//  Created by Nikolaos Detsikas on 11/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef LSITest_LetterMapping_h
#define LSITest_LetterMapping_h

#include <map>

using namespace std;

typedef  pair<unsigned char, unsigned char> utf8letter;

class LetterMapping
{
public:
    void FillMap();
    utf8letter getGreekMappedAsciiCapitalLetters(const char in) const;
    utf8letter getGreekLetters(const utf8letter in) const;
private:
    map<const char, utf8letter> greekMappedAsciiCapitalLetters;
    map<utf8letter, utf8letter> greekLetters;
};

#endif
