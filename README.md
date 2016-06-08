# Words
Words is a library that parses phrases, applies stemming and filters stop words. In other words, it does most of the operations needed
before builging text search indexes.

The library supports Greek letters, stemmer and stop word sets. Currently, Greek support is integrated in the code and I am planning to
make it optional. Until then, it is fairly easy to do it, once someone understands the code.

## Dependecies
The project uses [StopWordsLib] (https://github.com/detsikas/StopWordsLib). Before using **Words**, make sure to download that first.

## Usage
Here is some sample code on how to use the library

```C++
//Initialize Words class
string greekPath = "path_to_greek_stop_words_file";
string englishPath = path_to_english_stop_words_file";
Words words(greekPath, englishPath);
    
string englishWord = "Ourselves";

// convert test word to lower case and remove accent (for Greek words only)
// also detect the language
Languge_t language;
string loweredNonAccentEnglishWord = words.lowerNonAccent(engishWord, language);

// stem the word    
string stemmedEnglishWord = words.stemGreekWord(loweredNonAccentEnglishWord);
    
if (!words.findEnglishStopWord(stemmedEnglishWord, words))
  cout<<stemmedEnglishWord;
  
string englishPhrase = " This is a sample phrase";
string processedPhrase = words.processPhrase(englishPhrase);

