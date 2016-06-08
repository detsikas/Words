//
//  LetterMapping.cpp
//  LSITest
//
//  Created by Nikolaos Detsikas on 11/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "LetterMapping.h"

void LetterMapping::FillMap()
{
    greekMappedAsciiCapitalLetters['A'] = ::utf8letter(0316,0261);// byte0_a+0261;
    greekMappedAsciiCapitalLetters['B'] = ::utf8letter(0316,0262);//byte0_a+0262;
    greekMappedAsciiCapitalLetters['E'] = ::utf8letter(0316,0265);// byte0_a+0265;
    greekMappedAsciiCapitalLetters['Z'] = ::utf8letter(0316,0266);//byte0_a+0266;
    greekMappedAsciiCapitalLetters['H'] = ::utf8letter(0316,0267);//byte0_a+0267;
    greekMappedAsciiCapitalLetters['I'] = ::utf8letter(0316,0271);//byte0_a+0271;
    greekMappedAsciiCapitalLetters['K'] = ::utf8letter(0316,0272);//byte0_a+0272;
    greekMappedAsciiCapitalLetters['M'] = ::utf8letter(0316,0274);//byte0_a+0274;
    greekMappedAsciiCapitalLetters['N'] = ::utf8letter(0316,0275);//byte0_a+0275;
    greekMappedAsciiCapitalLetters['O'] = ::utf8letter(0316,0277);//byte0_a+0277;
    greekMappedAsciiCapitalLetters['P'] = ::utf8letter(0317,0201);//byte0_b+0201;
    greekMappedAsciiCapitalLetters['T'] = ::utf8letter(0317,0204);//byte0_b+0204;
    greekMappedAsciiCapitalLetters['Y'] = ::utf8letter(0317,0205);//byte0_b+0205;
    greekMappedAsciiCapitalLetters['X'] = ::utf8letter(0317,0207);//byte0_b+0207;
    
    //capital greek Α-O
    greekLetters[::utf8letter(0316,0221)] = ::utf8letter(0316,0261);
    greekLetters[::utf8letter(0316,0222)] = ::utf8letter(0316,0262);
    greekLetters[::utf8letter(0316,0223)] = ::utf8letter(0316,0263);
    greekLetters[::utf8letter(0316,0224)] = ::utf8letter(0316,0264);
    greekLetters[::utf8letter(0316,0225)] = ::utf8letter(0316,0265);
    greekLetters[::utf8letter(0316,0226)] = ::utf8letter(0316,0266);
    greekLetters[::utf8letter(0316,0227)] = ::utf8letter(0316,0267);
    greekLetters[::utf8letter(0316,0230)] = ::utf8letter(0316,0270);
    greekLetters[::utf8letter(0316,0231)] = ::utf8letter(0316,0271);
    greekLetters[::utf8letter(0316,0232)] = ::utf8letter(0316,0272);
    greekLetters[::utf8letter(0316,0233)] = ::utf8letter(0316,0273);
    greekLetters[::utf8letter(0316,0234)] = ::utf8letter(0316,0274);
    greekLetters[::utf8letter(0316,0235)] = ::utf8letter(0316,0275);
    greekLetters[::utf8letter(0316,0236)] = ::utf8letter(0316,0276);
    greekLetters[::utf8letter(0316,0237)] = ::utf8letter(0316,0277);

    //capital greek P-Ω
    greekLetters[::utf8letter(0316,0240)] = ::utf8letter(0317,0200);
    greekLetters[::utf8letter(0316,0241)] = ::utf8letter(0317,0201);
    greekLetters[::utf8letter(0316,0242)] = ::utf8letter(0317,0202);
    greekLetters[::utf8letter(0316,0243)] = ::utf8letter(0317,0203);
    greekLetters[::utf8letter(0316,0244)] = ::utf8letter(0317,0204);
    greekLetters[::utf8letter(0316,0245)] = ::utf8letter(0317,0205);
    greekLetters[::utf8letter(0316,0246)] = ::utf8letter(0317,0206);
    greekLetters[::utf8letter(0316,0247)] = ::utf8letter(0317,0207);
    greekLetters[::utf8letter(0316,0250)] = ::utf8letter(0317,0210);
    greekLetters[::utf8letter(0316,0251)] = ::utf8letter(0317,0211);

    //tonoi sta mikra
    greekLetters[::utf8letter(0316,0254)] = ::utf8letter(0316,0261);
    greekLetters[::utf8letter(0316,0255)] = ::utf8letter(0316,0265);
    greekLetters[::utf8letter(0316,0256)] = ::utf8letter(0316,0267);
    greekLetters[::utf8letter(0316,0257)] = ::utf8letter(0316,0271);
    greekLetters[::utf8letter(0317,0214)] = ::utf8letter(0316,0277);
    greekLetters[::utf8letter(0317,0215)] = ::utf8letter(0317,0205);
    greekLetters[::utf8letter(0317,0216)] = ::utf8letter(0317,0211);

    //tonoi sta kefalaia
    greekLetters[::utf8letter(0316,0206)] = ::utf8letter(0316,0261);
    greekLetters[::utf8letter(0316,0210)] = ::utf8letter(0316,0265);
    greekLetters[::utf8letter(0316,0211)] = ::utf8letter(0316,0267);
    greekLetters[::utf8letter(0316,0212)] = ::utf8letter(0316,0271);
    greekLetters[::utf8letter(0316,0214)] = ::utf8letter(0316,0277);
    greekLetters[::utf8letter(0316,0216)] = ::utf8letter(0317,0205);
    greekLetters[::utf8letter(0316,0217)] = ::utf8letter(0317,0211);

    //teliko s
    greekLetters[::utf8letter(0317,0202)] = ::utf8letter(0317,0203);
    
    //dialitika
    greekLetters[::utf8letter(0317,0213)] = ::utf8letter(0317,0205);
    greekLetters[::utf8letter(0316,0253)] = ::utf8letter(0317,0205);
    greekLetters[::utf8letter(0316,0260)] = ::utf8letter(0317,0205);
    greekLetters[::utf8letter(0317,0212)] = ::utf8letter(0316,0271);
    greekLetters[::utf8letter(0316,0252)] = ::utf8letter(0316,0271);
    greekLetters[::utf8letter(0316,0220)] = ::utf8letter(0316,0271);
    
}

utf8letter LetterMapping::getGreekMappedAsciiCapitalLetters(const char in) const
{
    map<const char, utf8letter>::const_iterator it = greekMappedAsciiCapitalLetters.find(in);
    utf8letter letter;
    if(it != greekMappedAsciiCapitalLetters.end())
    {
        //element found;
        letter = utf8letter(it->second.first, it->second.second);
    }
    else
        letter = utf8letter(0,0);
    
    return letter;
}


utf8letter LetterMapping::getGreekLetters(const utf8letter in) const
{
    map<utf8letter, utf8letter>::const_iterator it = greekLetters.find(in);
    utf8letter letter;
    if(it != greekLetters.end())
    {
        //element found;
        letter = utf8letter(it->second.first, it->second.second);
    }
    else
        letter = utf8letter(0,0);
    
    return letter;
}

