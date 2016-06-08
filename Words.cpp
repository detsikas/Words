//
//  Words.cpp
//  Words
//
//  Created by me on 27/4/15.
//  Copyright (c) 2015 me. All rights reserved.
//

#include "Words.h"
#include "libstemmer.h"
#include <sstream>
#include <vector>

#pragma mark Constructors/Descructor
Words::Words()
{
    fillLetterMap();
}

Words::Words(string & pathGreek, string & pathEnglish)
{
    initializeStopWords(pathGreek, pathEnglish);
    initiliazeStemmers();
    fillLetterMap();
}

Words::~Words()
{
    if (stemmerGreek!=NULL)
        sb_stemmer_delete(stemmerGreek);
    if (stemmerEnglish!=NULL)
        sb_stemmer_delete(stemmerEnglish);
}

#pragma mark Helper functions
void Words::toLowerNonAscii(string &word) const
{
    char *buf = (char*)malloc(word.length()*2);
    uint16_t bufIndex = 0;
    
    for (std::string::iterator i = word.begin(); i != word.end(); ++i)
    {
        unsigned char cc = *i;
        
        //cout << (uint8_t)cc<<endl;
        if (isascii(cc))
        {
            //capital ascii mapped greek
            utf8letter mappedLetter = lmap.getGreekMappedAsciiCapitalLetters(cc);
            if (mappedLetter.first!=0 && mappedLetter.second!=0)
            {
                buf[bufIndex++] = mappedLetter.first;
                buf[bufIndex++] = mappedLetter.second;
            }
            else
                buf[bufIndex++] = tolower(cc);
        }
        else
        {
            if (cc!=0316 && cc!=0317)
            {
                buf[bufIndex++] = cc;
            }
            else
            {
                if ((i+1)!=word.end())
                {
                    ++i;
                    unsigned char cc_2 = *i;
                    utf8letter letter(cc, cc_2);
                    utf8letter newLetter = lmap.getGreekLetters(letter);
                    
                    if (newLetter.first!=0 && newLetter.second!=0)
                    {
                        buf[bufIndex++] = newLetter.first;
                        buf[bufIndex++] = newLetter.second;
                    }
                    else
                    {
                        buf[bufIndex++] = cc;
                        buf[bufIndex++] = cc_2;
                    }
                }
                else
                {
                    buf[bufIndex++] = cc;
                }
            }
        }
    }
    buf[bufIndex]='\0';
    word = string(buf);
    free(buf);
}

void Words::toLowerAscii(string &word) const
{
    for (std::string::iterator i = word.begin(); i != word.end(); ++i)
    {
        unsigned char cc = *i;
        cc = tolower(cc);
        *i = cc;
    }
}

#pragma mark Capital, small, accent functions
string Words::lowerNonAccent(string const &word, Languge_t & language) const
{
    string result = word;
    language = ENGLISH;
    uint8_t asciinum = 0;
    uint8_t nonasciinum = 0;
    for (std::string::iterator i = result.begin(); i != result.end(); ++i)
    {
        char cc = *i;
        if (isascii(cc))
            asciinum++;
        else
        {
            nonasciinum++;
        }
    }
    
    nonasciinum/=2;
    if (nonasciinum==0)
        toLowerAscii(result);
    else
    {
        language = GREEK;
        toLowerNonAscii(result);
    }
    
    return result;
}

#pragma mark Stopword Functions
void Words::initializeStopWords(string & pathGreek, string & pathEnglish)
{
    {
        cout<<"Reading greek stopwords"<<endl;
        ifstream ifs("store_file_greek.dat");
        boost::archive::text_iarchive ia(ifs);
        ia>>stopWordsGreek;
    }
    
    {
        cout<<"Reading english stopwords"<<endl;
        ifstream ifs("store_file_english.dat");
        boost::archive::text_iarchive ia(ifs);
        ia>>stopWordsEnglish;
    }
}

bool Words::findEnglishStopWord(const string &word) const
{
    return stopWordsEnglish.find(word);
}

bool Words::findGreekStopWord(const string &word) const
{
    return stopWordsGreek.find(word);
}

#pragma mark Stemming Functions
string Words::stemEnglishWord(string &word) const
{
    sb_symbol* inWord = (sb_symbol*)word.c_str();
    
    const sb_symbol * stemmed = sb_stemmer_stem(stemmerEnglish, inWord, (int)word.length());
    
    if (stemmed==NULL)
        return NULL;
    else
        return string((char*)stemmed);
}

string Words::stemGreekWord(string &word) const
{
    sb_symbol* inWord = (sb_symbol*)word.c_str();
    
    const sb_symbol * stemmed = sb_stemmer_stem(stemmerGreek, inWord, (int)word.length());
    
    if (stemmed==NULL)
        return NULL;
    else
        return string((char*)stemmed);
}

void Words::initiliazeStemmers()
{
    stemmerGreek = sb_stemmer_new("greek", NULL);
    stemmerEnglish = sb_stemmer_new("english", NULL);
}

#pragma mark Letter Map Functions
void Words::fillLetterMap()
{
    lmap.FillMap();
}

const LetterMapping& Words::getLmap() const
{
    return lmap;
}

#pragma mark Phrase functions
/* Parses each word of a phrase and
    1. converts it to lower case and removes any accent (for languages with accents, like Greek)
    2. stems the word
    3. checks if it is a stop word
    4. appends it to the output phrase if it passes the above 
 */
string Words::processPhrase(string & phrase) const
{
    string outputPhrase;
//    vector<string> tokens;
    istringstream iss(phrase);
  //  copy(istream_iterator<string>(iss),
    //     istream_iterator<string>(),
      //   back_inserter(tokens));
    istream_iterator<string> it(iss);
    istream_iterator<string> endOfPhrase;
    
//    vector<string>::const_iterator it;
    while(it!=endOfPhrase)
    {
        string const & word = *it;
        Languge_t language;

        //convert word to lower case and remove accent
        string lowerNonAccent = this->lowerNonAccent(word, language);
        
        string stemmedWord;
        bool stopped = false;
        
        //stem the workd and see if it is a stop word
        if (language==GREEK)
        {
            stemmedWord = stemGreekWord(lowerNonAccent);
            stopped = findGreekStopWord(stemmedWord);
        }
        else
        {
            stemmedWord = stemEnglishWord(lowerNonAccent);
            stopped = findEnglishStopWord(stemmedWord);
        }
        
        it++;

        if (!stopped)
        {
            outputPhrase.append(stemmedWord);
            if (it!=endOfPhrase)
                outputPhrase.append(" ");
        }
    }
    
    return outputPhrase;
}