#include <iostream>
#include <string>

std::string pig_latin(std::string word);
std::string convert_sentence(std::string sentence);

int main()
{   
    std::string sentence = "this is a simple sentence ";
    std::cout << convert_sentence(sentence);

    return 0;
}

std::string pig_latin(std::string word)
{
    word.append(word.substr(0, 1));
    word.append("ay");
    word.erase(0, 1);
    return word;
}

std::string convert_sentence(std::string sentence)
{
    size_t start_of_word{};
    size_t end_of_word{};

    std::string result{};

    // no spaces in the sentence
    if (sentence.find_first_of(' ') == std::string::npos)
    {
        return pig_latin(sentence);
    }

    while (start_of_word < sentence.length())
    {
        end_of_word = sentence.find(' ', start_of_word);

        // check for last word
        if (end_of_word == std::string::npos)
        {
            result.append(pig_latin(sentence.substr(start_of_word)));
            break;
        }
        result.append(pig_latin(sentence.substr(start_of_word, end_of_word - start_of_word)));
        result += ' ';
        start_of_word = end_of_word + 1;
    }
    if (isspace(result[result.length() - 1]))
    {
        result = result.substr(0, result.length() - 1);
    }
    return result;
}