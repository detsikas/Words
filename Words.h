//
//  Words.h
//  Words
//
//  Created by me on 27/4/15.
//  Copyright (c) 2015 me. All rights reserved.
//

#ifndef __Words__Words__
#define __Words__Words__

#include <stdio.h>
#include <string>
#include "LetterMapping.h"
#include "StopSetClass.h"

typedef enum
{
    LANGUAGE_NONE,
    GREEK,
    ENGLISH
} Languge_t;

using namespace::std;

class Words
{
public:
    Words();
    Words(string &, string &);
    ~Words();

    string stemEnglishWord(string &) const;
    string stemGreekWord(string &) const;

    bool findEnglishStopWord(const string &) const;
    bool findGreekStopWord(const string &) const;

    string lowerNonAccent(string const &, Languge_t &) const;
    string processPhrase(string &) const;
    
private:
    void initializeStopWords(string &, string &);
    void initiliazeStemmers();

    void toLowerNonAscii(string &) const;
    void toLowerAscii(string &) const;
    
    void fillLetterMap();
    const LetterMapping& getLmap() const;

    StopSetClass stopWordsGreek;
    StopSetClass stopWordsEnglish;
    LetterMapping lmap;
    struct sb_stemmer * stemmerGreek;
    struct sb_stemmer * stemmerEnglish;
};

#endif /* defined(__Words__Words__) */
