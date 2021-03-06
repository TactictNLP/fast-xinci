#include <iostream>
#include <fstream>
#include <locale>

#include "args.h"
#include "dictionary.h"
#include "extractor.h"
#include "selector.h"

using namespace xinci;

int main(int argc, char** argv) {
    std::vector<std::string> args(argv, argv + argc);
    Args a = Args();

    if (args.size() < 2) {
        std::cerr << "Empty input path." << std::endl;
        a.printHelp();
        exit(EXIT_FAILURE);
    }
    a.parseArgs(args);
    a.printArgs();

//    a.input = "/Users/lapis-hong/Documents/C++/xinci/test.txt";
//    a.commonWordsDic = "/Users/lapis-hong/Documents/C++/xinci/common.dic";
    std:: ifstream in (a.input);
    std::istreambuf_iterator<char> begin(in);
    std::istreambuf_iterator<char> end;
    std::string document(begin, end);

    //std::string document = u8"我们是中国人！";

//    CnTextSelector selector (document, 5, 2);
//    std::cout << document.size() << std::endl;
//    std::cout << document.substr(0,3) << std::endl;
//    std::cout << document.substr(0,4) << std::endl;
//    std::cout << document[1] << std::endl;
//    while (!selector.end()) {
//    std::cout << selector.next() << std::endl;}

    Dictionary dictionary (a.commonWordsDic);
    WordExtractor xc (document, a.output, dictionary, a.minCandidateLen, a.maxCandidateLen,
        a.leastWordCount, a.solidRate, a.entropyRate, a.allWords);
    xc.extract();

    return 0;
}



